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
int cnt[26][MAXN];

int main (){
	scanf("%d", &n);
    scanf(" %s", s);
    int tam = strlen(s);
    for(int i=0;i<tam;i++){
        for(int c=0;c<26;c++){
            cnt[c][i] = (i > 0 ? cnt[c][i-1] : 0) + (c == s[i]-'a');
        }
    }
    int q;
    scanf("%d", &q);
	for(int a=0;a<q;a++){
        char pal[MAXN];
        scanf(" %s", pal);
        int pc[26];    
        for(int a=0;a<26;a++)
            pc[a] = 0;
        int szpal = strlen(pal);
        for(int i=0;i<szpal;i++){
            pc[pal[i] - 'a']++;
        }
        int i=0, j= tam-1;
        while(i < j){
            int m = (i + j)/2;
            bool ok = true;
            for(int c=0;c<26;c++){
                if(cnt[c][m] < pc[c])
                    ok = false;
            }
            if(ok)
                j = m;
            else
                i = m+1;
        }
        printf("%d\n", i+1);
	}
}

