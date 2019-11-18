#include <bits/stdc++.h>
using namespace std;
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
const int MAXN = 10004, MAXS = 109; 
int n, m, k;
int s[MAXN];
int dp[MAXN][MAXS][MAXS];
int mrk[MAXN][MAXS][MAXS];
int tempo;

int go(int i, int si, int sj){
    int j = n - 1 - (i-si) - sj;
    int &r = dp[i][si][sj];
    if(si + sj > 100)
        return r = 111;
    if(i >= j)
        return r = 0;
    if(mrk[i][si][sj] == tempo)
        return r;
    mrk[i][si][sj] = tempo;
    if(s[i] == s[j])
        r = go(i+1, si, sj);
    else
        r = 1 + min(go(i+1, si+1, sj), go(i, si, sj+1));
    return r;
}

int main (){
    for_tests(t, tt){
        tempo++;
        scanf("%d", &n);
        for(int a=0;a<n;a++)
            scanf("%d", s+a);
        printf("Sequence #%d: %d\n", tt, go(0, 0, 0));
    }
}

