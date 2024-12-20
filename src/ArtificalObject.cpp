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


void ArtificialObject::render(sf::RenderWindow& window, float scale, const sf::Vector2f& center) const {
    // Create rectangle shape
    sf::RectangleShape shape(sf::Vector2f(width * scale, height * scale));
    
    // Convert position to screen coordinates
    sf::Vector2f screenPos = worldToScreen(scale, center, window.getSize());
    
    // Set position (adjust to center the rectangle)
    shape.setPosition(screenPos.x - (width * scale / 2), screenPos.y - (height * scale / 2));
    
    // Set color
    if (color == "Grey") shape.setFillColor(sf::Color(128, 128, 128));
    else shape.setFillColor(sf::Color::White);

    // Add selection highlight
    if (selected) {
        shape.setOutlineThickness(2.0f);
        shape.setOutlineColor(sf::Color::Green);
    }

    // Draw the shape
    window.draw(shape);
}

void ArtificialObject::applyThrust(double dx, double dy) {
    // Calculate thrust direction
    double magnitude = sqrt(dx*dx + dy*dy);
    if (magnitude > 0) {
        // Apply thrust in the opposite direction of movement (as per requirements)
        double thrust_ax = -(thrustCapacity / mass) * (dx / magnitude);
        double thrust_ay = -(thrustCapacity / mass) * (dy / magnitude);
        
        // Add thrust acceleration to current acceleration
        ax += thrust_ax;
        ay += thrust_ay;
    }
}

