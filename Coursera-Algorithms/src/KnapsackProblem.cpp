#include "KnapsackProblem.h"
#include "utils.h"
#include <iostream>

/**
 * @brief
 * @todo: add documentation
 * @param
 * @param
 * @return
 *
 */
int getMax(int arr[],int size) {
    int max=arr[0];
    for(int i=0; i<size; i++) {
        if(max < arr[i]) {
            max=arr[i];
        }
    }
    return max;
}

/** @brief KnapsackProblem
  * @todo: document this function
  */
KnapsackProblem::KnapsackProblem(int values[], int weights[], int maxWeight, int noOfItems) {
    this->maxWeight=maxWeight;
    for(int i=0; i<noOfItems; i++) {
        allItems.push_back(item(values[i],weights[i]));
        cout<<allItems[i].first<<endl;
    }
    totalWeight=new int*[noOfItems+1] {0};
    for(int i=0; i<=noOfItems; i++) {
        totalWeight[i]=new int[maxWeight+1] {0};
    }
    this->noOfItems=noOfItems;
}

/** @brief calculateTheMaxWeight
  *
  * @todo: document this function
  */
void KnapsackProblem::calculateTheMaxWeight() {
    items::iterator start=allItems.begin();
    items::iterator finish=allItems.end();
    int count=1;
    printAllWeights();
    while(start != finish) {
        for(int i=1; i<=maxWeight; i++) {
            int first=totalWeight[count-1][i];
            int second;
            if(i<start->second) {
                second=totalWeight[count-1][i];
            } else {
                second=start->first+totalWeight[count-1][i-start->second];
            }
            cout<<"Second : "<<start->first<<endl;
            totalWeight[count][i]=getMaxOfTwo(first,second);
            //totalWeight[count][i]=
        }
        printAllWeights();
        start++;
        count++;
    }
    reconstruction(noOfItems,5);
}

/** @brief printAllWeights
  *
  * @todo: document this function
  */
void KnapsackProblem::printAllWeights() {
    print_2d_array(totalWeight,noOfItems+1,maxWeight+1);
}

void KnapsackProblem::reconstruction(int i,int x){
    if(i==0 || x<=0){
        return;
    }else{
        if(totalWeight[i][x] != totalWeight[i-1][x]){
                cout<<"i : "<<i<<","<<x;
            solution.insert(i);
            reconstruction(i-1,x-allItems[i-1].second);
        }else{
            reconstruction(i-1,x);
        }
    }
}
