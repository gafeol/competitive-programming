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

vector<int> pos[MAXN];

int main (){
    scanf(" %s", s);
    n = strlen(s);
    for(int a=0;a<n;a++){
        pos[s[a]].pb(a);
    }
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        char pal[MAXN];
        scanf(" %s", pal);
        int sz = strlen(pal);
        int i = 0;
        bool ok = false;
        for(char c: pal){
            auto it = lower_bound(pos[c].begin(), pos[c].end(), i);
            if(it == pos[c].end())
                break;                  
            i = *it + 1;
            printf("%c", c);
            ok = true;
        }
        if(!ok)
            printf("IMPOSSIBLE");
        puts("");
    }
}

