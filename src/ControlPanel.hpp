#pragma once

#include <SFML/Graphics.hpp>
#include "Diffusion.hpp"
#include <string>

class ControlPanel
{
public:
    // Font
    sf::Font font;

    // Background
    const sf::Vector2f BACKGROUND_SIZE{ 500, 1000 };
    const sf::Vector2f BACKGROUND_POSITION{ 0, 0 };
    const sf::Color BACKGROUND_COLOR{ 180, 170, 170 };

    // Simulation toggle ON / OFF button
    const sf::Vector2f SIMULATION_TOGGLE_SIZE{ 250, 50 };
    const sf::Vector2f SIMULATION_TOGGLE_POSITION{ 125, 40 };
    const sf::Color SIMULATION_TOGGLE_COLOR_ON{ 80, 230, 50 };
    const sf::Color SIMULATION_TOGGLE_COLOR_OFF = sf::Color::White;

    bool SIMULATION_ON = false;

    // Diffusion logic
    Diffusion* diff;

    // Constructor & Destructor
    ControlPanel(sf::Font& font, Diffusion* diff);
    ~ControlPanel();

    // Logic control
    void toggleSimulation();

    // Position checking
    bool mouseOnToggleSimulationButton(sf::RenderWindow& window);

    // Rendering elements
    void render(sf::RenderWindow& window);
    void renderBackground(sf::RenderWindow& window);
    void renderSimulationToggle(sf::RenderWindow& window);
    void renderSimulationSteps(sf::RenderWindow& window);

private:
    /* data */
};
