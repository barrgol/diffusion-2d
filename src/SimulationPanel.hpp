#pragma once

#include <SFML/Graphics.hpp>
#include "Diffusion.hpp"

class SimulationPanel
{
public:
    const int WIDTH = 1000;
    const int HEIGHT = 1000;
    const int LEFT_OFFSET = 500;
    const sf::Color BASE_COLOR{ 200, 200, 30 };

    Diffusion* diffPtr;
    std::vector<std::vector<sf::RectangleShape>> gridCells;

    SimulationPanel(Diffusion* diffPtr);
    ~SimulationPanel();

    void update();
    void render(sf::RenderWindow& window);

private:
    /* data */
};
