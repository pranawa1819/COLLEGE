#include <iostream>
#include <vector>
#include <limits.h>  // For INT_MAX
using namespace std;

#define V 4  // Number of cities

// Function to calculate the minimum cost of the travelling salesman problem
void tspBacktrack(int graph[][V], vector<bool>& visited, int currPos, int n, int count, int cost, int& minCost) {
    // Base case: if all cities have been visited and we're back to the starting city
    if (count == n && graph[currPos][0] > 0) {
        minCost = min(minCost, cost + graph[currPos][0]);  // Update minimum cost
        return;
    }

    // Try to visit every unvisited city
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i] > 0) {
            // Mark the city as visited
            visited[i] = true;

            // Recur for the next city
            tspBacktrack(graph, visited, i, n, count + 1, cost + graph[currPos][i], minCost);

            // Backtrack: unmark the city as visited
            visited[i] = false;
        }
    }
}

int main() {
    // Create a graph representing the cities and the distances between them
    int graph[V][V] = {
        { 0, 10, 15, 20 },
        { 5, 0, 9, 10 },
        { 6, 13, 0, 12 },
        { 8, 8, 9, 0 }
    };

    // To track visited cities
    vector<bool> visited(V, false);

    // Starting from the first city (index 0)
    visited[0] = true;

    // Initialize minimum cost to a large value
    int minCost = INT_MAX;

    // Call the backtracking function to calculate minimum TSP cost
    tspBacktrack(graph, visited, 0, V, 1, 0, minCost);

    // Print the minimum cost
    cout << "The minimum cost of the travelling salesman tour is: " << minCost << endl;

    return 0;
}
