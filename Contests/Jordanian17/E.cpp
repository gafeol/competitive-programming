#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define eb emplace_back
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

int n, m, k;
int s[MAXN];

char M[MAXN][MAXN];
tuple<int, int, int> nx[4][MAXN][MAXN];
vector<pii> path;

//           U  R  D  L
int vi[] = {-1, 0, 1, 0};
int vj[] = { 0, 1, 0,-1};

int val(char c){
    if(c == 'U')
        return 0;
    else if(c == 'R')
        return 1;
    else if(c == 'D')
        return 2;
    else
        return 3;
}

tuple<int, int, int> get(int d, int i, int j){
    if(get<0>(nx[d][i][j]) != -1)
        return nx[d][i][j];
    return nx[d][i][j] = get((d+1)%4, i, j);
}

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int main (){
    freopen("reduce.in", "r", stdin);
    for_tests(t, tt){
        path.clear();
        int q;
        scanf("%d%d%d", &n, &m, &q);
        int i, j, d;
        char id;
        scanf("%d%d %c", &i, &j, &id);
        i--;j--;
        d = val(id);
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf(" %c", &M[a][b]);
            }
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(M[a][b] == '#') continue;
                for(int d=0;d<4;d++){
                    int aa = a + vi[d];
                    int bb = b + vj[d];
                    nx[d][a][b] = {-1, -1, -1};
                    if(valid(aa, bb) && M[aa][bb] != '#')
                        nx[d][a][b] = {d, aa, bb};
                }
                for(int d=0;d<4;d++){
                    get(d, a, b);
                    //printf("i %d j %d d %d nx %d %d %d\n", i, j, d, get<0>(nx[d][i][j]), get<1>(nx[d][i][j]), get<2>(nx[d][i][j]));
                }
            }
        }
        //puts("ok nxt");
        int oi = i, oj = j, od = d;
        path.eb(i, j);
        for(int a=0;a<q;a++){
            char com;
            //printf("estou em %d %d d %d\n", i, j, d);
            scanf(" %c", &com);
            if(com == 'R')
                d = (d + 1)%4;
            else{
                int x;
                scanf("%d", &x);
                while(x--){
                    //printf("i %d j %d\n", i, j);
                    tuple<int, int, int> np = nx[d][i][j];
                    tie(d, i, j) = np;
                    if(make_pair(i, j) != path.back())
                        path.pb({i, j});
                }
            }
        }
        /*
        puts("path:");
        for(pii p: path){
            printf("%d %d\n", p.fst, p.snd);
        }
        */

        int ans = 0;
        bool stop = 1;
        i = oi;
        j = oj;
        d = od;
        for(int a=1;a<path.size();a++){
            //printf("a %d path %d %d i %d j %d d %d\n", a, path[a].fst, path[a].snd, i, j, d);
            int nd, ni, nj;
            tie(nd, ni, nj) = nx[d][i][j];
            if(path[a] == make_pair(ni, nj)){
                if(stop){
                    //puts("ANDOU");
                    ans++;
                    stop = false;
                }
            }
            else{
                while(path[a] != make_pair(get<1>(nx[d][i][j]), get<2>(nx[d][i][j]))){
                    //puts("GIROU");
                    d = (d+1)%4;
                    ans++;
                }
                //puts("ANDOU");
                ans++; // walk again
                stop = false;
            }
            tie(d, i, j) = nx[d][i][j];
        }
        printf("%d\n", ans);
    }
}

