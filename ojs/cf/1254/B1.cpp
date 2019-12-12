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

int n, m, k;
int s[MAXN];

ll solve(int k){
    ll cnt = 0, ans = 0;
    for(int a=0;a<n;a++){
        ans+=cnt;
        cnt += s[a];
        if(cnt == (k+1)/2){
            ll aux = k - cnt;
            do{
                if(aux == 0) break;
                a++;
                ans += aux;
                aux -= s[a];
            }while(aux > 0);
            cnt = 0;
        }
    }
    return ans;
}

int main (){
    int sum=0; 
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        sum += s[a];
	}
    if(sum == 1){
        puts("-1");
        return 0;
    }
    ll res = LLONG_MAX;
    for(int k=2;k<=sum;k++){
        if(sum%k == 0)
            res = min(res, solve(k));
    }
    
    printf("%lld\n", res);
}

