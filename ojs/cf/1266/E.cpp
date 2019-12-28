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
ll s[MAXN];
ll tot = 0;
int cnt[MAXN];
map<int, map<ll, int> > r;

void add(int x){
    //printf("add %d\n", x);
    cnt[x]++;
    if(cnt[x] <= s[x])
        tot--;
}

void rmv(int x){
    //printf("rmv %d\n", x);
    cnt[x]--; 
    if(cnt[x] < s[x])
        tot++;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        tot += s[a];
	}
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int i, j;
        ll x;
        scanf("%d%lld%d", &i, &x, &j);
        i--;j--;
        if(r[i].find(x) != r[i].end())
            rmv(r[i][x]);

        if(j != -1){  
            r[i][x] = j;
            add(j);
        }
        else
            r[i].erase(x);
        printf("%lld\n", max(1ll, tot));
    }
}

