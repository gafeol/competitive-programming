#include "bits/stdc++.h"
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

const int MAXN = 1000009;

int n, m, k;
int s[MAXN];

int main (){
    int oc, oh, oo;
    for_tests(t, tt){
        int c, h, o;
        int ans = INT_MAX;

        auto check = [&] () { ans = min(ans, abs(c) + abs(h) + abs(o));};
        scanf("%d%d%d", &c, &h, &o);
        oc = c; oh = h; oo = o;
        ans = c + h + o;  
        for(int glu=0;glu<MAXN;glu++){
            c = oc; h = oh; o = oo;
           c -= glu*6;  o -= glu*6;
           h -= glu*12;
           if(h >= 2){
               int div = h/2;
               h -= div*2;
               o -= div;
           }
           if(o >= 2){
               int div = o/2;
               o -= div*2;
               c -= div;
           }
           check();
           h -= 2;
           o--;
           check();
           o -= 2;
           c--;
           check();
           h += 2;
           o++;
           check();
        }
        printf("%d\n", ans);
    }
    return 0;
}

