Welcome to the Pokémon Pond Simulator, a virtual ecosystem where fish and plants interact in a lively and dynamic aquatic environment. 
This project brings the ecosystem to life by modeling the behavior and survival of organisms through a 2D grid. 
In this world, fish swim around and consume plants to sustain themselves, while plants grow with water and sunlight, only losing mass when they’re nibbled on by the fish.

Here’s how it works: 
fish gain weight by eating plants, but if they don’t consume enough, they shrink over time. 
If a fish’s weight reaches zero, it dies, mirroring the natural balance of life. 
On the other hand, plants regenerate under favorable conditions, growing back after being partially eaten. 
Every week in the simulation, pairs of organisms are randomly chosen to interact, creating a dynamic and unpredictable ecosystem.

From a technical perspective, I designed this simulator using object-oriented programming principles. 
Every organism, whether it’s a fish or a plant, is built from a shared base class. 
This means I can handle all organisms in a uniform way, while still letting each one behave according to its specific type—thanks to virtual functions. 
By using pointers and dynamic memory, the program is not only efficient but also flexible, making it easy to manage interactions and lifecycle changes as the simulation progresses.

Why did I create this?
I wanted to showcase the power of C++ concepts like inheritance, polymorphism, and dynamic memory allocation in a way that feels both engaging and practical. 
By managing the relationships between fish and plants in this ecosystem, I’ve built a system that’s not just functional but also reflective of real-world scenarios, like simulations, game development, or even artificial intelligence models.

This project is more than just a technical exercise—it’s an exploration of how software can mimic the complexities of life. 
Whether you’re a programmer looking to understand object-oriented design or just someone curious about how virtual ecosystems work, the Pokémon Pond Simulator is a dive into the fascinating intersection of biology and computer science. 
I hope you enjoy exploring it as much as I enjoyed creating it!
