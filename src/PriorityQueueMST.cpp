//Nathan Shorez
//11/24/2023

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class PriorityQueue
{
public:
    PriorityQueue(int numVertices) :key(numVertices, std::numeric_limits<int>::max()), parent(numVertices, -1), visited(numVertices, false) {}

    ~PriorityQueue() {}
    void insert(int vertex, int cost)
    {
        key[vertex] = cost;
    }

    std::pair<int, int> extractMin()
    {
        int minIndex = -1;
        for (int i = 0; i < key.size(); ++i)
        {
            if (!visited[i] && (minIndex == -1 || key[i] < key[minIndex]))
            {
                minIndex = i;
            }
        }
        visited[minIndex] = true;
        return std::make_pair(minIndex, key[minIndex]);
    }

    bool isEmpty() const
    {
        return std::all_of(visited.begin(), visited.end(), [](bool v) {return v; });
    }

    std::vector<int> parent;

private:
    std::vector<int> key;
    std::vector<bool> visited;

    friend void primMST(int graph[][8], int numVertices, PriorityQueue& pq, std::vector<std::pair<int, int>>& mstEdges);
};

void primMST(int graph[][8], int numVertices, PriorityQueue& pq, std::vector<std::pair<int, int>>& mstEdges)
{
    int startVertex = 0;
    pq.insert(startVertex, 0);

    while (!pq.isEmpty())
    {
        auto minVertex = pq.extractMin();
        int u = minVertex.first;
        int uCost = minVertex.second;
        //Stores cost from the minimum

        for (int v = 0; v < numVertices; ++v)
        {
            if (graph[u][v] && !pq.visited[v] && graph[u][v] < pq.key[v])
            {
                pq.insert(v, graph[u][v]);
                pq.parent[v] = u;
            }
        }

        //Updates key for vertices in proirity queue
        for (int i = 0; i < numVertices; ++i)
        {
            if (!pq.visited[i] && graph[u][i] && graph[u][i] < pq.key[i])
            {
                pq.key[i] = graph[u][i];
            }
        }

        mstEdges.push_back({ u, uCost });
    }
}

int main() {
    int customGraph[8][8] = {
            {0, 2, 0, 6, 0,16, 0, 1},
            {2, 0, 3, 8, 5, 0, 8, 0},
            {0, 3, 0,13, 7, 0,15, 0},
            {6, 8,13, 0, 9,14, 0,11},
            {0, 5, 7, 9, 0, 4, 0, 0},
            {16,0, 0,14, 4, 0,10, 0},
            {0, 8,15, 0, 0,10, 0,12},
            {1, 0, 0,11, 0, 0,12, 0}
    };

    int numVertices = 8;

    PriorityQueue pq(numVertices);
    std::vector<std::pair<int, int>> mstEdges;
    primMST(customGraph, numVertices, pq, mstEdges);

    std::cout << "Prim's MST is Edge -> Cost\n";
    for (const auto& edge : mstEdges)
    {
        if (pq.parent[edge.first] != -1)
        {
            std::cout << pq.parent[edge.first] << " - " << edge.first << " -> " << edge.second << "\n";
        }
    }

    return 0;
}


