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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

int val[] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123}; 

int dp[MAXN][MAXN];

bool valid(int x, int y){
    return ((x&y) == x);
}

int cus(int x, int y){
    assert(valid(x, y));
    return __builtin_popcount(x^y);
}

int go(int i, int k){
    if(k < 0)
        return 0;
    int &r = dp[i][k];
    if(i == n)
        return r = (k == 0);
    if(r != -1)
        return r;
    r = 0;
    for(int a=9;a>=0;a--){
        if(!valid(s[i], val[a])) continue;
        r = max(r, go(i+1, k-cus(s[i], val[a]))); 
    }
    return r;
}

void re(int i, int k){
    if(i == n)
        return ;
    for(int a=9;a>=0;a--){
        if(!valid(s[i], val[a])) continue;
        if(go(i+1, k-cus(s[i], val[a])) == 1){
            printf("%d", a);
            return re(i+1, k-cus(s[i], val[a]));
        }
    }
}


int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
        char c;
        int ans = 0;
        for(int i=0;i<7;i++){
            scanf(" %c", &c);
            ans *= 2;
            ans += (c - '0');
        }
        s[a] = ans; 
	}
    memset(dp, -1, sizeof(dp));
    if(go(0, k)){
        re(0, k);
        puts("");
    }
    else
        puts("-1");
}

