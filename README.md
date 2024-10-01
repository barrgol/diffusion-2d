# 2D Diffusion

A hobby project of mine implementing the process of particles [diffusing](https://en.wikipedia.org/wiki/Diffusion) in 2-dimensional space using the Gauss-Seidel method with successive over-relaxation for faster convergence. This is also my first project using SFML and a first-in-a-long time using C++.

Once you compile and run the `.exe` file you'll see a window with the simulation panel on the right and the control panel on the left. Control panel contains a button with which you can start and stop the simulation at any given moment.

https://github.com/user-attachments/assets/e75f0ecc-5107-4bcb-9a2a-9894a816cfbe

The counter in the bottom-left corner tells you how many simulation steps have been made or, in other words, how many times the numerical algorithm iterated over the 2-dimensional grid updating each cell value.

Once the simulation converges - this happens when updates to the cell values are so small we consider them insignificant - this will be reflected on the step counter. After convergence, you will not be able to run the simulation anymore.

The example above contains a very simple layout, with sources (cells where particles enter the grid) attached at the top wall and sinks (cells where particles leave the grid) attached at the bottom wall. This, of course, can be adapted to whatever setup you want. Unfortunately, I haven't yet found a user-friendly way to do it, so you will have to play with the logic in `Diffusion.cpp` file. With some simple math you can create more complex simulations like the one on the bottom.

https://github.com/user-attachments/assets/f10b8b06-8ec8-4baa-b8fa-b478a334600d

## How to run

To run the project you will need a valid [CMake](https://cmake.org/) installation (version at least 3.16).

I utilize the [SFML framework](https://github.com/SFML/SFML) for visualization (no installation needed, CMake should do it for you).

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

## Todo's

- [ ] Add logic for solid objects within simulation space
- [ ] Optimize the execution speed to handle rendering of grids bigger than 200 x 200
- [ ] Create demo files that can be loaded and shown in the simulation window
- [ ] Add a slider for $\omega$ parameter and grid size $N$
- [ ] Find a user-friendly way to edit sources, sinks and objects
