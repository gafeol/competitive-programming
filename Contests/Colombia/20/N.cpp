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

const int MAXN = 5123;

int n, m, k;
double s[MAXN];

double S[MAXN], U[MAXN][MAXN];

int main (){
	scanf("%d", &n);
    double fat = 1;
	for(int a=0;a<n;a++){
        fat *= (a+1);
        scanf("%lf", s+a);
        S[1] += (1-s[a]);
        U[1][a] = (1-s[a]);
	}
    for(int k=2;k<=n;k++){
        for(int a=0;a<n;a++){
            U[k][a] = (S[k-1]-U[k-1][a])*(1-s[a]);
            S[k] += U[k][a];
            printf("U[%d][%d] %.10f\n", k, a, U[k][a]);
        }
    }
    double res = 0;
    for(int k=1;k<=n;k++){
        printf("S[%d] %.10f\n", k, S[k]);
        if(k == n){
            printf("k %d res += %.10f\n", k, k*S[k]);
            res += k*S[k];
        }
        else{
            for(int i=0;i<n;i++){
                printf("k %d res += %.10f\n", k, k*(S[k] - U[k][i])*s[i]);
                res += k*(S[k] - U[k][i])*s[i];
            }
        }
    }
    printf("Fat %.10f\n", fat);
    printf("%.10f\n", res/fat);
}

