#include "huffman_code.h"
#include <vector>
using namespace std;

void huffman_code_test(){
    vector<string> sym={"A","B","C","D","E","F"};
    vector<int> freq={3,2,6,8,2,6};
    HuffmanCode h=HuffmanCode(sym,freq);
    h.generateBinaryCodes();
}
