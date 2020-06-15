#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int LOGN = 13;

int n, m, k;
ll orv[LOGN][2];

ll qry(int i, int t){
    vector<int> q;
    for(int a=0;a<n;a++){
        if((a&(1<<i)) == t*(1<<i))
            q.pb(a);
    }
    printf("? %d", (int)q.size());
    for(int x: q){
        printf(" %d", x+1);
    }
    puts("");
    fflush(stdout);
    ll x;
    scanf("%lld", &x);
    if(x == -1)
        exit(0);
    return x;
}

int main (){
	scanf("%d", &n);
    for(int i=0;(1<<i) < n;i++){
        for(int t=0;t<2;t++){
            orv[i][t] = qry(i, t);
        }
    }

    printf("! ");
    for(int a=0;a<n;a++){
        ll ans = 0;
        for(int i=0;(1<<i) < n;i++){
            ans |= orv[i][!((a&(1<<i)) > 0)];
        }
        printf("%lld ", ans);
    }
    puts("");
    fflush(stdout);
}

