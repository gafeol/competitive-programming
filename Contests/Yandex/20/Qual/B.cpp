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
const int INF = 0x3f3f3f3f;

int n, m, k;
char  s[MAXN];

int d[MAXN][2][2];


int main (){
    scanf("%[^\n]", s);
    n = strlen(s);
    int i = 0, st = 0, sh = 0;
    memset(d, INF, sizeof(d));
    set<tuple<int, int, int, int>> q;
    d[i][st][sh] = 0;
    q.insert({0, i, st, sh});

    int ans = INF;
    while(!q.empty()){
        tie(ignore, i, st, sh) = *q.begin();
        q.erase(q.begin());
        if(i == n){
            ans = min(ans, d[i][st][sh]);
            continue;
        }
            
        vector<tuple<int, int, int>> adj;

        if(s[i] == ' ')
            adj.pb({i+1, st, 0});
        if(sh)
            adj.pb({i, 1-st, 0}); 
        else
            adj.pb({i, st, 1});
        if(st == 0){
            if((islower(s[i]) && !sh) || (isupper(s[i]) && sh))
                adj.pb({i+1, st, 0});
        }
        else if(st == 1){
            if((isupper(s[i]) && !sh) || (islower(s[i]) && sh))
                adj.pb({i+1, st, 0});
        }

        for(auto [ni, nst, nsh]: adj){
            if(d[ni][nst][nsh] > d[i][st][sh] + 1){
                if(d[ni][nst][nsh] != INF)
                    q.erase({d[ni][nst][nsh], ni, nst, nsh});
                d[ni][nst][nsh] = 1 + d[i][st][sh];
                q.insert({d[ni][nst][nsh], ni, nst, nsh});
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

