#include <iostream>

using namespace std;

#define MAX_VERTICES 10
#define INF 99999

class Graph
{
private:
  int adj_matrix[MAX_VERTICES][MAX_VERTICES];
  int size;
  string vertex_data[MAX_VERTICES];

public:
  Graph(int size)
  {
    this->size = size;
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        adj_matrix[i][j] = 0;
      }
    }
  }

  void addEdge(int u, int v, int weight)
  {
    if (u >= 0 && u < size && v >= 0 && v < size)
    {
      adj_matrix[u][v] = weight;
      adj_matrix[v][u] = weight;
    }
  }

  void addVertexData(int vertex, string data)
  {
    if (vertex >= 0 && vertex < size)
    {
      vertex_data[vertex] = data;
    }
  }

  int getMinKeyVertex(int key_values[], bool in_mst[])
  {
    int minKey = INF, minIndex = -1;

    for (int v = 0; v < size; v++)
    {
      if (!in_mst[v] && key_values[v] < minKey)
      {
        minKey = key_values[v];
        minIndex = v;
      }
    }
    return minIndex;
  }

  void primsAlgorithm()
  {
    bool in_mst[MAX_VERTICES] = {false};
    int key_values[MAX_VERTICES];
    int parents[MAX_VERTICES];

    for (int i = 0; i < size; i++)
    {
      key_values[i] = INF;
      parents[i] = -1;
    }

    key_values[0] = 0;

    cout << "Edge \tWeight\n";

    for (int count = 0; count < size; count++)
    {
      int u = getMinKeyVertex(key_values, in_mst);
      in_mst[u] = true;

      if (parents[u] != -1)
      {
        cout << vertex_data[parents[u]] << "-" << vertex_data[u] << " \t" << adj_matrix[u][parents[u]] << "\n";
      }

      for (int v = 0; v < size; v++)
      {
        if (adj_matrix[u][v] > 0 && !in_mst[v] && adj_matrix[u][v] < key_values[v])
        {
          key_values[v] = adj_matrix[u][v];
          parents[v] = u;
        }
      }
    }
  }
};

int main()
{
  Graph g(8);

  g.addVertexData(0, "A");
  g.addVertexData(1, "B");
  g.addVertexData(2, "C");
  g.addVertexData(3, "D");
  g.addVertexData(4, "E");
  g.addVertexData(5, "F");
  g.addVertexData(6, "G");
  g.addVertexData(7, "H");

  g.addEdge(0, 1, 4);
  g.addEdge(0, 3, 3);
  g.addEdge(1, 2, 3);
  g.addEdge(1, 3, 5);
  g.addEdge(1, 4, 6);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 7, 2);
  g.addEdge(3, 4, 7);
  g.addEdge(3, 5, 4);
  g.addEdge(4, 5, 5);
  g.addEdge(4, 6, 3);
  g.addEdge(5, 6, 7);
  g.addEdge(6, 7, 5);

  cout << "Prim's Algorithm MST:\n";
  g.primsAlgorithm();

  return 0;
}
