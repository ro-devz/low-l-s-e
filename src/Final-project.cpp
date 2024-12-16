//============================================================================
// Name        : Final-project.cpp
// Author      : Romane Devezeaux de Lavergne
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include "ArtificialObject.hpp"
#include "StellarObject.hpp"

using namespace std;

int main()
{
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

    // Time step for simulation (e.g., 1 second)
    float timeStep = 1.0;

    // Simple simulation loop
    for (int i = 0; i < 10; ++i)
    { // Simulate 10 steps
        cout << "Simulation step " << i + 1 << ":\n";

        // Update all objects
        for (auto *obj : objects)
        {
            obj->update(timeStep);
            obj->render(); // For now, we're just printing the object's state
        }

        cout << endl;
    }

    return 0;
}
