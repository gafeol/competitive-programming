#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
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

const int MAXN = 412345;

int n, m, k;
int s[MAXN];

struct ed{
    int u;
    int id;
};

int mrk[MAXN];
vector<ed> adj[MAXN];
int ind[MAXN], oud[MAXN];

vector<pcc> v;

map<pcc, int> idd;
pcc ret[MAXN];
int ini[MAXN];

queue<int> aux_path;
stack<int> final_path;

void euler_path(int u){
    aux_path.push(u);
    while(ini[u] < adj[u].size()){
        ed e =  adj[u][ini[u]];
        ini[u]++;
        euler_path(e.u); 
    }
    final_path.push(u);
}



int main (){
    scanf("%d", &n);
    int deg = 0, degu=0;
    for(int a=0;a<n;a++){
        char i, j, k;
        scanf(" %c%c%c", &i, &j, &k);
        if(idd.find({i, j}) == idd.end()){
            ret[degu] = {i, j};
            idd[{i, j}] = degu++;
        }
        if(idd.find({j, k}) == idd.end()){
            ret[degu] = {j, k};
            idd[{j, k}] = degu++;
        }

        int id1 = idd[{i, j}], id2 = idd[{j, k}];
        adj[id1].pb({id2, deg++});
        oud[id1]++;
        ind[id2]++;
    }

    vector<int> odd;
    bool ok = true;
    for(int u=0;u<degu;u++){
        ok &= (abs(ind[u] - oud[u]) <= 1);
        if(ind[u] != oud[u])
            odd.pb(u);
    }
    ok &= (odd.size() <= 2);
    if(odd.size() == 2)
        ok &= (ind[odd[0]] - oud[odd[0]] + ind[odd[1]] - oud[odd[1]] == 0);

    if(!ok){
        puts("NO");
        return 0;
    }

    if(odd.size() == 2){
        if(oud[odd[0]] < ind[odd[0]])
            swap(odd[0], odd[1]);
        // start is odd[0]
        euler_path(odd[0]);
    }
    else
        euler_path(0);
    
    if(final_path.size() == n+1){
        puts("YES");
        printf("%c", ret[final_path.top()].first);
        while(final_path.size()){
            printf("%c", ret[final_path.top()].snd);
            final_path.pop();
        }
        puts("");
    }
    else
        puts("NO");
}

