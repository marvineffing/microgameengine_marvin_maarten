#include "Gameplay.hpp"
#include <iostream>
#include "Time.hpp"
#include "Behaviours/RaceCarBehaviour.hpp"
#include "Behaviours/MoveSkyBehaviour.hpp"

Gameplay::Gameplay(sf::RenderWindow* window) : _window(window)
{
    laps = 0;
    _normalProgram = new ShaderProgram("shaders/default.vs", "shaders/default.fs");
    _skyProgram = new ShaderProgram("shaders/sky.vs", "shaders/sky.fs");
}

void Gameplay::createCamera()
{
    _camera = new Camera("Camera", glm::vec3( -1.0f, 0.9f, -2.0f));
    //_raceCar->add(_camera);
}

void Gameplay::createWorld()
{
    _world = new World("World", _normalProgram);
}

void Gameplay::createLight(glm::vec3 position)
{
    _light = new Light("Light", position, _normalProgram);
    _world->add(_light);
}

void Gameplay::createCar()
{
    _raceCar = new RaceCar("Going Turbo", glm::vec3(7,0,0), _normalProgram);
    _raceCar->setMesh( Mesh::load( "models/car.obj") );
    _raceCar->setColorMap( Texture::load("models/truck_color_cleantest.jpg") );
    _raceCar->setCollider( new Collider( _raceCar ) );
    _raceCar->setBehaviour(new RaceCarBehaviour(_raceCar));
    _world->add(_raceCar);
}

void Gameplay::createFinish() {
    finish = new GameObject("Finish", glm::vec3(7.0, 0.0, 3.0), _normalProgram);
    //finish->setMesh(Mesh::load("models/finish.obj"));
    finish->setMesh(Mesh::load("models/suzanna.obj"));
    monkey->setColorMap(Texture::load("models/finish.jpg"));
    finish->setFinishCollider(new FinishCollider(finish));
    _world->add(finish);
}

void Gameplay::createObstacle(glm::vec3 position) {
    monkey = new GameObject("Monkey", position, _normalProgram);
    monkey->setMesh(Mesh::load("models/suzanna.obj"));
    monkey->setColorMap(Texture::load("models/monkey.jpg"));
    monkey->setCollider(new Collider(monkey));
    _world->add(monkey);
}

void Gameplay::createTrack(glm::vec3 position)
{
    _track = new GameObject("Track", position, _normalProgram);
    _track->setMesh( Mesh::load( "models/floor.obj" ) );
    _track->setColorMap( Texture::load( "models/track.jpg" ) );
    _world->add(_track);
    _track->scale(glm::vec3(2.0,1.0,2.0));
}

void Gameplay::createSkybox()
{
    _skybox = new Skybox("Skybox", glm::vec3(0.0, 0.0, 0.0), _skyProgram);
    _skybox->setBehaviour(new MoveSkyBehaviour(_skybox, _raceCar));
    _world->add(_skybox);
}

World * Gameplay::getWorld()
{
    return _world;
}

Camera * Gameplay::getCamera()
{
    return _camera;
}

RaceCar * Gameplay::getRaceCar()
{
    return _raceCar;
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
    std::cout << " Player has crossed finish line." << std::endl;
}

void Gameplay::draw() {

    glDisable( GL_CULL_FACE );
    char laps[] = "0/1 laps";
    sprintf( laps, "Laps: %1d", getLaps() );

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
