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
int p[3];
char s[3][MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        int mx = -1, mxi, mn = k+1, mni;
        for(int i=0;i<n;i++){
            scanf(" %s %d", s[i], p+i);
            if(mx < p[i]){
                mx = p[i];
                mxi = i;
            }
            if(mn > p[i]){
                mn = p[i];
                mni = i;
            }
        }
        printf("Case #%d: ", tt);
        if(mx >= k - mn){
            printf("%s %d/1\n", s[mxi], p[mxi]);
        }
        else{
            for(int a=0;a<k;a++){
                s[mni][a] = (s[mni][a] == 'F' ? 'T' : 'F');
            }
            printf("%s %d/1\n", s[mni], k-p[mni]);
        }
    }
    return 0;
}

