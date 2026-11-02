#include <stdio.h>

#define MAX 100

// Structure for storing an edge
struct Edge
{
    int u;
    int v;
    int weight;
};

// Find the parent of a vertex
int find(int parent[], int vertex)
{
    while (parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }

    return vertex;
}

// Join two sets
void unionSet(int parent[], int u, int v)
{
    int parentU = find(parent, u);
    int parentV = find(parent, v);

    parent[parentV] = parentU;
}

int main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX];

    // Taking input
    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }

    // -------------------------------
    // STEP 1: Sort edges
    // -------------------------------

    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];

                edges[j] = edges[j + 1];

                edges[j + 1] = temp;
            }
        }
    }

    // -------------------------------
    // STEP 2: Initialize parent
    // -------------------------------

    int parent[MAX];

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    // -------------------------------
    // STEP 3: Select edges
    // -------------------------------

    int edgeCount = 0;
    int totalWeight = 0;

    printf("\nEdges in MST:\n");

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        int parentU = find(parent, u);
        int parentV = find(parent, v);

        // If parents are different,
        // adding this edge will NOT create a cycle
        if (parentU != parentV)
        {
            printf("%d -- %d = %d\n", u, v, weight);

            totalWeight = totalWeight + weight;

            unionSet(parent, u, v);

            edgeCount++;

            // MST needs V-1 edges
            if (edgeCount == V - 1)
            {
                break;
            }
        }    
    }

    printf("Minimum Cost = %d\n", totalWeight);

    return 0;
}