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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123456;

int n, m, k;
int s[MAXN];

int mxmnr[MAXN], mnr[MAXN];
int mxl[MAXN];

int main (){
    int x;
	scanf("%d%d", &n, &x);
    set<int> q;
    memset(mnr, 0x3f3f3f3f, sizeof(mnr));
    int mx = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        mx = max(mx, s[a]);
        mxl[s[a]] = max(mxl[s[a]], mx);
    }
    for(int a=n-1;a>=0;a--){
        q.insert(s[a]);
        mnr[s[a]] = min(mnr[s[a]], *q.begin());
        auto it = q.lower_bound(s[a]);
        if(q.begin() != it){
            it--;
            mxmnr[s[a]] = max(mxmnr[s[a]], *it);
        }
    }
    ll res = 1;// delete everything
    int st = 1;
    for(st=1;st<x;st++){
        if(mnr[st] < st) break;
        res++;
        debug("conta 1 - %d\n", st);
    }
    st--;

    int end = x;

    int menordir = st;
    for(end=x;end>1;end--){
       if(mxl[end] > end) break;
       res++;
       debug("conta %d - %d\n", end, x);
       menordir = min(end-2, min(menordir, mnr[end]-1));
       debug("conta 1 - %d and %d - %d\n", menordir, end, x);
       res += max(0, menordir);
    }
    end++;

    if(end == 1 && st == x) // counted 1 - x twice
        res--;
    
    printf("%lld\n", res);
}

