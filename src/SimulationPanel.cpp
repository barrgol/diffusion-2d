#include "SimulationPanel.hpp"


SimulationPanel::SimulationPanel(Diffusion* diffPtr) {
    for (size_t i = 0; i < (*diffPtr).SIZE; i++) {
        this->gridCells.push_back({});
        this->diffPtr = diffPtr;

        for (size_t j = 0; j < (*diffPtr).SIZE; j++) {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(this->WIDTH / (*diffPtr).SIZE, this->HEIGHT / (*diffPtr).SIZE));
            rectangle.setPosition(this->LEFT_OFFSET + j * (float)this->WIDTH / (*diffPtr).SIZE, i * (float)this->HEIGHT / (*diffPtr).SIZE);
            rectangle.setFillColor(sf::Color(SimulationPanel::BASE_COLOR.r, BASE_COLOR.g, BASE_COLOR.b, (*diffPtr).grid[i][j] * 255));

            this->gridCells[i].push_back(rectangle);
        }
    }
}

SimulationPanel::~SimulationPanel() {

}

void SimulationPanel::update() {
    for (size_t i = 0; i < (*diffPtr).SIZE; i++) {
        for (size_t j = 0; j < (*diffPtr).SIZE; j++) {
            this->gridCells[i][j].setFillColor(sf::Color(SimulationPanel::BASE_COLOR.r, BASE_COLOR.g, BASE_COLOR.b, (*diffPtr).grid[i][j] * 255));
        }
    }
}

void SimulationPanel::render(sf::RenderWindow& window) {
    for (size_t i = 0; i < (*diffPtr).SIZE; i++) {
        for (size_t j = 0; j < (*diffPtr).SIZE; j++) {
            window.draw(this->gridCells[i][j]);
        }
    }
}
