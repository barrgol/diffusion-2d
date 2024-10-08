#include <SFML/Graphics.hpp>
#include "SimulationPanel.hpp"
#include "ControlPanel.hpp"
#include <filesystem>
#include <iostream>

const int WINDOW_WIDTH = 1500;
const int WINDOW_HEIGHT = 1000;

int main()
{
    // Load font from file
    sf::Font font;
    if (!font.loadFromFile("res/PIXELIFYSANS-VARIABLEFONT_WGHT.ttf")) {
        return EXIT_FAILURE;
    }

    // Declare diffusion logic
    Diffusion* diffPtr = new Diffusion();

    // Declare window and visual panels
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Application");
    SimulationPanel simulationPanel(diffPtr);
    ControlPanel controlPanel(font, diffPtr);

    // Mainloop
    window.clear();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left && controlPanel.mouseOnToggleSimulationButton(window))
                {
                    controlPanel.toggleSimulation();
                }
            }
        }

        window.clear();

        if (controlPanel.SIMULATION_ON && !(*diffPtr).converged) {
            (*diffPtr).step();
        }

        simulationPanel.update();
        simulationPanel.render(window);
        controlPanel.render(window);

        window.display();
    }

    return 0;
}