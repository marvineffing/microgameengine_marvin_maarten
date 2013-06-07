#include "RaceCar.hpp"

RaceCar::RaceCar(glm::vec3 position) : GameObject("RaceCar", position), _speed(0), _speed_limit(160)
{
    Mesh * tireMesh = Mesh::load("models/cartire.obj");

    // Tires
    Tire* frontLeft = new Tire("FrontLeftTire", glm::vec3(-0.15,0.10,-0.27));
    frontLeft->setMesh(tireMesh);
    frontLeft->transform = glm::mat4( glm::scale(frontLeft->transform, glm::vec3(2.5,2.5,2.5)));
    add(frontLeft);

    Tire* frontRight = new Tire("FrontLeftTire", glm::vec3(0.15, 0.10, -0.27));
    frontRight->setMesh(tireMesh);
    frontRight->rotate(180, glm::vec3(0,1.0,0));
    frontRight->transform = glm::mat4( glm::scale(frontRight->transform, glm::vec3(2.5,2.5,2.5)));
    add(frontRight);

    Tire* backLeft = new Tire("FrontLeftTire", glm::vec3(-0.15, 0.10, 0.32));
    backLeft->setMesh(tireMesh);
    backLeft->transform = glm::mat4( glm::scale(backLeft->transform, glm::vec3(2.5,2.5,2.5)));
    add(backLeft);

    Tire* BackRight = new Tire("FrontLeftTire", glm::vec3(0.15, 0.10, 0.32));
    BackRight->setMesh(tireMesh);
    frontRight->rotate(180, glm::vec3(0,1.0,0));
    BackRight->transform = glm::mat4( glm::scale(BackRight->transform, glm::vec3(2.5,2.5,2.5)));
    add(BackRight);
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
