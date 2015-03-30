#include <cstddef>
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
class node {
public:
    int value;
    node();
    node(int);
};

class adjacent_node {
public:
    node n;
    int edge_value;
    adjacent_node* next;
    adjacent_node();
};

class Graph {
    adjacent_node *heads;
    int value;
    int add(int,int);
    int remove(int,int);
    void set_edge(int,int,int);
public:
    Graph(int);
    bool isAdjacent(int,int);
    int* neighbors(int,int);
    void add_node(int);
    int add_edge(int,int);
    int remove_edge(int,int);
    int get_node_value(int);
    void set_node_value(int,int);
    int get_edge_value(int,int);
    void set_edge_value(int,int,int);
    void print_graph();
};


#endif // GRAPH_H_INCLUDED
