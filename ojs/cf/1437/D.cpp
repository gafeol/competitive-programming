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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int main (){
    for_tests(t, tt){
        queue<int> q;
        int ans = 1;
        scanf("%d", &n);
        q.push(0);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
        }
        for(int a=1;a<n;a++){
            int h = q.front();
            q.pop();
            q.push(h+1);
            ans = h+1;
            int b = a+1;
            while(b < n && s[b] > s[b-1]){
                q.push(h+1);
                b++;
            }
            a = b-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

