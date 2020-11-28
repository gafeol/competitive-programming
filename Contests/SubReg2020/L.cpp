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

const int MAXN = 55;

int n, m, k;
int s[MAXN];
char M[MAXN][MAXN];

int mrk[MAXN][MAXN];
int ans[MAXN][MAXN];
char pal[50];

int vi[] = {0, 1, 1, 1};
int vj[] = {1, 1, 0, -1};

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int cnt[30];
bool match(int i, int j, int d){
    int sz = strlen(pal);
    for(int a=0;a<=26;a++)
        cnt[a] = 0;
    for(int a=0;a<sz;a++)
        cnt[pal[a]-'A']++;
    while(sz){
        if(!valid(i, j)) return false;
        cnt[M[i][j]-'A']--;
        i = i + vi[d];
        j = j + vj[d];
        sz--;
    }
    
    for(int a=0;a<=26;a++)
        if(cnt[a] != 0)
            return false;
    return true;
}

int tempo;
void marca(int i, int j, int d){
    int sz = strlen(pal);
    while(sz){
        if(mrk[i][j] != -1 && mrk[i][j] != tempo)
            ans[i][j] = true;
        mrk[i][j] = tempo;
        i = i + vi[d];
        j = j + vj[d];
        sz--;
    }
}

int main (){
    memset(mrk, -1, sizeof(mrk));
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]);
        }
	}
    scanf("%d", &k);
    for(int a=0;a<k;a++){
        tempo = a;
        scanf(" %s", pal);
        //printf("TEMPO %d\n", tempo);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int d=0;d<4;d++){
                    if(match(i, j, d)){
                        //printf("match i %d j %d d %d\n", i, j, d);
                        marca(i, j, d);
                    }
                }
            }
        }
    }
    int res = 0;
    for(int a=0;a<n;a++)
        for(int b=0;b<m;b++)
            res += ans[a][b];
    printf("%d\n", res);
    return 0;
}

