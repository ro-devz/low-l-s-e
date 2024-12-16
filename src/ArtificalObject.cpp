//============================================================================
// Name        : ArtificialObject.cpp
// Author      : Romane Devezeaux de Lavergne
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================


#include "ArtificialObject.hpp"
#include <iostream>
#include <string>

using namespace std;

// Constructor implementation
ArtificialObject::ArtificialObject(const string &name, float x, float y, float vx, float vy, float mass, const string &color, float width, float height, float thrustCapacity)
    : SpaceObject(name, x, y, vx, vy, mass, color), width(width), height(height), thrustCapacity(thrustCapacity) {}

// Update position and velocity based on the time step and any forces (e.g., thrust)
// void ArtificialObject::update(float timeStep) {
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
void ArtificialObject::render() const {
    // Placeholder rendering logic (for SFML or similar graphics libraries)
    cout << "Rendering Artificial Object: " << name << " at (" << x << ", " << y << ")" << endl;
    // If using SFML, you might do something like:
    // sf::RectangleShape shape(sf::Vector2f(width, height));
    // shape.setPosition(x, y);
    // shape.setFillColor(sf::Color::Red); // Use the 'color' string or convert to sf::Color
    // window.draw(shape);
}
