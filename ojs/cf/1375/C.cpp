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

const int MAXN = 312345;

int n, m, k;
int s[MAXN], pos[MAXN];

int mxr[MAXN], mnl[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            pos[s[a]] = a;
            mnl[a] = s[a];
            if(a > 0)
                mnl[a] = min(mnl[a], mnl[a-1]);
        }
        for(int a=n-1;a>=0;a--){
            mxr[a] = s[a];
            if(a < n-1)
                mxr[a] = max(mxr[a], mxr[a+1]);
        }
        int mn = n;
        bool ok = true;
        for(int a=1;a<n;a++){
            mn = min(mn, pos[a]);     
            if(mn == n-a)
                ok = false;
        }

        int mx = 0;
        int from = s[0]-1;
        int ndeu = 0;
        while(from > 0){
            if(mxr[pos[from]] <= from){
                ndeu++;
                break;
            }
            from--;
        }

        from = s[n-1]+1;
        while(from < n+1){
            if(mnl[pos[from]] >= from){
                ndeu++;
                break;
            }
            from++;
        }
        if(ndeu == 2)
            ok = false;

        if(ok)
            puts("YES");
        else
            puts("NO");
    }
}

