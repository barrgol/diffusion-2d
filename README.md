# 2D Diffusion

A hobby project of mine implementing the process of particles ![diffusing](https://en.wikipedia.org/wiki/Diffusion) in 2-dimensional space using the Gauss-Seidel iteration with successive over-relaxation.

## How to run

To run the project you will need a valid ![CMake](https://cmake.org/) installation (version at least 3.16).

I utilize the ![SFML framework](https://github.com/SFML/SFML) for visualization (no installation needed).

### Automatic build (using IDE, recommended)

If you use an IDE that is configured to CMake projects (like Visual Studio or CLion), simply open this repository (`diffusion-2d` folder) and wait for your IDE to do all the magic.

### Manual build (using terminal)

If you want to build the project from the terminal, do:

```
mkdir build
cd build
cmake ..
cmake --build .
```
