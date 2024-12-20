#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace std;

class SpaceObject {
protected:
    static constexpr float G = 6.67430e-11f; // Gravitational constant
    string name;  // A name
    string color; // A color
    float x, y;   // A position (in m, for the center of mass)
    float vx, vy; // A velocity (in m/s)
    float ax, ay; // An acceleration (in m/s²)
    float mass;   // A mass (in kg)
    bool selected;

    sf::Vector2f worldToScreen(float scale, const sf::Vector2f& windowCenter, const sf::Vector2u& windowSize) const {
        return sf::Vector2f(
            (x * scale) + windowSize.x / 2.0f - windowCenter.x,
            (y * scale) + windowSize.y / 2.0f - windowCenter.y
        );
    }

public:
    SpaceObject(const string &name, float x, float y, float vx, float vy, float mass, const string &color);
    virtual ~SpaceObject() = default;

    // Getters
    const string &getName() const { return name; }
    float getX() const { return x; }
    float getY() const { return y; }
    float getVx() const { return vx; }
    float getVy() const { return vy; }
    float getMass() const { return mass; }
    bool isSelected() const { return selected; }
    
    void setSelected(bool select) { selected = select; }

    virtual void update(double timeStep, const vector<SpaceObject*>& allObjects);
    virtual void render(sf::RenderWindow& window, float scale, const sf::Vector2f& center) const = 0;
    void calculateGravitationalForce(const SpaceObject* other);
};

#endif
