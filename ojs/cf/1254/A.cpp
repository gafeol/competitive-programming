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

const int MAXN = 212;

int n, m, k;
char M[MAXN][MAXN];
int ans[MAXN][MAXN];

int main (){
    for_tests(t,tt){
        scanf("%d%d%d", &n, &m, &k);
        int cnt = 0;
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf(" %c", &M[a][b]);
                cnt += (M[a][b] == 'R');
                ans[a][b] = 0;
            }
        }
        int ex = cnt%k; 
        int i = 0, j = 0;
        int c = 1;
        int has = 0;
        while(c < k){
            ans[i][j] = c;
            has += (M[i][j] == 'R');
            if(ex){
                if(has == cnt/k + 1) {
                    c++;
                    has = 0;
                    ex--;
                }
            }
            else{
                if(has == cnt/k){
                    c++;
                    has = 0;
                }
            }
            if(i&1)
                j--;
            else
                j++;
            if(j < 0 || j >= m){
                i++;
                j = ((i&1) ? m-1 : 0);
            }
        }
        vector<char> chick;
        for(char a='0';a<='9';a++)
            chick.pb(a);
        for(char a='a';a<='z';a++)
            chick.pb(a);
        for(char a='A';a<='Z';a++)
            chick.pb(a);
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                printf("%c", chick[ans[a][b]]);
            }
            puts("");
        }
    }
}

