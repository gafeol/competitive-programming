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

const int MAXN = 1123456, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];
deque<int> o, np;
int dp[MAXN][2];

int go(int i, int t){
    int &r = dp[i][t];
    if(r != INF)
        return r;
    r = INF + 1;
    if(i == o.size())
        return r = 0;
    if(t){
        r = min(r, go(i+1, 0));
    }
    else{

        if(np[i] > 1)
            r = min(r, go(i, 1));
        if(i + 1  < o.size())
            r = min(r, go(i+1, 1) + (o[i+1]-o[i])*np[i]);
    }
    if(i + 1 < o.size())
        r = min(r, go(i+2, 0) + (o[i+1]-o[i])*np[i+1]);
    return r;
}

void zera(){
    for(int a=0;a<=o.size();a++){
        for(int t=0;t<2;t++){
            dp[a][t] = INF;
        }
    }
}

int main (){
    for_tests(t, tt){
        o.clear();
        np.clear();
        scanf("%d", &n);
        int bef = -1000000;
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            if(s[a]){
                np.pb(1);
                o.pb(a);
            }
        }
        if(o.empty()){
            puts("0");
            continue;
        }
        if(o.size() == 1){
            puts("-1");
            continue;
        }
        deque<int> ori = o;
        deque<int> onp = np;
        zera();
        int ans = go(0,0);

        int cus = n - ori.back() + ori[0];
        o = ori;
        np = onp;
        o.pop_back();
        np.pop_back();
        np[0]++;
        zera();
        ans = min(ans, go(0, 0) + cus);

        o = ori;
        np = onp;
        o.pop_front();
        np.pop_front();
        np[np.size()-1]++;
        zera();
        ans = min(ans, go(0, 0) + cus);
        if(ans < INF)
            printf("%d\n", ans);
        else
            puts("-1");
    }
}

