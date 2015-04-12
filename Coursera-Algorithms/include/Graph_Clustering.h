#include "graph.h"
#ifndef GRAPH_CLUSTERING_H
#define GRAPH_CLUSTERING_H


class Graph_Clustering: protected Graph
{
    int no_of_nodes,no_of_edges;
    void Sort_By_Edge_Lengths();
    public:
        /** Default constructor */
        Graph_Clustering(int,int);
        void Start_Clustering(int);
        void Create_Graph(int **);

};

#endif // GRAPH_CLUSTERING_H
