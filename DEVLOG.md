# Engineering Logs

This is the raw, unfiltered journal of my learning process. It documents the entire journey: the struggle with Lagrangian Mechanics, the "Euler Trap", the shift to C++, and the deep dive into Chaos Theory.

<details>
<summary><strong>Click to expand the full Engineering Journal</strong></summary>
<br>

**December 30, 2025**
I attempted to derive the equation of motion for a double pendulum from scratch using the Lagrangian equation, which led me to realize that I don't truly understand the Lagrangian equation. I followed that with 2 hours of studying the principle of least action and partial derivatives, with some academic explanations and some more intuitive explanations. I had many insights about the nature of vectors, partial derivatives, and gradients, which led me to be able to understand and visualize the Lagrangian equation at its core. I felt the need to explain and spread that knowledge, however incomplete it is.

I think the ability to switch between different rational systems that explain reality is interesting, like switching between the Newtonian and the Lagrangian explanations of physical reality. In my opinion, one system of rationality is unable to explain all of reality; the ability to understand multiple systems and switch between them depending on context is an important skill to develop. This skill is referred to as **meta-rationality**.

*Resource list:*
1. [Partial Derivatives and the Gradient of a Function](https://youtu.be/AXH9Xm6Rbfc?si=M5t-O4jDYDuMLnxY)
2. [Difference Between Partial and Total Derivative](https://youtu.be/Kp7sSp5Kn7o?si=pnt7O4HLW9mGwy_l)
3. [Gradients and Partial Derivatives](https://youtu.be/GkB4vW16QHI?si=onOwmBqSkhLtRnaQ)
4. [Chapter 6 - The Lagrangian Method (PDF)](https://www.ipcms.fr/uploads/2021/06/chap6.pdf)
5. [The Principle of Least Action (Feynman Lectures)](https://www.feynmanlectures.caltech.edu/II_19.html)

---

**January 4, 2026**
My mathematical objective extends beyond merely understanding the Euler-Lagrange Equation and applying it to a double pendulum. Instead, I intend to utilize Real Analysis to grasp the underlying principles fully. To derive the Euler-Lagrange Equation from scratch, I have identified four foundational pillars I must prove:

1. **The Gâteaux Derivative:** This answers the fundamental question: "What does it mean to differentiate a function with respect to another function?" Mastering this concept allows for the proof of the formal definition of the First Variation, a cornerstone of Variational Calculus.
2. **Multivariable Chain Rule:** A rigorous proof of this essential calculus operation.
3. **Integration by Parts:** A formal proof of this integration technique.
4. **The Fundamental Lemma of Calculus of Variations (FLCV):** This serves as the critical bridge connecting integral equations to differential equations.

By synthesizing these proofs with an intuitive understanding of the Principle of Least Action, I can derive the Euler-Lagrange Equation independently before proceeding with the rest of the project.

My goal is to understand the mathematical axioms driving the physics, but I lack the necessary foundation and prerequisites. However, I do not intend to learn Real Analysis in its entirety. Instead, I will adopt a targeted approach, learning only the specific theoretical concepts required to execute the tasks above.

This methodology represents a "sweet spot" between two disciplines:
* **Pure Mathematics:** Which often focuses heavily on proofs and principles, sometimes neglecting real-world application.
* **Engineering:** Which typically focuses only on what is necessary to achieve functionality.

I aim to implement a model of **Project-Based Learning** that digs deep into the low-level foundations of every project. This ensures I gain the best of both worlds: the rigorous depth of a mathematician and the practical execution of an engineer.

---

**January 23, 2026**
Regarding the double pendulum, I have finished the derivation of the equation of motion for the double pendulum. I studied the basics of real analysis to help me understand what I was solving through a deeper lens, but I did not use proofs for all that I wanted to prove, but merely the basics. The aim is to get back to them after finishing the simulation so I am able to see how they play out practically.

I think this is a better approach, as this mimics the history of how we discovered and used calculus. The tool was first invented and used then it was sharpened through purely analytical proof-based means.

I also decided to skip the python simulation and do it in C++ immediately. Another idea that popped up was building a physics informed neural network to balance the double pendulum after it is finished, as it is a chaotic system defined by its high sensitivity to initial conditions. 

These changes reflect the nature of the map and the territory. It is rare for a map and a blueprint to remain ideal and the same as one navigates from the realm of abstraction to the realm of practicality. I was lucky enough to be lectured last week by a robotics professor who I remember said focused a lot on something similar:

> Academics are usually very skilled in the realm of theory, abstraction, and "the map". Engineers or technicians are usually very skilled in the application, practicalities, and "the territory". I aim to have one foot in the realm of academics and the other in the realm of technicians.

In the meantime, I have been delving into control theory in my free time, using Steve Brunton's Control Bootcamp series.

*What I have learned so far:*
* The real analysis proof of limits and functions
* The intuition behind epsilon-delta definitions and what they mean
* Gradients and partial derivatives (in more depth)
* Functionals and variational calculus
* The principle of least action 
* Finding the Lagrangian and equations of motion for systems considered simple (such as the double pendulum)
* Centrifugal forces
* Revisited Cramer's rule for dealing with matrices

---

**January 25, 2026**

A lot of progress was made. I had trouble understanding the difference between mathematical and physical acceleration, my mind did not log the difference between them as I was viewing it only from the mathematical lens.

### Acceleration in Physics Is Different From Acceleration in Mathematics
Acceleration as we know it from school, which is usually the mathematical version is the second derivative of position. You would be given position or velocity as functions of time, and you just derive them to get acceleration. The problem that arises with this is that you can't exactly calculate the future of acceleration, its only like taking change in velocity curve, which is a trajectory that has already passed. 

In physics, especially in simulations, we need another way to look at acceleration, so we take it as a functional of displacement and velocity (sometimes time too), where `a = f(x,v,t)`. In this case, you don't really need the full trajectory, you only need the current displacement and velocity to calculate acceleration. I faced problems in my simulation trying to use the mathematical definition of acceleration so it lead me to refine my understanding which came with some difficulties.

### Letting Go of Assumptions and Old Beliefs is Necessary for Learning
I was struggling to grasp this other way of looking at acceleration not because it is hard but it goes against a lot of what we are usually taught in school. The moment I was able to let go of my old way of looking at it for a micro-second, this new way finally made sense. I can't help but think about scientists who strongly took classical and Newtonian mechanics for granted. It must have taken a lot of mental re-calibration to adjust to this new paradigm. What's truly fascinating to me is the minds that were able to first identify and log these new paradigms. I aim to solidify this approach in my own learning.

### Runge-Kutta is A Mathematical Method of Double-Checking Your Parameters
When simulations first started, they were attempted using Euler's method, which I am not well versed in, but from what I understood, it uses the slope at the start of each time step or interval to predict values like displacement, velocity, and acceleration. This is accurate for many predictive and linear systems, but when used in chaotic systems like in the double pendulum, the slope changes heavily during a single time step, leading to significant inaccuracies. Runge-Kutta is a method of numerical analysis that measures the change in slope multiple times per time step and finds the average change in slope, which makes it much more accurate. Runge-Kutta is flexible in terms of number of measurements per time rate, you can do it as many times as you like, but that comes with cost and diminishing returns, RK4 (4 calculations per time step) is the standard and usually optimal for most systems.

### RK4 Works With the System’s EOM for Maximum Accuracy
I am currently using RK4 with the double pendulum's equation of motion, which is in matrix form. Here is the logic:
1. Define my constants
2. Use the equation of motion to calculate acceleration at each tiny time step for each arm
3. Use RK4 to update the velocity and displacement back again
4. Take another time step
5. Re-calculate acceleration using the new velocity and displacement
6. Repeat to infinity

---

**January 26, 2026**

### Singular Value Decomposition (SVD)
It is used for data reduction of high resolution images or videos, it is like the Fourier transform for data. It is very similiar to Fourier’s transform but tailored to this problem or field. SVD is the basis for understanding correlations or features of images, even in things like facial recognition. Recommendation systems. Etc.

To use the SVD, we first take any data, such as an image and we create a big matrix where we would put each image as a vector until I cover all my images. This is known as the data matrix and it is the basis for so many modern data-based technologies.

So we will decompose the data matrix into $U \times \Sigma \times V^T$.
* **U and V** matrices are unitary matrices 
* **Sigma** is a diagonal matrix

U would have the same shape and dimensions of the original data matrix, and it is hierarchically arranged, so the first column would be more important than the second column in describing the variance between the columns of the data matrix.

I mentioned it is unitary, what does unitary mean? to visualize this correctly, you have to remember to think of matrices as geometry. Any matrix can be mapped out to coordinates. Now a unitary matrix has two characteristics:
1. Each column/vector has a total length of 1
2. Each column/vector has a 90 degrees angle to every other vector

How is this possible? because we are talking about possibly 10,000+ dimensions for each image, so the range of possibility explodes exponentially. 

Now I mentioned that U is also hierarchical, how is that possible? 
That’s why we have the sigma matrix, it can be used to give importance to each column of U, it is a diagonal matrix so each column in U is multiplied by a specific “scalar” which magnifies its importance.

Finally, we have V. V is used to make combinations of U in order to find specific images from the original data matrix images. It can’t make new images yet, unless we make some sort of deep learning which is outside the scope of this writing right now. V is transpose because it has to take the data matrix as rows in order to find relationship between them.

---

**January 28, 2026**

### Matrix Approximation (Eckhardt–Young Theorem)
So we talked about how matrices are often broken down into 3 composing matrices, these matrices add up to the original images. Now SVD is used in many modern technologies like noise reduction, data compression, eigenfaces, dimensionality reduction, and recommendation systems (not necessarily images, but whenever you have data that you need to break down into correlations). 

Speaking from a computing standpoint, our full data matrix may be composed of thousands of columns so it isn’t exactly computationally effective to use all of that. Just like it isn’t computationally effective to store all integers as doubles in a normal code when it is not needed. 

Eckhardt–Young Theorem basically states that we could use matrix approximation through using only the first R values of our matrices to get the best possible representation. You may recall that the $\Sigma$ (Sigma) matrix is used to arrange the others in terms of importance or contribution to the original data matrix. At some point values of $\Sigma$ will start giving diminishing returns and maybe even noise which causes distortions. Therefore we take a specific R number of values from all the matrices to get the best possible approximation. The number R is calculated either through trial and error or through specific mathematical methods which I won’t delve into.

### Correlation Matrix
We have our data matrix $X$. Now if we multiply our data matrix with its transpose, we get basically how similar every item is to every other item (pairwise dot product). If the data matrix was originally face images, this new matrix would be values that show the correlation or similarity between each possible face combination. This number would map out directly to the $\Sigma^2$ value as the result of this vector multiplication would be $U\Sigma^2$ or $V\Sigma^2$ (depending on matrix multiplication order).

There are many mathematical complications that are hard to note via text. The important intuition is that you can multiply the data matrix by its transpose to get.

*Note: multiplying $X^T X$ is very different from multiplying $X X^T$. The former gives you correlations between columns, usually between images. The latter gives correlation between rows, common in finding correlations between features or pixels.*

</details>