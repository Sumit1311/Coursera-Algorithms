#include "test/knapsackTest.h"
#include "KnapsackProblem.h"

void run_knapsack_test(){
    int values[]={3,7,2,9};
    int weights[]={2,3,4,5};
    KnapsackProblem kp(values,weights,5,4);
    kp.calculateTheMaxWeight();
}
