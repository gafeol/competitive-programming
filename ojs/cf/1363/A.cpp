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
int s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        int sum = 0;
        int cnt[2], cntt[2];
        memset(cnt, 0, sizeof(cnt));
        memset(cntt, 0, sizeof(cnt));
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            if(a < k){
                sum += s[a];
                cnt[(s[a]&1)]++;
            }
            else{
                cntt[(s[a]&1)]++;
            }
        }
        if(sum&1){
            puts("Yes");
        }
        else{
            if(cnt[1] && cntt[0])
                puts("Yes");
            else if(cnt[0] && cntt[1])
                puts("Yes");
            else
                puts("No");
        }
    }
}

