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

const int MAXN = 212345;

int n, m;
ll x, y, k;
int s[MAXN];
int ss[MAXN];

int main (){
	scanf("%d%d", &n, &m);
    scanf("%lld%lld%lld", &x, &k, &y);
    map<int, int> pos;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        pos[s[a]] = a;
	}
    int bef = -1;
    bool imp = false;
    ll ans = 0;
    for(int a=0;a<m;a++){
        scanf("%d", ss+a);
        if(pos.find(ss[a]) == pos.end()){
            imp = true;
            break;
        }
        if(a > 0 && pos[ss[a]] < pos[ss[a-1]]) {
            imp = true;
            break;
        }
        int dis = pos[ss[a]] - bef - 1;
        if(dis){
            int mx = *max_element(s+bef+1, s+pos[ss[a]]);
            if(dis >= k || mx < ss[a] || (bef != -1 && mx < s[bef])){
                if(mx < ss[a] || (bef!=-1 && mx < s[bef])){
                    ans += min((dis/k)*x + (dis%k)*y, dis*y);
                }
                else{
                    int nblock = dis/k;
                    if(nblock > 1)
                        ans += min((dis/k)*x + (dis%k)*y, x + (dis-k)*y);
                    else
                        ans += (dis/k)*x + (dis%k)*y;
                }
            }
            else 
                imp = true;
        }
        bef = pos[ss[a]];
    }
    int dis = n - bef - 1;
    if(dis){
        if(dis >= k || s[bef] > *max_element(s+bef+1, s+n)){
            if(s[bef] > *max_element(s+bef+1, s+n)){
                ans += min((dis/k)*x + (dis%k)*y, dis*y);
            }
            else{
                int nblock = dis/k;
                if(nblock > 1)
                    ans += min((dis/k)*x + (dis%k)*y, x + (dis-k)*y);
                else
                    ans += (dis/k)*x + (dis%k)*y;
            }
        }
        else
            imp = true;
    }

    if(imp){
        puts("-1");
    }
    else{
        printf("%lld\n", ans);
    }
}

