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
bool M[2][MAXN];

int lava(int i, int j){
    return (i>= 0 && j>= 0 &&  i < 2 && j < n && M[i][j]);
}

void t(int i, int j){
    if(M[i][j])
        k -= lava(i-1, j) + lava(i-1, j-1) + lava(i-1, j+1) + lava(i+1, j) + lava(i+1, j-1) + lava(i+1, j+1); 
    else
        k += lava(i-1, j) + lava(i-1, j-1) + lava(i-1, j+1) + lava(i+1, j) + lava(i+1, j-1) + lava(i+1, j+1); 
    M[i][j] = !M[i][j];
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int i,j;
        scanf("%d%d", &i, &j);
        i--;j--;
        t(i, j);
        if(k)
            puts("No");
        else
            puts("Yes");
	}
}

