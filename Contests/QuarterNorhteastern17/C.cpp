#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

int n, m, k, t;
unordered_map<bitset<101>, bool> vis;
int s[MAXN];
bitset<101> state;

vector<bitset<101>> ans;

bitset<101> u;

void dfs(){
    vis[u] = true;
    ans.pb(u);
    //printf("ans %d\n", ans.size());
    if((int)ans.size() == t) return ;
    for(int i=n-1;i>=0;i--){
        if(!u[i]) continue;
        for(int j=n-1;j>=0;j--){
            if(u[j]) continue;
            u[i] = 0; u[j] = 1;
            if(vis.find(u) == vis.end()){
                dfs(); 
                return ; // tem que achar um caminho so 
            }
            u[i] = 1;u[j] = 0;
        }
    }
}

int main (){
	scanf("%d%d%d", &n, &k, &t);
    for(int a=0;a<k;a++)
        u[a] = 1;
    dfs();

    if(ans.size() < t){
        puts("0");
    }
    else{
        printf("%d\n", ans.size());
        for(auto v: ans){
            for(int i=0;i<n;i++){
                if(v[i])
                    printf("%d ", i+1);
            }
            puts("");
        }
    }
    return 0;
}
