# Double Pendulum Simulator (C++ / SFML)

### [Read the Story: My Scientific Worldview Broke When I Tried to Build This](https://open.substack.com/pub/ayhamnotes/p/my-scientific-worldview-broke-when)
### [Read the Engineering Logs](./DEVLOG.md)


https://github.com/user-attachments/assets/971b710b-4b3b-4e0b-b545-1ea96fc53646


A high-precision physics simulation that visualizes the chaotic motion of a double pendulum using C++ and SFML. 

## The Challenge
I challenged myself that I need to go deeper into understanding how low level systems work. I decided I want to build a project that will upgrade my mathematical and computational understanding of reality, as  a strong base and foundation for future skills. Then a specific university class got me really hooked on Lagrangian mechanics which lead to this rabbit hole. This project aimed at bridging the gap between mathematical theory and physical simulation.
* **Physics:** Solved using Lagrangian Mechanics (Energy states) rather than Newtonian forces.
* **Integration:** Implemented Runge-Kutta 4 (RK4) to solve the Equations of Motion, avoiding the energy drift common in standard Euler integration.
* **Visualization:** Real-time rendering of the phase space trajectory using SFML.

## How to Build
**Prerequisites:** C++ Compiler (g++), SFML Library.

```bash
g++ main.cpp -o pendulum -lsfml-graphics -lsfml-window -lsfml-system
./pendulum
