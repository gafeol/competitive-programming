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

map<string, int> p;
map<string, int> ult;

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
        char nom[30];
        int min;
        scanf(" %s %d", nom, &min);
        if(p.find(nom) == p.end()){
            p[nom] = 0;
            ult[nom] = 0;
        }
        if(min >= ult[nom]){
            //printf("ponto pro %s %d\n", nom, min);
            p[nom]++;
            ult[nom] = min + k;
        }
	}
    vector<pair<int, string>> rk; 
    for(auto it: p){
        //printf("nome %s pt %d\n", it.fst.c_str(), it.snd);
        rk.pb({-it.snd, it.fst});
    }
    sort(rk.begin(), rk.end());
    puts("--Rank do Nepscord--");
    for(int i=0;i<3;i++){
        printf("#%d. ", i+1);
        if(i < rk.size()){
            printf("%s - Nivel %d", rk[i].snd.c_str(), (-rk[i].fst/4) + 1);
        }
        puts("");
    }
}

