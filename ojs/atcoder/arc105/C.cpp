#include "bits/stdc++.h"
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

ll d[MAXN];
ll w[MAXN];
ll l[MAXN], c[MAXN];
ll mrk[10][10];
ll res;

int main (){
    srand(time(NULL));
    clock_t clk = clock();
    res = LLONG_MAX;
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++)
        scanf("%lld", &w[a]);
    bool ok = true;
    for(int a=0;a<m;a++){
        scanf("%lld%lld", &l[a], &c[a]);
        for(int i=0;i<n;i++)
            if(c[a] < w[i])
                ok = false;
    }
    if(!ok){
        puts("-1");
        return 0;
    }
    vector<vector<ll>> rest;
    do{
        rest.clear();
        for(int a=0;a<n;a++){
            d[a] = 0;
            for(int b=a+1;b<n;b++){
                mrk[a][b] = 0;
            }
        }
        for(int a=0;a<m;a++){
            int i = 0, j = 0;
            ll sum = 0;
            while(i < n){
                //printf("i %d j %d sum %lld\n", i, j, sum);
                while(j < n && sum <= c[a]){
                    sum += w[j];
                    j++;
                }
                //printf("apos i %d j %d sum %lld\n", i, j, sum);
                if(sum <= c[a])
                    break;
                mrk[i][j-1] = max(mrk[i][j-1], l[a]);
                sum -= w[i];
                i++;
            }
        }
        for(int b=1;b<n;b++){
            for(int a=0;a<b;a++){
                if(mrk[a][b] == 0) continue;         
                rest.pb({a, b, mrk[a][b]});
            }
        }

        for(vector<ll> v: rest){
            ll l = v[2];
            int i = v[0], j = v[1];
            //printf("de i %d a j %d rest c %lld l %lld\n", i, j, c, l);
            ll sumd  =0;
            for(int a=i;a<j;a++)
                sumd += d[a];
            if(sumd >= l)
                continue;
            d[j-1] += l - sumd; 
            //printf("d[%d] += %lld\n", j-1, l - sumd);
        }
        ll ans = 0;
        for(int a=0;a<n;a++){
            ans += d[a];
        }
        //printf("%lld\n", ans);
        res = min(res, ans);
    //} while(next_permutation(w.begin(), w.end()));
        random_shuffle(w, w+n);
    } while(((double)clock() - clk)/CLOCKS_PER_SEC < 1.8);
    printf("%lld\n", res);
}
