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

const int MAXN = 12;

int n,k;
int M[10][10];

pii ini[MAXN], fim[MAXN];

int ans = 11;

int at(int i, int j){
    if(i < 0 || i > 5 || j < 0 || j > 5) return -1;
    return M[i][j];
}

int dist(){
    if(ini[1].fst != fim[1].fst || ini[1].fst != 2) return ans;
    int cus = 7 - fim[1].snd;
    int i = fim[1].fst;
    for(int j=fim[1].snd+1;j<=5;j++){
        if(M[i][j] == 0) continue;
        cus++; 
        cus += (at(i-1, j) == M[i][j] && at(i+1, j) == M[i][j]);
    }
    return cus;
}

void apaga(pii p){
    M[p.fst][p.snd] = 0;
}

void bota(int u, pii p){
    assert(M[p.fst][p.snd] == 0);
    M[p.fst][p.snd] = u;
}

bool move(int u){
    // move o fim 1 posicao, vai pra direita ou baixo
    if(u == 1 && fim[u].snd >= 5){
        apaga(ini[u]);
        fim[u].snd++;        
        ini[u].snd++;
        bota(u, fim[u]);
        return true;
    }
    if(ini[u].fst == fim[u].fst){
        if(at(fim[u].fst, fim[u].snd+1) != 0) 
            return false;
        apaga(ini[u]);
        fim[u].snd++;
        ini[u].snd++;
        bota(u, fim[u]);
    }
    else{
        if(at(fim[u].fst+1, fim[u].snd) != 0)
            return false;
        apaga(ini[u]);
        fim[u].fst++;
        ini[u].fst++;
        bota(u, fim[u]);
    }
}

bool unmove(int u){
    // move o ini 1 posicao
    if(ini[u].fst == fim[u].fst){
        if(at(ini[u].fst, ini[u].snd-1) != 0) 
            return false;
        apaga(fim[u]);
        fim[u].snd--;
        ini[u].snd--;
        bota(u, ini[u]);
    }
    else{
        if(at(ini[u].fst-1, ini[u].snd) != 0)
            return false;
        apaga(fim[u]);
        fim[u].fst--;
        ini[u].fst--;
        bota(u, ini[u]);
    }
}

void go(int d){
    //printf("go d %d\n", d);
    int dis = dist();
    /*
     printf("dis %d\n", dis);
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            printf("%d ", M[a][b]);
        }
        puts("");
    }
    puts("");
    */
    if(d + dis >= ans) return ;
    if(fim[1].snd == 7){
        ans = min(ans, d);
        return ;
    }

    for(int a=1;a<=10;a++){
        if(ini[a].fst == INT_MAX) break;
        if(move(a)){
            //printf("move %d\n", a);
            go(d+1);
            unmove(a);
        }
        if(d + dis >= ans) return ;
        if(unmove(a)){
            //printf("unmove %d\n", a);
            go(d+1);
            move(a);
        }
        if(d + dis >= ans) return ;
    }
}

int main (){
    n = 6;
    for(int a=0;a<=10;a++){
        ini[a] = {INT_MAX, INT_MAX};
        fim[a] = {INT_MIN, INT_MIN};
    }
	for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            scanf("%d", &M[a][b]);
            ini[M[a][b]] = min(ini[M[a][b]], {a, b});
            fim[M[a][b]] = max(fim[M[a][b]], {a, b});
        }
	}
    for(int a=1;a<=10;a++){
        //printf("A %d ini %d %d fim %d %d\n", a, ini[a].fst, ini[a].snd, fim[a].fst, fim[a].snd);
    }
    if(ini[1].fst != fim[1].fst || ini[1].fst != 2){
        puts("-1");
        return 0;
    }
    go(0);
    if(ans == 11)
        puts("-1");
    else
        printf("%d\n", ans);
}

