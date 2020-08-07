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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
char s[MAXN];
map<char, vector<int>> pos;

int main (){
    for_tests(t, tt){
        pos.clear();
        scanf(" %s", s);
        n = strlen(s);
        for(int a=0;a<n;a++)
            pos[s[a]].pb(a);  
        char mx = '0';
        for(char a='0';a<='9';a++){
            if(pos[a].size() >= pos[mx].size())
                mx = a;
        }
        int ans = min(n-2, n - (int)pos[mx].size());
        for(char c='0';c<='9';c++){
            for(char cc='0';cc<='9';cc++){
                if(c == cc) continue;
                int i=0, j=0;
                int aux = 0;
                while(i < pos[c].size() && j < pos[cc].size()){
                    if(pos[c][i] > pos[cc][j]){
                        j++;
                        continue;
                    }
                    else {
                        aux+=2;
                        while(i+1 < pos[c].size() && pos[c][i+1] < pos[cc][j])
                            i++;
                        i++;
                        j++;
                    }
                }
                //printf("c %c cc %c saves %d ans %d\n", c, cc, aux, n-aux);
                ans = min(ans, n - aux);
            }
        }
        printf("%d\n", ans);
    }
}

