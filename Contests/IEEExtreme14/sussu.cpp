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

#define fr(i,n) for(int i = 0; i<n; i++)
#define sz(v) (int)(v.size())
#define prin(a) cout << #a << " = " << a << endl

#define righti 0
#define ru 1
#define upi 2
#define lu 3
#define lefti 4
#define ld 5
#define downi 6
#define rd 7
#define stop 8

namespace lamarca{

namespace sub_lamarca{

int di[] = { 1, 1, 0,-1,-1,-1, 0, 1, 0};
int dj[] = { 0, 1, 1, 1, 0,-1,-1,-1, 0};
/*
int di[] = { 0, 1, 1, 1, 0,-1,-1,-1,0};
int dj[] = { 1, 1, 0,-1,-1,-1, 0, 1,0};
*/

vector<string> go1;
void make_go1(){
    go1.resize(9);
    fr(dir,9){
        go1[dir] = "w " + to_string(di[dir]) + " " + to_string(dj[dir]);
    }
}

string joga(int dx, int dy){
    swap(dx,dy);
    dy*=-1;
    return string("b ") + to_string(dx) + " " + to_string(dy);
}

void gov(vector<int> dirs, vector<string> &ans){
    for(auto dir : dirs){
        assert(dir>=0 and dir<9);
        ans.emplace_back(go1[dir]);
    }
}

vector<string> go_dir(int dir, bool orig_inf, bool jogab){
    vector<string> ans;
    assert(dir<=7);
    if(sz(go1)==0) make_go1();
    assert(sz(go1));
    //rever caso diagonal, depende se origem eh lateral ou superior
    
    
    /*
    cout << "func" << endl;
    prin(dir);
    //*/
    
    if(dir==righti){
        gov({righti},ans);
        if(jogab) ans.emplace_back(joga(2,3));
        gov({stop,ru,ru,righti,righti,rd,rd},ans);
    } else if(dir==ru){
        if(!orig_inf){ //orig_lateral
            gov({righti},ans);
            if(jogab) ans.emplace_back(joga(2,3));
            gov({stop,ru,ru,ru,upi},ans);
        } else{
            if(jogab) ans.emplace_back(joga(-3,-2));
            gov({stop,ru,ru,ru},ans);
        }
    } else if(dir==upi){
        if(jogab) ans.emplace_back(joga(-3,2));
        gov({stop,lu,lu,upi,ru,ru,upi},ans);
    } else if(dir==lu){
        if(!orig_inf){ //orig_lateral
            if(jogab) ans.emplace_back(joga(2,-3));
            gov({stop,lu,lu,lu,upi},ans);
        } else{
            if(jogab) ans.emplace_back(joga(-3,2));
            gov({stop,lu,lu,lu,lefti},ans);
        }
    } else if(dir==lefti){
        if(jogab) ans.emplace_back(joga(2,-3));
        gov({stop,lu,lu,lefti,lefti,ld,ld,lefti},ans);
    } else if(dir==ld){
        if(!orig_inf){ //orig_lateral
            if(jogab) ans.emplace_back(joga(-2,-3));
            gov({stop,ld,ld,ld},ans);
        } else{
            gov({downi},ans);
            if(jogab) ans.emplace_back(joga(3,2));
            gov({stop,ld,ld,ld,lefti},ans);
        }
    } else if(dir==downi){
        gov({downi},ans);
        if(jogab) ans.emplace_back(joga(3,2));
        gov({stop,ld,ld,downi,downi,rd,rd},ans);
    } else if(dir==rd){
        if(!orig_inf){ //orig_lateral
            gov({righti},ans);
            if(jogab) ans.emplace_back(joga(-2,3));
            gov({stop,rd,rd,rd},ans);
        } else{
            gov({downi},ans);
            if(jogab) ans.emplace_back(joga(3,-2));
            gov({stop,rd,rd,rd},ans);
        }
    }
    return ans;
    /*
    for(auto &s : ans){
        cout << s << "\n";
    }
    return;
    */
}

}

void print_moves(vector<tuple<bool,int,int,bool>> &pos, vector<string> &v){ //eh_inf, i, j, tij
    map<pair<int,int>,int> mp;
    
    /*
    for(int ii = 0; ii<sz(pos); ii++){
        bool eh_inf_cur, tij_cur;
        int i_cur, j_cur;
        tie(eh_inf_cur,i_cur,j_cur,tij_cur) = pos[ii];
        cout << "i=" << i_cur << ", j=" << j_cur << ", eh_inf=" << eh_inf_cur << ", eh_tij=" << tij_cur << "\n";
    }
    return;
    //*/
    
    for(int ii = 0; ii<sz(pos)-1; ii++){
        bool eh_inf_cur, tij_cur;
        int i_cur, j_cur;
        tie(eh_inf_cur,i_cur,j_cur,tij_cur) = pos[ii];
        
        bool eh_inf_prox, tij_prox;
        int i_prox, j_prox;
        tie(eh_inf_prox,i_prox,j_prox,tij_prox) = pos[ii+1];
        
        /*
        cout << endl;
        cout << "i=" << i_cur << ", j=" << j_cur << ", eh_inf=" << eh_inf_cur << ", eh_tij=" << tij_cur << endl;
        cout << "i=" << i_prox << ", j=" << j_prox << ", eh_inf=" << eh_inf_prox << ", eh_tij=" << tij_prox << endl;
        */
        
        
        int dir;
        
        int di = i_prox-i_cur;
        int dj = j_prox-j_cur;
        /*
        prin(di);
        prin(dj);
        prin(eh_inf_cur);
        prin(eh_inf_prox);*/
                
                
        if(eh_inf_cur==0 and eh_inf_prox==0 and dj==1 and di==0) dir = righti;
        else if(eh_inf_cur==1 and eh_inf_prox==0 and dj==0 and di==0) dir = ru;
        else if(eh_inf_cur==0 and eh_inf_prox==1 and dj==1 and di==-1) dir = ru;
        else if(eh_inf_cur==1 and eh_inf_prox==1 and dj==0 and di==-1) dir = upi;
        else if(eh_inf_cur==1 and eh_inf_prox==0 and dj==-1 and di==0) dir = lu;
        else if(eh_inf_cur==0 and eh_inf_prox==1 and dj==0 and di==-1) dir = lu;
        else if(eh_inf_cur==0 and eh_inf_prox==0 and dj==-1 and di==0) dir = lefti;
        else if(eh_inf_cur==1 and eh_inf_prox==0 and dj==-1 and di==1) dir = ld;
        else if(eh_inf_cur==0 and eh_inf_prox==1 and dj==0 and di==0) dir = ld;
        else if(eh_inf_cur==1 and eh_inf_prox==1 and dj==0 and di==1) dir = downi;
        else if(eh_inf_cur==1 and eh_inf_prox==0 and dj==0 and di==1) dir = rd;
        else if(eh_inf_cur==0 and eh_inf_prox==1 and dj==1 and di==0) dir = rd;
        else{ 
            //prin(dir);
            assert(0);
        }
        //prin(dir);
        
        /*prin(dir);
        prin(eh_inf_cur);
        prin(tij_prox);
        */
        vector<string> ans_aux = sub_lamarca::go_dir(dir,eh_inf_cur,tij_prox);
        for(auto &s : ans_aux) v.push_back(s);
        //sub_lamarca::go_dir(dir,tij_prox);
    }
    return;
}  

};

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
    /*for(pii p: path){
        printf("%d %d\n", p.fst, p.snd);
    }*/

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

    /*
    for(auto [t, i, j, m] : compPath){
        printf("tipo (0 -horiz, 1- ver) %d (ci) %d (cj) %d (has monster?) %d\n", t, i, j, m);
    }*/

    // resposta indo da Origem inii, inij para a primeira posicao de borda
    vector<string> primeiraParte;
    tie(i, j) = path[0];
    int ii, jj;
    tie(ii, jj) = path[1];
    if(i == ii){ // mesmo i (tipo 0)
        if(j < jj){
            primeiraParte.pb("w 1 0");
            primeiraParte.pb("w 1 0");
            primeiraParte.pb("w 1 0");
        }
        else{
            primeiraParte.pb("w -1 0");
            primeiraParte.pb("w -1 0");
            primeiraParte.pb("w -1 0");
            primeiraParte.pb("w -1 0");
        }
    }
    else{
        if(i < ii){
            primeiraParte.pb("w 0 -1");
            primeiraParte.pb("w 0 -1");
            primeiraParte.pb("w 0 -1");
        }
        else{ // ^  sobe
            primeiraParte.pb("w 0 1");
            primeiraParte.pb("w 0 1");
            primeiraParte.pb("w 0 1");
            primeiraParte.pb("w 0 1");

        }
    }


    // resposta indo da ultima borda pro final de tudo, obji, objj
    vector<string> ultimaParte;
    tie(i, j) = path[path.size()-2];
    tie(ii, jj) = path[path.size()-1];
    if(i == ii){ // mesmo i (tipo 0)
        if(j < jj){
            ultimaParte.pb("w 1 0");
            ultimaParte.pb("w 1 0");
            ultimaParte.pb("w 1 0");
            ultimaParte.pb("w 1 0");
        }
        else{
            ultimaParte.pb("w -1 0");
            ultimaParte.pb("w -1 0");
            ultimaParte.pb("w -1 0");
        }
    }
    else{
        if(i < ii){
            ultimaParte.pb("w 0 -1");
            ultimaParte.pb("w 0 -1");
            ultimaParte.pb("w 0 -1");
            ultimaParte.pb("w 0 -1");
        }
        else{ // ^  sobe
            ultimaParte.pb("w 0 1");
            ultimaParte.pb("w 0 1");
            ultimaParte.pb("w 0 1");

        }
    }
    
    cout << "primeiraParte" << endl;
    for(auto &s : primeiraParte){
        cout << s << "\n";
    }
    
    
    vector<string> ans = primeiraParte;
    lamarca::print_moves(compPath,ans);
    
    for(auto &s : ultimaParte){
        ans.push_back(s);
    }
    cout << "ultimaParte" << endl;
    for(auto &s : ultimaParte){
        cout << s << "\n";
    }
    
    assert(sz(ans)<=100000);
    cout << sz(ans) << "\n";
    for(auto &s : ans){
        cout << s << "\n";
    }
    
    return 0;
}
