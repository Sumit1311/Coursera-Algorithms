#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Graph *g=new Graph;
    cout<<"Creating Graph ...."<<endl;
    g->create_graph(10);
    node x(0);
    node y(1);
    g->add(x,y);
    g->print_graph();

    return 0;
}
