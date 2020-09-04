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
char s[MAXN];
char ss[MAXN];

vector<int> pos[400];

int main (){
    for_tests(t, tt){
        for(int a='a';a<='z';a++)
            pos[a].clear();
        scanf(" %s", s);
        scanf(" %s", ss);
        n = strlen(s);
        for(int a=0;a<n;a++){
            pos[s[a]].pb(a);
        }

        int nn = strlen(ss);
        int u = 0;
        int ans = 1;
        for(int a=0;a<nn;a++){
            char c = ss[a];
            if(pos[c].empty()){
                ans = -1;
                break;
            }
            if(lower_bound(pos[c].begin(), pos[c].end(), u) == pos[c].end()){
                u = pos[c][0]+1;
                ans++;
            }
            else{
                u = *lower_bound(pos[c].begin(), pos[c].end(), u) + 1;
            }
        }
        printf("%d\n", ans);
    }
}

