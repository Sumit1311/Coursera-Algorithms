#include <cstddef>
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
struct node{
    int value;
    node(){
        value=0;
    }
    node(int x){
        value=x;
    }
};

struct adjacent_node{
    node n;
    int edge_value;
    struct adjacent_node* next;
};

struct head_adjacency_list{
    struct adjacent_node *head;
    head_adjacency_list(){
        head=NULL;
    }
};
class Graph{
        struct head_adjacency_list *heads;
        int value;
    public:
        void create_graph(int);
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
