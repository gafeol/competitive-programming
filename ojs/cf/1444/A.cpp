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
int mrk[MAXN];



int main (){
    vector<ll> pri;
    for(int a=2;a<MAXN;a++){
        if(!mrk[a])
            pri.pb(a);
        for(ll b=a;b*a <MAXN;b++)
            mrk[a*b] = 1;
    }
    for_tests(t, tt){
        ll p, q;
        scanf("%lld%lld", &p, &q);
        if(p%q == 0){
            vector<pair<ll, int>> f;
                     
            for(ll p: pri){
                int cnt = 0;
                while(q%p == 0){
                    q/= p;
                    cnt++;
                }
                if(cnt)
                    f.eb(p, cnt);
            }
            if(q != 1)
                f.eb(q, 1);

            ll op = p;
            ll res = 0;
            for(int i=0;i<f.size();i++){
                ll mnpri = f[i].fst;
                //printf("test %lld\n", mnpri);
                p = op;
                while(p%mnpri == 0)
                    p/=mnpri;
                f[i].snd--;
                while(f[i].snd>0){
                    p *= mnpri;
                    f[i].snd--;
                }
                res = max(res, p);
            }
            p = res;
        }
        printf("%lld\n", p);
    }
}

