#include "GameObject.hpp"
#include <vector>
#include <string>
#include "glm.hpp"
#include "Wheel.hpp"
class GameObject;
class Checkpoint : public GameObject
{
    public:
        Checkpoint( std::string aName = NULL, glm::vec3 aPosition = glm::vec3(0.0f ,0.0f, 0.0f) );
        virtual ~Checkpoint();
        virtual void onCollision(GameObject * otherGameObject);
    protected:
    private:
};
