#include <cassert>

#include "Time.hpp"
#include "FPS.hpp"

#include "Hud.hpp"
#include "Renderer.hpp"
#include "ShaderProgram.hpp"
#include "Game.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Behaviours/KeysBehaviour.hpp"
#include "Behaviours/WASDBehaviour.hpp"
#include "Behaviours/RotatingBehaviour.hpp"
#include "Collider.hpp"
#include "Gameplay.h"

Game::Game()
:	window(NULL), hud(NULL), renderer(NULL)
{
	window = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "Saxion Game" ); // get a window
	std::cout << "Init Glew" << glewInit() << std::endl;
	hud = new Hud( window );
	//window->setVerticalSyncEnabled( true ); // sync with monitor ->60 hz approx
	renderer = new Renderer( window );
}

Game::~Game()
{
	//dtor
}

void Game::build()
{
	renderer->use(  new ShaderProgram( "shaders/default.vs", "shaders/default.fs" ) );

    gameplay = new Gameplay(window);
	gameplay->createWorld();
	gameplay->createCamera(glm::vec3( 0, 1, 10 ));
	gameplay->createLight(glm::vec3( 2.0f, 10.0f, 15.0f ));

    gameplay->createCar();
    gameplay->createTrack(glm::vec3(0.0,0.0,0.0));
}

void Game::run()
{
	running = true;
	while ( running ) {
		Time::update();
		FPS::update();
		control();
		if ( running ) { // control may have changed running;
			update( Time::step() );
			draw();
		}
	}
}

void Game::stop()
{
}

// private functions

void Game::control()
{
	sf::Event event;
	while( window->pollEvent( event ) ) {
		if ( event.type == sf::Event::Closed ) {
			window->close();
			running = false; // running = false;
		}
	}
}

void Game::update( float step )
{
    World * world = gameplay->getWorld();
	assert( world != NULL );
	world->update( step );
	checkCollisions();
}

void Game::draw()
{
    World * world = gameplay->getWorld();
	assert( window != NULL );
	assert( renderer != NULL );
	assert( world != NULL );

	renderer->draw( world );
	window->pushGLStates();
	hud->draw();
	window->popGLStates();
	window->display();
}


bool Game::checkCollisions()
{
    World * world = gameplay->getWorld();
	return world->checkCollisions();
}