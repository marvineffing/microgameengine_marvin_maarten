#include "Gameplay.hpp"
#include <iostream>
#include "Time.hpp"

Gameplay::Gameplay(sf::RenderWindow* window) : _window(window)
{
}

void Gameplay::createCamera()
{
    _camera = new Camera("Camera", glm::vec3( -1.0f, 0.9f, -2.0f ) );
    _camera->setBehaviour(new CameraBehaviour(_camera));
    _raceCar->add(_camera);
}

void Gameplay::createWorld()
{
    _world = new World("World");
}

void Gameplay::createLight(glm::vec3 position)
{
    _light = new Light("Light", position);
    _world->add(_light);
}

void Gameplay::createCar()
{
    _raceCar = new RaceCar(glm::vec3(0,0,0));
    _raceCar->setBehaviour(new RaceCarBehaviour(_raceCar));
    _raceCar->setMesh( Mesh::load( "models/car.obj") );
    _raceCar->setColorMap( Texture::load("models/truck_color_cleantest.jpg") );
    _raceCar->setCollider( new Collider( _raceCar ) );

    _world->add(_raceCar);
}

void Gameplay::createObstacle(glm::vec3 position) {

}

void Gameplay::createTrack(glm::vec3 position)
{
    _track = new GameObject("Track", position );
    _track->setMesh( Mesh::load( "models/floor.obj" ) );
    _track->setColorMap( Texture::load( "models/land.jpg" ) );
    _world->add(_track);
}

void Gameplay::createSkybox()
{
    _skybox = new Skybox("Skybox", glm::vec3(0.0, 0.0, 0.0));
    _world->add(_skybox);
}

World * Gameplay::getWorld()
{
    return _world;
}

void Gameplay::updateCamera() {
    _camera->update(Time::step());
}
