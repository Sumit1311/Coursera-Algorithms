#include <iostream>
#include "test/graphtest.h"
#include "test/primtest.h"
#include "utils.h"
#include "JobSchedulingTest.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    //run_graph_test();
    //run_prim_test();
    JobSchedulingTest schedule_test("input/TestCase1.txt");
    cout<<"Completion time : "<<schedule_test.run_test();
    return 0;
}
