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

vector<ll> res;
int ans;

ll mul(ll a, ll b){
    if(log(a) + log(b) > 18*log(10))
        return 1e18;
    return a*b;
}

vector<ll> som(vector<ll> s, ll x, int bm){
    for(int i=0;i<3;i++){
        if(!(bm&(1<<i))) continue;
        ll &v = s[i];
        if(v == res[i]) continue;
        v = v + x;
    }
    return s;
}

vector<ll> mul(vector<ll> s, ll x, int bm){
    for(int i=0;i<3;i++){
        if(!(bm&(1<<i))) continue;
        ll &v = s[i];
        if(v == res[i]) continue;
        v = mul(v, x);
    }
    return s;
}

vector<int> divs;

void go(vector<ll> s, int d){
    bool eq = true;
    for(int a=0;a<3;a++){
        if(s[a] != res[a])
            eq = false;
    }
    if(eq){
        ans = min(ans, d);  
        return ;
    }
    if(d >= ans-1)
        return ;

    // single update
    for(int a=0;a<3;a++){
        for(int bm=1;bm<8;bm++){
            if(s[a] != res[a])
                go(som(s, res[a] - s[a], bm), d+1); 
            if(s[a] != 0){
                go(mul(s, res[a]/s[a], bm), d+1);
                go(mul(s, (res[a]+s[a]-1)/s[a], bm), d+1);
            }
        }
    }
    if(d == 0){
        //soma para algum divisor
        for(int a=0;a<3;a++){
            for(int di: divs){
                for(int bm=1;bm<8;bm++){
                    go(som(s, di - s[a], bm), d+1); 
                }
            }
        }

        for(int a=0;a<3;a++){
            for(int b=a+1;b<3;b++){
                if(res[a] - res[b] == 0 || ((res[b]*s[a] - res[a]*s[b])%(res[a] - res[b])) != 0) continue;
                int k = (res[b]*s[a] - res[a]*s[b])/(res[a] - res[b]);
                for(int bm=1;bm<8;bm++){
                    go(som(s, k, bm), d+1);
                }
            }
        }
        // mult pra um valor que somado um tanto em dois da res
        for(int a=0;a<3;a++){
            for(int b=a+1;b<3;b++){
                if(s[b] - s[a] == 0 || ((res[b] - res[a])%(s[b] - s[a])) != 0) continue;
                int k = (res[b] - res[a])/(s[b] - s[a]);  
                for(int bm=1;bm<8;bm++){
                    go(mul(s, k, bm), d+1);
                }
            }
        }
    }
}

int main (){
    vector<ll> s;
    for_tests(t, tt){
        s.clear();
        res.clear();
        divs.clear();
        for(int a=0;a<3;a++){
            ll x;
            scanf("%lld", &x);
            s.pb(x);
        }
        ans = 0;
        for(int a=0;a<3;a++){
            ll x;
            scanf("%lld", &x);
            res.pb(x);
            if(res[a] != s[a])
                ans++;
            for(int i=1;i<=sqrt(x)+1 && i <= x;i++){
                if(x%i == 0){
                    divs.pb(i);
                    divs.pb(-i);
                    divs.pb(x/i);
                    divs.pb(-x/i);
                }
            }
        }
        sort(divs.begin(), divs.end());
        divs.erase(unique(divs.begin(), divs.end()), divs.end());
        go(s, 0);
        printf("%d\n", ans);
    }
}
