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

const int MAXN = 28;

int n, m, k;
char M[MAXN][MAXN];

bool bef(pii p, pii pp){ // left or top
    return (p.snd <= pp.snd || (p.snd == pp.snd && p.fst <= pp.fst));
}

bool valid(int i, int j){
    return (i>=0 && j>=0 && i < n && j < m);
}

int main (){
    for_tests(t, tt){
        int countP =0;
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf(" %c", &M[a][b]);
                countP += (M[a][b] == '.');
            }
        }

        vector<pair<pii, pii>> ans;

        for(int d=0;d<n+m;d++){
            bool ok = true;
            pii pri = {INT_MAX, INT_MAX}, lst = {INT_MIN, INT_MIN};
            int cnt = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int diag = i+j;
                    if(diag == d){
                        pri = min(pri, {i, j});
                        lst = max(lst, {i, j});
                        if(M[i][j] != '#')
                            ok = false;
                    }
                    else{
                        int dd = d - diag;
                        int oi = i + dd, oj = j + dd;
                        if(valid(oi, oj)){
                            if(max(M[i][j], M[oi][oj]) == max('#', '.') && min(M[i][j], M[oi][oj]) == min('#', '.')){
                                cnt++;
                            }
                            else
                                ok = false;
                        }
                    }
                }
            }
            if(!bef(pri, lst))
                swap(pri, lst);
            if(ok && cnt == countP*2)
                ans.pb({pri, lst});
        }

        for(int d=-m+1;d<n;d++){
            bool ok = true;
            pii pri = {INT_MAX, INT_MAX}, lst = {INT_MIN, INT_MIN};
            int cnt = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int diag = i-j;
                    if(diag == d){
                        pri = min(pri, {i, j});
                        lst = max(lst, {i, j});
                        if(M[i][j] != '#')
                            ok = false;
                    }
                    else{
                        int dd = diag - d;
                        int oi = i - dd, oj = j + dd;
                        if(valid(oi, oj)){
                            if(max(M[i][j], M[oi][oj]) == max('#', '.') && min(M[i][j], M[oi][oj]) == min('#', '.')){
                                cnt++;
                            }
                            else{
                                ok = false;
                            }
                        }
                    }
                }
            }
            if(!bef(pri, lst))
                swap(pri, lst);
            if(ok && cnt == countP*2)
                ans.pb({pri, lst});
        }

        for(int lin=0;lin<n;lin++){
            int cnt = 0;
            bool ok = true;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i <= lin){
                        int oi = lin+(lin-i+1);
                        int oj = j;
                        if(valid(oi, oj)){
                            if(max(M[i][j], M[oi][oj]) == max('#', '.') && min(M[i][j], M[oi][oj]) == min('#', '.')){
                                cnt++;
                            }
                            else
                                ok = false;
                        }
                    }
                }
            }
            pii pri = {lin, 0};
            pii lst = {lin, m-1};
            if(ok && cnt == countP)
                ans.pb({pri, lst});
        }

        for(int col=0;col<m;col++){
            int cnt = 0;
            bool ok = true;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(j <= col){
                        int oi = i;
                        int oj = col + (col - j + 1);
                        if(valid(oi, oj)){
                            if(max(M[i][j], M[oi][oj]) == max('#', '.') && min(M[i][j], M[oi][oj]) == min('#', '.')){
                                cnt++;
                            }
                            else
                                ok = false;
                        }
                    }
                }
            }
            pii pri = {0, col};
            pii lst = {n-1, col};
            if(ok && cnt == countP)
                ans.pb({pri, lst});
        }
        assert(!ans.empty());
        sort(ans.begin(), ans.end());
        printf("%d %d %d %d\n", ans[0].fst.fst+1, 1+ans[0].fst.snd, 1+ans[0].snd.fst, 1+ans[0].snd.snd);
    }
}

