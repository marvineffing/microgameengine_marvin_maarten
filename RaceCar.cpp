#include "RaceCar.hpp"

RaceCar::RaceCar(std::string name, glm::vec3 position)
    : GameObject("RaceCar", position), _speed(0), _xrot_wheel(0), _yrot_wheel(0)

{
    Mesh * tireMesh = Mesh::load("models/cartire.obj");

    // Tires
    Tire* frontLeft = new Tire("FrontLeftTire", glm::vec3(-0.15, 0.10, 0.32));
    frontLeft->setMesh(tireMesh);
    frontLeft->transform = glm::mat4(glm::scale(frontLeft->transform, glm::vec3(2.5,2.5,2.5)));
    _tires.push_back(frontLeft);

    Tire* frontRight = new Tire("FrontRightTire", glm::vec3(0.15, 0.10, 0.32));
    frontRight->setMesh(tireMesh);
    frontRight->rotate(180, glm::vec3(0,1.0,0));
    frontRight->transform = glm::mat4(glm::scale(frontRight->transform, glm::vec3(2.5,2.5,2.5)));
    _tires.push_back(frontRight);

    Tire* backLeft = new Tire("BackLeftTire", glm::vec3(-0.15, 0.10, -0.27));
    backLeft->setMesh(tireMesh);
    backLeft->transform = glm::mat4(glm::scale(backLeft->transform, glm::vec3(2.5,2.5,2.5)));
    _tires.push_back(backLeft);

    Tire* backRight = new Tire("BackRightTire", glm::vec3(0.15, 0.10, -0.27));
    backRight->setMesh(tireMesh);
    backRight->rotate(180, glm::vec3(0,1.0,0));
    backRight->transform = glm::mat4(glm::scale(backRight->transform, glm::vec3(2.5,2.5,2.5)));
    _tires.push_back(backRight);

    for (unsigned int i = 0; i < _tires.size(); ++i)
        add(_tires[i]);

    _soundBuffer.loadFromFile("sounds/horn.wav");
    _sound.setBuffer(_soundBuffer);
}

void RaceCar::accelerate(float step)
{
    if (_speed < _speed_limit) {
        _speed = _speed + _acceleration;
    }
    translate(glm::vec3(0.0f, 0.0f, step * _speed));
}

void RaceCar::stop() {
    _speed = 0;
}

void RaceCar::decelerate(float step)
{
    if ((_speed < _acceleration && _speed > 0) || (_speed > _acceleration && _speed < 0)) {
        _speed = 0;
    }
    if (_speed > 0) {
        _speed = _speed - _acceleration;
    } else if (_speed < 0) {
        _speed = _speed + _deceleration;
    }
    translate(glm::vec3(0.0f, 0.0f, step * _speed));
}

void RaceCar::brake(float step)
{
    correctSpeed();
    if (_speed > 0) {
        _speed = _speed -_fast_deceleration;
    } else if (_speed < 0) {
        _speed = _speed + _fast_deceleration;
    }
    translate(glm::vec3(0.0f, 0.0f, step * _speed));
}

void RaceCar::reverseAccelerate(float step)
{
    if (_speed > _speed_limit_reverse) {
        _speed = _speed - _acceleration;
    }
    translate(glm::vec3(0.0f, 0.0f, step * _speed ) );
}

void RaceCar::steerCar(float step, int direction)
{
    //TODO: Limit rotation of wheels
    glm::vec3 rotationAxes = glm::vec3(0,1.0,0);
    if (direction == LEFT) {
        if (_speed > 0) {
            rotate(step*_steering,rotationAxes);
        }
        if (_speed < 0) {
            rotate(step*(0-_steering),rotationAxes);
        }
        steerWheels(step, direction);
    } else if (direction ==  RIGHT) {
        if (_speed > 0) {
            rotate(step*(0-_steering),rotationAxes);
        }
        if (_speed < 0) {
            rotate(step*_steering,rotationAxes);
        }
        steerWheels(step, direction);
    }
}

void RaceCar::steerWheels(float step, int direction)
{
   // std::cout << "yrot = " << _yrot_wheel << std::endl;
    glm::vec3 rotationAxes = glm::vec3(0,cos(_xrot_wheel),sin(_xrot_wheel));
    if (direction == LEFT && _yrot_wheel <  _yrot_wheel_limit) {
        float angle = step * _yrot_wheel_step;
        _yrot_wheel += angle;
        _tires[0]->rotate(angle, rotationAxes);
        _tires[1]->rotate(angle, rotationAxes);

    } else if (direction == RIGHT && _yrot_wheel > (0-_yrot_wheel_limit)) {
        float angle = step * (0-_yrot_wheel_step);
        _yrot_wheel += angle;
        _tires[0]->rotate(angle,rotationAxes);
        _tires[1]->rotate(angle,rotationAxes);
    }
}

void RaceCar::resetSteerWheels(float step)
{
    glm::vec3 rotationAxes = glm::vec3(0,1,0);
    if (_yrot_wheel < (_yrot_wheel_step*step) && _yrot_wheel > (0-(_yrot_wheel_step*step)))
        _yrot_wheel = 0;
    if (_yrot_wheel > 0) {
        float angle = step * (0-_yrot_wheel_step);
        _yrot_wheel += angle;
        _tires[0]->rotate(angle, rotationAxes);
        _tires[1]->rotate(angle, rotationAxes);
    } else if (_yrot_wheel < 0) {
        float angle = step * _yrot_wheel_step;
        _yrot_wheel += angle;
        _tires[0]->rotate(angle, rotationAxes);
        _tires[1]->rotate(angle, rotationAxes);
    }
}

void RaceCar::rotateWheels(float step)
{
    if (_speed != 0) {
        for (unsigned int i = 0; i < _tires.size(); ++i) {
            float angle = 150 * step * _speed;
            _xrot_wheel += angle;
            if (_xrot_wheel > 360)
                _xrot_wheel -= 360;
            if (_xrot_wheel < 0)
                _xrot_wheel += 360;

            if (i == 0 || i == 1) {
                _tires[i]->rotate(angle,glm::vec3(cos(_yrot_wheel),0,sin(_yrot_wheel)));
            } else {
                _tires[i]->rotate(angle,glm::vec3(1,0,0));
            }
        }
    }
}

void RaceCar::correctSpeed()
{
    if ((_speed < _acceleration && _speed > 0) || (_speed > _acceleration && _speed < 0)) {
        _speed = 0;
    }
}

void RaceCar::playHorn()
{
//    if (_sound.getStatus() == sf::Sound::Stopped) {
//        _sound.play();
//    }
}

float RaceCar::getSpeed()
{
    return _speed;
}

void RaceCar::setSpeed(int speed)
{
    _speed = speed;
}

int RaceCar::getSpeedLimit()
{
    return _speed_limit;
}
