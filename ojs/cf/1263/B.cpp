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
int s[MAXN][5];

bool eq(int i, int j){
    for(int a=0;a<4;a++)
        if(s[i][a] != s[j][a])
            return false;
    return true;
}

bool check(int i){
    for(int a=0;a<n;a++){
        if(a == i) continue;
        if(eq(a, i))
            return false;
    }
    return true;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            for(int i=0;i<4;i++){
                char c;
                scanf(" %c", &c);
                s[a][i] = c-'0';
            }
        }
        int ans = 0;
        for(int a=0;a<n;a++){
            if(!check(a)){
                ans++;
                bool ok = false;
                for(int p=0;!ok && p<4;p++){
                    int o = s[a][p];
                    for(int d=0;!ok && d<=9;d++){
                        s[a][p] = d;
                        ok = check(a);
                    }
                    if(!ok)
                        s[a][p] = o;
                }
            }
        }
        printf("%d\n", ans);
        for(int a=0;a<n;a++){
            for(int i=0;i<4;i++){
                printf("%d", s[a][i]);
            }
            puts("");
        }
    }
}

