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

const int MAXS = 212;

int n, m, k, s;

int id;
map<string, int> ind;
string inv[MAXS];

int f[MAXS][MAXS];

int main (){
	scanf("%d%d%d", &s, &m, &n);
    vector<string> aux(s);
	for(int a=0;a<s;a++){
        cin >> aux[a];
    }
    sort(aux.begin(), aux.end());
    for(int a=0;a<s;a++){
        ind[aux[a]] = id;
        inv[id] = aux[a];
        id++;
	}
    for(int a=0;a<m;a++){
        char sp1[30], sp2[30];
        scanf(" %s %s", sp1, sp2);
        int i = ind[sp1], j = ind[sp2];
        f[i][j] = 1;
        f[j][i] = 1;
    }
    vector<int> v(n);
    vector<int> pos(s, -1);
    vector<int> deg(n,0);
    vector<vector<int>> adj(n);
    for(int a=0;a<n;a++){
        string st;
        cin >> st; 
        v[a] = ind[st];
        for(int sp=0;sp<s;sp++){
            if(f[v[a]][sp] || pos[sp] < 0) continue;
            adj[pos[sp]].pb(a);
            deg[a]++;
        }
        pos[v[a]] = a;
    }
    set<pii> q;
    for(int a=0;a<n;a++){
        if(deg[a]) continue;
        q.insert({v[a], a});
    }
    while(!q.empty()){
        pii top = *q.begin();
        q.erase(q.begin());
        cout << inv[top.fst] << " ";
        for(int nxt: adj[top.snd]){
            deg[nxt]--;
            if(deg[nxt] == 0)
                q.insert({v[nxt], nxt});
        }
    }
    puts("");
}

