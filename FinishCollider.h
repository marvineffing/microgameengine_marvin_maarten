#pragma once
#include "Collider.hpp"

#include <SFML/Audio.hpp>

class GameObject;
class Collider;
class SphereCollider;

//todo: square / AABB collider
class FinishCollider {

public:
    FinishCollider(GameObject * aParent, float aRadius = 1.0f);
    virtual ~FinishCollider();
    virtual bool collidesWithFinish(Collider * otherCollider);

private:
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;
protected:
    GameObject * parent;
    float radius;

};
