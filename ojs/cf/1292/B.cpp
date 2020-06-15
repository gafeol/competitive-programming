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

const int MAXN = 71;

ll x[MAXN], y[MAXN];
ll xx, yy, t, ax, ay, bx, by;

int main (){
	scanf("%lld%lld%lld%lld%lld%lld", x, y, &ax, &ay, &bx, &by);
    scanf("%lld %lld %lld", &xx, &yy, &t);

    ll res =0;
    for(int i=0;;i++){
        if(i > 0){
            x[i] = x[i-1]*ax + bx;
            y[i] = y[i-1]*ay + by;
            if(x[i] - xx > t || y[i] - yy > t)
                break;
        }
        ll tt = 0;
        ll ans = 0;
        ll ux = xx, uy = yy;
        //printf("i %d \n", i);
        for(int j=i;j>=0;j--){
            if(tt + abs(x[j] - ux) + abs(y[j]-uy) <= t){
                //printf("pega o %d\n", j);
                tt += abs(x[j] - ux) + abs(y[j]-uy);
                ux = x[j];
                uy = y[j];
                ans++;
                //printf("tt %lld\n", tt);
            }
        }
        res = max(res, ans);    
    }
    for(int i=0;;i++){
        if(x[i] - xx > t || y[i] - yy > t)
            break;
        ll tt = abs(xx - x[i]) + abs(yy - y[i]) + 2ll*abs(x[i] - x[0]) + 2ll*abs(y[i] - y[0]);
        ll ans = i+1;
        for(int j=i+1;tt <= t;j++){
            if(tt + abs(x[j] - x[j-1]) + abs(y[j] - y[j-1]) <= t){
                tt +=abs(x[j] - x[j-1]) + abs(y[j] - y[j-1]); 
                ans++;
            }
            else
                break;
        }
        if(tt <= t){
            res = max(res, ans);
        }
    }
    printf("%lld\n", res);
}

