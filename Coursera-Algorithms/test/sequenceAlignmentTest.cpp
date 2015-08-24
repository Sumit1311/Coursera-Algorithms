#include "test/sequenceAlignmentTest.h"
#include <string>
#include "SequenceAlignment.h"
using namespace std;

void run_sequence_alignment(){
    string first="GAATTCAGTTA",second="GGATCGA";
    int penForGap=-2,penForMismatch=-1;
    SequenceAlignment sa(first,second,penForGap,penForMismatch);
    sa.startCalculatingPenalties();
}
