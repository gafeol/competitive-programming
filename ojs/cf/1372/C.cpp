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
int s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        bool sorted = true;
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            if(s[a] != a+1)
                sorted = false;
        }
        if(sorted){
            puts("0");
            continue;
        }
        int pref = 0;
        while(pref < n && s[pref] == pref+1)
            pref++;
        int suf = n-1;
        while(suf >= 0 && s[suf] == suf+1)
            suf--;
        bool ok1 = true;
        for(int i=pref;i<=suf;i++){
            if(s[i] == i+1)
                ok1 = false;
        }
        if(ok1)
            puts("1");
        else
            puts("2");
    }
}

