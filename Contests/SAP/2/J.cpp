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

const int MAXN = 1123456;

int n, m, k;
int h[MAXN];
int x[MAXN];
ll nw[MAXN];

int l[MAXN], r[MAXN];
int ind[MAXN];
int indx[MAXN];
set<pii> pos;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        ind[a] = a;
        indx[a] = a;
        scanf("%d%d", h+a, x+a);
	}
    sort(indx, indx+n, [&](int a, int b) { return x[a] < x[b]; } );
    stack<pii> st;
    for(int aa=0;aa<n;aa++){
        int a = indx[aa];
        while(!st.empty() && st.top().fst <= h[a])
            st.pop();
        if(st.empty())
            l[a] = n;
        else
            l[a] = st.top().snd;
        st.push({h[a], a});
    }
    while(!st.empty())
        st.pop();
    for(int aa=n-1;aa>=0;aa--){
        int a = indx[aa];
        while(!st.empty() && st.top().fst <= h[a])
            st.pop();
        if(st.empty())
            r[a] = n;
        else
            r[a] = st.top().snd;
        st.push({h[a], a});
    }

    sort(ind, ind+n, [&](int a, int b) { return h[a] < h[b]; } );
    ll  res = 0;
    for(int aa=0;aa<n;aa++){
        int a = ind[aa];
        nw[a] = mod(nw[a] + 1);
        //printf("nw %d %lld\n", a, nw[a]);
        if(l[a] == n && r[a] == n){
            res = mod(res + nw[a]);
        }
        else if(l[a] == n)
            nw[r[a]] = mod(nw[r[a]] + nw[a]);
        else if(r[a] == n)
            nw[l[a]] = mod(nw[l[a]] + nw[a]);
        else{
            nw[l[a]] = mod(nw[l[a]] + nw[a]);
            nw[r[a]] = mod(nw[r[a]] + nw[a]);
        }
    }
    printf("%lld\n", res);
}

