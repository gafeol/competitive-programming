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

const int MAXN = 2000006;

int n;
ll k;
int s[MAXN];


int m[2][MAXN];
int gt;
int dif;

vector<int> pos;
void put(int bit, int t){
    pos.pb(bit);
    m[t][bit]++; 
    if(m[t][bit] == k){
        m[t][bit] = 0;
        put(bit+1, t);
        return ;
    }

    if(dif == -1){
        dif = bit;
        gt = t;
    }
    else if(bit == dif){
        if(m[t][bit] == m[1-t][bit]){
            dif = -1;
        }
        else{
            gt = (m[t][bit] > m[1-t][bit] ? t : 1-t);
        }
    }
    else if(bit > dif){
        dif = bit;
        gt = (m[t][bit] > m[1-t][bit] ? t : 1-t);
        assert(gt == t);
    }
}

ll expo(ll base, ll e){
    if(e == 0)
        return 1;
    ll ans = expo(base, e/2);
    ans = mod(ans*ans);
    if(e&1)
        ans = mod(ans*base);
    return ans;
}

int main (){
    for_tests(t, tt){
        scanf("%d%lld", &n, &k);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
        }
        if(k == 1){
            printf("%d\n", (n&1));
            continue;
        }
        sort(s, s+n, greater<int>());
        pos.clear();
        gt = 1;
        dif = -1;
        for(int a=0;a<n;a++)
            put(s[a], 1-gt);  
        ll ans = 0;
        for(int a:pos){
            ll mul = m[gt][a] - m[1-gt][a];
            m[0][a] = m[1][a] = 0;
            if(mul != 0)
                ans = mod(ans + mod(mul*expo(k, a)));
        }
        ans = mod(ans + modn);
        printf("%lld\n", ans);
    }
}

