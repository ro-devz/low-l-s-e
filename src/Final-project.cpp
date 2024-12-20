//============================================================================
// Name        : Final-project.cpp
// Author      : Romane Devezeaux de Lavergne
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "ArtificialObject.hpp"
#include "StellarObject.hpp"


using namespace std;

int main()
{
	// Simulation parameters
    float scale = 1e-9f;  // Pixels per meter
    sf::Vector2f center(0, 0);
    float timeStep = 3600.0f; // One hour per step
    float timeFactor = 1.0f;

	StellarObject sun("Sun", 0, 0, 0, 0, 1.989e30, "Yellow", 696340.0e3); // 696,340 km in meters

    // Create Planets (StellarObjects)
    StellarObject mercury("Mercury", 57.91e9, 0, 0, 47.87e3, 3.3011e23, "Gray", 2439.7e3);     // 2,439.7 km in meters
    StellarObject venus("Venus", 108.2e9, 0, 0, 35.02e3, 4.8675e24, "Yellow", 6051.8e3);       // 6,051.8 km in meters
    StellarObject earth("Earth", 149.6e9, 0, 0, 29.78e3, 5.972e24, "Blue", 6371.0e3);          // 6,371 km in meters
    StellarObject mars("Mars", 227.9e9, 0, 0, 24.077e3, 6.4171e23, "Red", 3396.2e3);           // 3,396.2 km in meters
    StellarObject jupiter("Jupiter", 778.5e9, 0, 0, 13.07e3, 1.898e27, "Orange", 69911.0e3);   // 69,911 km in meters
    StellarObject saturn("Saturn", 1.429e12, 0, 0, 9.69e3, 5.683e26, "Golden", 58232.0e3);     // 58,232 km in meters
    StellarObject uranus("Uranus", 2.871e12, 0, 0, 6.81e3, 8.681e25, "Light Blue", 25362.0e3); // 25,362 km in meters
    StellarObject neptune("Neptune", 4.495e12, 0, 0, 5.43e3, 1.024e26, "Blue", 24622.0e3);     // 24,622 km in meters

    // Create some Artificial Objects (e.g., satellites or probes)
    ArtificialObject satellite("Satellite", 7e6, 0, 0, 1500, 500, "Grey", 10, 10, 100); // Example satellite

    // Create Moons (for planets like Earth, Jupiter)
    StellarObject luna("Luna", 0.3844e9, 0, 0, 1.6e3, 7.34767309e22, "Gray", 1737.4e3); // Luna: distance = 384,400 km, radius = 1,737.4 km
    StellarObject io("Io", 0.422e9, 0, 0, 1.8e3, 8.9319e22, "Yellow", 1821.6e3);        // Io: radius = 1,821.6 km
    StellarObject europa("Europa", 0.671e9, 0, 0, 1.0e3, 4.7998e22, "White", 1560.8e3); // Europa: radius = 1,560.8 km

    // Put all objects into a vector for easy iteration
    vector<SpaceObject *> objects = {&sun, &mercury, &venus, &earth, &mars, &jupiter, &saturn, &uranus, &neptune, &satellite, &luna, &io, &europa};


    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Star System Simulation");
    window.setFramerateLimit(60);



    vector<SpaceObject*> objects = {&sun, &mercury, &venus, &earth /* ... add other objects */};
    SpaceObject* selectedObject = nullptr;

    // Font for text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) { // Make sure you have this font file
        cout << "Error loading font" << endl;
        return -1;
    }

    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Zoom with mouse wheel
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0)
                    scale *= 1.1f;
                else
                    scale /= 1.1f;
            }

            // Pan with middle mouse button
            if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
                center.x -= event.mouseMove.x * (1.0f / scale);
                center.y -= event.mouseMove.y * (1.0f / scale);
            }

            // Object selection with left click
            if (event.type == sf::Event::MouseButtonPressed && 
                event.mouseButton.button == sf::Mouse::Left) {
                // Deselect previous object
                if (selectedObject) {
                    selectedObject->setSelected(false);
                    selectedObject = nullptr;
                }
                
                // Convert mouse position to world coordinates and check each object
                sf::Vector2f mousePos = window.mapPixelToCoords(
                    sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                
                for (auto* obj : objects) {
                    // Simple distance check for selection
                    sf::Vector2f objPos = obj->worldToScreen(scale, center, window.getSize());
                    float dx = mousePos.x - objPos.x;
                    float dy = mousePos.y - objPos.y;
                    if (sqrt(dx*dx + dy*dy) < 10.0f) { // 10 pixel selection radius
                        selectedObject = obj;
                        obj->setSelected(true);
                        break;
                    }
                }
            }

            // Adjust time factor with + and - keys
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Add)
                    timeFactor *= 2.0f;
                else if (event.key.code == sf::Keyboard::Subtract)
                    timeFactor /= 2.0f;
            }
        }

        // Update physics
        for (auto* obj : objects) {
            obj->update(timeStep * timeFactor, objects);
        }

        // Clear window
        window.clear(sf::Color::Black);

        // Render all objects
        for (auto* obj : objects) {
            obj->render(window, scale, center);
        }

        // Draw legend
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::White);
        
        string info = "Time Factor: " + to_string(timeFactor) + "x\n";
        info += "Scale: " + to_string(scale) + " pixels/m\n";
        if (selectedObject) {
            info += "\nSelected: " + selectedObject->getName() + "\n";
            info += "Position: (" + to_string(selectedObject->getX()) + ", " 
                   + to_string(selectedObject->getY()) + ")\n";
        }
        
        text.setString(info);
        text.setPosition(10, 10);
        window.draw(text);

        // Display the frame
        window.display();
    }

    return 0;
}
