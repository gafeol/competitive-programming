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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, m, k;
vector<string> vs;

int main (){
    for_tests(t, tt){
        vs.clear();
        scanf("%d", &n);
        vector<char> pre;
        vector<char> suf;
        vector<int> i(n,0), j(n, 0);
        for(int a=0;a<n;a++){
            string s;
            cin >> s;
            vs.pb(s);
        }
        printf("Case #%d: ", tt);
        bool let = true;
        while(let){
            let = false; 
            char c = 0;
            for(int a=0;a<n;a++){
                if(vs[a][i[a]] == '*') continue;
                let = true;
                if(c > 0 && c != vs[a][i[a]]){
                    debug("falhou c %c vs[%d][%d] %c\n", c, a, i[a], vs[a][i[a]]);
                    goto falhou;
                }
                c = vs[a][i[a]];
                i[a]++;
            }
            if(let){
                debug("add %c\n", c);
                pre.pb(c);
            }
        }
        let = true;
        for(int a=0;a<n;a++){
            j[a] = vs[a].size()-1;
        }
        while(let){
            let = false; 
            char c = 0;
            for(int a=0;a<n;a++){
                if(vs[a][j[a]] == '*') continue;
                let = true;
                if(c > 0 && c != vs[a][j[a]]){
                    goto falhou;
                }
                c = vs[a][j[a]];
                j[a]--;
            }
            if(let)
                suf.pb(c);
        }

        for(char c: pre)
            printf("%c", c);
        for(int a=0;a<n;a++){
            for(int b=i[a];b<=j[a];b++){
                if(vs[a][b] != '*')
                    printf("%c", vs[a][b]);
            }
        }
        for(int a=suf.size()-1;a>=0;a--)
            printf("%c", suf[a]);
        puts("");
        continue;


falhou: puts("*");
    }
}

