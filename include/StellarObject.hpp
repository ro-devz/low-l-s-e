//============================================================================
// Name        : StellarObject.hpp
// Author      : Romane Devezeaux de Lavergne
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================


#ifndef STELLAR_OBJECT_HPP
#define STELLAR_OBJECT_HPP

#include "SpaceObject.hpp"
#include <string>

using namespace std;

class StellarObject : public SpaceObject {
protected:
    float radius;  // Radius of the stellar object
    // A stellar object shall be represented as a circle

public:

    StellarObject(const string &name, float x, float y, float vx, float vy, float mass, const string &color, float radius);  // Use const std::string&
    ~StellarObject() override = default;

    void render() const override;
};

#endif
