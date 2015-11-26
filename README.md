# cg-micromachines
3D version of the first Micro Machines game for the Computer Graphics course.

# Authors
* Bruno Henriques
* Luís Silva
* Sofia Reis

# Compiling and running on Linux
## Compiling
* Make sure you have g++, make, OpenGL, GLU,  GLUT and SOIL installed.
On Ubuntu (and variants), this command should install all of them:
 ```shell
 sudo apt-get install g++ make freeglut3-dev libsoil-dev
 ```

* Create a directory named `obj` inside the projet root directory, otherwise you'll get a bunch of errors.

* To compile, just run:
 ```shell
 make
 ```
 This will create an executable named `micromachines`.

## Running
To run Micro Machines, from the project root:
```shell
make run
```
or, if it's already compiled:
```shell
./micromachines
```
## Compiling without SOIL
If you wish, it is possible to compile the project without libSOIL (and no textures).
To do this, simply define `NOSOIL` when compiling.

# Controls
Use the arrow keys to move the car.
## Cameras
* 1 - Ortogonal Top View
* 2 - Perspective Top View
* 3 - Perspective Car View
* 4 - Ortogonal side view

## Game
* S - Pause
* R - Restart

## Lights
* L - Enable Lighting
* N - Toggle Night/Day
* C - Toggle Candle lights
* H - Toggle Car Lights
* G - Toggle Smooth Lighting Model

## Debug
* P - Toggle Car Ghost Mode (no collisions)
* B - Show Collision (AABB) Boxes
* T - Toggle (weird) Teapot
