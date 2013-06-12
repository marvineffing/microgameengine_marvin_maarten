#include "Skybox.h"
#include "Mesh.hpp"
#include "Texture.hpp"
Skybox::Skybox(std::string aName, glm::vec3 aPosition )
:	GameObject(aName, aPosition )
{
	Mesh * planeMesh = Mesh::load("models/plane.obj");
    float test = 50;

    upPlane = new GameObject("PLANE", glm::vec3(-test/2,test/2,-test/2));
    upPlane->rotate(90,glm::vec3(1.0,0,0));
    upPlane->setMesh(planeMesh);
    upPlane->transform = glm::mat4( glm::scale(upPlane->transform, glm::vec3(test,test,1)));
    upPlane->setColorMap( Texture::load("models/skybox_up.jpg") );

    bottomPlane = new GameObject("PLANE", glm::vec3(-test/2,-test/2,test/2));
	bottomPlane->rotate(270,glm::vec3(1,0,0));
    bottomPlane->setMesh(planeMesh);
    bottomPlane->transform = glm::mat4( glm::scale(bottomPlane->transform, glm::vec3(test,test,1)));
    bottomPlane->setColorMap( Texture::load("models/skybox_bottom.jpg") );

    frontPlane = new GameObject("PLANE", glm::vec3(-test/2,-test/2,-test/2));
	frontPlane->setMesh(planeMesh);
	frontPlane->transform = glm::mat4( glm::scale(frontPlane->transform, glm::vec3(test,test,1)));
    frontPlane->setColorMap( Texture::load("models/skybox_front.jpg") );

    backPlane = new GameObject("PLANE", glm::vec3(test/2,-test/2,test/2));
    backPlane->setMesh(planeMesh);
    backPlane->rotate(180, glm::vec3(0,1,0));
    backPlane->transform = glm::mat4( glm::scale(backPlane->transform, glm::vec3(test,test,1)));
    backPlane->setColorMap( Texture::load("models/skybox_back.jpg") );

    rightPlane = new GameObject("PLANE", glm::vec3(test/2,-test/2,-test/2));
	rightPlane->setMesh(planeMesh);
	rightPlane->rotate(270, glm::vec3(0,1,0));
    rightPlane->transform = glm::mat4( glm::scale(rightPlane->transform, glm::vec3(test,test,1)));
	rightPlane->setColorMap( Texture::load("models/skybox_right.jpg") );

    leftPlane = new GameObject("PLANE", glm::vec3(-test/2,-test/2,test/2));
	leftPlane->setMesh(planeMesh);
	leftPlane->rotate(90, glm::vec3(0,1,0));
    leftPlane->transform = glm::mat4( glm::scale(leftPlane->transform, glm::vec3(test,test,1)));
	leftPlane->setColorMap( Texture::load("models/skybox_left.jpg") );

    GameObject::add(frontPlane);
    GameObject::add(backPlane);
    GameObject::add(rightPlane);
    GameObject::add(leftPlane);
    GameObject::add(upPlane);
    GameObject::add(bottomPlane);
}

Skybox::~Skybox()
{
    //dtor
}
