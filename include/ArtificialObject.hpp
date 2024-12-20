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

class ArtificialObject : public SpaceObject {
protected:
    float width, height;      // Dimensions in meters
    float thrustCapacity;     // Thrust capacity in Newtons

public:
    ArtificialObject(const string &name, float x, float y, float vx, float vy,
                    float mass, const string &color, float width, float height, 
                    float thrustCapacity);
    ~ArtificialObject() override = default;

    float getWidth() const { return width; }
    float getHeight() const { return height; }
    void render(sf::RenderWindow& window, float scale, const sf::Vector2f& center) const override;
    void applyThrust(double dx, double dy);
};

#endif
