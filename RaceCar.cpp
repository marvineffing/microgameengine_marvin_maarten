#include "RaceCar.hpp"

RaceCar::RaceCar(glm::vec3 position) : GameObject("RaceCar", position), _speed(0)
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

void RaceCar::steer(float step, int direction)
{
    //TODO: Limit rotation of wheels
    glm::vec3 rotationAxes = glm::vec3(0,1.0,0);
    if (direction == LEFT) {
        if (_speed > 0) {
            rotate(step*50,rotationAxes);
        }
        if (_speed < 0) {
            rotate(-step*50,rotationAxes);
        }
        steerWheels(step, direction);
    } else if (direction ==  RIGHT) {
        if (_speed > 0) {
            rotate(-step*50,rotationAxes);
        }
        if (_speed < 0) {
            rotate(step*50,rotationAxes);
        }
        steerWheels(step, direction);
    }
}

void RaceCar::steerWheels(float step, int direction)
{
    glm::vec3 rotationAxes = glm::vec3(0,1.0,0);
    if (direction == LEFT) {
        _tires[0]->rotate(step*50, rotationAxes);
        _tires[1]->rotate(step*50, rotationAxes);

    } else if (direction == RIGHT) {
        _tires[0]->rotate(step*-50,rotationAxes);
        _tires[1]->rotate(step*-50,rotationAxes);
    }
}

void RaceCar::resetSteerWheels()
{

}

void RaceCar::rotateWheels(float step)
{
    if (_speed != 0) {
        for (unsigned int i = 0; i < _tires.size(); ++i)
            _tires[i]->rotate(150*step*_speed,glm::vec3(1.0,0,0));
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
    if (_sound.getStatus() == sf::Sound::Stopped) {
        _sound.play();
    }
}

int RaceCar::getSpeed()
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
