#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

Graph::Graph(){}
Graph::~Graph(){}

void Graph::addEdge(std::string v1, std::string v2, int weight){
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == v2 && i != j)
                {
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(std::string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == n)
        {
            found = true;
            cout<<vertices[i].name<<" found. Vertex already exists"<<endl;
        }
    }
    if(found == false)
    {
        vertex v;
        v.name = n;
        vertices.push_back(v);
    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++)
    {
        cout<<vertices[i].district<<":";
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
            cout<<vertices[i].adj[j].v->name;
            if(j != vertices[i].adj.size()-1)
                cout<<"***";
        }
        cout<<endl;
    }
}

void Graph::assignDistricts()
{
    string assign[3] = {"Atlanta","Boston","Cheyenne"};
//breadthFirstTraversal(value)
    for(int i = 0; i < 3; i++)
    {
        vertex *vertexx = new vertex;
        queue <vertex*> q;
        vertexx = findVertex(assign[i]); //vertex = search(value)
        vertexx->visited = true;
        vertexx->district = i+1;
        q.push(vertexx);
        while(! q.empty())
        {
            vertex *n = new vertex;
            n = q.front();
            q.pop();
            for(int x = 0; x < n->adj.size(); x++)
            {
                if(! n->adj[x].v->visited)
                {
                    n->adj[x].v->visited = true;
                    n->adj[x].v->district = i+1;
                    q.push(n->adj[x].v);
                }
            }
        }
        //Returns all visiteds to false
        vertexx->visited = false;
        q.push(vertexx);
        while(! q.empty())
        {
            vertex *n = new vertex;
            n = q.front();
            q.pop();
            for(int x = 0; x < n->adj.size(); x++)
            {
                if(n->adj[x].v->visited == true)
                {
                    n->adj[x].v->visited = false;
                    q.push(n->adj[x].v);
                }
            }
        }
    }
}

void Graph::BFTraversalLabel(std::string startingCity, int distID)
{
}

void Graph::shortestPath(std::string startingCity,std::string endingCity)
{
    queue <vertex*> q;
    vertex* startVertex = findVertex(endingCity); //vertex = search(value)
    vertex* endVertex = findVertex(startingCity);
    if(startVertex == NULL || endVertex == NULL)
    {
        cout<<"One or more cities doesn't exist"<<endl;
        return;
    }
    else if(startVertex->district == -1)
    {
        cout << "Please identify the districts before checking distances" << endl;
        return;
    }
    else if (startVertex->district != endVertex->district)
    {
        cout<<"No safe path between cities"<<endl;
        return;
    }


    else{
        startVertex->visited = true;
        startVertex->parent = NULL;
        q.push(startVertex);
        int edgesTraversed = 0;
        while(! q.empty())
        {
            vertex *n = new vertex;
            n = q.front();
            q.pop();
            for(int x = 0; x < n->adj.size(); x++)
            {

                if(! n->adj[x].v->visited)
                {
                    n->adj[x].v->visited = true;
                    n->adj[x].v->parent = n;
                    q.push(n->adj[x].v);
                }
            }
        }
        vertex *walker = endVertex;
        while (walker->parent != NULL)
        {
            edgesTraversed++;
            walker = walker->parent;
        }
        walker = endVertex;
        cout<<edgesTraversed;
        while (walker->parent != NULL)
        {
            cout<<","<<walker->name;
            walker = walker->parent;
        }
        cout<<","<<startVertex->name<<endl;

        //Returns all visiteds to false
        startVertex->visited = false;
        q.push(startVertex);
        while(! q.empty())
        {
            vertex *n = new vertex;
            n = q.front();
            q.pop();
            for(int x = 0; x < n->adj.size(); x++)
            {
                if(n->adj[x].v->visited == true)
                {
                    n->adj[x].v->visited = false;
                    q.push(n->adj[x].v);
                }
            }
        }
    }
}

vertex* Graph::findVertex(std::string name)
{
    for(int x = 0; x < vertices.size(); x++)
    {
        if(vertices[x].name == name)
        {
            vertex* found;
            found = &vertices[x];
            return found;
        }
    }
    return NULL;
}
