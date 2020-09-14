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

const int MAXN = 312345;
    
int n, m, k;
int s[MAXN];

int dep[MAXN];
int bit[2][MAXN];

void upd(int i, int t=0){
    while(i > 0){
        bit[t][i]++;
        i -= (i&-i);
    }
}
int qry(int i, int t=0){
    int ans = 0;
    while(i < MAXN){
        ans += bit[t][i];
        i += (i&-i);
    }
    return ans;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
        scanf("%d", s+a);
        dep[a] = 0;
	}
    for(int a=1;a<=n;a++){
        if(a == s[a]){
            dep[a] = a;
        }
        else if(a > s[a]){
            int i = 1, j = a;
            while(i < j){
                int m = (i+j+1)/2;
                if(qry(m) >= a - s[a])
                    i = m;
                else
                    j = m-1;
            }
            if(qry(i) >= a - s[a]){
                dep[a] = i;
            }
        }
        //printf("a %d dep %d\n", a, dep[a]);
        if(dep[a])
            upd(dep[a]);
    }
    vector<int> ans(m);
    vector<tuple<int, int, int>> q;
    for(int a=0;a<m;a++){
        int x, y;
        scanf("%d%d", &x, &y);
        y = n-y;
        q.pb({y, x, a});
    }
    sort(q.begin(), q.end());
    int i = 0;
    for(tuple<int, int, int> tp: q){
        int y, x, id;
        tie(y, x, id) = tp;
        while(i<y){
            i++;
            if(dep[i]){
                upd(dep[i], 1);
            }
        }
        ans[id] = qry(x+1, 1);
    }
    for(int a=0;a<m;a++){
        printf("%d\n", ans[a]);
    }
}

