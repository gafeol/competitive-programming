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
int s[MAXN];

int mn[MAXN];

int main (){
    for_tests(t, tt){

        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
        }
        s[n] = INT_MAX;
        mn[n] = n;
        for(int a=n-1;a>=0;a--){
            mn[a] = mn[a+1];
            if(s[a] < s[mn[a]])
                mn[a] = a;
        }
        bool ok = false;
        int men = 0;
        tuple<int, int, int> ans;
        for(int a=1;a<n;a++){
            if(s[a] < s[men])
                men = a;
            if(s[a] > s[men] && s[a] > s[mn[a]]){
                ans = {men, a, mn[a]};
                ok = true;
                break;
            }
        }

        if(ok){
            puts("YES");
            printf("%d %d %d\n", get<0>(ans)+1, get<1>(ans)+1, 1+get<2>(ans));
        }
        else
            puts("NO");
    }
}

