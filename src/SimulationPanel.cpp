#include "SimulationPanel.hpp"


SimulationPanel::SimulationPanel() {

}

SimulationPanel::~SimulationPanel() {

}

void SimulationPanel::render(sf::RenderWindow& window, Diffusion& diff) {
    // TODO: This should not be reinitialized
    std::vector<sf::RectangleShape> shapes{};

    for (size_t i = 0; i < diff.SIZE; i++) {
        for (size_t j = 0; j < diff.SIZE; j++) {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(this->WIDTH / diff.SIZE, this->HEIGHT / diff.SIZE));
            rectangle.setPosition(this->LEFT_OFFSET + j * (float)this->WIDTH / diff.SIZE, i * (float)this->HEIGHT / diff.SIZE);
            rectangle.setFillColor(sf::Color(SimulationPanel::BASE_COLOR.r, BASE_COLOR.g, BASE_COLOR.b, diff.grid[i][j] * 255));

            shapes.push_back(rectangle);
        }
    }

    for (sf::RectangleShape rectangle : shapes) {
        window.draw(rectangle);
    }

    return;
}
