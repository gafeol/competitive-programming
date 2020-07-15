#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
ll l, w;
vector<pll> s;

ll go(vector<pll> &s){
    vector<double> pos; // guarda xi de quem vai pra lua

    vector<ll> afasta;
    for(int a=0;a<s.size();a++){
        if(s[a].snd == 1){
            pos.pb(s[a].fst);
        }
        else
            afasta.pb(s[a].fst+l);
    }
    sort(pos.begin(), pos.end());

    ll ans = 0;
    for(ll x: afasta){
        if(x >= 0){
            ans += pos.size();
        }
        else{
            ll cruza =  0;  
                cruza = ((w+1)*x)/(w-1);
            if(cruza != ceil(((double)(w+1)*x)/(w-1))){
                printf(" %lld / %lld - cruza %lld ceil %lld\n", (w+1)*x, w-1, cruza, (ll)ceil(((double)(w+1)*x)/(w-1)));
                exit(0);
            }
            ans += lower_bound(pos.begin(), pos.end(), cruza) - pos.begin();
            debug("cara em %lld cruza em %lld com %d\n", x, cruza, (int)(lower_bound(pos.begin(), pos.end(), cruza) - pos.begin()));
        }
    }
    return ans;
}

int main (){
    scanf("%d%lld%lld", &n, &l, &w);
    ll goR = 0;
    ll goL = 0;
    ll ans = 0;
    if(w == 1){
        for(int a=0;a<n;a++){
            ll i, v;
            scanf("%lld%lld", &i, &v);
            if(v == 1 && i <= 0){
                if(i == 0 && w == 1)
                    continue;
                goR++;  
            }
            else if(v == -1 && i+l >= 0){
                if(i+l == 0 && w == 1)
                    continue;
                goL++;
            }
        }
        ans = goR*goL;
        debug("gor %lld gol %lld\n", goR, goL);
        printf("%lld\n", ans);
        return 0;
    }
    else{
        bool fdp1 = false;
        bool fdp2 = false;
        for(int a=0;a<n;a++){
            ll i, v;
            scanf("%lld%lld", &i, &v);
            s.pb({i, v});
            if(v == 1 && i+l < 0){
                goR++;  
            }
            else if(v == -1 && i > 0){
                goL++;
            }


            if(v == 1 && i+l == 0)
                fdp1 = true;
            if(v == -1 && i == 0)
                fdp2 = true;
        }
        ans = goR*goL + (fdp1 && fdp2);
    }
    vector<pll> left;
    vector<pll> right;
    for(int i=0;i<n;i++){
        if(s[i].fst <= 0 && s[i].fst + l >= 0){ // intersecta com a lua
            if(s[i].snd == 1)
                right.pb(s[i]);
            else
                left.pb(s[i]);
        }
        else{
            if(s[i].fst <= 0){
                left.pb(s[i]);
            }
            else
                right.pb(s[i]);
        }
    }

    /*
       debug("em left:\n");
       for(pll p: left){
       printf("(%lld %lld)\n", p.fst, p.snd);
       }
       */

    ans += go(left);
    debug("goLEFT %lld\n", go(left));

    /*
       debug("em right bef:\n");
       for(pll p: right){
       printf("(%lld %lld)\n", p.fst, p.snd);
       }
       */
    for(int a=0;a<right.size();a++)
        right[a] = {-(right[a].fst+l), -right[a].snd};
    debug("em right aft:\n");
    /*
       for(pll p: right){
       printf("(%lld %lld)\n", p.fst, p.snd);
       }
       */
    ans += go(right);
    debug("goRIGHT %lld\n", go(right));
    printf("%lld\n", ans);
}
