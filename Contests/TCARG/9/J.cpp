#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, char> plc;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000009;
const ll p =    1000000007;
const ll p2 = 927513371;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
ll valc[MAXN];

vector<plc> s, ss;

bool in(plc p, plc pp){
    return (p.snd == pp.snd && p.fst <= pp.fst);
}

ll val(plc p){
    return mod(valc[p.snd]*mod(p.fst*p2));
}

int main (){
    srand(time(NULL));
    for(int a='a';a<='z';a++)
        valc[a] = rand();
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        ll q;
        char c;
        scanf("%lld-%c", &q, &c);
        if(!s.empty() && s.back().snd == c)
            s[s.size()-1].fst += q;
        else
            s.pb({q, c});
	}
    for(int a=0;a<m;a++){
        ll q;
        char c;
        scanf("%lld-%c", &q, &c);
        if(!ss.empty() && ss.back().snd == c)
            ss[ss.size()-1].fst += q;
        else
            ss.pb({q, c});
	}
    if(s.size() < ss.size()){
        puts("0");
        return 0;
    }
    if(ss.size() == 1){
        ll ans = 0;
        for(plc p: s){
            if(in(ss[0], p))
                ans += p.fst - ss[0].fst + 1; 
        }
        printf("%lld\n", ans);
    }
    else if(ss.size() == 2){
        ll ans = 0; 
        for(int i=0;i<s.size()-1;i++){
            ans += (in(ss[0], s[i]) && in(ss[1], s[i+1]));
        }
        printf("%lld\n", ans);
    }
    else{
        int ans = 0;
        ll h = 0;
        ll pot = 1;
        for(int a=0;a<ss.size()-3;a++)
            pot = mod(pot*p);
        for(int a=1;a+1<ss.size();a++){
            h = mod(h*p);
            h = mod(h + val(ss[a]));
        }

        ll hx = 0;
        for(int a=1;a+1<ss.size();a++){
            hx = mod(hx*p);    
            hx = mod(hx + val(s[a]));
        }

        int i = 1, j = ss.size()-2;
        while(j < s.size()-1){
            if(hx == h && in(ss[0], s[i-1]) && in(ss.back(), s[j+1]))
                ans++;
            hx = mod(hx - pot*val(s[i]));
            hx = mod(modn + hx);
            hx = mod(hx*p);
            hx = mod(hx + val(s[j+1]));
            i++;j++;
        }
        printf("%d\n", ans);
    }
}

