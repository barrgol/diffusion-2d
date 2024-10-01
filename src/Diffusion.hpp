#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

class Diffusion
{
public:
    const int SIZE = 200;
    const float OMEGA = 1.91f;
    const float EPSILON = 1.0e-5;

    std::vector<std::vector<float>> grid;
    int nsteps;
    bool converged;

    Diffusion();
    ~Diffusion();

    void step();

private:

};
