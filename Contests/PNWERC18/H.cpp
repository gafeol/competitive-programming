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

const int MAXN = 1000006;

int n, m, k;
int s[MAXN];

int mrk[MAXN];
vector<int> pri;

int main (){
    mrk[0] = mrk[1] = true;
    for(int i=2;i<MAXN;i++){
        if(!mrk[i])
            pri.pb(i);
        for(ll j = i; i*j < MAXN;j++){
            mrk[i*j] = true;
        }
    }
	scanf("%d", &n);
    int cnt = 0;
    for(int i=pri.size()-1;n >= 4 && i>=0;i--){
        if(pri[i] < n && mrk[n - pri[i]] == false){
            //printf("n %d pri %d o %d\n", n, pri[i], n-pri[i]);
            n = pri[i] - (n - pri[i]);
            cnt++;
        }
    }
    printf("%d\n", cnt);
}

