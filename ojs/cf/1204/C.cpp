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

const int MAXN = 212, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];
int d[MAXN][MAXN];

int main (){
	scanf("%d", &n);
    memset(d, INF, sizeof(d));
    for(int a=1;a<=n;a++)
        d[a][a] = 0;
	for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            char c;
            scanf(" %c", &c);
            if(c == '1')
                d[a][b] =1;
        }
	}
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    scanf("%d", &m);
    vector<int> v(m);
    for(int a=0;a<m;a++){
        scanf("%d", &v[a]);
    }
    vector<int> ans;
    for(int a=0;a<m;){
        ans.pb(v[a]);
        int bd = 1;
        for(int nxt=1;nxt<=n;nxt++){
            if(nxt == v[a]) continue;
            //printf("A %d + d %d %d %d\n", a, v[a], nxt, d[v[a]][nxt]);
            int nxtp = a + d[v[a]][nxt];
            if(nxtp < m && v[nxtp] == nxt && bd <= d[v[a]][nxt]){
                bd = d[v[a]][nxt];
            }
        }
        a += bd;
    }
    printf("%d\n", (int)ans.size());
    for(int x:ans)
        printf("%d ", x);
    puts("");
}
