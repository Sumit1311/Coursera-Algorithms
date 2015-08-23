#ifndef MAXWEIGHTINDEPSET_H
#define MAXWEIGHTINDEPSET_H
#include "graph.h"
#include <set>
using namespace std;

class MaxWeightIndepSet {
public:
    MaxWeightIndepSet(int,int,int[]);
    void run(int [][2]);
    void printIndependentSet();
protected:
private:
    Graph *pathGraph;
    int *weights;
    int *maximumWeight,noOfNodes,noOfEdges;
    set<int> independentSet;
    void createGraph(int [][2]);
    void calculateMaxWeight();
    void reconstruct(int);
};

#endif // MAXWEIGHTINDEPSET_H
