#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1123456;
//                123456789
const int MAXX = 1000000009;
const int INF = INT_MAX;
ll n;
ll k, t;
int s[MAXN];



int main (){
	scanf("%lld%lld%lld", &n, &k, &t);
    ll ans = 0;
    t *= 2;
    if(t >= k){
        ans += (t/k)*(n*(n-1));
        t %= k;
    }
    int vai = -1;
    int v = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        int ate = s[a] + t;

        if(ate >= k){
            ate = ate%k;
            while(vai+1 < a && s[vai+1] <= ate)
                vai++;
        }
        ans += (vai + 1);
        //printf("a %d vai %d\n", a, vai);

        int volta = s[a] - t;
        while(v < a && s[v] < volta)
            v++;
        //printf("a %d volta %d\n", a, v);
        ans += a - v;
	}
    double res = ans/4.;
    printf("%.10f\n", res);
}

