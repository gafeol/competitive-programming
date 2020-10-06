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

const int MAXN = 1000006;

int n, m, k;
int ans[MAXN];
int mrk[MAXN];
queue<int> q;

int main (){
    for(int a=2;a<MAXN;a++){
        if(mrk[a]) continue;
        for(ll b=a;a*b < MAXN;b++)
            mrk[a*b] = 1;
    }
    ans[1] = 1;
    for(int a=2;a<MAXN;a++){
        if(!mrk[a])
            q.push(a);
        ll x = q.front();
        if(a >= x*x){
            q.pop();
        }
        ans[a] = 1 + q.size();
    }
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
	}
}

