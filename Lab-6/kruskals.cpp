#include <iostream>

using namespace std;

#define MAX_EDGES 20
#define MAX_VERTICES 10

struct Edge
{
  int u, v, weight;
};

class Graph
{
private:
  int size;
  Edge edges[MAX_EDGES];
  int edgeCount;
  string vertex_data[MAX_VERTICES];

public:
  Graph(int size)
  {
    this->size = size;
    edgeCount = 0;
  }

  void addEdge(int u, int v, int weight)
  {
    if (u >= 0 && u < size && v >= 0 && v < size && edgeCount < MAX_EDGES)
    {
      edges[edgeCount++] = {u, v, weight};
    }
  }

  void addVertexData(int vertex, string data)
  {
    if (vertex >= 0 && vertex < size)
    {
      vertex_data[vertex] = data;
    }
  }

  int find(int parent[], int i)
  {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent, parent[i]);
  }

  void unionSets(int parent[], int rank[], int x, int y)
  {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY)
    {
      if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
      else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
      else
      {
        parent[rootY] = rootX;
        rank[rootX]++;
      }
    }
  }

  void bubbleSort()
  {
    for (int i = 0; i < edgeCount - 1; i++)
    {
      for (int j = 0; j < edgeCount - i - 1; j++)
      {
        if (edges[j].weight > edges[j + 1].weight)
        {
          Edge temp = edges[j];
          edges[j] = edges[j + 1];
          edges[j + 1] = temp;
        }
      }
    }
  }

  void kruskalsAlgorithm()
  {
    Edge result[MAX_VERTICES];
    int parent[MAX_VERTICES], rank[MAX_VERTICES];
    int e = 0, i = 0;

    for (int node = 0; node < size; node++)
    {
      parent[node] = node;
      rank[node] = 0;
    }

    bubbleSort();

    while (e < size - 1 && i < edgeCount)
    {
      Edge nextEdge = edges[i++];
      int x = find(parent, nextEdge.u);
      int y = find(parent, nextEdge.v);

      if (x != y)
      {
        result[e++] = nextEdge;
        unionSets(parent, rank, x, y);
      }
    }

    cout << "Edge \tWeight\n";
    for (int j = 0; j < e; j++)
    {
      cout << vertex_data[result[j].u] << "-" << vertex_data[result[j].v] << " \t" << result[j].weight << "\n";
    }
  }
};

int main()
{
  Graph g(7);

  g.addVertexData(0, "A");
  g.addVertexData(1, "B");
  g.addVertexData(2, "C");
  g.addVertexData(3, "D");
  g.addVertexData(4, "E");
  g.addVertexData(5, "F");
  g.addVertexData(6, "G");

  g.addEdge(0, 1, 4);
  g.addEdge(0, 6, 10);
  g.addEdge(0, 2, 9);
  g.addEdge(1, 2, 8);
  g.addEdge(2, 3, 5);
  g.addEdge(2, 4, 2);
  g.addEdge(2, 6, 7);
  g.addEdge(3, 4, 3);
  g.addEdge(3, 5, 7);
  g.addEdge(4, 6, 6);
  g.addEdge(5, 6, 11);

  cout << "Kruskal's Algorithm MST:\n";
  g.kruskalsAlgorithm();

  return 0;
}
