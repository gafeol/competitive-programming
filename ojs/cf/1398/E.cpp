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
#define norm asdlsajad

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
ll ans = 0;

int chg;
multiset<ll, greater<ll>> dbl, norm;

multiset<ll> lig;

void add(ll x){
    norm.insert(x); 
    ans += x;
}

void rmv(ll x){
    if(norm.find(x) != norm.end()){
        norm.erase(norm.find(x));
        ans -= x;
        return;
    }
    dbl.erase(dbl.find(x));
    ans -= 2ll*x;
    chg++;
}

void balance(){
    while(chg < 0){
        ll sm = *dbl.rbegin(); 
        dbl.erase(dbl.find(sm));
        ans -= sm;
        norm.insert(sm);
        chg++;
    }
    while(chg > 0 && !norm.empty()){
        ll bg = *norm.begin();
        norm.erase(norm.begin());
        chg--;
        dbl.insert(bg);
        ans += bg;
    }

    while(!dbl.empty() && !norm.empty()){
        ll sm = *dbl.rbegin(); 
        ll bg = *norm.begin();
        if(sm < bg){
            ans += bg - sm;
            dbl.erase(dbl.find(sm));
            norm.erase(norm.find(bg));
            dbl.insert(bg);
            norm.insert(sm);
        }
        else
            break;
    }

    if(!lig.empty()){
        ll smLig = *lig.begin();
        if(norm.find(smLig) == norm.end()){
            if(!norm.empty()){
                //swapa
                ll bg = *norm.begin();
                norm.erase(norm.begin());
                ans += bg;
                dbl.insert(bg);
            }
            else //so troca
                chg++;
            dbl.erase(dbl.find(smLig));
            ans -= smLig;
            norm.insert(smLig);
        }

    }
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int t;
        scanf("%d", &t);
        ll x;
        scanf("%lld", &x);
        if(x < 0){
            x = -x;
            if(t == 1){
                chg--;
                lig.erase(lig.find(x));
            }
            rmv(x);
        }
        else{
            add(x);
            if(t == 1){
                chg++;
                lig.insert(x);
            }
        }

        balance();
        printf("%lld\n", ans);
	}
}

