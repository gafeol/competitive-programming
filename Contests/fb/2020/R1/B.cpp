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

const int MAXN = 1e6+10;

int n, m, k;
ll ts;
ll p[MAXN], q[MAXN];

bool go(ll t){
    int j = 0;
    for(int i=0;i<n;i++){
        ll esq = 0, dir = 0;          
        ll cnt = 0;
        while(j < m){
            cnt++;
            if(q[j] < p[i])
                esq = max(esq, abs(q[j] - p[i]));
            else
                dir = max(dir, abs(q[j] - p[i]));
            ll cus = ts*cnt + min(2ll*esq + dir, 2ll*dir + esq);
            if(cus > t)
                break;
            j++;
        }
    }
    return (j == m);
}

int main (){
    for_tests(t, tt){
        scanf("%d%d%d%lld", &n, &m, &k, &ts);
        for(int a=0;a<k;a++){
            scanf("%lld", p+a);
        }
        ll A, B, C, D;
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<n;a++){
            p[a] = ((A*p[a-2] + B*p[a-1] + C)%D) + 1;
        }
        for(int a=0;a<k;a++){
            scanf("%lld", q+a);
        }
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        for(int a=k;a<m;a++){
            q[a] = ((A*q[a-2] + B*q[a-1] + C)%D) + 1;
        }

        sort(p, p+n);
        sort(q, q+m);

        ll i = 1, j = (ll)2e15 + 10ll; 
        while(i < j){
            ll mid = (i + j)/2ll;
            if(go(mid))
                j = mid;
            else
                i = mid + 1;
        }
        printf("Case #%d: %lld\n", tt, i);
    }
}

