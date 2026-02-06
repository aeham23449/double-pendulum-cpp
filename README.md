# Double Pendulum Simulator (C++ / SFML)

### 📖 [Read the Story: My Scientific Worldview Broke When I Tried to Build This](https://open.substack.com/pub/ayhamnotes/p/my-scientific-worldview-broke-when)
### 🧠 [Read the Engineering Logs](./DEVLOG.md)

![Double Pendulum Demo](demo.gif)

A high-precision physics simulation that visualizes the chaotic motion of a double pendulum using C++ and SFML. 

## The Challenge
Building this wasn't just about writing code; it was about bridging the gap between mathematical theory and physical simulation.
* **Physics:** Solved using Lagrangian Mechanics (Energy states) rather than Newtonian forces.
* **Integration:** Implemented Runge-Kutta 4 (RK4) to solve the Equations of Motion, avoiding the energy drift common in standard Euler integration.
* **Visualization:** Real-time rendering of the phase space trajectory using SFML.

## How to Build
**Prerequisites:** C++ Compiler (g++), SFML Library.

```bash
g++ main.cpp -o pendulum -lsfml-graphics -lsfml-window -lsfml-system
./pendulum