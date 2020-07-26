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

const int MAXN = 1000006;

int n, m, k;
int s[MAXN];
int mrk[MAXN];
int l, r;

int go(int tam){
    int cnt = 0;
    for(int a=l;a<l+tam;a++){
        cnt += (mrk[a] == 0);
    }

    for(int fim=l+tam-1;fim<=r;fim++){
        if(cnt < k) return false;
        cnt -= (mrk[fim-tam+1] == 0);
        cnt += (mrk[fim+1] == 0);
    }
    return true;
}

int main (){
    mrk[1] = true;
    for(int i=2;i<MAXN;i++){
        if(mrk[i]) continue;
        for(ll j = i;j*i < MAXN;j++){
            mrk[i*j] = true;
        }
    }
	scanf("%d%d%d", &l, &r, &k);

    int i = 1, j = r - l + 1;
    while(i < j){
        int m = (i + j)/2;
        if(go(m))
            j = m;
        else
            i = m + 1; 
    }
    if(go(i))
        printf("%d\n", i);
    else
        puts("-1");

}

