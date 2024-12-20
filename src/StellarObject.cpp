//============================================================================
// Name        : StellarObject.cpp
// Author      : Romane Devezeaux de Lavergne
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================

#include "StellarObject.hpp"

StellarObject::StellarObject(const string &name, float x, float y, float vx, float vy,
                           float mass, const string &color, float radius)
    : SpaceObject(name, x, y, vx, vy, mass, color), radius(radius) {}

void StellarObject::render(sf::RenderWindow& window, float scale, const sf::Vector2f& center) const {
    float screenRadius = std::max(2.0f, radius * scale);
    sf::CircleShape shape(screenRadius);
    
    sf::Vector2f screenPos = worldToScreen(scale, center, window.getSize());
    shape.setPosition(screenPos.x - screenRadius, screenPos.y - screenRadius);
    
    if (color == "Yellow") shape.setFillColor(sf::Color::Yellow);
    else if (color == "Blue") shape.setFillColor(sf::Color::Blue);
    else if (color == "Red") shape.setFillColor(sf::Color::Red);
    else if (color == "Gray") shape.setFillColor(sf::Color(128, 128, 128));
    else if (color == "Orange") shape.setFillColor(sf::Color(255, 165, 0));
    else if (color == "Golden") shape.setFillColor(sf::Color(255, 215, 0));
    else if (color == "Light Blue") shape.setFillColor(sf::Color(173, 216, 230));
    else shape.setFillColor(sf::Color::White);

    if (selected) {
        shape.setOutlineThickness(2.0f);
        shape.setOutlineColor(sf::Color::Green);
    }

    window.draw(shape);
}
