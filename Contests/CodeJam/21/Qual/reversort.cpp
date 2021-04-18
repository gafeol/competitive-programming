#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 212;

int n, m, k;
int s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
        }
        int res = 0;
        for(int val=1;val<n;val++){
            int pos = val-1;
            while(s[pos] != val)
                pos++;
            int l = val-1, r = pos;
            res += r - l + 1;
            while(l < r){
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
