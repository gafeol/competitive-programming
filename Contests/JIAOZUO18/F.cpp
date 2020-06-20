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

int n, m, t, k;
vector<vector<char>> M;

int vi[] = {-2, -4, -2, 2, 4, 2};
int vj[] = {-6, 0, 6, -6, 0, 6};
map<int, map<int, int>> d;

bool wall(int i, int j){
    return (M[i][j] != ' ' && M[i][j] != 'S' && M[i][j] != 'T');
}

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < M.size() && j < M[i].size() && !wall(i, j));
}
char lin[112345];

int main (){
    for_tests(t, tt){
        M.clear();
        d.clear();
        scanf("%d %d", &n, &m);
        if(m == 1)
            n = n*4 + 1;
        else
            n = n*4 + 3;
        M.resize(n);
        int si, sj, ti, tj;
        char a = getchar();
        for(int i=0;i<n;i++){
            char c;
            while((c = getchar()) != '\n'){
                M[i].pb(c); 
            }
            for(int j=0;j<M[i].size();j++){
                if(M[i][j] == 'S'){
                    si = i;
                    sj = j;
                }
                else if(M[i][j] == 'T'){
                    ti = i;
                    tj = j;
                }
            }
        }
        assert(M[si][sj] == 'S');
        d[si][sj] = 1;
        queue<pii> q;
        q.push({si, sj});
        while(!q.empty()){
            pii p = q.front();
            q.pop();
            int i = p.fst, j = p.snd;
            for(int dir=0;dir<6;dir++){
                int ii = i + vi[dir], jj = j + vj[dir];
                int mi = i + vi[dir]/2, mj = j + vj[dir]/2;
                if(valid(ii, jj) && valid(mi, mj) && d[ii].find(jj) == d[ii].end()){
                    d[ii][jj] = d[i][j] + 1;
                    //M[ii][jj] = d[ii][jj] + '0';
                    q.push({ii, jj});
                }
            }
        }
        /*
        for(vector<char> s: M){
            for(char c: s){
                printf("%c", c);
            }
            puts("");
        }
        */
        if(d[ti].find(tj) == d[ti].end())
            puts("-1");
        else
            printf("%d\n", d[ti][tj]);
    }
}

