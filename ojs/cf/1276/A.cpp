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

int n, m, k;
char s[MAXN];

int dp[MAXN][5][5];
map<char, int> val;
int ch[10];

int go(int i, int a, int b){
    int &r = dp[i][a][b];
    if(r != -1) return r;
    r = INT_MAX;
    if(i == n)
        return r = 0;
    
    r = min(r, 1+go(i+1, a, b));
    if((ch[a] != 'o' || ch[b] != 'n' || s[i] != 'e') &&
        (ch[a] != 't' || ch[b] != 'w' || s[i] != 'o'))
        r = min(r, go(i+1, b, val[s[i]]));
    return r;
}

void re(int i, int a, int b){
    int &r = dp[i][a][b];
    if(i == n)
        return ;
    
    if(r == 1 + go(i+1, a, b)){
        printf("%d ", i+1);
        return re(i+1, a, b);
    }
    else
        return re(i+1, b, val[s[i]]);
}


int main (){
    ch[0] = 0;
    val['o'] = 1;
    ch[1] = 'o';
    val['n'] = 2;
    ch[2] = 'n';
    val['t'] = 3;
    ch[3] = 't';
    val['w'] = 4;
    ch[4] = 'w';
    for_tests(t, tt){
        scanf(" %s", s);
        n = strlen(s);
        for(int a=0;a<=n;a++){
            for(int b=0;b<5;b++){
                for(int c=0;c<5;c++){
                    dp[a][b][c] = -1;
                }
            }
        }
        printf("%d\n", go(0, 0, 0)); 
        re(0, 0, 0);
        puts("");
    }
}

