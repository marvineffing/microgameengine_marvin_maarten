#include "Gameplay.hpp"
#include <iostream>
#include "Time.hpp"

Gameplay::Gameplay(sf::RenderWindow* window) : _window(window)
{
    laps = 0;
}

void Gameplay::createCamera()
{
    _camera = new Camera("Camera", glm::vec3( -1.0f, 0.9f, -2.0f));
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
    _raceCar = new RaceCar("Going Turbo", glm::vec3(7,0,0));
    _raceCar->setMesh( Mesh::load( "models/car.obj") );
    _raceCar->setColorMap( Texture::load("models/truck_color_cleantest.jpg") );
    _raceCar->setCollider( new Collider( _raceCar ) );
    _raceCar->setBehaviour(new RaceCarBehaviour(_raceCar));
    _world->add(_raceCar);
}

void Gameplay::createObstacle(glm::vec3 position) {
    monkey = new GameObject("Monkey", position);
    monkey->setMesh(Mesh::load("models/suzanna.obj"));
    monkey->setColorMap(Texture::load("models/monkey.jpg"));
    monkey->setCollider(new Collider(monkey));
    _world->add(monkey);
}

void Gameplay::createTrack(glm::vec3 position)
{
    _track = new GameObject("Track", position);
    _track->setMesh( Mesh::load( "models/floor.obj" ) );
    _track->setColorMap( Texture::load( "models/track.jpg" ) );
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

void Gameplay::stopCar() {
    _raceCar->setSpeed(0);
}

void Gameplay::crashCar() {
    stopCar();
    _raceCar->setSpeed(-1);
}

int Gameplay::getLaps() {
    return laps;
}

void Gameplay::incrLaps() {
    laps++;
}

void Gameplay::draw() {

    glDisable( GL_CULL_FACE );
    char laps[] = "0/1 laps";
    sprintf( laps, "%1d", getLaps() );

    sf::Text text( laps );
	//text.setFont(font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	text.setPosition( 10, 50);


	// Draw it
	//std::cout << "Drawing text" << std::endl;
	assert ( _window != NULL );
	_window->draw(text);

}
