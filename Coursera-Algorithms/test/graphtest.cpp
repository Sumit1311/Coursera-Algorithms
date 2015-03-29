#include "graph.h"
void run_graph_test(){
    int NO_OF_VERTICES=10;

    Graph *g=new Graph(10);
    for(int i=0;i<NO_OF_VERTICES;i++){
        g->add_node(i);
    }
    for(int i=0;i<NO_OF_VERTICES;i++){
        for(int j=i+1;j<NO_OF_VERTICES;j++){
            g->add_edge(i,j);
            g->set_edge_value(i,j,i+j);
        }
    }
    g->remove_edge(0,9);
    g->print_graph();
}
