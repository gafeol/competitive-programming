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

int main (){
    for_tests(t, tt){
        int x;
        scanf("%d%d%d", &n, &x, &m);
        int l = x, r = x;
        for(int a=0;a<m;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            if(r < i || l > j)
                continue;
            l = min(l, i);
            r = max(r, j);
            //printf("l %d r %d\n", l, r);
        }
        printf("%d\n", r - l + 1);
    }
}

