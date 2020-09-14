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

const int MAXN = 2123;

int n;
int s[MAXN];
int cnt[2];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        cnt[0] = cnt[1] = 0;
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            cnt[s[a]]++;
        }
        int ch = (cnt[0] >= cnt[1] ? 0 : 1);
        int extra = (ch && ((n/2)&1));
        printf("%d\n", n/2 + extra);
        for(int a=0;a<n/2 + extra;a++){
            printf("%d ", ch);
        }
        puts("");
    }
}

