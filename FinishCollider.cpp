#include "GameObject.hpp"
#include "FinishCollider.h"
#include <iostream>

FinishCollider::FinishCollider(GameObject * aParent, float aRadius) : parent(aParent), radius(aRadius) {
    soundBuffer.loadFromFile("sounds/finish.wav");
}

FinishCollider::~FinishCollider() {}

bool FinishCollider::collidesWithFinish(Collider * otherCollider) {
    bool retVal = false;

    glm::vec3 location = parent->getLocation();
    glm::vec3 otherLocation = otherCollider->parent->getLocation();
    float distance = glm::distance(location, otherLocation);

    if (distance < radius + otherCollider->radius) {
        if (sound.getStatus() == sf::Sound::Stopped) {
            sound.setBuffer(soundBuffer);
            sound.play();
        }
        std::cout << parent->getName() << " crossed the finish line." << std::endl;
        retVal = true;
    }

    return retVal;
}
