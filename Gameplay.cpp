#include "Gameplay.hpp"
#include <iostream>
#include "Skybox.hpp"

Gameplay::Gameplay(sf::RenderWindow* window) : window(window)
{
    laps = 0;
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
    raceCar = new RaceCar(glm::vec3(7,0,0));
    raceCar->setBehaviour(new RaceCarBehaviour(raceCar));
    raceCar->setMesh( Mesh::load( "models/car.obj") );
    raceCar->setColorMap( Texture::load("models/truck_color_cleantest.jpg") );
    raceCar->setCollider( new Collider( raceCar ) );
    world->add(raceCar);
}

void Gameplay::createObstacle(glm::vec3 position) {
    monkey = new GameObject("Monkey", position);
    monkey->setMesh(Mesh::load("models/suzanna.obj"));
    monkey->setColorMap(Texture::load("models/monkey.jpg"));
    monkey->setCollider(new Collider(monkey));
    world->add(monkey);
}

void Gameplay::createTrack(glm::vec3 position)
{
    track = new GameObject("Track", position );
    track->setMesh( Mesh::load( "models/floor.obj" ) );
    track->setColorMap( Texture::load( "models/track.jpg" ) );
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

void Gameplay::stopCar() {
    raceCar->setSpeed(0);
}

void Gameplay::crashCar() {
    stopCar();
    raceCar->setSpeed(-1);
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
	assert ( window != NULL );
	window->draw(text);

}
