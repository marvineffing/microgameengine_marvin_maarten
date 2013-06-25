#pragma once

#include "GameObject.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "RaceCar.hpp"
#include "Skybox.hpp"

#include "Behaviours/RaceCarBehaviour.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Gameplay {
    private:
        sf::RenderWindow * _window;
        World * _world;
        Camera * _camera;
        Light * _light;
        RaceCar * _raceCar;
        GameObject * _track;
        GameObject * _tree;
        Skybox * _skybox;
        GameObject * monkey;
        int laps;

    public:
        Gameplay(sf::RenderWindow * window);

        void createCamera();
        void createWorld();
        void createLight(glm::vec3 position);
        void createCar();
        void createTrack(glm::vec3 position);
        void createSkybox();
        void createObstacle(glm::vec3 position);
        void updateCamera();

        //collision
        void stopCar();
        void crashCar();

        World * getWorld();

        int getLaps();
        void incrLaps();

        void draw(); //for laps
};
