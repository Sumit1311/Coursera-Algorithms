#include "utils.h"
#include "MaxWeightIndepSet.h"
void run_max_weight_indep_set() {
    int edges[3][2];
    edges[0][0]=0;
    edges[0][1]=1;
    edges[1][0]=1;
    edges[1][1]=2;
    edges[2][0]=2;
    edges[2][1]=3;
    int weights[4];
    weights[0]=1;
    weights[1]=4;
    weights[2]=4;
    weights[3]=5;
    //char *file="input/MWISTest.txt";
    //read_data_from_file(file, edges);
    MaxWeightIndepSet mwis(4,3,weights);
    mwis.run(edges);
    mwis.printIndependentSet();
}
