#include "SequenceAlignment.h"

SequenceAlignment::SequenceAlignment(string first,string second,int penGap, int penMis) {
    //ctor
    this->first=first;
    this->second=second;
    for(int i=0; i<first.length; i++) {
        pen.push_back(VectorInt(second.length));
    }
    penaltyForGap=penGap;
    penaltyForMismatch=penMis;
}



/** @brief SequenceAlignment
  *
  * @todo: document this function
  */
SequenceAlignment::SequenceAlignment(string, string) {

    int i=0;
    for (int j=0; j<second.length; j++) {
        pen[i][j]=j*penaltyForGap;
    }
    int j=0;
    for (i=0; i<first.length; i++) {
        pen[i][j]=i*penaltyForGap;
    }
    for()
}

/** @brief startCalculatingPenalties
  *
  * @todo: document this function
  */
int SequenceAlignment::startCalculatingPenalties() {

}

