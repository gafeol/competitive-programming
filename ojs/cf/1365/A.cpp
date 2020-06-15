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

const int MAXN = 215;

int n, m, k;
int mrkl[MAXN];
int mrkc[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<max(n, m);a++){
            mrkl[a] = mrkc[a] = 0;
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                int x;
                scanf("%d", &x);
                if(x){
                    mrkl[a] = 1;
                    mrkc[b] = 1;
                }
            }
        }
        int ans = 0, res = INT_MAX;
        for(int a=0;a<n;a++){
            ans += (!mrkl[a]);
        }
        res = ans;
        ans = 0;
        for(int a=0;a<m;a++)
            ans += (!mrkc[a]);
        res = min(res, ans);
        if(res&1)
            puts("Ashish");
        else
            puts("Vivek");
    }
}

