#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    int ID = 0;
    std::string name;
    int district = -1;
    bool visited;
    int distance;
    vertex* parent;
    //vertex* next;
    std::vector<adjVertex> adj;
};

struct queueVertex{
    int distance;
    std::vector<vertex *> path;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string n);
        void displayEdges();
        void assignDistricts();
        void BFTraversalLabel(std::string startingCity, int distID);
        void shortestPath(std::string startingCity,std::string endingCity);
        vertex * findVertex(std::string name);

    protected:
    private:
        std::vector<vertex> vertices;

};

#endif // GRAPH_H
