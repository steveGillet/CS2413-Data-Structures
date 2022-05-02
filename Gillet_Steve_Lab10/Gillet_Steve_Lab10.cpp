#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void breadthFS(int startVertex);
};

Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::breadthFS(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> listVert;

    visited[startVertex] = true;
    listVert.push_back(startVertex);
    list<int>::iterator i;

    while (!listVert.empty())
    {
        startVertex = listVert.front();
        cout << startVertex << " ";
        listVert.pop_front();
        for (i = adjLists[startVertex].begin(); i != adjLists[startVertex].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                listVert.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.breadthFS(2);
    return 0;
}