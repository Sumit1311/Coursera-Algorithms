#ifndef KRUSKAL_ALGORITHM_H
#define KRUSKAL_ALGORITHM_H
#include "graph.h"

class Kruskal_Algorithm
{
    public:
        Kruskal_Algorithm(int,int);
        void run_kruskal_algorithm();
    protected:
    private:
        int NO_OF_VERTICES=0;
        int NO_OF_EDGES=0;
        Graph *input;
        Graph *min_span_tree;
};

#endif // KRUSKAL_ALGORITHM_H
