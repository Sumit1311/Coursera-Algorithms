#ifndef SEQUENCEALIGNMENT_H
#define SEQUENCEALIGNMENT_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> VectorInt;
typedef vector<VectorInt> Penalties;

class SequenceAlignment
{
    public:
        SequenceAlignment(string first,string second,int penGap, int penMis);
        int startCalculatingPenalties();
    protected:
    private:
        string first,second,opFirst,opSecond;
        Penalties pen;
        int penaltyForGap,penaltyForMismatch, matchScore;
        void printAllPenalties();
        void reconstruct(int i, int j);

};

#endif // SEQUENCEALIGNMENT_H
