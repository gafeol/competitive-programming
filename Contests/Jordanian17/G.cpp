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

int n, m, k;
int s[MAXN];

int cnt[30];

void add(int x){
    for(int i=0;i<30 && x > 0;i++){
        if(x&1)
            cnt[i]++;
        x/=2;
    }
}
void rmv(int x){
    for(int i=0;i<30 && x > 0;i++){
        if(x&1)
            cnt[i]--;
        x/=2;
    }
}
int qry(){
    int ans = 0;
    for(int i=0;i<30;i++){
        if(cnt[i])
            ans += (1<<i);
    }
    return ans;
}

int test(int x){
    add(x);
    int ans = qry();
    rmv(x);
    return ans;
}


int main (){
    freopen("wifi.in", "r", stdin);
    for_tests(t, tt){
        k = 0;
        for(int a=0;a<30;a++)
            cnt[a] = 0;
        int v;
        scanf("%d%d", &n, &v);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
        }
        int j = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
           j = max(j, i);  
           while(j < n && test(s[j]) <= v){
               add(s[j]);
               j++;
           }
           ans = max(ans, j-i);
           if(j > i)
               rmv(s[i]);
        }
        printf("%d\n", ans);
    }
}

