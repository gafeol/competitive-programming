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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int rm[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
        }

        bool ok = true;
        int sub = 0;
        int ult = s[0];
        for(int a=1;a<n;a++){
            if(s[a] - sub > ult)
                sub  += (s[a] - sub) - ult;
            if(s[a] - sub < 0){
                ok = false; 
                break;
            }
            ult = s[a] - sub;
        }
        if(ok){
            puts("YES");
            continue;
        }
        ok = true;
        sub = 0;
        ult = s[n-1];
        for(int a=n-2;a>=0;a--){
            if(s[a] - sub > ult)
                sub  += (s[a] - sub) - ult;
            if(s[a] - sub < 0){
                ok = false; break;
            }
            ult = s[a] - sub;
        }
        if(ok){
            puts("YES");
            continue;
        }
        puts("NO");
    }
    return 0;
}

