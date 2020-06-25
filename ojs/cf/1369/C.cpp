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

int n, m, k;

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        vector<ll> s(n), w(m);

        for(int a=0;a<n;a++){
            scanf("%lld", &s[a]);
        }
        for(int a=0;a<m;a++)
            scanf("%lld", &w[a]);
        sort(s.begin(), s.end());
        sort(w.begin(), w.end(), greater<int>());
        int mx = n-1;
        int mn = 0;
        ll res = 0;
        while(!w.empty() && w.back() == 1){
            res += 2ll*s[mx];
            mx--;
            w.pop_back();
        }
        for(int a=0;a<w.size();a++){
            //printf("A %d mx %d mn %d\n", a, mx, mn);
            res += s[mx];
            w[a]--;
            mx--;
            if(w[a]){
                res += s[mn];
                mn++;
                w[a]--;
            }
            while(w[a]--)
                mn++;
        }
        printf("%lld\n", res);
    }
}

