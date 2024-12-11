#include <SFML/Graphics.hpp>
#include <format>
#include <filesystem>
#include <iostream>

#include "configuration.hpp"
#include "arraygrid.hpp"
#include "colors.hpp"

const int WINDOW_WIDTH = 1500;
const int WINDOW_HEIGHT = 1000;

int main()
{
    auto window = sf::RenderWindow{ { conf::WINDOW_SIZE.x, conf::WINDOW_SIZE.y }, "Application" };
    window.setFramerateLimit(conf::MAX_FRAMERATE);

    //ShapeGrid grid{ dim, {0.0f, 0.0f}, conf::WINDOW_SIZE_F, Gradient::GREEN_BLUE };
    ArrayGrid grid{ {conf::SIZE, conf::SIZE}, {0.0f, 0.0f}, conf::WINDOW_SIZE_F, Gradient::CUSTOM(sf::Color::White, sf::Color::Blue, 0, 1) };

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("res/PIXELIFYSANS-VARIABLEFONT_WGHT.ttf"))
    {
        std::cerr << "Error: Could not open 'arialbd.ttf'" << std::endl;
        return EXIT_FAILURE;
    }

    // Text that displays the FPS
    int nframes = 0;
    sf::Text fpsText(std::format("FPS: {}", nframes), font);

    fpsText.setCharacterSize(36);
    fpsText.setColor(sf::Color::Red);
    fpsText.setStyle(sf::Text::Bold);
    fpsText.setPosition(sf::Vector2f{ 20.0f, 20.0f });

    // Create a clock to track FPS
    sf::Clock clock;

    // Check for convergence
    bool converged = false;
    bool on = false;

    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {
                    on = !on;
                }
            }
        }

        if (!converged && on) {
            float max_change = 0.0f;
            for (int i = 0; i < grid.dim.y; i++) {
                for (int j = 0; j < grid.dim.x; j++) {
                    int dist_to_center = std::sqrt(std::pow(i - conf::SIZE / 2, 2) + std::pow(j - conf::SIZE / 2, 2));

                    //if (i == 0) {
                    //    // Source
                    //    grid.values[i][j] = 1.0f;
                    //} else if (i == conf::SIZE - 1) {
                    //    // Sink
                    //    grid.values[i][j] = 0.0f;
                    //} else {
                    //    const float left = j > 0 ? grid.values[i][j - 1] : grid.values[i][conf::SIZE - 1];;
                    //    const float right = j < conf::SIZE - 1 ? grid.values[i][j + 1] : grid.values[i][0];
                    //    const float top = i > 0 ? grid.values[i - 1][j] : grid.values[conf::SIZE - 1][j];
                    //    const float bottom = i < conf::SIZE - 1 ? grid.values[i + 1][j] : grid.values[0][j];

                    //    float newval = conf::OMEGA / 4 * (left + right + top + bottom) + (1 - conf::OMEGA) * grid.values[i][j];
                    //    max_change = std::max(std::abs(newval - grid.values[i][j]), max_change);

                    //    grid.values[i][j] = newval;
                    //}

                    if (i % 10 <= 0 && j % 10 <= 0 && i >= 50 && i <= 150) {
                        // Source
                        grid.values[i][j] = 1.0f;
                    } else if (i == conf::SIZE) {
                        // Sink
                        grid.values[i][j] = 0.0f;
                    } else {
                        const float left = j > 0 ? grid.values[i][j - 1] : grid.values[i][conf::SIZE - 1];;
                        const float right = j < conf::SIZE - 1 ? grid.values[i][j + 1] : grid.values[i][0];
                        const float top = i > 0 ? grid.values[i - 1][j] : grid.values[conf::SIZE - 1][j];
                        const float bottom = i < conf::SIZE - 1 ? grid.values[i + 1][j] : grid.values[0][j];

                        float newval = conf::OMEGA / 4 * (left + right + top + bottom) + (1 - conf::OMEGA) * grid.values[i][j];
                        max_change = std::max(std::abs(newval - grid.values[i][j]), max_change);

                        grid.values[i][j] = newval;
                    }
                }
            }

            if (max_change < conf::EPSILON) {
                converged = true;
                fpsText.setString(std::format("FPS: {}", nframes));
                window.draw(fpsText);
            } else {
                // Check elapsed time
                if (clock.getElapsedTime().asSeconds() >= 1.0) {
                    fpsText.setString(std::format("FPS: {}", nframes));
                    nframes = 0;
                    clock.restart();
                }
            }

            nframes += 1;
        }

        grid.render(window);
        window.draw(fpsText);
        window.display();
    }
}