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

const int MAXN = 200005;

int n[3], m, k;
vector<int> s[3];

int bit[2][MAXN];

int qry(int t, int i){
    i += 2;
    int ans = 0;
    while(i > 0){
        ans += bit[t][i];
        i -= (i&-i);
    }
    return ans;
}

void upd(int t, int i){
    // soma 1
    i += 2;
    while(i < MAXN){
        bit[t][i]++;
        i += (i&-i);
    }
}

int val[2][MAXN];

int main (){
	scanf("%d%d%d", n, n+1, n+2);
    for(int t=0;t<3;t++){
        for(int a=0;a<n[t];a++){
            int x;
            scanf("%d", &x);
            if(t == 0)
                upd(0, x);
            else if(t == 2)
                upd(1, x);
        }
    }
    int tot = n[0] + n[1] + n[2];
    for(int i=0;i<=tot+1;i++){
        val[0][i] = i - qry(0, i)
            + qry(0, tot) - qry(0, i)
            - qry(1, i);

        val[1][i] = tot - i + 1 - (qry(1, tot) - qry(1, i-1))
                    + qry(1, i-1)
                    - (qry(0, tot) - qry(0, i-1));
    }
    for(int i=1;i<=tot+1;i++)
       val[0][i] = min(val[0][i], val[0][i-1]); 
    for(int i=tot;i>=0;i--)
        val[1][i] = min(val[1][i], val[1][i+1]);

    int ans = INT_MAX;
    for(int i=0;i<=tot;i++){
       ans = min(ans, val[0][i] + val[1][i+1]);
    }
    printf("%d\n", ans);
}

