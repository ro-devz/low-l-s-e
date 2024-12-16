//============================================================================
// Name        : StellarObject.cpp
// Author      : Romane Devezeaux de Lavergne
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================


#include "StellarObject.hpp"
#include <iostream>
#include <string>

using namespace std;

// Constructor implementation
StellarObject::StellarObject(const string &name, float x, float y, float vx, float vy, float mass, const string &color, float radius)
    : SpaceObject(name, x, y, vx, vy, mass, color), radius(radius) {}

// Update position and velocity based on the time step (physics-based updates)
// void StellarObject::update(float timeStep) {
//     // Update velocity using acceleration
//     vx += ax * timeStep;
//     vy += ay * timeStep;

//     // Update position using velocity
//     x += vx * timeStep;
//     y += vy * timeStep;

//     // Reset acceleration for the next iteration
//     ax = 0;
//     ay = 0;
// }

// Render method (this will depend on the graphics library used)
void StellarObject::render() const {
    // Placeholder rendering logic (for SFML or similar graphics libraries)
    cout << "Rendering Stellar Object: " << name << " at (" << x << ", " << y << ")" << endl;
    // If using SFML, you might do something like:
    // sf::CircleShape shape(radius);
    // shape.setPosition(x, y);
    // shape.setFillColor(sf::Color::Yellow); // Use the 'color' string or convert to sf::Color
    // window.draw(shape);
}
