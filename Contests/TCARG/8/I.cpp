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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
string M[10];
vector<int> id[10];

vector<int> adj[30];

int vi[] = {-1, -1, 0};
int vj[] = {-1,  1, 2};


bool valid(int i, int j){
    return (i >= 0 && j >= 0 && j < M[i].size() && M[i][j] == 'O');
}

int dp[(1<<21)];

int cnt;
int go(int bm){
    int &r = dp[bm];
    if(r != -1)
        return r;
    if(__builtin_popcount(bm) == 0)
        return r = 0;
    for(int u=0;u<cnt;u++){
        if(!(bm&(1<<u))) continue;
        for(int nbm: adj[u]){
            if((bm&nbm) != nbm) continue;
            r = max(r, 1-go(bm^nbm));
        }
    }
    return r;
}

int main (){
    IOS();
    cnt = 0;

    int state = 0;
    for(int i=0;i<5;i++){
        getline(cin, M[i]);
        id[i].resize(M[i].size(), 0);
        for(int j=0;j<M[i].size();j++){
            if(M[i][j] == 'O'){
                id[i][j] = cnt;
                state |= (1<<cnt);
                cnt++;
            }
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<M[i].size();j++){
            if(M[i][j] == 'O'){
                int u = id[i][j];
                int bm = (1<<u);
                adj[u].pb(bm);
                for(int d=0;d<3;d++){
                    bm = (1<<u);
                    int ni = i + vi[d];
                    int nj = j + vj[d];
                    while(valid(ni, nj)){
                        bm |= (1<< id[ni][nj]);
                        adj[u].pb(bm);
                        ni += vi[d];
                        nj += vj[d];
                    }
                }
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    if(go(state))
        puts("Karlsson");
    else
        puts("Lillebror");
}

