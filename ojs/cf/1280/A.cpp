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

const int MAXN = 2123456;

int x;
int s[MAXN];
char num[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &x);
        scanf(" %s", num);
        ll sz = strlen(num);
        for(int a=1;a<=sz;a++)
            s[a] = num[a-1]-'0';
        int l = 0;
        bool pass = false;
        while(l < x){
            l++;
            ll right = sz-l;
            ll nsz = sz + right*(s[l]-1ll); 
            for(int a=sz+1;!pass && a<=nsz;a++){
                if(a > x){
                    pass = true;
                    break;
                }
                s[a] = s[a-right];  
            }
            sz = mod(modn + mod(nsz));
        }
        printf("%lld\n", sz);
    }
}

