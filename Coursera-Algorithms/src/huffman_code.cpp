#include<huffman_code.h>
#include<algorithm>

/** \brief Functors for comarison of pairs to sort by highest value first
 *
 * \param
 * \param
 * \return
 *
 */
bool ComparePairs::operator()(const tree_pairs& first_item, const tree_pairs& second_item)  {
    tree_pairs::iterator it=first_item.begin();
    int first=0,second=0;
    while(it!=first_item.end()) {
        first+=it->second;
    }
    it=second_item.begin()
    while(it!=second_item.end()) {
        second+=it->second;
    }
    if(first<second) {
        return true;
    }
    return false;
}

void HuffmanCode::generateTree() {
    if(this->symbols.size() == 2) {
        return;
    } else {
        stable_sort(this->symbols.begin(),this->symbols.end(),ComparePairs());
        tree_pairs merged=mergeTwoSymbols(this->symbols[0],this->symbols[1]);
        //int combinedFrequency=this->tree[0].second+this->tree[1].second;
        vector<tree_pairs>::iterator start=this->symbols.begin();
        this->symbols.erase(start++);
        this->symbols.erase(start);
        this->symbols.push_back(merged);
        return generateTree();
    }
}

tree_pairs HuffmanCode::mergeTwoSymbols(tree_pairs first,tree_pairs second) {
    return tree_pairs();
}

/** \brief Constructor which initializes the map with given symbols and frequencies.
 *
 * \param vector of symbols.
 * \param vector of frequencies
 *
 */
HuffmanCode::HuffmanCode(vector<string> symbols, vector<int> freq) {
    this->symbols=map_symbols();
    this->binary_codes=map<string,string>();
    unsigned int i,j;
    for(i=0,j=0; i<symbols.size() && j<freq.size(); i++,j++) {
        this->symbols.push_back(tree<sym_freq>(make_pair(symbols[i],freq[i])));
        //this->symbols.push_back(make_pair(symbols[i],freq[i]));
    }
    //if freq not given assume as 0
    while(i != symbols.size()) {
        this->symbols.push_back(tree<sym_freq>(make_pair(symbols[i],0)));
        i++;
    }
    return;
}

/** \brief Used to generate huffman codes of given symbols.
 */

void HuffmanCode::generateBinaryCodes() {
    generateTree();
}


