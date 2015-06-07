#ifndef HUFFMAN_CODE_H_INCLUDED
#define HUFFMAN_CODE_H_INCLUDED
#endif // HUFFMAN_CODE_H_INCLUDED
#include<map>
#include<string>
#include<vector>
#include<utility>
#include "xinlin.hh"

using namespace std;
typedef pair<string,int> sym_freq;
typedef tree<sym_freq> tree_pairs;
typedef vector<tree_pairs> map_symbols;

struct ComparePairs {
// TODO (geek#1#): Make it public
    bool  operator()(const tree_pairs&,const tree_pairs&);
};
class HuffmanCode {
private :
    //stores name of symbols and their frequencies
    map_symbols symbols;
    map<string,string> binary_codes;
    tree_pairs mergeTwoSymbols(tree_pairs,tree_pairs);
    void generateTree();
public :
    HuffmanCode(vector<string>,vector<int>);
    void generateBinaryCodes();
};
