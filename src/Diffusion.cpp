#include "Diffusion.hpp"

Diffusion::Diffusion() {
    this->grid = std::vector<std::vector<float>>(Diffusion::SIZE, std::vector<float>(Diffusion::SIZE, 0.0f));
    this->nsteps = 0;
    this->converged = false;
}

Diffusion::~Diffusion() {
}

void Diffusion::step() {
    float max_change = 0.0f;
    for (int i = 0; i < Diffusion::SIZE; i++) {
        for (int j = 0; j < Diffusion::SIZE; j++) {
            // if (std::sqrt(std::pow(i - Diffusion::SIZE / 2, 2) + std::pow(j - Diffusion::SIZE / 2, 2)) <= 5) {
            if (i == 0) {
                // Source
                this->grid[i][j] = 1.0f;
            }
            else if (i == Diffusion::SIZE - 1) {
                // Sink
                this->grid[i][j] = 0.0f;
            }
            else {
                const float left = j > 0 ? this->grid[i][j - 1] : this->grid[i][Diffusion::SIZE - 1];;
                const float right = j < Diffusion::SIZE - 1 ? this->grid[i][j + 1] : this->grid[i][0];
                const float top = i > 0 ? this->grid[i - 1][j] : this->grid[Diffusion::SIZE - 1][j];
                const float bottom = i < Diffusion::SIZE - 1 ? this->grid[i + 1][j] : this->grid[0][j];

                float newval = Diffusion::OMEGA / 4 * (left + right + top + bottom) + (1 - Diffusion::OMEGA) * this->grid[i][j];
                max_change = std::max(std::abs(newval - this->grid[i][j]), max_change);

                this->grid[i][j] = newval;
            }
        }
    }

    this->nsteps++;

    if (max_change < Diffusion::EPSILON) {
        this->converged = true;
    }
}
