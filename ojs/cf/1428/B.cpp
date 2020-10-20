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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];
int ok[MAXN];


vector<int> adj[MAXN];


int main (){
    for_tests(t, tt){
        bool okd = true, oke = true;
        scanf("%d", &n);
        for(int a=0;a<n;a++)
            ok[a] = 0;
        for(int a=0;a<n;a++){
            int u = a;
            int v = (a+1)%n;
            char c;
            scanf(" %c", &c);
            if(c == '<'){
                okd = false;
            }
            if(c == '>'){
                oke = false;
            }
            if(c == '-'){
                ok[u] = 1;
                ok[v] = 1;
            }
        }
        if(okd || oke){
            printf("%d\n", n);
            continue;
        }
        int cnt = 0;
        for(int a=0;a<n;a++){
            cnt += ok[a];
        }
        printf("%d\n", cnt);
    }
}

