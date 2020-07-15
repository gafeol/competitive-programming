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

int n, m, k;
int dp[21][21][201]; 
int dig = 20;


void clear(int ndig){
    for(int a=0;a<ndig;a++){
        for(int b=0;b<ndig;b++){
            for(int val=0;val<=n;val++){
                dp[a][b][val] = -1;
            }
        }
    }
}

bool go(int i, int n9, int sum){
    if(sum < 0) return 0;   
    int &r = dp[i][n9][sum];
    if(r != -1) return r;
    if(i == 0){
        bool ok = 0;
        int osum = sum;
        for(int d=0;d<10;d++){ 
            int below = min(k+1, 10-d); 
            int aft = k+1 - below;
            ll bc = n9*9*below + ((d + d+below-1)*below)/2;
            ll ac = 0;
            if(aft > 0)
                ac = 1*aft + ((0 + aft-1)*aft)/2;
            sum = osum - bc - ac; 
            ok |= (sum == 0);
        }
        return r = ok;
    }

    for(int d=0;d<9;d++){
        if(go(i-1, 0, sum - d*(k+1) - n9*9*(k+1)))
            return r = 1;
    }
    return r = go(i-1, n9+1, sum);
}

void re(int i, int n9, int sum){
    if(i == 0){
        bool ok = 0;
        int osum = sum;
        for(int d=0;d<10;d++){ 
            int below = min(k+1, 10-d); 
            int aft = k+1 - below;
            ll bc = n9*9*below + ((d + d+below-1)*below)/2;
            ll ac = 0;
            if(aft > 0)
                ac = 1*aft + ((0 + aft-1)*aft)/2;
            sum = osum - bc - ac; 
            if(sum == 0){
                printf("%d", d);
                return ;
            }
        }
    }

    for(int d=0;d<9;d++){
        if(go(i-1, 0, sum - d*(k+1) - n9*9*(k+1))){
            printf("%d", d);
            re(i-1, 0, sum - d*(k+1) - n9*9*(k+1));
            return ;
        }
    }
    printf("9");
    re(i-1, n9+1, sum);
}


int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        int i = 1, j = dig;
        while(i < j){
            int m = (i + j)/2;            
            clear(m);
            if(go(m-1, 0, n))
                j = m;
            else
                i = m+1;
        }
        if(!go(i-1, 0, n)){
            puts("-1");
        }
        else{
            re(i-1, 0, n);
            puts("");
        }
    }
}

