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
char s[210];

int ind[500];
char ch[30];

vector<pair<int, int> > mk[500];

int cus[30][30];
bool beg = true;

long long dp[210][210][30];

long long go(int i, int j, int c){
    if(i == j){
        if(ind[s[i]] != c)
            return INT_MAX;
        else return 0;
    }

    long long &r = dp[i][j][c];
    if(r != -1)
        return r;

    r = INT_MAX;

    for(pii p: mk[c]){
        for(int m=i;m<j;m++){
            r = min(r, go(i, m, p.fst) + go(m+1, j, p.snd) + cus[p.fst][p.snd]);
        }
    }
    return r;
}

int main (){
    beg = true;
    while(scanf("%d", &k) != EOF && k){
        if(!beg){
            puts("");
        }
        beg = false;
        for(int a=0;a<=k;a++)
            mk[a].clear();
        for(int a=0;a<k;a++){
            char c;
            scanf(" %c", &c);
            ch[a] = c;
            ind[c] = a;
        }
        for(int a=0;a<k;a++){
            for(int b=0;b<k;b++){
                int cost;
                char c;
                scanf("%d-%c", &cost, &c);
                cus[a][b] = cost;
                mk[ind[c]].pb({a, b});
            }
        }
        scanf("%d", &n);
        while(n--){
            scanf(" %s", s);
            int len = strlen(s);


            for(int sz=0;sz<len;sz++){
                for(int i=0;i+sz<len;i++){
                    if(sz == 0){
                        for(int c=0;c<k;c++){
                            if(ind[s[i]] != c)
                                dp[i][i+sz][c] = INT_MAX;
                            else
                                dp[i][i+sz][c] = 0;
                        }
                        continue;
                    }
                    for(int c=0;c<k;c++){
                        ll &r = dp[i][i+sz][c];
                        r = INT_MAX;  
                        //printf("c %d mk sz %d\n", c, mk[c].size());
                        for(pii p: mk[c]){
                         //   printf("mk %d with %d %d\n", c, p.fst, p.snd);
                            for(int m=i;m<i+sz;m++){
                                r = min(r, dp[i][m][p.fst] + dp[m+1][i+sz][p.snd] + cus[p.fst][p.snd]);
                          //      printf("r min= %lld + %lld + %d\n", dp[i][m][p.fst], dp[m+1][i+sz][p.snd], cus[p.fst][p.snd]);
                            }
                        }
                        //printf("dp %d %d %d = %lld\n", i, i+sz, c, dp[i][i+sz][c]);
                    }
                }
            }
            ll mn = INT_MAX;
            int mnc;
            for(int a=0;a<k;a++){
                if(mn > dp[0][len-1][a]){
                    mn = dp[0][len-1][a];
                    mnc = a;
                }
            }
            printf("%lld-%c\n", mn, ch[mnc]);
        }
    }
}

