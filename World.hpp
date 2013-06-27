#pragma once

#include "GameObject.hpp"
#include <SFML/Audio.hpp>
class Camera;
class Light;
class World : public GameObject
{
	private:
        sf::SoundBuffer soundBuffer;
        sf::Sound sound;
	public:
		World( std::string aName = NULL, ShaderProgram* shaderProgram = NULL);
		virtual ~World();

		void update( float step );
		bool checkCollisions();
		bool checkFinishCollisions();

		virtual void draw( Renderer * renderer );

};
