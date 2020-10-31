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

const int MAXN = 1123456;

int n, m, k;

map<char, char> t;

bool trad(string s, char c = 'A'){
    if(s.empty()) return true;
    t[s[0]] = c;
    string nxt = "";
    bool ok = true;
    for(int i=0;i<s.size();i++){
        if(i%2 == 0 && s[i] != s[0])
            ok = false;
        if(i%2 == 1){ 
            if(s[i] == s[0])
                ok = false;
            nxt.push_back(s[i]);
        }
    }
    if(ok && trad(nxt, c+1)){
        return true;
    }
    if(s.size() > 1){
        t[s[1]] = c;
        nxt = "";
        ok = true;
        for(int i=0;i<s.size();i++){
            if(i%2 == 1 && s[i] != s[1])
                ok = false;
            if(i%2 == 0){ 
                if(s[i] == s[1])
                    ok = false;
                nxt.push_back(s[i]);
            }
        }
        if(ok && trad(nxt, c+1)){
            return true;
        }
    }
    return false;
}

int main (){
    char s[MAXN];
    scanf(" %s", s);
    n = strlen(s);
        
    if(!trad(s)){
        puts("No solution");
        return 0;
    }
    char mxc = 0;
    int pos = 0;
    for(int a=0;a<n;a++){
        s[a] = t[s[a]];
        mxc = max(mxc, s[a]);
        if(mxc == s[a])
            pos = a;
    }

    printf("%s\n", s);
    printf("%lld\n", (1ll<<(mxc-'A')-pos));
    return 0;
}

