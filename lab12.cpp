#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX // Infinity

// Structure to represent a vertex and its distance from the source
struct Vertex {
    int index;
    int distance;

    Vertex(int i, int d) : index(i), distance(d) {}
};

// Comparison operator for the priority queue (min-heap)
struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance;
    }
};

// Dijkstra's algorithm for finding shortest paths
void dijkstraShortestPaths(std::vector<std::vector<int>>& graph, int source) {
    int V = graph.size(); // Number of vertices
    std::vector<int> distances(V, INF); // Array to store the shortest distance values
    std::vector<bool> visited(V, false); // Array to track visited vertices

    distances[source] = 0; // Distance from source to itself is 0

    // Priority queue (min-heap) to store vertices with their distances
    std::priority_queue<Vertex, std::vector<Vertex>, CompareVertex> pq;
    pq.push(Vertex(source, 0));

    while (!pq.empty()) {
        int u = pq.top().index;
        pq.pop();

        // Skip if the vertex has already been visited
        if (visited[u])
            continue;

        visited[u] = true;

        // Iterate through all adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // Update the distance if there is a shorter path
            if (!visited[v] && graph[u][v] != INF &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                pq.push(Vertex(v, distances[v]));
            }
        }
    }

    // Print the shortest distance values
    int total=0;
    std::cout << "Shortest time from the Source:\n";
    
    for (int v = 0; v < V; v++) {
        total+=distances[v];
        std::cout << "City " << v << ": " << distances[v] << "\n";
    }
    float average= total/5.0;
    //std::cout<< "Average  "<<average<< "\n";
    
}

int main() {
    // Example graph represented by the adjacency matrix
    std::vector<std::vector<int>> graph = {
        {0, 10,INF, INF,15,5},
        {10, 0,10, 30, INF, INF},
        {INF,10, 0, 12, 5, INF},
        {INF, 30, 12, 0, INF, 20},
        {15, INF, 5, INF, 0, INF},
        {5, INF, INF, 20, INF, 0}
    };

    int source;
    std::cout << "Enter the source city: ";
    std::cin >> source;

    dijkstraShortestPaths(graph, source);

    return 0;
}
