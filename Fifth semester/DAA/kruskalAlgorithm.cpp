#include <iostream>
#include <vector>

#define MAX 999

using namespace std;

int parent[MAX];

int find(int);
int uni(int, int);

void kruskal(int n, vector<vector<int>>& cost)
{
    int i, j, k, a, b, u, v;
    int min = MAX;
    int ne = 1;
    int mincost = 0;

    cout << "\nThe edges of Minimum Cost Spanning Tree are\n";
    while (ne < n)
    {
        min = MAX;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min && cost[i][j] != 0)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            cout << ne++ << " edge (" << a + 1 << "," << b + 1 << ") = " << min << endl;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 0;
    }
    cout << "\nMinimum cost = " << mincost << endl;
}

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int i, j, n;
    cout << "Enter the no. of vertices: ";
    cin >> n;
    
    vector<vector<int>> cost(n, vector<int>(n));
    
    cout << "\nEnter the cost adjacency matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    kruskal(n, cost);

    return 0;
}
