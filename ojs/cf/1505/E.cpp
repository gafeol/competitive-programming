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

const int MAXN = 7;

int n, m, k;
int s[MAXN];
char M[MAXN][MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]);
        }
	}
    int i = 0, j = 0;
    int res = 0;
    while(i < n-1 || j < m-1){
        res += (M[i][j] == '*');
        if(M[i][j+1] == '*'){
            j++;
            continue;
        }
        if(M[i+1][j] == '*'){
            i++;
            continue;
        }
        if(j < m-1)
            j++;
        else
            i++;

    }
    res += (M[i][j] == '*');
    printf("%d\n", res);
    return 0;
}

