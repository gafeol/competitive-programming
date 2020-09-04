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


class StringsBetween{
    private:
        string base;
        int sz;
        ll dp[20][2];

        ll go(int i, int lo){
            ll &r = dp[i][lo];
            if(r != -1)
                return r;
            if(i == sz)
                return r = lo;
            r = lo;
            if(lo)
                r += 26*go(i+1, lo);
            else{
                if(i >= base.size())
                    return r = 0;
                if(i+1 < base.size())
                    r += 1;
                r += (base[i]-'a')*go(i+1, 1);
                r += go(i+1, 0);
            }
            return r;
        }
        ll sm(string s, int k){
            base = s;
            sz = k;
            memset(dp, -1, sizeof(dp));
            return go(0, 0);
        }

    public:
        ll count(int L, string A, string B){
            if(A == "")
                return sm(B, L);
            else
                return sm(B, L) - sm(A, L) - 1;
        }
};

int main (){
    for_tests(t,tt){
        int n;
        scanf("%d", &n);
        char s[300], ss[300];
        scanf("%s", s);
        scanf("%s", ss);
        StringsBetween sb;
        printf("%lld\n", sb.count(n, s, ss));
    }

}

