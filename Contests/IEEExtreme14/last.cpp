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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 512;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];
char name[MAXN];

int d[MAXN][MAXN];
char M[MAXN][MAXN];

int inii, inij;
int obji, objj;
pii from[MAXN][MAXN];

bool valid(int i, int j){
    return (i>= 0 && j>=0 && i < n && j < m);
}

int main (){
    scanf(" %s", name);
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]);
            if(M[a][b] == 'E'){
                inii = a;
                inij = b;
            }
            if(M[a][b] == 'X'){
                obji = a;
                objj = b;
            }
        }
	}
    int i = inii, j = inij;
    memset(d, INF, sizeof(d));
    set<tuple<int, int, int>> q;
    d[i][j] = 0;
    q.insert({0, i, j});
    int vi[] = {7, 0, -7, 0};
    int vj[] = {0, 7, 0, -7};
    while(!q.empty()){
        auto [dis, i, j] = *q.begin();
        q.erase(q.begin());
        //printf("dij %d %d %d\n", dis, i, j);
        for(int dir=0;dir<4;dir++){ 
            int ii = i + vi[dir];
            int jj = j + vj[dir];
            if(!valid(ii, jj)) continue;
            if(d[ii][jj] > d[i][j] + (M[ii][jj] == 'C')){
                if(d[ii][jj] != INF)
                    q.erase({d[ii][jj], ii, jj});
                from[ii][jj] = {i, j};
                d[ii][jj] = d[i][j] + (M[ii][jj] == 'C');
                q.insert({d[ii][jj], ii, jj});
            }
        }
    }
    printf("dis %d\n", d[obji][objj]);
    if(d[obji][objj] > k){
        assert(false);
        puts("-1");
        return 0;        
    }

    vector<pii> path;
    i = obji; j = objj;
    while(i != inii || j != inij){
        path.emplace_back(i, j);
        tie(i, j) = from[i][j];
    }
    path.emplace_back(i, j);
    reverse(path.begin(), path.end());
    for(pii p: path){
        printf("%d %d\n", p.fst, p.snd);
    }

    /*  --------
     * |        |
     * |        |0 (mesmo i)
     * _________|
     *     1 (mesmo j)
     */
    vector<tuple<bool, int, int, bool>> compPath;
    for(int a=0;a+1<path.size();a++){
        auto [i, j] = path[a];
        auto [ii,jj] = path[a+1];

        bool tipo; // 0- horizontal, 1 -vertical
        int compI, compJ;
        bool hasMonster = (M[i][j] == 'C');
        if(i == ii){ // mesmo i (tipo 0)
            tipo = 0;
            compI = (i - 3)/7;
            if(j < jj){
                debug("DIREITA\n");
                // ->
                compJ = (j - 3)/7;
            }
            else{
                debug("ESQUERDA\n");
                // <-
                compJ = (jj - 3)/7;
            }
        }
        else{
            tipo = 1;
            compJ = (j - 3)/7;
            if(i < ii){
                debug("DESCE\n");
                // v desce
                compI = (i - 3)/7;    
            }
            else{ // ^  sobe
                debug("SOBE\n");
                compI = (ii - 3)/7;
            }
        }
        compPath.pb({tipo, compI, compJ, hasMonster});
    }

    for(auto [t, i, j, m] : compPath){
        printf("tipo (0 -horiz, 1- ver) %d (ci) %d (cj) %d (has monster?) %d\n", t, i, j, m);
    }

    // resposta indo da Origem inii, inij para a primeira posicao de borda
    vector<string> primeiraParte;
    tie(i, j) = path[0];
    int ii, jj;
    tie(ii, jj) = path[1];
    if(i == ii){ // mesmo i (tipo 0)
        if(j < jj){
            primeiraParte.pb("w 0 1");
            primeiraParte.pb("w 0 1");
            primeiraParte.pb("w 0 1");
        }
        else{
            primeiraParte.pb("w 0 -1");
            primeiraParte.pb("w 0 -1");
            primeiraParte.pb("w 0 -1");
            primeiraParte.pb("w 0 -1");
        }
    }
    else{
        if(i < ii){
            primeiraParte.pb("w -1 0");
            primeiraParte.pb("w -1 0");
            primeiraParte.pb("w -1 0");
            primeiraParte.pb("w -1 0");
        }
        else{ // ^  sobe
            primeiraParte.pb("w 1 0");
            primeiraParte.pb("w 1 0");
            primeiraParte.pb("w 1 0");

        }
    }


    // resposta indo da ultima borda pro final de tudo, obji, objj
    vector<string> ultimaParte;
    tie(i, j) = path[path.size()-2];
    tie(ii, jj) = path[path.size()-1];
    if(i == ii){ // mesmo i (tipo 0)
        if(j < jj){
            ultimaParte.pb("w 0 1");
            ultimaParte.pb("w 0 1");
            ultimaParte.pb("w 0 1");
        }
        else{
            ultimaParte.pb("w 0 -1");
            ultimaParte.pb("w 0 -1");
            ultimaParte.pb("w 0 -1");
            ultimaParte.pb("w 0 -1");
        }
    }
    else{
        if(i < ii){
            ultimaParte.pb("w -1 0");
            ultimaParte.pb("w -1 0");
            ultimaParte.pb("w -1 0");
            ultimaParte.pb("w -1 0");
        }
        else{ // ^  sobe
            ultimaParte.pb("w 1 0");
            ultimaParte.pb("w 1 0");
            ultimaParte.pb("w 1 0");

        }
    }


    return 0;
}

