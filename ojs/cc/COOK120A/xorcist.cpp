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

const int MAXN = 500005;

int n, m, k;
int s[MAXN];

int bit[30][MAXN];

void upd(int b, int i){
    i += 2;
    while(i < MAXN){
        bit[b][i]++;
        i += (i&-i);
    }
}

int qry(int b, int i){
    i += 2;
    int ans = 0;
    while(i > 0){
        ans += bit[b][i];  
        i -= (i&-i);
    }
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++){
            for(int b=0;b<30;b++){
                bit[b][a] = 0;
            }
        }
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            for(int b=29;b>=0;b--){
                if((s[a]&(1<<b))){
                    upd(b, a);
                    break;
                }
            }
        }
        for(int a=0;a<m;a++){
            int l, r;
            scanf("%d%d", &l, &r);
            l--;
            r--;
            int tot = r - l + 1;
            ll ans = 0;
            for(int b=29;b>=0;b--){
                int q = qry(b, r) - qry(b, l-1); 
                printf("com bit %d tenho %d caras de l %d a r %d\n", b, q, l, r);
                tot -= q;
                printf("tot %d\n", tot);
                ans += ((ll)q)*tot;
            }
            printf("%lld\n", ans);
        }
    }

}
