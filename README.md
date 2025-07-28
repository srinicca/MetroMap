# MetroMap
Metro Route Finder
A C++ console application that finds the shortest path between metro stations using Dijkstra's algorithm. This program models a metro network as a weighted graph where stations are vertices and connections between stations are edges with weights representing distances or travel time.
Features

Graph-based Metro Network: Represents metro stations and their connections using an adjacency list
Shortest Path Finding: Implements Dijkstra's algorithm to find the optimal route between any two stations
Interactive Interface: User-friendly console interface for entering source and destination stations
Input Validation: Checks if entered station names exist in the network
Distance Calculation: Displays both the route and total distance/time for the journey

Prerequisites

C++ compiler supporting C++17 or later (for structured bindings)
Standard Template Library (STL) support

Compilation
bashg++ -std=c++17 -o metro_finder metro_finder.cpp
Or with additional optimization:
bashg++ -std=c++17 -O2 -o metro_finder metro_finder.cpp
Usage

Run the program:
bash./metro_finder

View the metro network: The program will display all stations and their connections
Enter your journey details:

Starting station (full name)
Destination station (full name)


Get your route: The program will display the shortest path and total distance

Current Metro Network
The application includes the following stations and connections:

Noida Sector 62 ↔ Botanical Garden (8 units)
Botanical Garden ↔ Yamuna Bank (10 units)
Yamuna Bank ↔ Rajiv Chowk (6 units)
Yamuna Bank ↔ Vaishali (8 units)
Rajiv Chowk ↔ Moti Nagar (9 units)

Example Usage
Graph Representation (Adjacency List):
Noida Sector 62 -> Botanical Garden (8), 
Botanical Garden -> Noida Sector 62 (8), Yamuna Bank (10), 
Yamuna Bank -> Botanical Garden (10), Rajiv Chowk (6), Vaishali (8), 
Rajiv Chowk -> Yamuna Bank (6), Moti Nagar (9), 
Vaishali -> Yamuna Bank (8), 
Moti Nagar -> Rajiv Chowk (9), 

Enter the starting station: Noida Sector 62
Enter the destination station: Moti Nagar

Shortest path from Noida Sector 62 to Moti Nagar: Noida Sector 62 Botanical Garden Yamuna Bank Rajiv Chowk Moti Nagar 
Distance: 33
Code Structure
Classes

Graph: Main class that handles the metro network

addVertex(): Adds a new station to the network
addEdge(): Creates bidirectional connections between stations
dijkstra(): Implements the shortest path algorithm
findShortestPath(): User-friendly wrapper for path finding
displayGraph(): Shows the current network structure
stationExists(): Validates station names



Algorithm
The program uses Dijkstra's algorithm with the following characteristics:

Time Complexity: O((V + E) log V) where V is vertices and E is edges
Space Complexity: O(V)
Optimal: Guarantees the shortest path in weighted graphs with non-negative weights

Customization
Adding New Stations
To add new stations to the network, modify the main() function:
cpp// Add new vertex
metroMap.addVertex("New Station Name");

// Add connections
metroMap.addEdge("New Station Name", "Existing Station", weight);
Modifying Weights
Change the weight values in the addEdge() calls to reflect:

Distance in kilometers
Travel time in minutes
Cost of travel
Any other metric you want to optimize

Limitations

Currently supports a predefined set of metro stations
Assumes undirected graph (bidirectional travel)
All edge weights must be non-negative
Station names are case-sensitive and must match exactly
