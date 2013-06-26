#include <cassert>
#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include "FPS.hpp"
#include "Hud.hpp"

Hud::Hud( sf::RenderWindow * aWindow , Gameplay * gameplay)
:	_window( aWindow ), _gameplay(gameplay)
{
	assert ( _window != NULL );
}

Hud::~Hud()
{
	//dtor
}

void Hud::draw()
{
    glDisable( GL_CULL_FACE ); // needed for text, dont know why

    drawFPS();
    drawSpeed();
    drawTime();
}

void Hud::drawFPS()
{
    char fpsLabel[] = "FPS: ";
	char fps[] = "Test";
	sprintf( fps, "%4d", FPS::getFPS() );
	sf::Text text1(fpsLabel);
	sf::Text text2(fps);
	//text.setFont(font);
	text1.setCharacterSize(30);
	text2.setCharacterSize(30);
	text1.setStyle(sf::Text::Bold);
	text2.setStyle(sf::Text::Bold);
	text1.setColor(sf::Color::White);
	text2.setColor(sf::Color::White);
	text1.setPosition( 10,10);
	text2.setPosition( 80,10);


	// Draw it
	//std::cout << "Drawing text" << std::endl;
	if (_window != NULL) {
        _window->draw(text1);
        _window->draw(text2);
	}
}

void Hud::drawSpeed()
{
    char speed[] = "Tes";
    char speedLabel[] = "km/h";
    float carSpeed = _gameplay->getRaceCar()->getSpeed();

    int realSpeed = abs((floor(carSpeed*5+0.5)/5)*10);

    sprintf(speed, "%3i", realSpeed);
    sf::Text text1(speed);
    sf::Text text2(speedLabel);
    text1.setCharacterSize(30);
    text2.setCharacterSize(30);
	text1.setStyle(sf::Text::Bold);
	text2.setStyle(sf::Text::Bold);
	text1.setColor(sf::Color::White);
	text2.setColor(sf::Color::White);
	text1.setPosition(10,50);
	text2.setPosition(80,50);

	assert ( _window != NULL );
	if (_window != NULL) {
        _window->draw(text1);
        _window->draw(text2);
	}
}

void Hud::drawTime()
{

}
