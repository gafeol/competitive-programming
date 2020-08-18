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

const int MAXN = 212345;

int n, m, k;
ll s[MAXN];
ll q[MAXN];

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

pii get(ll x){
    pii p;
}

const int MAXB = 150;
int EPS = 50;
const int INF  = MAXB - EPS - 5;
int bit[MAXB][MAXB];

void updy(int i, int j){
    while(j < MAXB){
        //printf("upd %d %d\n", i, j);
        bit[i][j]++;
        j += (j&-j);
    }
}

void upd(int i, int j){
    i += EPS;
    j += EPS;
    for(int a=i;a>=0;a--){
        for(int b=j;b>=0;b--){
            bit[a][b]++;
        }
    }
}

int qryy(int i, int j){
    int ans = 0;
    while(j > 0){
        //printf("qry %d %d\n", i, j);
        ans += bit[i][j];
        j -= (j&-j);
    }
    return ans;
}

int qry(int i, int j){
    i += EPS; 
    j += EPS;
    return bit[i][j];
}


int main (){
	scanf("%d", &n);
    ll ans = 0;
	for(int a=0;a<n;a++){
        char num[30];
        scanf(" %s", num);
        int sz = strlen(num);
        s[a] = 0;
        q[a] = 1;
        bool pass = false;
        for(int i=0;i<sz;i++){
            if(num[i] == '.')
                pass = true;
            else{
                s[a] *= 10; 
                s[a] += num[i]-'0';
                if(pass)
                    q[a] *= 10;
            }
        }
        ll gc = gcd(s[a], q[a]);
        s[a] /= gc;
        q[a] /= gc;
        //printf("s %lld q %lld\n", s[a], q[a]);
        pii bal = {0, 0};
        while(q[a]%2 == 0){
            bal.fst--;
            q[a]/=2;
        }
        while(q[a]%5 == 0){
            bal.snd--;
            q[a]/=5;
        }

        while(s[a]%2 == 0){
            bal.fst++;
            s[a]/=2;
        }
        while(s[a]%5 == 0){
            bal.snd++;
            s[a]/=5;
        }

        ans += qry(-bal.fst, -bal.snd);
        upd(bal.fst, bal.snd);
	}
    printf("%lld\n", ans);
}

