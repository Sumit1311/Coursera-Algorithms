#include "Kruskal_Algorithm.h"
#include "utils.h"

Kruskal_Algorithm::Kruskal_Algorithm(int nodes) {
    //ctor
    input = Graph(nodes);
    min_span_tree = Graph(nodes);
}

void Kruskal_Algorithm::run_kruskal_algorithm() {
    long int min_cost=0;

    int data[NO_OF_EDGES][3];
    read_data_from_file("input/prims_algorithm_edges.txt",data);

    for(int i=0; i<NO_OF_VERTICES; i++) {
        input.add_node(i);
    }

    for(int i=0; i<NO_OF_EDGES; i++) {
        input.add_edge(data[i][0]-1,data[i][1]-1);
        input.set_edge_value(data[i][0]-1,data[i][1]-1,data[i][2]);
    }
}

bool nodeComparison(const Pairs* first_item, const Pairs* second_item)  {
    //cout<<"Symbols : "<<first_item.data.first<<","<<second_item.data.first<<endl;
    if(first_item->data.second < second_item->data.second){
        //cout<<"return "<<first_item.data.first<<endl;
        return false;
    }
    //cout<<"return "<<second_item.data.first<<endl;
    return true;
}
