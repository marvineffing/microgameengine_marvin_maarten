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
#include "Collider.hpp"
#include "Gameplay.hpp"
#include "Skybox.hpp"

Game::Game()
:	_window(NULL), _hud(NULL), _renderer(NULL)
{
	_window = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "Race Game Marvin en Maarten" ); // get a window
	std::cout << "Init Glew" << glewInit() << std::endl;
	_hud = new Hud( _window );
	//window->setVerticalSyncEnabled( true ); // sync with monitor ->60 hz approx
	_renderer = new Renderer( _window );

	//load music file
    //music.openFromFile("sounds/hellmarch.wav");
}

Game::~Game()
{
	//dtor
}

void Game::build()
{
	_renderer->use(  new ShaderProgram( "shaders/default.vs", "shaders/default.fs" ) );

    _gameplay = new Gameplay(_window);
	_gameplay->createWorld();
	_gameplay->createSkybox();
	_gameplay->createLight(glm::vec3( 2.0f, 10.0f, 5.0f ));


    _gameplay->createCar();
	_gameplay->createCamera();
    _gameplay->createTrack(glm::vec3(0.0,0.0,0.0));
    _gameplay->createObstacle(glm::vec3(0.0, 0.0, 9.0));
}

void Game::run()
{
    //todo: loop music door getstatus
    //playMusic();
	_running = true;
	while ( _running ) {
		Time::update();
		FPS::update();
		control();
		if ( _running ) { // control may have changed running;
			update( Time::step() );
			draw();
		}
	}
}

//void Game::playMusic() {
//    _music.play();
//}

//void Game::pauseMusic() {
//    _music.pause();
//}

void Game::stop()
{
}

// private functions

void Game::control()
{
	sf::Event event;
	while( _window->pollEvent( event ) ) {
		if ( event.type == sf::Event::Closed ) {
			_window->close();
			_running = false; // running = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        _window->close();
        _running = false;
	}
}

void Game::update(float step)
{
    World * world = _gameplay->getWorld();
	assert( world != NULL );
	world->update( step);
	checkCollisions();
}

void Game::draw()
{
    World * world = _gameplay->getWorld();
	assert( _window != NULL );
	assert( _renderer != NULL );
	assert( world != NULL );

	_renderer->draw( world );
	_window->pushGLStates();
	_hud->draw();
	_window->popGLStates();
	_window->display();
    _gameplay->updateCamera();
}


bool Game::checkCollisions()
{
    bool retVal;
    World * world = _gameplay->getWorld();
    retVal = world->checkCollisions();
    if (retVal) {
        _gameplay->crashCar();
    }
	return retVal;
}
