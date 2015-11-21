# cg-micromachines
3D version of the first Micro Machines game for the Computer Graphics course.

# Authors
* Bruno Henriques
* Luís Silva
* Sofia Reis

# Compiling and running on Linux
## Compiling
* Make sure you have g++, make, OpenGL, GLU and GLUT installed.
On Ubuntu (and variants), this command should install all of them:
 ```shell
 sudo apt-get install g++ make freeglut3-dev
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
