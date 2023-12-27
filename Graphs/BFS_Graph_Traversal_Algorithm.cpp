#include <iostream>
#include <list>
using namespace std;

class graph
{
    int V;
    list<int> *adj;

public:
    graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void add_Edge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void BFS(int source)
    {
        // Make all the vertices as not visited
        bool *visited = new bool[V]{false};

        list<int> queue;

        visited[source] = true;
        queue.push_back(source);

        // "i" will  be used to get all adjacent vertices of a vertex
        list<int>::iterator i;

        while (!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            source = queue.front();
            cout << source << " ";
            queue.pop_front();

            for (i = adj[source].begin(); i != adj[source].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
};

// Driver program to test the method of the class graph
int main(void)
{
    graph g(4);

    g.add_Edge(0, 1);
    g.add_Edge(0, 2);
    g.add_Edge(1, 2);
    g.add_Edge(2, 0);
    g.add_Edge(2, 3);
    g.add_Edge(3, 3);

    cout << "Following is the Breath first search Traversal (Starting from vertex 2)" << endl;
    g.BFS(2);
}