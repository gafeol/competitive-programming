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

int n, m, k;
const int MBIT = 3;

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        printf("1 %d\n", (1<<MBIT));
        fflush(stdout);
        ll base;
        scanf("%lld", &base);
        if(base == -1)
            return 0;
        base -= (1<<MBIT)*((ll)n);
        ll tot = 0;
        ll res = 0;
        ll sub = 0;
        for(int bit=0;bit<MBIT-1;bit++){
            int x = (1<<bit);
            printf("1 %d\n", x);
            fflush(stdout);
            ll soma;
            scanf("%lld", &soma);
            if(soma == -1)
                return 0;
            int n0 = ((soma - base)/x + n)/2;
            int n1 = n - n0;
            //printf("bit %d n0 %d n1 %d\n", bit, n0, n1);
            sub += n1*((ll)x);
            res += x*(n1&1);
        }

        int x = (1<<MBIT-1);
        int n1 = (base - sub)/x;
        res += x*(n1&1);
        printf("2 %lld\n", res);
        fflush(stdout);
        int v;
        scanf("%d", &v);
        if(v == -1)
            return 0;
    }
}

