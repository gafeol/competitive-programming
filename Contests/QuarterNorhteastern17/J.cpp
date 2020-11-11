#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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
int s[2][MAXN];

ll sum[MAXN];

ll sq(ll x){
    return x*x;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", &s[0][a]);
	}
	for(int a=0;a<n;a++){
        scanf("%d", &s[1][a]);
	}
    
    for(int a=0;a<n;a++){
        if(a > 0) 
            sum[a] = sum[a-1];
        sum[a] += sq(s[1][a] - s[0][a]);
    }
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int i,j;
        scanf("%d%d", &i, &j);
        i--;j--;
        double res = sqrt(sum[j] - (i > 0 ? sum[i-1] : 0));
        printf("%.10lf\n", res);
    }

    return 0;
}

