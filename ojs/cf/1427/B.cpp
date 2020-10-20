#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
char s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        int p = 0;
        bool noW = true;

        int sob = 0;
        for(int a=0;a<n;a++){
            scanf(" %c", s+a);
            if(s[a] == 'W')
                noW = false;
            p += (s[a] == 'W') + (s[a] == 'W' && a > 0 && s[a-1] == 'W');
        }

        if(noW){
            printf("%d\n", max(0, min(n, k)*2 - 1));
            continue;
        }

        debug("p %d\n", p);
        int ini = 0;
        while(ini < n && s[ini] == 'L'){
            sob++;
            ini++;
        }
        int fim = n-1;
        while(fim > ini && s[fim] == 'L'){
            sob++;
            fim--;
        }

        debug("ini %d fim %d sob %d\n", ini, fim, sob);

        int cnt = 0;
        multiset<int> inter;
        if(ini < fim){
            for(int i=ini;i<=fim;i++){
                cnt += (s[i] == 'L');        
                if(s[i] == 'W' && cnt > 0){
                    inter.insert(cnt);
                    debug("inter add %d\n", cnt);
                    cnt = 0;
                }
            }
            if(cnt){
                inter.insert(cnt);
                debug("inter add %d\n", cnt);
                cnt = 0;
            }
        }

        while(!inter.empty()){
            int sm = *inter.begin();
            inter.erase(inter.begin());
            if(k >= sm){
                p += 2*sm + 1;
                k -= sm;
            }
            else{
                p += 2*k;
                k = 0;
            }
        }
        p += min(sob, k)*2;
        printf("%d\n", p);
    }
}

