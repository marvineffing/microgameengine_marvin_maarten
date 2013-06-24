#include "Gameplay.hpp"
#include <iostream>
#include "Skybox.hpp"

Gameplay::Gameplay(sf::RenderWindow* window) : window(window)
{
}

void Gameplay::createCamera()
{
    camera = new Camera("Camera", glm::vec3( 0.0f, 3.0f, -5.0f ) );
    camera->setBehaviour(new CameraBehaviour(camera));
    raceCar->add(camera);
}

void Gameplay::createWorld()
{
    world = new World("World");
}

void Gameplay::createLight(glm::vec3 position)
{
    light = new Light("Light", position);
    world->add(light);
}

void Gameplay::createCar()
{
    raceCar = new RaceCar(glm::vec3(0,0,0));
    raceCar->setBehaviour(new RaceCarBehaviour(raceCar));
    raceCar->setMesh( Mesh::load( "models/car.obj") );
    raceCar->setColorMap( Texture::load("models/truck_color_cleantest.jpg") );
    raceCar->setCollider( new Collider( raceCar ) );
    //raceCar->rotate(10, glm::vec3(0,1.0,0));

    world->add(raceCar);
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
