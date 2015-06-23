#ifndef KRUSKAL_ALGORITHM_H
#define KRUSKAL_ALGORITHM_H
#include "graph.h"

class Kruskal_Algorithm
{
    public:
        /** Default constructor */
        Kruskal_Algorithm();
        void run_kruskal_algorithm();
    protected:
    private:
        const int NO_OF_VERTICES=500;
        const int NO_OF_EDGES=2184;
        Graph input;
        Graph min_span_tree;
};

#endif // KRUSKAL_ALGORITHM_H
