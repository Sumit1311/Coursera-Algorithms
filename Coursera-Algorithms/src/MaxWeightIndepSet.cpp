#include "MaxWeightIndepSet.h"
#include <iostream>
#include "utils.h"
#include <utility>

using namespace std;

MaxWeightIndepSet::MaxWeightIndepSet(int noOfNodes, int noOfEdges,int weights[]) {
    //ctor
    pathGraph=new Graph(noOfNodes,noOfEdges);
    this->noOfEdges=noOfEdges;
    this->noOfNodes=noOfNodes;
    this->weights=new int[noOfNodes];
    maximumWeight =new int[noOfNodes];
    for(int i=0; i < noOfNodes; i++) {
        pathGraph->add_node(i);
        pathGraph->set_node_value(i,weights[i]);
        this->weights[i]=weights[i];
        maximumWeight[i]=0;
    }
}

void MaxWeightIndepSet::createGraph(int edges[][2]) {
    for(int i=0; i<noOfEdges; i++) {
        pathGraph->add_edge(edges[i][0],edges[i][1]);
        //pathGraph->set_edge_value(edges[i][0],edges[i][1],edges[i][2]);
    }
    return;
}

void MaxWeightIndepSet::calculateMaxWeight() {
    for(int i=0; i<noOfNodes; i++) {
        if(i == 0) {
            maximumWeight[i]=pathGraph->get_node_value(i);
        } else if(i == 1) {
            maximumWeight[i]=getMaxOfTwo(maximumWeight[i-1],pathGraph->get_node_value(i));
        } else {
            maximumWeight[i]=getMaxOfTwo(maximumWeight[i-1],maximumWeight[i-2]+pathGraph->get_node_value(i));
        }
        print_array(maximumWeight,noOfNodes);
    }
}

void MaxWeightIndepSet::reconstruct(int i) {
    if(i <= 0) {
        return;
    } else if(i == 1) {
        independentSet.insert(i);
        return;
    } else {
        if((pathGraph->get_node_value(i) + maximumWeight[i-2] ) >= (maximumWeight[i-1])) {
            independentSet.insert(i);
            reconstruct(i-2);
        } else {
            reconstruct(i-1);
        }
    }
}

void MaxWeightIndepSet::printIndependentSet() {
    cout<<"{";
    set<int>::iterator beg=independentSet.begin();
    set<int>::iterator end=independentSet.end();
    while(beg != end){
        cout <<(*beg)<<",";
        beg++;
    }
    cout<<"}"<<endl;
}

void MaxWeightIndepSet::run(int edges[][2]){
    createGraph(edges);
    calculateMaxWeight();
    reconstruct(noOfNodes-1);
}
