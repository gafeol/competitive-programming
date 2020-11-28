#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 20;

int n, m, k;
int s[MAXN];
int mrk[MAXN][MAXN];

bool valid(int i, int j){
    return (i >= 1 && j >= 1 && i <= 10 && j <= 10);
}


int main (){
	scanf("%d", &n);
    bool ok = true;
	for(int a=0;a<n;a++){
        int d, l, r, c;
        scanf("%d%d%d%d", &d, &l, &r, &c);
        if(d == 0){
            if(valid(r, c) && valid(r, c+l-1)){
                for(int j=c;j<=c+l-1;j++){
                    mrk[r][j]++;
                    if(mrk[j][c] > 1)
                        ok = false;
                }
            }
            else
                ok = false;
        }
        else{
            if(valid(r, c) && valid(r+l-1, c)){
                for(int j=r;j<=r+l-1;j++){
                    mrk[j][c]++;
                    if(mrk[j][c] > 1)
                        ok = false;
                }
            }
            else
                ok = false;
        }
    }
    if(ok)
        puts("Y");
    else
        puts("N");
    return 0;
}

