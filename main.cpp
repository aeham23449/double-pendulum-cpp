/*
 * Double Pendulum Simulator:
 * A physics simulation using Runge-Kutta 4 (RK4) integration to solve 
 * the equations of motion for a chaotic double pendulum system.
 * Built with C++ and SFML.
 * * Author: Ayham Hamid
 * Date: 2024
 */


#include <iostream>
#include <array>
#include <cmath>
#include <thread> 
#include <chrono>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
using namespace this_thread;

struct States{
    double a1;
    double a2;
    double v1;
    double v2;
};

States CurrentState;



double m1 = 15;
double m2 = 20;
double l1 = 15;
double l2 = 15;
double phi = 1.61803398875;
double pi = 3.14159265359;

array<double, 2> AccelerationCalc(States k){
    double a = k.a1 - k.a2;
    double m11 = (m1+m2) * l1;
    double m12 = m2 * l2  * cos(a);
    double m21 = l1 * cos(a);
    double m22 = l2;
    double g = 9.80665; 
    double f1 = -m2 *l2 * (k.v2*k.v2) * sin(a) - (m1+m2)*g*sin(k.a1); 
    double f2 = l1*(k.v1*k.v1)*sin(a) - g*sin(k.a2); 
    double det = ((m11*m22) - (m12*m21));
    double acc1 = ((f1 * m22) - (f2*m12)) / det; 
    double acc2 = ((f2 * m11) - (f1*m21)) / det; 

    return {acc1, acc2};
}

States derivative(States s){
    array<double, 2> acc = AccelerationCalc(s);

    States slope;

    slope.a1 = s.v1;
    slope.a2 = s.v2;
    slope.v1 = acc[0];
    slope.v2 = acc[1];


    return slope;
}


States step(States s, States k, double dt){
    States temp;
    temp.a1 = s.a1 + (k.a1 * dt);
    temp.a2 = s.a2 + (k.a2 * dt); 
    temp.v1 = s.v1 + (k.v1 * dt); 
    temp.v2 = s.v2 + (k.v2 * dt);  

    return temp;
}

States rk4(States s, double dt){
    States k1 = derivative(s); 

    States temp2 = step(s, k1, dt*0.5);
    States k2 = derivative(temp2);

    States temp3 = step(s, k2, dt*0.5);
    States k3 = derivative(temp3);

    States temp4 = step(s, k3, dt);
    States k4 = derivative(temp4);
    
    States final;

    final.a1 = s.a1 + (dt * ((k1.a1 + (2*k2.a1)+ (2*k3.a1) + k4.a1)/6.0)) ;
    final.a2 = s.a2 + (dt * ((k1.a2 + (2*k2.a2)+ (2*k3.a2) + k4.a2)/6.0)) ;
    final.v1 = s.v1 + (dt * ((k1.v1 + (2*k2.v1)+ (2*k3.v1) + k4.v1)/6.0)) ;
    final.v2 = s.v2 + (dt * ((k1.v2 + (2*k2.v2)+ (2*k3.v2) + k4.v2)/6.0)) ;

    return final;
}

void draw(RenderWindow &window, VertexArray &rods, CircleShape &mass1, CircleShape &mass2){

    window.draw(rods);
    window.draw(mass1);
    window.draw(mass2);


}

int main(){
    cout << "Welcome to the double pendulum simulator" << endl;
    array<string, 4> names = {"Mass 1", "Mass 2", "Length 1", "Length 2"};
    array<double*, 4> inputs = {&m1, &m2, &l1, &l2};
    for (int i = 0; i <= 3; i++){
        cout << "Enter value of " << names[i] << ": ";
        cin >> *inputs[i];
        cout << endl;

    }


    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(800,600), "Double Pendulum Simulator", Style::Default, settings);
    window.setFramerateLimit(60);
    CircleShape mass1(10.f);
    mass1.setFillColor(Color::Green);
    mass1.setOrigin(10.f, 10.f);

    CircleShape mass2(10.f);
    mass2.setFillColor(Color::Red);
    mass2.setOrigin(10.f, 10.f);

    VertexArray rods(Lines, 4);
    for(int i = 0; i < 4; i++){
        rods[i].color = Color::White;
    }


    double dt = 0.002;
    double offsetX = 400;
    double offsetY = 150;
    double targetlength = 250;
    double totallength = l1 + l2;

    double scale = (totallength > 0)? (targetlength/totallength) : 10.0; 

    States Start {phi, phi, 0, 0};
    

    vector<CircleShape> trail;
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
            }
        }

        for (int k = 0; k <= 20; k++){
            Start = rk4(Start, dt);   
        }
        
        float mass1x = offsetX + (l1*scale*sin(Start.a1));
        float mass1y = offsetY + (l1*scale*cos(Start.a1));
        float mass2x = mass1x + (l2*scale*sin(Start.a2));
        float mass2y = mass1y + (l2*scale*cos(Start.a2));

        window.clear(Color::Black);
        CircleShape dot(1.5f);
        dot.setPosition(mass2x, mass2y);
        dot.setFillColor(Color::Cyan);
        trail.push_back(dot);

        if (trail.size() > 400) trail.erase(trail.begin());

        for (auto& dot: trail){
            window.draw(dot);
        }
        mass1.setPosition(mass1x, mass1y);
        mass2.setPosition(mass2x, mass2y);
        
        rods[0].position = Vector2f(offsetX, offsetY);
        rods[1].position = Vector2f(mass1x, mass1y);
        rods[2].position = Vector2f(mass1x, mass1y);
        rods[3].position = Vector2f(mass2x, mass2y);

        draw(window, rods, mass1, mass2);
        window.display();

        array<double, 4> FullState = {Start.a1, Start.a2, Start.v1, Start.v2};


        for (int i = 0; i <= 3; i++){
        cout << FullState[i] << " | ";
        }
        cout << endl;
        
        
    }
        


}
