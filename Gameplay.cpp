#include "Gameplay.h"

Gameplay::Gameplay(sf::RenderWindow* window) : window(window)
{
}

void Gameplay::createCamera(glm::vec3 position)
{
    camera = new Camera( "Camera", position);
    camera->setBehaviour( new WASDBehaviour( camera, window ) );
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
    GameObject * car = new GameObject("Enemy", glm::vec3( 2,0,-5 ) );
   // car->setBehaviour( new KeysBehaviour( car ) );
    car->setMesh( Mesh::load( "models/car.obj") );
    car->setColorMap( Texture::load("models/truck_color_cleantest.jpg") );
    car->setCollider( new Collider( car ) );
    world->add( car );
}

void Gameplay::createTrack(glm::vec3 position)
{
    GameObject * track = new GameObject("Track", position );
    track->setMesh( Mesh::load( "models/floor.obj" ) );
    track->setColorMap( Texture::load( "models/land.jpg" ) );
    world->add(track);
}

void Gameplay::createSkybox()
{

}

World * Gameplay::getWorld()
{
    return world;
}
