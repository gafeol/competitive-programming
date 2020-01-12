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

const int MAXN = 61; 
int n, m, k;
char M[MAXN][MAXN];


bool check(int i, int j){
    if(i == -1){
        for(int a=0;a<n;a++)
            if(M[a][j] == 'P')
                return false;
    }
    else{
        for(int b=0;b<m;b++)
            if(M[i][b] == 'P')
                return false;
    }
    return true;
}
int sum(int i, int j){
    int cnt = 0;
    if(i == -1)
        for(int a=0;a<n;a++)
            cnt += (M[a][j] == 'A');
    else
        for(int b=0;b<m;b++)
            cnt += (M[i][b] == 'A');
    return cnt;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        bool has = false, ok = false;
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf(" %c", &M[a][b]);
                has |= (M[a][b] == 'P');
                ok |= (M[a][b] == 'A');
            }
        }
        if(!ok){
            puts("MORTAL");
            continue;
        }
        if(!has){
            puts("0");
            continue;
        }
        if(check(0, -1) || check(n-1, -1) || check(-1, 0) || check(-1, m-1)){
            puts("1");
            continue;
        }
        if(M[0][0] == 'A' || M[n-1][0] == 'A' || M[0][m-1] == 'A' || M[n-1][m-1] == 'A'){
            puts("2");
            continue;
        }
        bool foi = false;
        for(int a=0;a<n;a++)
            if(check(a, -1))
                foi = true;
        if(foi)
            continue;
        for(int a=0;a<m;a++)
            if(check(-1, a))
                foi = true;
        if(foi){
            puts("2");
            continue;
        }
        if(sum(0, -1) || sum(n-1, -1) || sum(-1, m-1) || sum(-1, 0)){
            puts("3");
            continue;
        }
        puts("4");
    }
}

