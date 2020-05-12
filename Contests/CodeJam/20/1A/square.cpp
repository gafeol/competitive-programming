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


int n, m, k;

int vi[] = {0, 0, -1, 1};
int vj[] = {-1, 1, 0, 0};

bool valid(pii p){
    return (p.fst >= 0 && p.snd >= 0 && p.fst < n && p.snd < m);
}

map<pii, pii> nxt[4];
vector<vector<int>> M;
map<pii, bool> ersd;

bool er(int i, int j){
    int cnt = 0;
    int sum = 0;
    for(int d=0;d<4;d++){
        pii nx = nxt[d][{i, j}];
        if(!valid(nx) || ersd[nx]) continue;
        cnt++;
        sum += M[nx.fst][nx.snd];
    }
    return (cnt > 0 && M[i][j]*cnt < sum);

}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        ll res = 0;
        ll sum = 0;
        M.clear();
        ersd.clear();
        for(int a=0;a<4;a++)
            nxt[a].clear();
        for(int a=0;a<n;a++){
            vector<int> lin;
            for(int b=0;b<m;b++){
                int x;
                scanf("%d", &x); 
                lin.pb(x);
                sum += x;
                for(int d=0;d<4;d++){
                    nxt[d][{a, b}] = {a+vi[d], b+vj[d]};
                }
            }
            M.pb(lin);
        }
        res += sum;
        vector<pii> mrk;
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(er(a, b)){
                    mrk.pb({a, b});
                }
            }
        }
        for(pii p: mrk)
            ersd[p] = true;
        while(mrk.size() > 0){
            vector<pii> mrk2;
            //printf("new round======\n");
            for(pii p: mrk){
                //printf("erase %d %d\n", p.fst, p.snd);
                sum -= M[p.fst][p.snd];
                for(int d=0;d<4;d++){
                   pii nx = nxt[d][p]; 
                   if(!valid(nx)) continue;
                   nxt[d^1][nx] = nxt[d^1][p];
                   if(!ersd[nx] && er(nx.fst, nx.snd))
                       mrk2.pb(nx);
                }
            }
            mrk = mrk2;
            sort(mrk.begin(), mrk.end());
            mrk.erase(unique(mrk.begin(), mrk.end()), mrk.end());
            for(pii p: mrk)
                ersd[p] = true;
            res += sum;
            //printf("Res += %lld\n", sum);
        }
        printf("Case #%d: %lld\n", tt, res);
    }
}

