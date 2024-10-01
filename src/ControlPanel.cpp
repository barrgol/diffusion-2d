#include "ControlPanel.hpp"
#include <iostream>

ControlPanel::ControlPanel(sf::Font& font, Diffusion* diff) {
    this->font = font;
    this->diffPtr = diff;
}

ControlPanel::~ControlPanel() {
}

void ControlPanel::toggleSimulation() {
    this->SIMULATION_ON = !this->SIMULATION_ON;
}

bool ControlPanel::mouseOnToggleSimulationButton(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return (mousePosition.x > SIMULATION_TOGGLE_POSITION.x && mousePosition.x < SIMULATION_TOGGLE_POSITION.x + SIMULATION_TOGGLE_SIZE.x &&
        mousePosition.y > SIMULATION_TOGGLE_POSITION.y && mousePosition.y < SIMULATION_TOGGLE_POSITION.y + SIMULATION_TOGGLE_SIZE.y);
};

void ControlPanel::render(sf::RenderWindow& window) {
    this->renderBackground(window);
    this->renderSimulationToggle(window);
    this->renderSimulationSteps(window);
    return;
}

void ControlPanel::renderBackground(sf::RenderWindow& window) {
    sf::RectangleShape background{ this->BACKGROUND_SIZE };
    background.setPosition(this->BACKGROUND_POSITION);
    background.setFillColor(this->BACKGROUND_COLOR);
    window.draw(background);

    return;
}

void ControlPanel::renderSimulationToggle(sf::RenderWindow& window) {
    // Hovering and clicking the button
    if (this->mouseOnToggleSimulationButton(window)) {
        // Set cursor style to pointing hand
        sf::Cursor cursor;
        cursor.loadFromSystem(sf::Cursor::Hand);
        window.setMouseCursor(cursor);
    }
    else {
        // Set cursor style to regular arrow
        sf::Cursor cursor;
        cursor.loadFromSystem(sf::Cursor::Arrow);
        window.setMouseCursor(cursor);
    }

    // TODO: This should not be reinitialized
    // Simulation toggle button
    sf::RectangleShape simulationToggle{ this->SIMULATION_TOGGLE_SIZE };
    simulationToggle.setPosition(this->SIMULATION_TOGGLE_POSITION);
    simulationToggle.setFillColor(this->SIMULATION_ON ? this->SIMULATION_TOGGLE_COLOR_ON : this->SIMULATION_TOGGLE_COLOR_OFF);
    simulationToggle.setOutlineColor(this->SIMULATION_TOGGLE_COLOR_OFF);
    simulationToggle.setOutlineThickness(5);

    // Text on the toggle button
    sf::Text text{ this->SIMULATION_ON ? "STOP" : "START", this->font };
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);
    text.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
    text.setPosition(simulationToggle.getPosition() + (simulationToggle.getSize() / 2.f));

    // Rendering
    window.draw(simulationToggle);
    window.draw(text);

    return;
}

void ControlPanel::renderSimulationSteps(sf::RenderWindow& window) {
    // Simulation steps text
    // Text on the toggle button
    sf::Text text{ "Simulation steps: " + std::to_string(this->diffPtr->nsteps) + (this->diffPtr->converged ? " (conv.)" : ""), this->font };
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setOrigin(-(this->BACKGROUND_POSITION + sf::Vector2f{ 0, this->BACKGROUND_SIZE.y }));
    text.setPosition(sf::Vector2f{ 10, -30 });

    // Rendering
    window.draw(text);

    return;
}
