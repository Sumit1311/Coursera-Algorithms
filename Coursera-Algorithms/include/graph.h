#include <cstddef>
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
class node {
public:
    int value;/**< Value for the current vertex. Default is -1 */
    node();
    node(int);
};

class adjacent_node {
public:
    node n; /**< Node class reference for current vertex */
    int edge_value; /**< Edge length */
    adjacent_node* next; /**< Reference to next node in the list */
    adjacent_node();
};

class Graph {
    adjacent_node *heads; /**< For storing adjacency list of each vertex */
    int value; /**< No of vertices in graph */
    void add(int,int);
    void remove(int,int);
    void set_edge(int,int,int);
public:
    Graph(int);
    bool isAdjacent(int,int);
    void neighbors(int [],int,int);
    void add_node(int);
    void add_edge(int,int);
    void remove_edge(int,int);
    int get_node_value(int);
    void set_node_value(int,int);
    int get_edge_value(int,int);
    void set_edge_value(int,int,int);
    void print_graph();
};


#endif // GRAPH_H_INCLUDED
