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

const int MAXN = 212345;

int n, m, k;
deque<int> s;

pii ans[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        int x;
        scanf("%d", &x);
        s.push_back(x);
	}
    for(int i=0;i<n;i++){
        int f1 = s.front();
        s.pop_front();
        int f2 = s.front();
        s.pop_front();
        ans[i] = {f1, f2};
        s.push_front(max(f1, f2));
        s.push_back(min(f1, f2));
    }

    for(int a=0;a<m;a++){
        ll i;
        scanf("%lld", &i);
        i--;
        if(i < n)
            printf("%d %d\n", ans[i].fst, ans[i].snd);
        else{
            i -= n;
            int o = i%(n-1ll) + 1;
            //printf("o %d\n", o);
            printf("%d %d\n", s.front(), s[o]);
        }

    }
}

