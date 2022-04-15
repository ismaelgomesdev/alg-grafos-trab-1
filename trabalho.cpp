// DFS algorithm in C++

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Graph
{
  int numVertices;

public:
  list<int> *adjLists;
  bool *visited;

public:
  Graph(int V);
  void addEdge(int src, int dest);
  void clearVisited();
  void DFS(int vertex);
  void DFS_ALL();
};

// Initialize graph
Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjLists = new list<int>[vertices + 1];
  visited = new bool[vertices];
}

// set false all visited
void Graph::clearVisited()
{
  for (int i = 1; i <= numVertices; i++)
  {
    visited[i] = 0;
  }
}

// Add edges
void Graph::addEdge(int src, int dest)
{
  adjLists[src].push_front(dest);
  adjLists[dest].push_front(src);

  //itera sobre adjLists[src] e imprime os vertices adjacentes

  list<int>::iterator i;
  for (i = adjLists[src].begin(); i != adjLists[src].end(); ++i)
  {
    
  }
}

// DFS algorithm
void Graph::DFS(int vertex)
{
  list<int> adjList = adjLists[vertex];

  adjList.push_front(vertex);
  adjList.sort();
  

  for (list<int>::iterator it = adjList.begin(); it != adjList.end(); it++)
  {
    if (!visited[*it])
    {
      visited[*it] = true;
      cout << *it << " ";
      DFS(*it);
    }
  }
}

void Graph::DFS_ALL()
{
  for (unsigned j = 1; j <= numVertices; j++)
  {
    if (visited[j] == false)
      cout << j << " ";
    visited[j] = true;
    list<int> adjList = adjLists[j];

    if (*adjList.begin() == 0)
    {
      cout << "\n";
    }
    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
    {
      if (!visited[*i])
      {
        DFS(*i);
        cout << "\n";
      }
    }
  }
}

int main()
{
  string input;

  while (getline(cin, input))
  {
    if (input.find("n=") != string::npos)
    {
      int n = stoi(input.substr(input.find("=") + 1));

      getline(cin, input);

      Graph g(n);
      g.clearVisited();

      while (getline(cin, input))
      {
        if (input.empty())
          break;
        int src = stoi(input.substr(0, input.find(" ")));
        int dest = stoi(input.substr(input.find(" ") + 1));
        g.addEdge(src, dest);
      }

      g.DFS_ALL();
      break;
    }
  }

  return 0;
}