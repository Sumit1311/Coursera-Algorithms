#ifndef SEQUENCEALIGNMENT_H
#define SEQUENCEALIGNMENT_H
#include <string>
#include <vector>

typedef vector<int> VectorInt;
typedef vector<VectorInt> Penalties;

class SequenceAlignment
{
    public:
        SequenceAlignment(string,string);
        int startCalculatingPenalties();
    protected:
    private:
        string first,second;
        Penalties pen;
        int penaltyForGap,penaltyForMismatch;

};

#endif // SEQUENCEALIGNMENT_H
