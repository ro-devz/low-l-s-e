#include "SpaceObject.hpp"
#include <cmath>

SpaceObject::SpaceObject(const string &name, float x, float y, float vx, float vy, 
                        float mass, const string &color)
    : name(name), color(color), x(x), y(y), vx(vx), vy(vy), ax(0), ay(0), 
      mass(mass), selected(false) {}

void SpaceObject::calculateGravitationalForce(const SpaceObject* other) {
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

void SpaceObject::update(double timeStep, const vector<SpaceObject*>& allObjects) {
    // Reset acceleration
    ax = ay = 0;

    // Calculate gravitational forces with all other objects
    for (const auto* other : allObjects) {
        calculateGravitationalForce(other);
    }

    // Update velocity using acceleration
    vx += ax * timeStep;
    vy += ay * timeStep;

    // Update position using velocity
    x += vx * timeStep;
    y += vy * timeStep;
}
