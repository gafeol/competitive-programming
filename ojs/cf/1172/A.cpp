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
int s[MAXN], p[MAXN], pos[MAXN];
int has[MAXN];
int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        has[s[a]] = 1;
    }

    int mxDif = 0;
    for(int a=0;a<n;a++){
        scanf("%d", p+a);
        pos[p[a]] = a;
        if(p[a]){
            mxDif = max(mxDif, a - p[a] + 2);
            //printf("mxDif a %d p %d %d\n", a, p[a], a - p[a]+2);
        }
    }
    int ans = mxDif + n;
    if(has[1] == 0){
        int i=0;
        while(pos[1] + i + 1 < n && p[pos[1] + i + 1] == i+2){
            i++;
        }
        //printf("i %d pos[1] %d n %d\n", i, pos[1], n);
        int cnt = 0;
        if(pos[1] + i == n-1){
            bool ok = true;
            while(i+1 < n){
          //     printf("cnt %d i %d has[%d] %d\n", cnt, i, i+2, has[i+2]);
                if(!has[i+2]){
                    ok = false;
                    break;
                }
                has[p[cnt]] = 1;
                cnt++;
                i++;
            }
            if(ok){
           //     printf("pegou cnt %d\n", cnt);
                ans = cnt;
            }
        }
    }
    printf("%d\n", ans);
}

