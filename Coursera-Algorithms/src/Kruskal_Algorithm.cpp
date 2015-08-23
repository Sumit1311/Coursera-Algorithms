#include "Kruskal_Algorithm.h"
#include "utils.h"
#include "Union_Find.h"
#include <iostream>

/** \brief Constructor for algorithm.
 *
 * \param nodes (int) : No of nodes in graph.
 * \param edges (int) : No of edges in graph.
 *
 */
Kruskal_Algorithm::Kruskal_Algorithm(int nodes, int edges) {
    //ctor
    input =new  Graph(nodes,edges);
    min_span_tree =new Graph(nodes);
    NO_OF_EDGES=edges;
    NO_OF_VERTICES=nodes;
}

/** \brief Compare the two edges (Format : [NODE1,NODE2,EDGE_COST])
 *
 * \param a (void *)
 * \param b (void *)
 * \return (int)
 *
 */
int compare2(const void *a,const void *b) {
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

/** \brief Runs Kruskal's algorithm graph given in file.
 *         Store generated minimum spanning tree and return cost of the tree.
 * \return (long int).
 *
 */
long int Kruskal_Algorithm::run_kruskal_algorithm() {
    long int min_cost=0;

    int data[NO_OF_EDGES][3];
    read_data_from_file("input/KruskalAlgorithmTest.txt",data);

    for(int i=0; i<NO_OF_VERTICES; i++) {
        input->add_node(i);
        min_span_tree->add_node(i);
    }

    for(int i=0; i<NO_OF_EDGES; i++) {
        input->add_edge(data[i][0]-1,data[i][1]-1);
        input->set_edge_value(data[i][0]-1,data[i][1]-1,data[i][2]);
    }
    int **sorted_edges;
    sorted_edges=new int*[NO_OF_EDGES];
    for(int i=0; i<NO_OF_EDGES; i++) {
        sorted_edges[i]=new int[3];
    }
    cout<<"Get All Edges :"<<endl;
    input->get_all_edges(sorted_edges);
    print_2d_array(sorted_edges,NO_OF_EDGES,3);
    qsort(sorted_edges,NO_OF_EDGES,sizeof(sorted_edges[0]),compare2);
    print_2d_array(sorted_edges,NO_OF_EDGES,3);
    Union_Find uf=Union_Find(NO_OF_VERTICES);
    cout<<"Sorted Edges :"<<endl;
    print_2d_array(sorted_edges,NO_OF_EDGES,3);
    for(int i=0; i<NO_OF_EDGES; i++) {
        int first=uf.find(sorted_edges[i][0]);
        int second=uf.find(sorted_edges[i][1]);
        int edge_cost=input->get_edge_value(sorted_edges[i][0],sorted_edges[i][1]);
        uf.printAll();
        if(first != second) {
            uf.unionVertices(sorted_edges[i][0],sorted_edges[i][1]);
            cout<<"Adding Edges : "<<sorted_edges[i][0]<<","<<sorted_edges[i][1]<<endl;
            min_span_tree->add_edge(sorted_edges[i][0],sorted_edges[i][1]);
            min_span_tree->set_edge_value(sorted_edges[i][0],sorted_edges[i][1],edge_cost);
            min_cost +=edge_cost;
        } else {
            continue;
        }
    }
    min_span_tree->print_graph();
    return min_cost;
}
