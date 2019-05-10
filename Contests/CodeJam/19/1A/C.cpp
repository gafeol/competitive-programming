#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

struct node {
    unordered_map<char, int> adj;
    int cnt;

    node() {
        cnt = 0;
    }


};

vector<node> nodes;

int next(int u, char c){
    if(nodes[u].adj.find(c) == nodes[u].adj.end()){
        nodes[u].adj[c] = nodes.size();
        nodes.pb({});
    }
    return nodes[u].adj[c];
}

void add(string str){
    reverse(str.begin(), str.end());
    int u = 0;
    int i = 0;
    while(i < str.size()){
        u = next(u, str[i]);
        i++;
    }
    nodes[u].cnt++;
}

int go(int u){
    int sum = 0;
    int sob = 0;
    for(auto it: nodes[u].adj){
        sum += go(it.snd);
        nodes[u].cnt += nodes[it.snd].cnt;
    }
    if(u != 0 && nodes[u].cnt >= 2){
        sum += 2;
        nodes[u].cnt-=2;
    }
    return sum;
}

int main (){
    for_tests(t, tt){
        nodes.clear();
        nodes.pb({});
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            char str[55];
            scanf(" %s", str);
            add(str);
        }

        printf("Case #%d: %d\n", tt, go(0));
    }
}

