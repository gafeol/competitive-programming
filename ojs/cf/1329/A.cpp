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
int l[MAXN];
int res[MAXN];

bool cmp(int a, int b){
    return l[a] > l[b];
}

void fail(){
    puts("-1");
    exit(0);
}

int main (){
	scanf("%d%d", &n, &m);
    ll sum = 0;
	for(int a=0;a<m;a++){
        scanf("%d", l+a);
        sum += l[a];
	}
    int L = n, R = n;
    for(int i=0;i<m;i++){
        if(sum >= R){
            int pi = R - l[i];
            if(pi < 0)
                fail();
            res[i] = pi;
            sum -= l[i];
            L = pi;
            R = pi+l[i]-1;
        }
        else if(sum >= L){
           int pi = sum - l[i];
            if(pi < 0)
                fail();
            res[i] = pi;
            sum -= l[i];
            L = pi;
            R = pi+l[i]-1;
        }
        else
            fail();
    }
    if(L != 0)
        fail();
    for(int a=0;a<m;a++){
        printf("%d ", res[a]+1);
    }
    puts("");
}

