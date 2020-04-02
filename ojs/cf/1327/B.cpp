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
map<int, bool> mrk;

int main (){
    for_tests(t, tt){
        int lp = -1;
        mrk.clear();
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", &m);
            bool ok = false;
            while(m--){
                int x;
                scanf("%d", &x); 
                if(!ok && !mrk[x]){
                    mrk[x] = true;
                    ok = true; 
                }
            }
            if(!ok)
                lp = a;
        }
        if(lp < 0){
            puts("OPTIMAL");
        }
        else{
            puts("IMPROVE");
            for(int a=1;a<=n;a++){
                if(!mrk[a]){
                    printf("%d %d\n", lp+1, a);
                    break;
                }
            }
        }
    }
}

