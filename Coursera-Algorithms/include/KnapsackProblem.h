#ifndef KNAPSACKPROBLEM_H
#define KNAPSACKPROBLEM_H
#include <vector>
#include <utility>
#include <set>

using namespace std;

typedef pair<int,int> item;
typedef vector<item> items;

class KnapsackProblem
{
    public:
        KnapsackProblem(int [],int [], int,int);
        void calculateTheMaxWeight();
    protected:
    private:
        items allItems;
        int maxWeight,**totalWeight,noOfItems;
        set<int> solution;
        void printAllWeights();
        void reconstruction(int,int);
};

#endif // KNAPSACKPROBLEM_H
