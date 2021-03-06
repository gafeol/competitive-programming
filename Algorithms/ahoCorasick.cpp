const int K = 26;
const char base = 'a'; // aresta vai ser char

struct Vertex {
    int next[K]; // arestas reais
    bool leaf = false;
    int cntLeaf = 0;
    int p = -1;
    char pch;
    int link = -1; // Calculado de forma lazy, tem que chamar get_link pra calcular
    int go[K]; // arestas reais + do automato
    int endLink = -1; // direto pro link que eh leaf mais proximo ou zero

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - base;
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].cntLeaf++;
}

int go(int v, char ch);

// So chamar depois que todas strings estiverem na trie
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0){
            t[v].link = 0;
            t[v].endLink = 0;
        }
        else{
            t[v].link = go(get_link(t[v].p), t[v].pch);
            get_link(t[v].link); // tem que chamar pra calcular o cntLeaf de la tambem antes
            t[v].cntLeaf += t[t[v].link].cntLeaf;
            t[v].endLink = (t[t[v].link].leaf ? t[v].link : t[t[v].link].endLink);
        }
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - base;
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 
