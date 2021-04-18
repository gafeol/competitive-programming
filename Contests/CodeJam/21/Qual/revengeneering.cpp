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

int sum(int q){
    return q*(q+1)/2;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        k++;
        printf("Case #%d: ", tt);
        if(k < n || k > sum(n)){
            puts("IMPOSSIBLE");
            continue;
        }
        vector<int> res(n);
        int pos[2];
        pos[0] = 0; pos[1] = n-1;
        int inc[2];
        inc[0] = 1; inc[1] = -1;
        int front = 0, back = 1;
        for(int u=1;u<=n;u++){
            if(sum(n-u) >= k-1){ 
                res[pos[front]] = u;
                pos[front] += inc[front];
                k--;
            }
            else{
                res[pos[back]] = u;
                pos[back] += inc[back];
                swap(front, back);
                k -= n-u+1;
            }
        }
        for(int a=0;a<n;a++)
            printf("%d%c", res[a], " \n"[a==n-1]);
    }
    return 0;
}

