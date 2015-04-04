#include "graph.h"
#include "utils.h"
#include <iostream>

using namespace std;

const int NO_OF_VERTICES=4;
Graph g(NO_OF_VERTICES);
Graph min_span_tree(NO_OF_VERTICES);
bool explored[NO_OF_VERTICES];

bool all_explored(){
    bool temp=explored[0];
    for(int i=0;i<NO_OF_VERTICES;i++){
        temp=temp && explored[i];
    }
    return temp;
}

void select_minimum_edge(int i,int temp[][2]){
    int neighbor_edges[NO_OF_VERTICES]={-1};
    g.neighbors(neighbor_edges,i,NO_OF_VERTICES);
    print_array(neighbor_edges,NO_OF_VERTICES);
    int min[1][2]={0,10000};
    for(int k=0;k<NO_OF_VERTICES;k++){
        if(explored[k]==true){
            continue;
        }
        if(neighbor_edges[k] == 0)
            continue;
        if(k==i)
            continue;
        if(min[0][1] > neighbor_edges[k]){
            min[0][1]=neighbor_edges[k];
            min[0][0]=k;
        }

    }
    cout<<"min "<<min[0][1];
    temp[0][0]=min[0][0];
    temp[0][1]=min[0][1];
}

void prims_algorithm() {

    for(int i=0; i<NO_OF_VERTICES; i++) {
        g.add_node(i);
        explored[i]=false;
    }

    for(int i=0;i<NO_OF_VERTICES;i++){
        for(int j=i+1;j<NO_OF_VERTICES;j++){
            g.add_edge(i,j);
        }
    }
    g.set_edge_value(0,1,2);
    g.set_edge_value(0,2,2);
    g.set_edge_value(0,3,8);
    g.set_edge_value(1,2,1);
    g.set_edge_value(1,3,3);
    g.set_edge_value(2,3,4);

    g.print_graph();

    min_span_tree.add_node(0);
    explored[0]=true;
    int count=0;
    while(!all_explored()){
        int min[1][2]={0,10000},ind=-1;
        for(int i=0;i<NO_OF_VERTICES;i++){
            if(explored[i] == true){
                int temp[1][2]={0,10000};
                select_minimum_edge(i,temp);
                cout<<"Selected Edge : "<<i<<" "<<temp[0][0];
                if(temp[0][1]<min[0][1]){
                    min[0][0]=temp[0][0];
                    min[0][1]=temp[0][1];
                    ind=i;
                }
            }
        }
        if(ind!=-1){
            explored[min[0][0]]=true;
            min_span_tree.add_node(min[0][0]);
            min_span_tree.add_edge(ind,min[0][0]);
            min_span_tree.set_edge_value(ind,min[0][0],min[0][1]);
        }
        count++;

    }
}



