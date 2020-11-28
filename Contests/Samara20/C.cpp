#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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
 
int mn = 0;
const int mx = 100009;
const int N = mx;

int tree[4*mx];
 
int t[N<<1];

void modify(int pos, int val, int n = N) {
	for(t[pos += n] += val; pos != 1; pos>>=1)
		t[pos>>1] = (t[pos] + t[pos^1]);
}

int query(int l, int r, int n=N) { // [l, r)
	int resp = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) resp = (resp + t[l++]);
		if (r&1) resp = (resp + t[--r]);
	}
	return resp;
}

int n;
ll k;
vector<pii> s;
vector<int> yc;
int main (){
	scanf("%d%lld", &n, &k);
    vector<int> Y;
	for(int a=0;a<n;a++){
        int x, y;
        scanf("%d%d", &x, &y);
        Y.pb(x - y);
        s.pb({x+y, x-y});
	}
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    for(int a=0;a<n;a++)
        yc.pb(lower_bound(Y.begin(), Y.end(), s[a].snd) - Y.begin());
    int i = 0, j = 400000009;
    while(i < j){
        int m = (i + j)/2;
        ll sum = 0;
        map<int, vector<pair<int, int>>> ev;
        for(int a=0;a<n;a++){
            ev[s[a].fst - m].eb(0, a);
            ev[s[a].fst].eb(1, a);
        }
        for(auto [x, v]: ev){
            sort(v.begin(), v.end());
            for(auto [t, i] : v){
                if(t == 0){
                    modify(yc[i], 1);
                }
                else if(t == 1){
                    modify(yc[i], -1);
                    int l = lower_bound(Y.begin(), Y.end(), s[i].snd-m) - Y.begin();
                    int r = upper_bound(Y.begin(), Y.end(), s[i].snd+m) - Y.begin() - 1;
                    int val = query(l, r+1);
                    sum += val;
                    //printf("i %d alcanca %d\n", i, val);
                }
            }
        }
        //printf("i %d j %d m %d sum %lld\n", i, j, m, sum);
        if(sum >= k) j = m;
        else i = m+1;
    }
    printf("%d\n", i);
    return 0;
}
 
