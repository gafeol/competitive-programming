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

const int MAXN = 2123456;

int n, m, k;
double dp[MAXN];
double pp[MAXN];
double del[MAXN];
double prob;
double sum;
double psum;
const double EPS = 1e-8;

int sz = 0;

void add(int i){
    if(i < 0) return ;
    if(i >= n) return ;
    if(dp[i] >= -EPS){
        sum += (dp[i] + 1);
        psum += prob*pp[i];
        sz++;
    }
}

void rmv(int i){
    if(i < 0) return ;
    if(i >= n) return ;
    if(dp[i] >= -EPS){
        sum -= (dp[i] + 1);
        psum -= prob*pp[i];
        sz--;
    }
}

int main (){
    int l, r;
	scanf("%d%d%d", &n, &l, &r);
    for(int a=0;a<=n+r;a++){
        dp[a] = -1;
        pp[a] = 0;
    }
    int i = -r;
    int j = -l;
    prob = 1./(r - l + 1);
    dp[0] = 0;
    pp[0] = 1;
    double opsum;
    if(l == 0){
        dp[0] = prob;
        double cte = 0;
        prob = 1./r;
        cte = 1./r;
        j--;
        for(int a=0;a<n+r;a++){
            if(a > 0 && sz){
                dp[a] = sum + cte;
                pp[a] = psum;
            }
            j++;
            add(j);
            rmv(i);
            i++;
        }
    }
    else{
        for(int a=0;a<n;a++){
            printf("a %d inter i %d j %d sum %.3f sz %d prob %.3f\n", a, i, j, sum, sz, psum);
            if(sz){
                dp[a] = sum/((double)sz);
                pp[a] = psum;
            }
            printf("dp[%d] %.3f\n", a, dp[a]);
            // incremeneta i, j      
            j++;
            add(j);
            rmv(i);
            i++;
        }
        opsum = psum;

        while(i < n){
            if(sz){
                dp[n] += sum/((double)sz);
            }
            rmv(i);
            i++;
        }
    }
    double ans = 0;
    /*
    for(int a=n;a<n+r;a++){
        if(dp[a] > -EPS)
            ans += pp[a]*dp[a];
    }
    */
    printf("%.10f\n", dp[n]*opsum);

    return 0;
}
