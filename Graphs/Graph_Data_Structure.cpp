#include <iostream>
#include <list>

using namespace std;

// Graph Representation
/*
        0 ---- 1
        \      /
         \    /
          \ /
           2
           |
           |
           3
*/

// Adjency List
/*
    Array of list size "v" (number of vertexe)

    L1 => 0 -> 1,2
    L2 => 1 -> 2,0
    L3 => 2 -> 3,0,1
    L4 => 3 -> 2
*/

class graph
{
private:
    int v;
    // Array of list;
    list<int> *l;

public:
    // Graph constructor where we'll accept how many node this Graph has
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    // In this case it is assumed that it is a bi-directional graph
    void add_Edge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    // To print the adjcency list
    void print_list()
    {
        // Iterate over all the vertices
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << " -> ";
            for (int j : l[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main(void)
{
    // Cresting a graph with 4 vertex
    graph g(4);

    // All of the Edges are bidirectional
    g.add_Edge(0, 1);
    g.add_Edge(0, 2);
    g.add_Edge(2, 3);
    g.add_Edge(1, 2);

    g.print_list();
}
