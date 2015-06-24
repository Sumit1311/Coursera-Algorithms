#include "Graph_Clustering.h"
#include <cstdlib>
#include "utils.h"
#include <iostream>

using namespace std;

/** \brief Constructor for initializing Graph_Clustering.
 *
 * \param n (int) : No. of Nodes.
 * \param e (int) : No. of edges.
 */
Graph_Clustering::Graph_Clustering(int n,int e):Graph(n,e) {
    //ctor
    no_of_nodes=n;
    no_of_edges=e;
    cout<<"No of edges : "<<e<<endl;
}

/** \brief Comparison function for comparing edge costs of two edges.
 *
 * \param a(void *) : pointer to first edge format(NODE1 NODE2 EDGE_COST)
 * \param b(void *) : pointer to second edge format(NODE1 NODE2 EDGE_COST)
 * \return (int).
 */
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

/** \brief Start clustering algorithm on Graph. For given no. of clusters.
 *
 * \param clusters (int) : Number of clusters after which algorithm should stop.
 */
void Graph_Clustering::Start_Clustering(int clusters) {
    int **sorted_edges;
    sorted_edges=new int*[no_of_edges];
    for(int i=0; i<no_of_edges; i++) {
        sorted_edges[i]=new int[3];
    }
    cout<<"Get All Edges :"<<endl;
    get_all_edges(sorted_edges);
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

/** \brief Create a graph for clustering algorithm.
 *
 * \param list (int **) : a 2-d array with edge information (NODE1 NODE2 EDGE_COST)
 */
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
