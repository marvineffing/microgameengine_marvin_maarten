#include "RaceCar.hpp"
#include "Timer.hpp"

#include <GLM/gtx/quaternion.hpp>
#include <GLM/gtc/quaternion.hpp>

RaceCar::RaceCar(std::string name, glm::vec3 position, ShaderProgram* shaderProgram)
    : GameObject("RaceCar", position, shaderProgram), _shaderProgram(shaderProgram), _speed(0), _xrot_wheel(0), _yrot_wheel(0), _hitCounter(0)

{
    Mesh * tireMesh = Mesh::load("models/cartire.obj");
    crashSoundBuffer.loadFromFile("sounds/crash.wav");
    startSoundBuffer.loadFromFile("sounds/finish.wav");

    // Tires
    Tire* frontLeft = new Tire("FrontLeftTire", glm::vec3(-0.15, 0.10, 0.32), _shaderProgram);
    frontLeft->setMesh(tireMesh);
    frontLeft->transform = glm::mat4(glm::scale(frontLeft->transform, glm::vec3(2.5,2.5,2.5)));
    _tires.push_back(frontLeft);

    Tire* frontRight = new Tire("FrontRightTire", glm::vec3(0.15, 0.10, 0.32), _shaderProgram);
    frontRight->setMesh(tireMesh);
    frontRight->rotate(180, glm::vec3(0,1.0,0));
    frontRight->transform = glm::mat4(glm::scale(frontRight->transform, glm::vec3(2.5,2.5,2.5)));
    _tires.push_back(frontRight);

    Tire* backLeft = new Tire("BackLeftTire", glm::vec3(-0.15, 0.10, -0.27), _shaderProgram);
    backLeft->setMesh(tireMesh);
    backLeft->transform = glm::mat4(glm::scale(backLeft->transform, glm::vec3(2.5,2.5,2.5)));
    _tires.push_back(backLeft);

    Tire* backRight = new Tire("BackRightTire", glm::vec3(0.15, 0.10, -0.27), _shaderProgram);
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
    } else if (direction ==  RIGHT) {
        if (_speed > 0) {
            rotate(step*(0-_steering),rotationAxes);
        }
        if (_speed < 0) {
            rotate(step*_steering,rotationAxes);
        }
    }
}

void RaceCar::onCollision(GameObject * anObject) {
    if (anObject->getName() == "START") {
        if (_hitCounter == 0) {
            Timer::start();
            completeLap();
        }

        //omdat de tijd andere na 0.00000xx seconden weer reset. Collision vindt plaatst op meer dan 1 tijdstip.
        if (Timer::now() > 5) {
            completeLap();
            ++_hitCounter;
            if (_hitCounter == 1)
                Timer::setBestTime(1000.00);
            Timer::reset();
        }
    } else if (anObject->getName() == "Monkey") {
        crashCar();
    }

}

void RaceCar::crashCar() {
    if (sound.getStatus() == sf::Sound::Stopped) {
        sound.setBuffer(crashSoundBuffer);
        sound.play();
    }
    stop();
    setSpeed(-1);
}

/**
* Method to signify a completion of a lap by the car by playing a sound and recording your time.
**/
void RaceCar::completeLap() {
    if (sound.getStatus() == sf::Sound::Stopped) {
        sound.setBuffer(startSoundBuffer);
        sound.play();
    }
}

void RaceCar::rotateWheels(float step, int direction)
{
    float xAngle = 200 * step * _speed;
    _xrot_wheel += xAngle;
//    _tires[0]->rotate(xAngle,glm::vec3(cos(_yrot_wheel),0,-sin(_yrot_wheel)));
//    _tires[1]->rotate(-xAngle,glm::vec3(cos(_yrot_wheel),0,-sin(_yrot_wheel)));
//    _tires[2]->rotate(xAngle,glm::vec3(1,0,0));
//    _tires[3]->rotate(-xAngle,glm::vec3(1,0,0));
    _tires[0]->rotate(xAngle,glm::vec3(1,0,0));
    _tires[1]->rotate(-xAngle,glm::vec3(1,0,0));
    _tires[2]->rotate(xAngle,glm::vec3(1,0,0));
    _tires[3]->rotate(-xAngle,glm::vec3(1,0,0));

//    float yAngle = step * _yrot_wheel_step;
//    if (direction == LEFT) {
//        _yrot_wheel += yAngle;
//        _tires[0]->rotate(yAngle, glm::vec3(0,cos(_xrot_wheel),sin(_yrot_wheel)));
//        _tires[1]->rotate(yAngle, glm::vec3(0,cos(_xrot_wheel),sin(_yrot_wheel)));
////        _tires[0]->setAngle(yAngle, glm::vec3(0,1,0));
////        _tires[1]->setAngle(yAngle, glm::vec3(0,1,0));
//    } else if (direction == RIGHT) {
//        _yrot_wheel -= yAngle;
//        _tires[0]->rotate(yAngle*-1, glm::vec3(0,cos(_xrot_wheel),sin(_yrot_wheel)));
//        _tires[1]->rotate(yAngle*-1, glm::vec3(0,cos(_xrot_wheel),sin(_yrot_wheel)));
////        _tires[0]->setAngle(yAngle*-1, glm::vec3(0,1,0));
////        _tires[1]->setAngle(yAngle*-1, glm::vec3(0,1,0));
//    } else if (direction == CENTER) {
//        if (_yrot_wheel > 0) {
//            _yrot_wheel -= yAngle;
//            _tires[0]->setAngle(yAngle*-1, glm::vec3(0,cos(_xrot_wheel),sin(_yrot_wheel)));
//            _tires[1]->setAngle(yAngle*-1, glm::vec3(0,cos(_xrot_wheel),sin(_yrot_wheel)));
//        } else if (_yrot_wheel < 0) {
//            _yrot_wheel += yAngle;
//            _tires[0]->setAngle(yAngle, glm::vec3(0,cos(_xrot_wheel),sin(_yrot_wheel)));
//            _tires[1]->setAngle(yAngle, glm::vec3(0,cos(_xrot_wheel),sin(_yrot_wheel)));
//        }
//    }
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
