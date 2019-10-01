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

const int MAXB = 13, MAXZ = 112;

int pos[MAXB];
int nxt[MAXB][MAXZ];
int cnt[MAXZ];

int b, z;
ll res;

void go(int st){
    while(st--){
        for(int a=1;a<=z;a++){
            if(cnt[a] == b){
                printf("%d %lld\n", a, res);
                exit(0);
            }
            else if(cnt[a] > 0)
                break;
        }
        for(int a=1;a<=b;a++){
            cnt[pos[a]]--;
            pos[a] = nxt[a][pos[a]]; 
            cnt[pos[a]]++;
        }
        res++;
    }
}

int cycsz[MAXB], zno[MAXB][MAXZ];
vector<int> poss_zoo;

void dfs(int b, int u, int ini){
    zno[b][u] = cycsz[b]++; 
    if(nxt[b][u] != ini)
        dfs(b, nxt[b][u], ini);
}


void recon(){
    // discover cycsz, make inters, fill zno[beast][vert]
    for(int a=1;a<=b;a++){
        dfs(a, pos[a], pos[a]); 
    }
    for(int i=1;i<=z;i++){
        int aux = 0;
        for(int a=1;a<=b;a++)
            aux += (cnt[a] != -1);
        if(aux == b){
           poss.pb(i); 
        }
    }
}


void prep(int zoo, vector<int> &val, vector<int> &md){
    for(int bst=1;bst<=b;bst++){
        // x % cycsz[bst] == zno[bst][zoo]
        val.pb(zno[bst][zoo]);
        md.pb(cycsz[bst]);
    }
}

ll crt(vector<int> &val, vector<int> &md){


}

int main (){
    memset(zno, -1, sizeof(zno));
	scanf("%d%d", &b, &z);
	for(int a=1;a<=b;a++){
        scanf("%d", pos+a);
        cnt[pos[a]]++;
        for(int i=1;i<=z;i++){
            scanf("%d", &nxt[a][i]);
        }
	}
    go(100);
    recon();

    for(int zoo: poss_zoo){
        vector<int> val, md;
        prep(zoo, val, md);
    }
}


