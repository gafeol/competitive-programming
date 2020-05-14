#include <bits/stdc++.h>
using namespace std;

int root;

struct no {
    map<char, int> nxt;
    
    int next(char c){
        if(nxt.find(c) == nxt.end())
            return -1;
        return nxt[c];
    }
};

vector<no> trie;

int create(int u, char c){
    if(trie[u].next(c) == -1){
        trie[u].nxt[c] = trie.size();
        trie.push_back(no()); 
    }
    return trie[u].next(c);
}

void add(string s){ // adds string s to trie
     int u = root; 
     for(char c: s){
        u = create(u, c);
     }
}

void init(){
    trie.clear();
    trie.push_back(no());
    root = 0;
}


void print() { // prints the whole trie
    for(int i=0;i<trie.size();i++){
        printf("i %d nxt: ", i); 
        for(auto it: trie[i].nxt){
            printf("(%c %d) ", it.first, it.second); 
        }
        puts("");
    }
}

int main (){
    init();
}

