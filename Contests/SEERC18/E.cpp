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

const int MAXN = 212345;

int n, m;
ll k;
int s[MAXN];


int main (){
	scanf("%d%d%lld", &n, &m, &k);
    vector<tuple<ll, int, int>> ev;
	for(int a=0;a<n;a++){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        if(y > k) continue;
        ll sob = k - y;
        ev.pb({x-sob, 0, 0});
        ev.pb({x+sob, 2, 0});
	}
    for(int a=0;a<m;a++){
        ll x;
        scanf("%lld", &x);
        ev.pb({x, 1, a});
    }
    sort(ev.begin(), ev.end());
    int cnt = 0;
    vector<int> ans(m, 0);
    for(tuple<ll, int, int> tp: ev){
        ll x;
        int t, id;
        tie(x, t, id) = tp;
        if(t == 0){
            cnt++;    
        }
        else if(t == 1){
            ans[id] = cnt;
        }
        else
            cnt--;
    }
    for(int a=0;a<m;a++){
        printf("%d\n", ans[a]);
    }
}

