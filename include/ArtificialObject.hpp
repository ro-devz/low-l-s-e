//============================================================================
// Name        : ArtificialObject.hpp
// Author      : Romane Devezeaux de Lavergne
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================


#ifndef ARTIFICIAL_OBJECT_HPP
#define ARTIFICIAL_OBJECT_HPP

#include "SpaceObject.hpp"
#include <string>

using namespace std;

class ArtificialObject : public SpaceObject {
protected:
    float width, height;  // in (m)
    float thrustCapacity; // Thrust capacity in N
    // An artificial object shall be represented as a rectangle

public:

    ArtificialObject(const string &name, float x, float y, float vx, float vy, float mass, const string &color, float width, float height, float thrustCapacity);
    ~ArtificialObject() override = default;
    void update(double timeStep, const vector<SpaceObject*>& allObjects) override;

    void render() const override;
    void applyThrust(double dx, double dy);

};

#endif
