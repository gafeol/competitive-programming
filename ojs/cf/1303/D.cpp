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

int n, m;
ll k;

int main (){
    for_tests(t, tt){
        scanf("%lld%d", &k, &n);
        multiset<ll> s;
        ll sum = 0;
        for(int a=0;a<n;a++){
            ll x;
            scanf("%lld", &x);
            sum += x;
            s.insert(x);
        }
        int ans = 0;
        int i=0;
        int bit = 0;
        if(sum < k)
            goto falhou;
        sum = 0;
        while((1ll<<bit) <= k){
            while(!s.empty() && *s.begin() <= (1ll << bit)){
                sum += *s.begin();
                s.erase(s.begin());
                i++;
            }
            if((k>>bit)&1){
                if(sum >= (1ll<<bit)){
                    sum -= (1ll<<bit);
                    //printf("bit %d usa cred novo sum %lld\n", bit, sum);
                }
                else{
                    if(s.empty())
                        goto falhou;
                    else{
                        ll prox = *s.begin();
                        s.erase(s.begin());
                        int cus = 0;
                        while(prox > (1ll<<bit)){
                            cus++;
                            prox >>= 1;
                            s.insert(prox); 
                        }
                        ans +=  cus;
                        i++;
                    }
                }
            }
            bit++;
        }

        printf("%d\n", ans);
        continue;

falhou:
        puts("-1");
    }
}

