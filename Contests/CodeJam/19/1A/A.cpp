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

const int MAXN = 22;

int n, m, k;

int M[MAXN][MAXN];

bool ok(int i, int j, int ii, int jj){
    return !(i == ii || j == jj || i + j == ii + jj || i - j == ii - jj);
}

bool go(int t){
    if(t == n*m) return true;
    int lsti, lstj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j] == t-1){
                lsti = i;
                lstj = j;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j] != -1) continue;
            if(t == 0 || ok(lsti, lstj, i, j)){
                M[i][j] = t;
                if(go(t+1)) return true;
                M[i][j] = -1;
            }
        }
    }

    return false;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        printf("Case #%d: ", tt);
        memset(M, -1, sizeof(M));
        if(go(0)){
            puts("POSSIBLE");
            for(int pos=0;pos<n*m;pos++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(M[i][j] == pos){
                            printf("%d %d\n", i+1, j+1);
                        }
                    }
                }
            }
        }
        else{
            puts("IMPOSSIBLE");
        }
    }
}

