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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];
int L[MAXN], R[MAXN];
int deg[MAXN];

int main (){
    scanf("%d%d", &n, &m);
    for(int a=0;a<=n;a++){
        L[a] = R[a] = -1;
        deg[a] = 0;
    }
    vector<pii> bad;
    for(int a=0;a<m;a++){
        int t, i, j;
        scanf("%d %d%d", &t, &i, &j);
        i--;j--;
        if(t == 0){
            bad.pb({i, j});
        }
        else{
            for(int u=i+1;u<=j;u++){
                L[u] = u-1;
            }
        }
    }
    queue<int> q;
    int val = n;
    vector<int> ans(n);
    for(pii p: bad){
        bool ok = false;
        for(int u=p.first+1;u<=p.second;u++){
            if(L[u] != u-1){
                R[u-1] = u;
                ok = true;
                break;
            }
        }
        if(!ok)
            goto falhou;
    }

    for(int a=0;a<n;a++){
        if(L[a] != -1)
            deg[L[a]]++;
        if(R[a] != -1)
            deg[R[a]]++;
    }

    for(int a=0;a<n;a++)
        if(deg[a] == 0)
            q.push(a);
    while(!q.empty()){
        int u = q.front();
        ans[u] = val;
        val--;
        q.pop();
        if(L[u] != -1){
            deg[L[u]]--;
            if(deg[L[u]] == 0)
                q.push(L[u]);
        }
        if(R[u] != -1){
            deg[R[u]]--;
            if(deg[R[u]] == 0)
                q.push(R[u]);
        }
    }
    if(val == 0){
        puts("YES");
        for(int a=0;a<n;a++)
            printf("%d ", ans[a]);
        puts("");
        return 0;
    }
falhou:
    puts("NO");
}

