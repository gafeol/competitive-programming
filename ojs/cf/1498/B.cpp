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

int n, m, k, W;

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &W);
        multiset<int> q;
        for(int a=0;a<n;a++){
            int x;
            scanf("%d", &x);
            q.insert(x);
        }
        int res = 0;
        while(!q.empty()){
            res++;
            int sum = *q.rbegin();
            q.erase(q.find(sum));
            while(q.upper_bound(W - sum) != q.begin()){
                auto it = (--q.upper_bound(W - sum));
                sum += *it;
                q.erase(it);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

