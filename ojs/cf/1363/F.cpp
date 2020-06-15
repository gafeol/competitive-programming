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
const int INF  = 0x3f3f3f3f;

int n, m, k;
char s[MAXN];
char ss[MAXN];
int sum[30][MAXN], summ[30][MAXN];
int dp[MAXN][MAXN];

int go(int i, int j){
    if(i < 0 || j < 0)
        return 0;
    int &r = dp[i][j];      
    if(r != -1)
        return r;
    r = INF;
    if(s[i] == ss[j])
        r = min(r, go(i-1, j-1));
    if(sum[ss[j]-'a'][i+1] > summ[ss[j]-'a'][j+1])
        r = min(r, go(i, j-1));
    r = min(r, go(i-1, j) + 1);
    return r;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<=n;a++)
            for(int b=0;b<=n;b++)
                dp[a][b] = -1;
        scanf(" %s", s);
        scanf(" %s", ss);
        for(int c = 0;c<26;c++){
            for(int a=n-1;a>=0;a--){
                sum[c][a] = sum[c][a+1] + (s[a] == 'a' + c);
                summ[c][a] = summ[c][a+1] + (ss[a] == 'a' + c);
            }
        }
        bool ok = true;
        for(int c=0;c<26;c++){
            if(sum[c][0] != summ[c][0]){
                ok = false;
            }
        }
        if(!ok){
            puts("-1");
            continue;
        }
        printf("%d\n", go(n-1, n-1));
    }
}

