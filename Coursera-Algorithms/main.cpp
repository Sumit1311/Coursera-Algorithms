#include <iostream>
#include "test/graphtest.h"
#include "test/primtest.h"
#include "utils.h"
#include "JobSchedulingTest.h"
#include "Graph_Clustering.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    //run_graph_test();
    //run_prim_test();
    //JobSchedulingTest schedule_test("input/min_weighted_sum_of_jobs1.txt");
    //cout<<"Completion time : "<<schedule_test.run_test();
    Graph_Clustering clustering=Graph_Clustering(4,5);
    int **graph;
    graph=new int*[5];
    for(int i=0;i<5;i++){
        graph[i]=new int[3];
    }
    graph[0][0]=0;
    graph[0][1]=1;
    graph[0][2]=3;
    graph[1][0]=0;
    graph[1][1]=2;
    graph[1][2]=1;
    graph[2][0]=0;
    graph[2][1]=3;
    graph[2][2]=5;
    graph[3][0]=1;
    graph[3][1]=3;
    graph[3][2]=2;
    graph[4][0]=2;
    graph[4][1]=3;
    graph[4][2]=4;
    //cout<<"Calling create graph";
    clustering.Create_Graph(graph);
    clustering.Start_Clustering(2);
    return 0;
}
