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

int n, m, k;
int s[MAXN];

int accl[MAXN], accc[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m); 
        for(int i=0;i<=m+1;i++){
            accl[i] = accc[i] = 0;
        }
        for(int a=0;a<n;a++){
            int x, y;
            char d;
            scanf("%d%d %c", &x, &y, &d);
            if(d == 'N'){
                accl[y+1]++;
            }
            else if(d == 'S'){
                accl[0]++;
                accl[y]--;
            }
            else if(d == 'W'){
                accc[0]++;
                accc[x]--;
            }
            else{
                accc[x+1]++;
            }
        }
        int mxl = INT_MIN, mxc = INT_MIN, imxl = 0, imxc = 0;
        for(int i=0;i<=m;i++){
            if(i > 0){
                accl[i] += accl[i-1];
                accc[i] += accc[i-1];
            }
            if(accl[i] > mxl){
                mxl = accl[i];
                imxl = i;
            }
            if(accc[i] > mxc){
                mxc = accc[i];
                imxc = i;
            }
        }
        printf("Case #%d: %d %d\n", tt, imxc, imxl);
    }
}

