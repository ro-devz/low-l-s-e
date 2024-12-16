//============================================================================
// Name        : SpaceObject.hpp
// Author      : Romane Devezeaux de Lavergne
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================

#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP

#include <string>
using namespace std;

class SpaceObject
{
protected:
    string name;  // A name
    string color; // A color
    float x, y;   // A position (in m, for the center of mass, in the coordinates system)
    float vx, vy; // A velocity (in m/s)
    float ax, ay; // An acceleration (in m/s²)
    float mass;   // A mass (in kg)
    float radius; // A radius (in m)

public:
    SpaceObject(const string &name, float x, float y, float vx, float vy, float mass, const string &color)
        : name(name), color(color), x(x), y(y), vx(vx), vy(vy), ax(0), ay(0), mass(mass), radius(0) {}

    virtual ~SpaceObject() = default;

    const string &getName() const { return name; }
    float getX() const { return x; }
    float getY() const { return y; }

    virtual void update(float timeStep)
    {
        // Update velocity
        vx += ax * timeStep;
        vy += ay * timeStep;

        // Update position based on velocity
        x += vx * timeStep;
        y += vy * timeStep;

        // Reset acceleration for the next iteration
        ax = 0;
        ay = 0;
    }

    virtual void render() const = 0;  // Pure virtual method to render the object
    
};

#endif
