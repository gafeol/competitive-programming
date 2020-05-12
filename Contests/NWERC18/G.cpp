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
char s[MAXN];

map<int, map<int, int> > mrk;
int x = 0; 
int y = 0;

int mnx, mxx, mny, mxy;

map<char, int> dic;


int vx[] = {0, -1, 1, 0};
int vy[] = {-1, 0, 0, 1};
vector<pii> walls;

void add_wall(int x, int y){
    mrk[x][y] = 2;
    walls.pb({x, y});
    mnx = min(mnx, x);
    mxx = max(mxx, x);
    mny = min(mny, y);
    mxy = max(mxy, y);
}

void go(int d){
    //debug("go %d\n", d);
    while(1){
        //printf("x %d y %d\n", x, y);
        assert(mrk[x][y] != 2);
        mrk[x][y] = 1;
        int xx = x + vx[d];
        int yy = y + vy[d];
        //printf("xx %d yy %d d %d\n", xx, yy, d);
        if(mrk[xx][yy] == 2) return;
        if(x < mnx || x > mxx || y < mny || y > mxy){
            add_wall(xx, yy);
            return;
        }
        x = xx;
        y = yy;
    }
}

int endX, endY;

void goEnd(int d){
    //debug("go end\n");
    while(1){
        if(mrk[x][y] == 0){
            endX = x;
            endY = y;
            return;
        }
        int xx = x + vx[d];
        int yy = y + vy[d];
        if(mrk[xx][yy] == 2){
            puts("impossible");
            exit(0);
        }
        x = xx;
        y = yy;
    }
}

int main (){
	scanf(" %s", s);
    dic['D'] = 0;
    dic['L'] = 1;
    dic['R'] = 2;
    dic['U'] = 3;
    n = strlen(s);
    mrk[0][0] = 1;
    for(int a=0;a<n-1;a++){
        go(dic[s[a]]);
    }
    goEnd(dic[s[n-1]]);
    printf("%d %d\n", -endX, -endY);
    printf("%d\n", (int)walls.size());
    for(pii p: walls){
        printf("%d %d\n", p.fst - endX, p.snd - endY);
    }
}

