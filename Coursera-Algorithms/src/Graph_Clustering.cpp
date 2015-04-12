#include "Graph_Clustering.h"
#include <cstdlib>

Graph_Clustering::Graph_Clustering(int n,int e):Graph(n,e) {
    //ctor
    no_of_nodes=n;
    no_of_edges=e;
}

int compare(const void *a,const void *b){
    int **aint=(int **)a;
    int **bint=(int **)b;
    //aint=*a;
    //bint=*b;
    //aint=*a;
    //cout<<"first1 : "<<aint[0][0]<<" second : "<<bint[0][0]<<endl;
    if(aint[0][2] > bint[0][2])
        return -1;
    if(aint[0][2] == bint[0][2]){
            return 0;
    }
    if(aint[0][2] < bint[0][2])
        return 1;
}


void Graph_Clustering::Start_Clustering(int clusters) {
    int **sorted_edges;
    get_all_edges(sorted_edges);
    qsort(sorted_edges,no_of_edges,sizeof(sorted_edges[0]),compare);
    for(int i=0;i<no_of_edges;i++){
        sorted_edges[i][3]=sorted_edges[i][0];
    }
    int current_clusters=no_of_nodes,count=0;
    while(current_clusters != clusters){

    }

}


void Graph_Clustering::Create_Graph(int **list ) {
    for(int i=0; i<no_of_nodes; i++) {
        add_node(i);
    }
    for(int i=0; i<no_of_edges; i++) {
        add_edge(list[i][0],list[i][1]);
        set_edge_value(list[i][0],list[i][1],list[i][2]);
    }
}
