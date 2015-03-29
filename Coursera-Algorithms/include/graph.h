#include <cstddef>
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
struct node {
    int value;
    node();
    node(int);
};

struct adjacent_node {
    node n;
    int edge_value;
    struct adjacent_node* next;
    adjacent_node();
};

class Graph {
    struct adjacent_node *heads;
    int value;
public:
    Graph(int);
    int isAdjacent(node,node);
    node* neighbors(node);
    int add(node,node);
    int removeEdge(node,node);
    int get_node_value(node);
    void set_node_value(node,int);
    int get_edge_value(node,node);
    void set_edge_value(node,node,int);
    void print_graph();
};




#endif // GRAPH_H_INCLUDED
