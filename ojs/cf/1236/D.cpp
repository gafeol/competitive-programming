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

const int MAXN = 112345;

ll n, m, k;

set<int> lin[MAXN], col[MAXN];

int main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int a=0;a<k;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        lin[i].insert(j);
        col[j].insert(i);
    }
    for(int a=0;a<n;a++){
        lin[a].insert(m);
        lin[a].insert(-1);
    }
    for(int a=0;a<m;a++){
        col[a].insert(n);
        col[a].insert(-1);
    }
    ll cnt = 1;
    int i = 0, j = 0;
    int bi = 0, ei = n-1, bj = 0, ej = m-1;
    int d = 0;
    while(bi <= ei && bj <= ej){
        //printf("i %d j %d\n", i, j);
        int ii = i, jj = j;
        if(d == 0){
            jj = min(ej, *lin[i].lower_bound(j)-1);
            bi++;
            ej = jj;
        }
        else if(d == 1){
            ii = min(ei, *col[j].lower_bound(i)-1);
            ej--;
            ei = ii;
        }
        else if(d == 2){
            jj = max(bj, *(--lin[i].lower_bound(j)) + 1);
            ei--;
            bj = jj;
        }
        else {
            ii = max(bi, *(--col[j].lower_bound(i)) + 1);
            bj++;
            bi = ii;
        }

        d = (d+1)%4;
        if(abs(ii - i) + abs(jj - j) == 0) break;
        cnt += (ll)abs(ii - i) + (ll)abs(jj - j);
        i = ii; j = jj;
    }
    if(cnt == n*m - k)
        puts("Yes");
    else{

        cnt = 1;
        i = 0; j = 0;
        bi = 0; ei = n-1; bj = 0; ej = m-1;
        d = 1;
        while(bi <= ei && bj <= ej){
            //printf("i %d j %d\n", i, j);
            int ii = i, jj = j;
            if(d == 0){
                jj = min(ej, *lin[i].lower_bound(j)-1);
                bi++;
                ej = jj;
            }
            else if(d == 1){
                ii = min(ei, *col[j].lower_bound(i)-1);
                ej--;
                ei = ii;
            }
            else if(d == 2){
                jj = max(bj, *(--lin[i].lower_bound(j)) + 1);
                ei--;
                bj = jj;
            }
            else {
                ii = max(bi, *(--col[j].lower_bound(i)) + 1);
                bj++;
                bi = ii;
            }

            d = (d+1)%4;
            if(abs(ii - i) + abs(jj - j) == 0) break;
            cnt += (ll)abs(ii - i) + (ll)abs(jj - j);
            i = ii; j = jj;
        }

        if(cnt == n*m - k)
            puts("Yes");
        else
            puts("No");
    }
}
