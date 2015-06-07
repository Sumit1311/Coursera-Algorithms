#include "Graph_Clustering.h"
#include <cstdlib>
#include "utils.h"
#include <iostream>

using namespace std;

Graph_Clustering::Graph_Clustering(int n,int e):Graph(n,e) {
    //ctor
    no_of_nodes=n;
    no_of_edges=e;
    cout<<"No of edges : "<<e<<endl;
}

int compare1(const void *a,const void *b) {
    int **aint=(int **)a;
    int **bint=(int **)b;
    //aint=*a;
    //bint=*b;
    //aint=*a;
    cout<<"first1 : "<<aint[0][2]<<" second : "<<bint[0][2]<<endl;
    if(aint[0][2] < bint[0][2])
        return -1;
    if(aint[0][2] == bint[0][2]) {
        return 0;
    }
    if(aint[0][2] > bint[0][2])
        return 1;
}


void Graph_Clustering::Start_Clustering(int clusters) {
    int **sorted_edges;
    sorted_edges=new int*[no_of_edges];
    for(int i=0; i<no_of_edges; i++) {
        sorted_edges[i]=new int[3];
    }
    cout<<"Get All Edges :"<<endl;
    get_all_edges(sorted_edges);
    print_2d_array(sorted_edges,no_of_edges,3);
    qsort(sorted_edges,no_of_edges,sizeof(sorted_edges[0]),compare1);
    print_2d_array(sorted_edges,no_of_edges,3);
    int cluster[no_of_nodes];
    for(int i=0; i<no_of_nodes; i++) {
        cluster[i]=i;
    }
    int current_clusters=no_of_nodes,count=0;
    while(current_clusters != clusters) {
        cluster[sorted_edges[count][1]]=sorted_edges[count][0];
        count++;
        current_clusters--;
    }
    cout<<"Max Spacing :"<<sorted_edges[count][2];
}


void Graph_Clustering::Create_Graph(int **list ) {
    cout<<"Creating  Graph.."<<endl;
    for(int i=0; i<no_of_nodes; i++) {
        add_node(i);
    }
    for(int i=0; i<no_of_edges; i++) {
        add_edge(list[i][0],list[i][1]);
        set_edge_value(list[i][0],list[i][1],list[i][2]);
    }
    //print_graph();
}
