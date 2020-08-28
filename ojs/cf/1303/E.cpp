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

const int MAXN = 402;

char s[MAXN], obj[MAXN];
int n, no;

short dp[MAXN][MAXN][MAXN];

short go(int i, int s1, int s2){
    short &r = dp[i][s1][s2];
    if(r != -1)
        return r;
    if(i == n){
        if(s2 < no)
            r = -2;
        else
            r = s1;
        return r;
    }
    r = -2;
    r = max(r, go(i+1, s1, s2));
    if(s1 < s2 && s[i] == obj[s1])
        r = max(r, go(i+1, s1+1, s2));
    if(s2 < no && s[i] == obj[s2])
        r = max(r, go(i+1, s1, s2+1));
    return r;
}

int main (){
    for_tests(t, tt){
        scanf(" %s", s);
        scanf(" %s", obj);
        n = strlen(s);
        no = strlen(obj);
        for(int a=0;a<=n;a++){
            for(int b=0;b<=no;b++){
               for(int c=0;c<=no;c++){
                    dp[a][b][c] = -1;
               }
            }
        }
        bool ok = false;
        for(int div=0;div<=no;div++){
            if(go(0, 0, div) >= div){
                ok = true;
                break;
            }
        }
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
}

