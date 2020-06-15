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

int mrk[MAXN], tempo;
int d[MAXN];
int cnt[MAXN];

int main (){
    int x, y;
	scanf("%d%d%d", &n, &x, &y);
    for(int ini=1;ini<=n;ini++){
        queue<int> q; 
        q.push(ini);
        d[ini] = 0;
        tempo++;
        mrk[ini] = tempo;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt[d[u]]++;
            if(u+1 <= n && mrk[u+1] != tempo){
                q.push(u+1);
                d[u+1] = d[u] + 1;
                mrk[u+1] = tempo;
            }
            if(u-1 >= 1 && mrk[u-1] != tempo){
                q.push(u-1);
                d[u-1] = d[u] + 1;
                mrk[u-1] = tempo;
            }
            int nxt = -1;
            if(u == x)
                nxt = y;
            if(u == y)
                nxt = x;
            if(nxt != -1 && mrk[nxt] != tempo){
                q.push(nxt);
                mrk[nxt]  = tempo;
                d[nxt] = d[u] + 1;
            }
        }
    }
    for(int a=1;a<n;a++){
        printf("%d\n", cnt[a]/2);
    }
}

