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
int s[MAXN];
int nxt[MAXN];
int mrk[MAXN];
int tempo;
vector<vector<int>> vc;
vector<int> c;
set<int> divs;

int main (){
    for_tests(t, tt){
        vc.clear();
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", nxt+a);
            nxt[a]--;
        }
        for(int a=0;a<n;a++)
            scanf("%d", s+a);

        int mn = INT_MAX;
        tempo++;
        for(int a=0;a<n;a++){
            if(mrk[a] == tempo) continue;
            
            int u = a;
            c.clear();
            do{
                mrk[u] = tempo;
                c.pb(u);
                u = nxt[u];
            } while(u != a);
            vc.pb(c);
            mn=min(mn,(int)c.size());
        }
        divs.clear();
        for(vector<int> &c: vc){
            int tam = c.size();    
            for(int i=1;i <= mn && i<=(int)(sqrt(tam)+0.001);i++){
                if(tam%i == 0){
                    divs.insert(i); 
                    if(tam/i <= mn)
                        divs.insert(tam/i);
                }
            }
        }
        for(int k: divs){
            tempo++;
            for(vector<int> &c: vc){
                for(int i=0;i<c.size();i++){
                    int v = c[i];
                    if(mrk[v] == tempo) continue;
                    mrk[v] = tempo;
                    int cor = s[v];
                    int iu = (i + k)%c.size();
                    int u = c[iu];
                    bool ok = true;
                    while(u != v){
                        mrk[u] = tempo;
                        ok &= (s[u] == cor);
                        iu = (iu + k)%c.size();
                        u = c[iu];
                    }
                    if(ok){
                        printf("%d\n", k);
                        goto stop;
                    }
                }
            }
        }
stop: continue;
    }
}
