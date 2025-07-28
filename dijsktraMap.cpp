#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <algorithm>
using namespace std;

// Class to represent a graph
class Graph {
private:
    unordered_map<string, unordered_map<string, int>> adjList;

public:
    // Add a vertex to the graph
    void addVertex(const string& vertex) {
        adjList[vertex];
    }

    // Add an edge to the graph
    void addEdge(const string& source, const string& destination, int weight) {
        adjList[source][destination] = weight;
        adjList[destination][source] = weight; // Undirected graph
    }

    // Display the graph
    void displayGraph() {
        cout << "\nGraph Representation (Adjacency List):\n";
        for (const auto& vertex : adjList) {
            cout << vertex.first << " -> ";
            for (const auto& neighbor : vertex.second) {
                cout << neighbor.first << " (" << neighbor.second << "), ";
            }
            cout << "\n";
        }
    }

    // Dijkstra's algorithm to find the shortest path
    vector<string> dijkstra(const string& start, const string& end) {
        unordered_map<string, int> distances;
        unordered_map<string, string> previous;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

        // Initialize distances to infinity
        for (const auto& vertex : adjList) {
            distances[vertex.first] = numeric_limits<int>::max();
        }
        distances[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [currentDistance, currentVertex] = pq.top();
            pq.pop();

            if (currentVertex == end) break;

            for (const auto& [neighbor, weight] : adjList[currentVertex]) {
                int newDistance = currentDistance + weight;

                if (newDistance < distances[neighbor]) {
                    distances[neighbor] = newDistance;
                    previous[neighbor] = currentVertex;
                    pq.push({newDistance, neighbor});
                }
            }
        }

        vector<string> path;
        for (string at = end; !at.empty(); at = previous[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        if (path.empty() || path.front() != start) {
            path.clear(); // Clear path if no valid path exists
        }
        return path;
    }

    // Utility to find and print the shortest path and distance
    void findShortestPath(const string& start, const string& end) {
        vector<string> path = dijkstra(start, end);

        if (path.empty()) {
            cout << "No path exists between " << start << " and " << end << ".\n";
        } else {
            int distance = 0;
            for (size_t i = 0; i < path.size() - 1; ++i) {
                distance += adjList[path[i]][path[i + 1]];
            }

            cout << "Shortest path from " << start << " to " << end << ": ";
            for (const string& vertex : path) {
                cout << vertex << " ";
            }
            cout << "\nDistance: " << distance << "\n";
        }
    }

    // Function to check if a station exists in the graph
    bool stationExists(const string& station) const {
        return adjList.find(station) != adjList.end();
    }
};

int main() {
    Graph metroMap;

    // Adding vertices
    metroMap.addVertex("Noida Sector 62");
    metroMap.addVertex("Botanical Garden");
    metroMap.addVertex("Yamuna Bank");
    metroMap.addVertex("Rajiv Chowk");
    metroMap.addVertex("Vaishali");
    metroMap.addVertex("Moti Nagar");

    // Adding edges with weights
    metroMap.addEdge("Noida Sector 62", "Botanical Garden", 8);
    metroMap.addEdge("Botanical Garden", "Yamuna Bank", 10);
    metroMap.addEdge("Yamuna Bank", "Rajiv Chowk", 6);
    metroMap.addEdge("Yamuna Bank", "Vaishali", 8);
    metroMap.addEdge("Rajiv Chowk", "Moti Nagar", 9);

    // Display the graph
    metroMap.displayGraph();

    // Find the shortest path between two stations
    string start, end;
    cout << "\nEnter the starting station: ";
    cin >> ws; // Consume whitespace
    getline(cin, start); // Read full station name

    cout << "Enter the destination station: ";
    cin >> ws;
    getline(cin, end);

    // Validate stations
    if (!metroMap.stationExists(start) || !metroMap.stationExists(end)) {
        cout << "One or both station names are invalid. Please enter valid station names.\n";
        return 1;
    }

    metroMap.findShortestPath(start, end);

    return 0;
}
