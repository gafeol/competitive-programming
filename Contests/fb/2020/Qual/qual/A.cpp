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

const int MAXN = 55;

int n, m, k;
char in[MAXN], out[MAXN];

int adj[MAXN][MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        scanf(" %s", in);
        scanf(" %s", out);
        memset(adj, 0, sizeof(adj));
        for(int i=0;i+1<n;i++){
           if(in[i+1] == 'Y' && out[i] == 'Y')
               adj[i][i+1] = 1;
           if(out[i+1] == 'Y' && in[i] == 'Y')
                adj[i+1][i] = 1;
        }

        for(int a=0;a<n;a++){
            adj[a][a] = true;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k] && adj[k][j])
                        adj[i][j] = true;
                }
            }
        }
        printf("Case #%d: \n", tt);
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                printf("%c", (adj[a][b] ? 'Y' : 'N'));
            }
            puts("");
        }
    }
}

