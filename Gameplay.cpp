#include "Gameplay.h"
#include <iostream>
#include "Skybox.h"

Gameplay::Gameplay(sf::RenderWindow* window) : window(window)
{
}

void Gameplay::createCamera()
{
    camera = new Camera( "Camera");
    camera->setBehaviour(new CameraBehaviour(camera, car));
    world->add(camera);
}

void Gameplay::createWorld()
{
    world = new World("World");
}

void Gameplay::createLight(glm::vec3 position)
{
    light = new Light( "Light", position );
    world->add(light);
}

void Gameplay::createCar()
{
    car = new GameObject("Car", glm::vec3( 0,0,0 ) );
    car->setBehaviour( new WASDBehaviour( car, window ) );
    car->setMesh( Mesh::load( "models/car.obj") );
    car->setColorMap( Texture::load("models/truck_color_cleantest.jpg") );
    car->setCollider( new Collider( car ) );

    // add tires
    GameObject* frontLeft = new GameObject("FrontLeftTire", glm::vec3(0.5f,0,0));
    frontLeft->setMesh(Mesh::load("models/cartire.obj"));
    car->add(frontLeft);

    world->add( car );
}

void Gameplay::createObstacle(glm::vec3 position) {

}

void Gameplay::createTrack(glm::vec3 position)
{
    track = new GameObject("Track", position );
    track->setMesh( Mesh::load( "models/floor.obj" ) );
    track->setColorMap( Texture::load( "models/land.jpg" ) );
    world->add(track);
}

void Gameplay::createSkybox()
{
    Skybox * skybox = new Skybox("Skybox", glm::vec3(0.0, 0.0, 0.0));
    world->add(skybox);
}

World * Gameplay::getWorld()
{
    return world;
}
