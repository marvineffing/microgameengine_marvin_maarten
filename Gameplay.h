#pragma once

#include "GameObject.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"

#include "Behaviours/WASDBehaviour.hpp"
#include "Behaviours/RotatingBehaviour.hpp"
#include "Behaviours/KeysBehaviour.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Gameplay {
    private:
        sf::RenderWindow * window;
        World * world;
        Camera * camera;
        Light * light;
        GameObject * car;

    public:
        Gameplay(sf::RenderWindow * window);

        void createCamera(glm::vec3 position);
        void createWorld();
        void createLight(glm::vec3 position);
        void createCar();
        void createTrack(glm::vec3 position);
        void createSkybox();

        World * getWorld();
};
