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

const int MAXN = 21234;

int n, m, k;
int s[MAXN];

int mrk[MAXN];

int main (){
	scanf("%d", &n);
    int unk = 1;
    for(int j=2;j<=n;j++){
        printf("? %d %d\n", unk, j);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        printf("? %d %d\n", j, unk);
        fflush(stdout);
        int y;
        scanf("%d", &y);

        if(x > y){
            s[unk] = x;  
            unk = j;
        }
        else{
            s[j] = y;        
        }
    }
    s[unk] = n;
    printf("! ");
    for(int a=1;a<=n;a++){
        printf("%d ", s[a]);
    }
    puts("");
    fflush(stdout);
}

