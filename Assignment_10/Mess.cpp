
        vertex *vertexx = new vertex;
        queue <vertex*> q;
        vertexx = findVertex(startingCity); //vertex = search(value)
        vertexx->visited = true;
        vertexx->parent = NULL;
        q.push(vertexx);
        while(! q.empty())
        {
            vertex *n = new vertex;
            n = q.front();
            q.pop();
            for(int x = 0; x < n->adj.size(); x++)//for(int x = 0; x < n->adj.end; x++)
            {
                if(! n->adj[x].v->visited) //if(! n->adj[x].visited)
                {
                    n->adj[x].v->visited = true;
                    n->adj[x].v->parent = n;
                    //cout<<n->adj[x].weight<<endl;
                    q.push(n->adj[x].v);
                }
            }
        }

void Graph::assignDistricts()
{
    string assign[3] = {"Atlanta","Boston","Cheyenne"};
//breadthFirstTraversal(value)
    for(int i = 0; i < 3; i++)
    {
        //queue <vertex*> q;
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
//////////////////////////////////////////////////////
void Graph::shortestPath(std::string startingCity,std::string endingCity)
{
    vertex *vertexx = new vertex;
    queue <vertex*> q;
    vertexx = findVertex(startingCity); //vertex = search(value)
    vertex* endVertex = findVertex(endingCity);
    vertexx->visited = true;
    vertexx->parent = NULL;
    q.push(vertexx);
    while(! q.empty())
    {
        vertex *n = new vertex;
        n = q.front();
        q.pop();
        for(int x = 0; x < n->adj.size(); x++)
        {
            //cout<<n->name<<" "<<n->adj[x].v->name<<" "<<n->adj[x].v->visited<<endl;
            if(! n->adj[x].v->visited)
            {
                n->adj[x].v->visited = true;
                n->adj[x].v->parent = n;
                cout<<n->adj[x].v->name<<endl;
                q.push(n->adj[x].v);
            }
        }
    }
    vertex *walker = endVertex;
    while (walker->parent != NULL)
    {
        cout<<walker->name<<" ---> ";
        walker = walker->parent;
    }
    cout<<vertexx->name<<endl;
/////////////////////////////////////////////////////////////
void Graph::shortestPath(std::string startingCity,std::string endingCity)
{
    vertex *startVertex = new vertex;
    queue <vertex*> q;
    startVertex = findVertex(endingCity); //vertex = search(value)
    vertex* endVertex = findVertex(startingCity);
    startVertex->visited = true;
    startVertex->parent = NULL;
    q.push(startVertex);
    while(! q.empty())
    {
        vertex *n = new vertex;
        n = q.front();
        q.pop();
        for(int x = 0; x < n->adj.size(); x++)
        {
            //cout<<n->name<<" "<<n->adj[x].v->name<<" "<<n->adj[x].v->visited<<endl;
            if(! n->adj[x].v->visited)
            {
                n->adj[x].v->visited = true;
                n->adj[x].v->parent = n;
                //cout<<n->adj[x].v->name<<endl;
                q.push(n->adj[x].v);
            }
        }
    }
    vertex *walker = endVertex;
    while (walker->parent != NULL)
    {
        cout<<walker->name<<" ---> ";
        walker = walker->parent;
    }
    cout<<startVertex->name<<endl;
///////////////////////////////
#Works #3
    queue <vertex*> q;
    vertex* startVertex = findVertex(endingCity); //vertex = search(value)
    vertex* endVertex = findVertex(startingCity);
    startVertex->visited = true;
    startVertex->parent = NULL;
    q.push(startVertex);
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
        cout<<walker->name<<" ---> ";
        walker = walker->parent;
    }
    cout<<startVertex->name<<endl;
//////
    cout << "Enter a starting city:" << endl;
    getline(cin,userInput);
    vertex* v1 = network->findVertex(userInput);
    cout << "Enter an ending city:" << endl;
    string city2;
    getline(cin, city2);
    vertex* v2 = network->findVertex(city2);
    if(v1 == NULL or v2 == NULL)
    {
        cout<<"One or more cities doesn't exist"<<endl;
        continue;
    }
    else if(v1->district == -1 or v2->district == -1)
    {
        cout << "Please identify the districts before checking distances" << endl;
        continue;
    }
    else if (v1->district != v2->district)
    {
        cout<<"No safe path between cities"<<endl;
        continue;
    }
    else
    {
        network->shortestPath(userInput, city2);
    }
/////////
if (startVertex->district != endVertex->district)
{
    cout<<"No safe path between cities"<<endl;
    return;
}
else if(startVertex == NULL || endVertex == NULL)
{
    cout<<"One or more cities doesn't exist"<<endl;
    return;
}
else if(startVertex->district == -1)
{
    cout << "Please identify the districts before checking distances" << endl;
    return;
}
/////////////////////////////////////////////////////////
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

void Graph::shortestPath(std::string startingCity,std::string endingCity)
{
    queue <vertex*> q;
    vertex* startVertex = findVertex(endingCity); //vertex = search(value)
    vertex* endVertex = findVertex(startingCity);

    startVertex->visited = true;
    startVertex->parent = NULL;
    q.push(startVertex);
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
        cout<<walker->name<<",";
        walker = walker->parent;
    }
    cout<<startVertex->name<<endl;

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
//??????????????????????????????????
//??????????????????????????????????
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
       /* vertex *vertexx = new vertex;
        queue <vertex*> q;
        vertexx = findVertex(startingCity); //vertex = search(value)
        vertexx->visited = true;
        vertexx->parent = NULL;
        q.push(vertexx);
        while(! q.empty())
        {
            vertex *n = new vertex;
            n = q.front();
            q.pop();
            for(int x = 0; x < n->adj.size(); x++)//for(int x = 0; x < n->adj.end; x++)
            {
                if(! n->adj[x].v->visited) //if(! n->adj[x].visited)
                {
                    n->adj[x].v->visited = true;
                    n->adj[x].v->parent = n;
                    //cout<<n->adj[x].weight<<endl;
                    q.push(n->adj[x].v);
                }
            }
        }
*/
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
            cout<<walker->name<<",";
            walker = walker->parent;
        }
        cout<<startVertex->name<<endl;

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
//////??????????????????????????????????
////////?????????????????????////???????
/**Tarahs Code*/
void Graph::shortestPath(std::string startingCity,std::string endingCity)
{
    vertex startV;
    vertex endV;
    vertex solvedV;

    startV = findVertex(startingCity);
    endV = findVertex(endingCity);

    startV.visited = true;
    startV.distance = 0;

    std::vector<vertex> solved;
    vertex s;
    int dist;

    while(!endV.visted)
    {
        int mindistance = INT_MAX;
        solvedV = NULL;

        for(int x = 0; x<solved.size(); x++)
        {
            s = solved[x];
            for(int y = 0; y < s.adj.size();y++)
            {
                if(!s.adj[y].v.visited)
                {
                   dist = s.adj[y].v + s.adj[y].v.distance;
                }
                if(dist < mindistance)
                {
                    solvedV = s.adj[y].v;
                    mindistance = dist;
                    vertex parent = s;
                }
            }
        }

        solvedV.distance = mindistance;
        solvedV.parent = parent;
        solvedV.visited = true;
        solved.push_back(solvedV);
    }

/////////////////
/**work on tarahs*/
void Dijkstra(string sourceVertex, string destinationVertex)
    {
    vertex* startV = displayEdges(sourceVertex);
    vertex* endV = displayEdges(destinationVertex);

    vertex solvedV;

    startV->visited = true;
    startV->distance = 0;

    std::vector<vertex> solved;
    vertex s;
    int dist;

    while(!endV->visited)
    {
        int mindistance = INT_MAX;
        solvedV = NULL;

        for(int x = 0; x<solved.size(); x++)
        {
            s = solved[x];
            for(int y = 0; y < s.adj.size();y++)
            {
                if(!s.adj[y].v->visited)
                {
                   dist = s.adj[y].v + s.adj[y].v->distance;
                }
                if(dist < mindistance)
                {
                    solvedV = s.adj[y].v;
                    mindistance = dist;
                    vertex parent = s;
                }
            }
        }

        solvedV.distance = mindistance;
        solvedV.previous = parent;
        solvedV.visited = true;
        solved.push_back(solvedV);
    }
}
///////////////////////////////////////////////////////////
vertex* findVertex(std::string name)
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

    void Dijkstra(string sourceVertex, string destinationVertex)
    {
        vertex* startV = findVertex(sourceVertex);
        vertex* endV = findVertex(destinationVertex);
        //vertex* startV = new vertex;
        //vertex* endV = new vertex;

        startV->visited = true;
        startV->distance = 0;
        vector <vertex*> solved;  // list of solved vertices
        solved.push_back(startV);
        while (! endV->visited)
        {
            int minDistance = 77698;//minDistance = INT_MAX;
            vertex* solvedV = NULL;
            vertex* parent;
            for(int x = 0; x < solved.size(); x++)
            {
                vertex* s = solved[x];
                for(int y = 0; y < s->adj.size(); y++)
                {
                    if(! s->adj[y].v->visited)
                    {
                        int dist = s->distance + s->adj[y].v->distance;
                        if(dist < minDistance)
                        {
                            solvedV = s->adj[y].v;
                            minDistance = dist;
                            parent = s;
                        }
                    }
                }
            }
            solvedV->distance = minDistance;
            solvedV->previous = parent;
            solvedV->visited = true;
            solved.push_back(solvedV);
        }
    }
/////////////////////////////////////////////////////////2222222222222
        void Dijkstra(string sourceVertex, string destinationVertex){
            //vertex* startV = search(sourceVertex);
            //vertex* endV = search(destinationVertex);
            vertex* startV = new vertex;
            vertex* endV = new vertex;
            for(int i = 0; i < 8 ; i++)
            {
                if (vertices[i].name == sourceVertex)
                    startV = &vertices[i];
            }
            for (int i = 0; i < 8; i++)
            {
                if (vertices[i].name == destinationVertex)
                    endV = &vertices[i];
            }
            startV->visited = true;
            startV->distance = 0;
            vector <vertex*> solved;// list of solved vertices
            solved.push_back(startV);
            while (! endV->visited)
            {
                int minDistance = 77698;//minDistance = INT_MAX;
                vertex* solvedV = NULL;
                vertex* parent;
                for(int x = 0; x <8 /*solved.size()*/; x++)
                {
                    vertex* s = solved[x];
                    for(int y = 0; y < s->adj.size(); y++)
                    {
                        if(! s->adj[y].v->visited)
                        {
                            int dist = s->distance + s->adj[y].v->distance;
                            if(dist < minDistance)
                            {
                                solvedV = s->adj[y].v;
                                minDistance = dist;
                                parent = s;
                            }
                        }
                    }
                }
                solvedV->distance = minDistance;
                solvedV->previous = parent;
                solvedV->visited = true;
                solved.push_back(solvedV);
            }
        }

/**h/////CORRECT//////////////**/
void Graph::Dijkstra(string starting, string destination)
{
    int dist, minDistance;
    vertex *startV, *endV, *s, *parent, *solvedV;
    std::vector<vertex*> solved, answer;
    for (int i=0; i<vertices.size(); i++)
    {
        vertices[i].visited = false;
        if (vertices[i].name == starting)
        {
            startV = &vertices[i];
        }
        else if (vertices[i].name == destination)
        {
            endV = &vertices[i];
        }
    }
    startV->visited = true;
    startV->distance = 0;
    solved.push_back(startV);
    while (!endV->visited)
    {
        minDistance = INT_MAX;
        solvedV=NULL;
        for (int j=0; j<solved.size(); j++)
        {
            s = solved[j];
            for (int k=0; k<s->adj.size(); k++)
            {
                if (!s->adj[k].v->visited)
                {
                    dist = s->distance + s->adj[k].weight;
                    if (dist < minDistance)
                    {
                        solvedV = s->adj[k].v;
                        minDistance = dist;
                        parent = s;
                    }
                }
            }
        }
        solvedV->distance = minDistance;
        solvedV->previous = parent;
        solvedV->visited = true;
        solved.push_back(solvedV);
    }


    std::cout << "Shortest Path" << std::endl;

    //std::cout << solved[0]->name;
    std::cout<< endV->previous->previous->previous->previous->name<< " - ";
    std::cout<< endV->previous->previous->previous->name<< " - ";
    std::cout<< endV->previous->previous->name<< " - ";
    std::cout<< endV->previous->name<< " - ";
    std::cout<< endV->name;





    for (int i=1; i<solved.size(); i++)
    {
        //std::cout << " - " << solved[i]->name;
    }

    std::cout << std::endl;
    std::cout << "Minimum Distance: " << minDistance;
}

