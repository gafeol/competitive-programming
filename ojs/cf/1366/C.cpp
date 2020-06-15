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

const int MAXN = 39;

int n, m, k;
int s[MAXN];
int M[MAXN][MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n,&m);
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf("%d", &M[a][b]);
            }
        }
        int som = 0;
        for(int d=0;d<=n+m-2;d++){
            int o = n+m-2-d;
            if(o <= d) break;
            int cnt[2];
            memset(cnt, 0, sizeof(cnt));
            for(int i=0;i<n;i++){
                int j = d - i;
                if(j < 0 || j >= m) continue;
                int ii = n-1 - i;
                int jj = m-1 - j;
                cnt[M[i][j]]++;
                cnt[M[ii][jj]]++;
            }
            som += min(cnt[0], cnt[1]);
        }
        printf("%d\n", som);
    }
}

