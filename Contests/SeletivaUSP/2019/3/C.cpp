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

const int MAXN = 212345;


ll n;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

map<tuple<int, int, int, int>, int> cnt;

bool valid(int i, int j){
    return (i >= -100 && j >= -100 && i <= 100 && j <= 100);
}

ll raiz(ll x){
    return ll(sqrt(x) + 0.001);
}

int main (){
	scanf("%lld", &n);
    pii s[MAXN];
	for(int a=0;a<n;a++){
        int x, y;
        scanf("%d %d", &x, &y);
        s[a] = {x, y};
	}
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int p = s[i].fst - s[j].fst; 
            int q = s[i].snd - s[j].snd;
            int gc = gcd(abs(p), abs(q));
            p /= gc;
            q /= gc;
            if(p < 0) {
                p *= -1;
                q *= -1;
            }
            else if(p == 0){
                if(q < 0)
                    q *= -1;
            }
            pii rep = s[i];
            while(valid(rep.fst + p, rep.snd + q)){
                rep.fst += p;
                rep.snd += q;
            }

            cnt[{p, q, rep.fst, rep.snd}]++;
        }
    }
    ll res = (n*(n-1)*(n-2))/6;
    for(auto it: cnt){
        int val = it.snd;
        ll x = (1 + raiz(1+8*val))/2;
        res -= (x*(x-1)*(x-2))/6;
    }
    printf("%lld\n", res);
}

