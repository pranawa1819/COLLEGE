#include <iostream>
using namespace std;
#include <limits.h>

#define V 9
int count=0;

int minDistance(int dist[], bool sptSet[])
{


    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
        {
        min = dist[v], min_index = v;
        count = count+4;    
        }
    count = count+4;            

    return min_index;
}


void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}


void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 

    bool sptSet[V]; 
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;    
        dist[src] = 0;
        count = count +3;
    
    for (int i = 0; i < V - 1; i++) {
    
        int u = minDistance(dist, sptSet);    
        sptSet[u] = true;
        count++;
    
        for (int v = 0; v < V; v++)        
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                {
                dist[v] = dist[u] + graph[u][v];
                count = count+6;    
                }
        count = count +5;        
    }


    printSolution(dist);
}


int main()
{


    int graph[V][V] = { { 0, 9, 0, 0, 0, 10, 5, 0, 0 },
                        { 9, 0, 12, 0, 0, 0, 6, 0, 0 },
                        { 0, 12, 0, 2, 0, 0, 0, 0, 5 },
                        { 0, 0, 2, 0, 1, 0, 0, 0, 1 },
                        { 0, 0, 0, 1, 0, 7, 0, 3, 0 },
                        { 10, 0, 0, 0, 7, 0, 0, 1, 0 },
                        { 5, 6, 0, 0, 0, 0, 0, 2, 5 },
                        { 0, 0, 0, 0, 3, 1, 2, 0, 4 },
                        { 0, 0, 5, 1, 0, 0, 5, 4, 0 } };


    dijkstra(graph, 0);
cout<<"No. of steps required :"<<count;
    return 0;
}