#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int cross(int a, int b, int c){
    printf("2 %d %d %d\n", a, b, c);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main (){
	scanf("%d", &n);
    int o = 2;
    for(int t=3;t<=n;t++){
        printf("2 1 %d %d\n", o, t);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if(x < 0)
            o = t;
    }

    vector<pli> v;
    for(int t=2;t<=n;t++){
        if(t == o) continue;
        ll ar;
        printf("1 1 %d %d\n", o, t);
        fflush(stdout);
        scanf("%lld", &ar);
        v.pb({ar, t});
    }
    sort(v.begin(), v.end());
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(o);
    int far = v.back().snd;
    v.pop_back();
    for(pli x: v){
        if(cross(1, far, x.snd) > 0)
            dq.push_front(x.snd);
        else
            dq.push_back(x.snd);
    }
    dq.push_back(far);
    printf("0 ");
    vector<int> ans;
    bool ok = false;
    for(int x: dq){
        if(x == 1)
            ok = true;
        if(ok)
            ans.pb(x);
    }
    for(int x:dq){
        if(x == 1)
            ok = false;
        if(ok)
            ans.pb(x);
    }
    for(int x: ans)
        printf("%d ", x);
    puts("");
    fflush(stdout);
}

