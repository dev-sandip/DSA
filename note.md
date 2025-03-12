## **🔹 What Are These Algorithms?**

Both **Kruskal’s** and **Prim’s** algorithms are used to find the **Minimum Spanning Tree (MST)** of a given graph.

### **🔹 What is a Minimum Spanning Tree (MST)?**

A **spanning tree** is a subset of a graph that:

- Connects all the vertices (nodes) **without any cycles**.
- Has **minimum possible total edge weight**.

For example, imagine a **network of cities** connected by **roads** with different costs. MST will **connect all cities with the minimum cost** while ensuring there's no cycle.

---

# **📌 Kruskal’s Algorithm**

### **👀 How It Works?**

Kruskal’s algorithm is a **greedy algorithm** that picks edges in **increasing order of weight** and adds them to the MST **if they don’t form a cycle**.

### **📌 Step-by-Step:**

1️⃣ **Sort all edges** in increasing order based on their weight.  
2️⃣ **Pick the smallest edge** and check if adding it forms a **cycle** (using **Union-Find**).  
3️⃣ **If no cycle is formed**, add it to MST.  
4️⃣ **Repeat** until we have **(V - 1) edges**, where `V` is the number of vertices.

### **🚀 Example Walkthrough (Graph)**

Let’s say we have **5 cities (A, B, C, D, E)** and these roads:  
| Edge | Weight |
|-------|--------|
| A - B | 1 |
| A - C | 4 |
| B - C | 2 |
| B - D | 5 |
| C - D | 3 |

#### **👉 Step 1: Sort the edges**

- **A-B (1)**
- **B-C (2)**
- **C-D (3)**
- **A-C (4)**
- **B-D (5)**

#### **👉 Step 2: Pick edges one by one**

- Pick **A-B (1)** ✅
- Pick **B-C (2)** ✅
- Pick **C-D (3)** ✅
- Pick **A-C (4)** ❌ (cycle formed, so we ignore it)
- Pick **B-D (5)** ✅

#### **✅ Final MST:**

**Edges in MST: (A-B, B-C, C-D, B-D)**  
**Total Cost = 1 + 2 + 3 + 5 = 11**

---

### **👨‍💻 Kruskal’s Code (C++) (Without STL)**

```cpp
#include <iostream>

using namespace std;

#define MAX_EDGES 20
#define MAX_VERTICES 10

struct Edge {
    int u, v, weight;
};

class Graph {
private:
    int size;
    Edge edges[MAX_EDGES]; // Edge list
    int edgeCount;
    string vertex_data[MAX_VERTICES]; // Store vertex names

public:
    Graph(int size) {
        this->size = size;
        edgeCount = 0;
    }

    void addEdge(int u, int v, int weight) {
        if (edgeCount < MAX_EDGES) {
            edges[edgeCount++] = {u, v, weight};
        }
    }

    void addVertexData(int vertex, string data) {
        vertex_data[vertex] = data;
    }

    int find(int parent[], int i) {
        if (parent[i] == i) return i;
        return find(parent, parent[i]);
    }

    void unionSets(int parent[], int x, int y) {
        parent[find(parent, x)] = find(parent, y);
    }

    void kruskalsAlgorithm() {
        Edge result[MAX_VERTICES];
        int parent[MAX_VERTICES];

        for (int i = 0; i < size; i++) parent[i] = i;

        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = 0; j < edgeCount - i - 1; j++) {
                if (edges[j].weight > edges[j + 1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        int e = 0, i = 0;
        while (e < size - 1) {
            Edge nextEdge = edges[i++];
            int x = find(parent, nextEdge.u);
            int y = find(parent, nextEdge.v);

            if (x != y) {
                result[e++] = nextEdge;
                unionSets(parent, x, y);
            }
        }

        cout << "Edge \tWeight\n";
        for (int j = 0; j < e; j++) {
            cout << vertex_data[result[j].u] << "-" << vertex_data[result[j].v] << " \t" << result[j].weight << "\n";
        }
    }
};
```

---

# **📌 Prim’s Algorithm**

### **👀 How It Works?**

Prim’s algorithm also finds the **MST**, but instead of sorting edges, it **starts with one vertex and grows the MST step by step**.

### **📌 Step-by-Step:**

1️⃣ **Pick any starting vertex** (usually vertex `0`).  
2️⃣ Find the **smallest edge** that connects an MST node to a non-MST node.  
3️⃣ Add that edge and mark the new node as part of the MST.  
4️⃣ Repeat until **all nodes are in MST**.

### **🚀 Example Walkthrough**

Using the same graph:  
| Edge | Weight |
|-------|--------|
| A - B | 1 |
| A - C | 4 |
| B - C | 2 |
| B - D | 5 |
| C - D | 3 |

#### **👉 Step 1: Start with A**

- **Pick A**
- Smallest edge: **A-B (1)** ✅

#### **👉 Step 2: Expand MST**

- Smallest edge: **B-C (2)** ✅
- Smallest edge: **C-D (3)** ✅
- Smallest edge: **B-D (5)** ✅

#### **✅ Final MST:**

**Edges in MST: (A-B, B-C, C-D, B-D)**  
**Total Cost = 1 + 2 + 3 + 5 = 11**

---

### **👨‍💻 Prim’s Code (C++) (Without STL)**

```cpp
#include <iostream>

using namespace std;

#define MAX_VERTICES 10
#define INF 99999

class Graph {
private:
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int size;
    string vertex_data[MAX_VERTICES];

public:
    Graph(int size) {
        this->size = size;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                adj_matrix[i][j] = 0;
    }

    void addEdge(int u, int v, int weight) {
        adj_matrix[u][v] = adj_matrix[v][u] = weight;
    }

    void addVertexData(int vertex, string data) {
        vertex_data[vertex] = data;
    }

    void primsAlgorithm() {
        bool in_mst[MAX_VERTICES] = {false};
        int key_values[MAX_VERTICES], parents[MAX_VERTICES];

        for (int i = 0; i < size; i++) key_values[i] = INF, parents[i] = -1;
        key_values[0] = 0;

        for (int count = 0; count < size; count++) {
            int u = 0;
            for (int v = 0; v < size; v++)
                if (!in_mst[v] && key_values[v] < key_values[u]) u = v;

            in_mst[u] = true;
            if (parents[u] != -1) cout << vertex_data[parents[u]] << "-" << vertex_data[u] << " \t" << adj_matrix[u][parents[u]] << "\n";

            for (int v = 0; v < size; v++)
                if (adj_matrix[u][v] && !in_mst[v] && adj_matrix[u][v] < key_values[v])
                    key_values[v] = adj_matrix[u][v], parents[v] = u;
        }
    }
};
```
