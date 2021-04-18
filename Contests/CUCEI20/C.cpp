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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<string> vs;

int main (){
	scanf("%d", &n);
    ll sum = 0;
    int ini = 0;
	for(int a=0;a<n;a++){
        char pal[20];
        scanf(" %s", pal);
        if(strcmp(pal, "Cheems") == 0)
            ini = a;
        vs.pb(pal);
        sum += strlen(pal);
	}
    ll k;
    scanf("%lld", &k);
    ini = (ini + k/sum)%n;
    k = k%sum;
    
    for(int i=ini;;i++){
        if(i == n) i = 0;
        for(char c: vs[i]){
            k--;
            if(k == 0){
                printf("%c\n", c);
                return 0;
            }
        }
    }
    return 0;
}

