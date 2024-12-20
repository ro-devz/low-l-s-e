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

class StellarObject : public SpaceObject {
protected:
    float radius;  // Radius of the stellar object in meters

public:
    StellarObject(const string &name, float x, float y, float vx, float vy, 
                  float mass, const string &color, float radius);
    ~StellarObject() override = default;

    float getRadius() const { return radius; }
    void render(sf::RenderWindow& window, float scale, const sf::Vector2f& center) const override;
};

#endif
