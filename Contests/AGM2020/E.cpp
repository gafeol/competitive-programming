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

int MAGIC = 60;
const int SSIZE = 60;

int n, m, k;
int cnt[1123];

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a,a);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}

bool tle(clock_t c){
    return ((double)clock() - c)/CLOCKS_PER_SEC > 1.7;
}

int main (){
    clock_t clk = clock();
	scanf("%d%d", &n, &k);
    MAGIC = min(MAGIC, k);
    vector<int> s;
	for(int a=0;a<n;a++){
        int x;
        scanf("%d", &x);
        cnt[x]++;
        if(cnt[x] <= 2)
            s.pb(x);
	}
    sort(s.begin(), s.end(), greater<int>()); 
    if(s.size() > SSIZE)
        s.resize(SSIZE);

    ll ans = 0;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(tle(clk)) break;
            int oi = s[i], oj = s[j];              
            int div = k - MAGIC; 
            if(s[j] + div <= s[i])
                s[j] += div;
            else{
                int num = s[i] + s[j] + div;
                s[i] = (num+1)/2;
                s[j] = num/2;
            }

            for(int usa = MAGIC;usa>=0;usa--){
                for(int pri=usa;pri>=0;pri--){
                    int seg = usa - pri;
                    ans = max(ans, lcm(s[i] + pri, s[j] + seg));
                }
            }
            s[i] = oi;
            s[j] = oj;
        }
    }
    printf("%lld\n", ans);
}

