#include "SequenceAlignment.h"
#include "utils.h"

SequenceAlignment::SequenceAlignment(string first,string second,int penGap, int penMis) {
    //ctor
    this->first=first;
    this->second=second;
    for(int i=0; i<=this->first.length(); i++) {
        pen.push_back(VectorInt(this->second.length()+1));
    }
    penaltyForGap=penGap;
    penaltyForMismatch=penMis;
    matchScore=2;
}

/** @brief startCalculatingPenalties
  *
  * @todo: document this function
  */
int SequenceAlignment::startCalculatingPenalties() {
    int i=0;
    for (int j=0; j<=second.length(); j++) {
        pen[i][j]=j*penaltyForGap;
    }
    int j=0;
    for (i=0; i<=first.length(); i++) {
        pen[i][j]=i*penaltyForGap;
    }
    for(i=1; i<=first.length(); i++) {
        cout<<"Starting on "<<i<<"th row...."<<endl;
        for(j=1; j<=second.length(); j++) {
            int penAfterGapInFirst,penAfterGapInSecond,penMistmatch;
            //cout<<"First : "<<first[i-1] <<", Second : "<<second[j-1]<<endl;
            if(first[i-1] == second[j-1]) {
                cout<<"Matched"<<endl;
                pen[i][j]=matchScore + pen[i-1][j-1];
                continue;

            } else {
                penMistmatch=pen[i-1][j-1]+ penaltyForMismatch;
            }
            cout<<penMistmatch<<endl;
            penAfterGapInFirst=pen[i-1][j] + penaltyForGap;
            penAfterGapInSecond=pen[i][j-1]+ penaltyForGap;
            //cout<<"After Gap In first : "<<penAfterGapInFirst<<endl;
            //cout<<"After Gap In Second : "<<penAfterGapInSecond<<endl;
            //cout<<"Mismatch :"<<penMistmatch<<endl;
            pen[i][j]=getMaxOfThree(penAfterGapInFirst,penAfterGapInSecond,penMistmatch);
            cout<<"Selected : "<<pen[i][j]<<endl;
        }
        cout<<endl;
    }
    //print_2d_array(pen,this->first.length()+1,this->second.length()+1);
    printAllPenalties();
    reconstruct(first.length(),second.length());
    cout<<"First  : "<<opFirst<<endl<<"Second : "<<opSecond<<endl;
}

/** @brief
 *
 * @param
 * @param
 * @return
 *
 */
void SequenceAlignment::printAllPenalties() {
    Penalties::iterator rowsBegin=pen.begin();
    Penalties::iterator rowsEnd=pen.end();
    VectorInt::iterator columnsBegin,columnsEnd;

    while(rowsBegin != rowsEnd) {
        columnsBegin=(*rowsBegin).begin();
        columnsEnd=(*rowsBegin).end();
        while(columnsBegin != columnsEnd) {
            cout << *columnsBegin<<",";
            columnsBegin++;
        }
        cout<<endl;
        rowsBegin++;
    }
}

/** @brief
 *
 * @param
 * @param
 * @return
 *
 */
void SequenceAlignment::reconstruct(int i, int j) {
    if(i == 0 && j == 0) {
        return;
    } else {
        int valueForMatch,valueForMisMatch,valueForGap;
        cout<<"Penalties : "<<first[i-1]<<","<<second[j-1]<<endl;
        if(first[i-1] == second[j-1]) {
            valueForMatch=pen[i][j]-matchScore;
            if(valueForMatch == pen[i-1][j-1]) {
                opFirst.insert(0,1,first[i-1]);
                opSecond.insert(0,1,second[j-1]);
                cout<<"First  : "<<opFirst<<endl<<"Second : "<<opSecond<<endl;
                return reconstruct(i-1,j-1);
            }
        }
        valueForMisMatch=pen[i][j]-penaltyForMismatch;
        valueForGap=pen[i][j]-penaltyForGap;
        if(valueForMisMatch == pen[i-1][j-1]) {
            opFirst.insert(0,1,first[i-1]);
            opSecond.insert(0,1,second[j-1]);
            cout<<"First  : "<<opFirst<<endl<<"Second : "<<opSecond<<endl;
            return reconstruct(i-1,j-1);
        }
        if(valueForGap == pen[i-1][j]) {
            opFirst.insert(0,1,first[i-1]);
            opSecond.insert(0,1,'_');
            cout<<"First  : "<<opFirst<<endl<<"Second : "<<opSecond<<endl;
            return reconstruct(i-1,j);
        }
        if(valueForGap == pen[i][j-1]) {
            opFirst.insert(0,1,'_');
            opSecond.insert(0,1,second[j-1]);
            cout<<"First  : "<<opFirst<<endl<<"Second : "<<opSecond<<endl;
            return reconstruct(i,j-1);
        }

    }
}
