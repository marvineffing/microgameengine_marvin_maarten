#ifndef SKYBOX_H
#define SKYBOX_H

#include "GameObject.hpp"

class Skybox : public GameObject
{
    public:
        Skybox( std::string aName = NULL, glm::vec3 aPosition = glm::vec3(0.0f ,0.0f, 0.0f) );
        virtual ~Skybox();
    protected:
    private:
        GameObject * upPlane;
        GameObject * leftPlane;
        GameObject * rightPlane;
        GameObject * frontPlane;
        GameObject * backPlane;
        GameObject * bottomPlane;
};

#endif // SKYBOX_H

