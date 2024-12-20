//============================================================================
// Name        : SpaceObject.hpp
// Author      : Romane Devezeaux de Lavergne
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================

#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace std;

class SpaceObject
{
protected:
    static constexpr float G = 6.67430e-11f; // Gravitational constant
    string name;  // A name
    string color; // A color
    float x, y;   // A position (in m, for the center of mass, in the coordinates system)
    float vx, vy; // A velocity (in m/s) VITESSE
    float ax, ay; // An acceleration (in m/s²)
    float mass;   // A mass (in kg)
    float radius; // A radius (in m)
    bool selected;

    // Helper function to convert world coordinates to screen coordinates
    sf::Vector2f worldToScreen(float scale, const sf::Vector2f& windowCenter, const sf::Vector2u& windowSize) const {
        return sf::Vector2f(
            (x * scale) + windowSize.x / 2.0f - windowCenter.x,
            (y * scale) + windowSize.y / 2.0f - windowCenter.y
        );
    }

public:
    SpaceObject(const string &name, float x, float y, float vx, float vy, float mass, const string &color)
        : name(name), color(color), x(x), y(y), vx(vx), vy(vy), ax(0), ay(0), mass(mass), radius(0), selected(false) {}

    virtual ~SpaceObject() = default;

    // Getters
    const string &getName() const { return name; }
    float getX() const { return x; }
    float getY() const { return y; }
    float getMass() const { return mass; }
    bool isSelected() const { return selected; }
    void setSelected(bool select) { selected = select; }

    // Calculate gravitational force from another object
    void calculateGravitationalForce(SpaceObject* other) {
        if (other == this) return;

        float dx = other->x - x;
        float dy = other->y - y;
        float distanceSquared = dx * dx + dy * dy;
        float distance = sqrt(distanceSquared);
        
        if (distance < 1.0f) return; // Prevent division by zero

        // Calculate gravitational force: F = G * (m1 * m2) / r^2
        float force = G * (mass * other->mass) / distanceSquared;
        
        // Calculate force components
        float forceX = force * dx / distance;
        float forceY = force * dy / distance;
        
        // F = ma, so a = F/m
        ax += forceX / mass;
        ay += forceY / mass;
    }

    // Update position and velocity based on forces
    virtual void update(float timeStep, vector<SpaceObject*>& objects) {
        // Reset acceleration
        ax = ay = 0;

        // Calculate gravitational forces with all other objects
        for (auto* other : objects) {
            calculateGravitationalForce(other);
        }

        // Update velocity using acceleration
        vx += ax * timeStep;
        vy += ay * timeStep;

        // Update position using velocity
        x += vx * timeStep;
        y += vy * timeStep;
    }

    // Pure virtual render method to be implemented by derived classes
    virtual void render(sf::RenderWindow& window, float scale, const sf::Vector2f& center) const = 0;
};

#endif
