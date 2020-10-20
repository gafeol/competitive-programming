#include "bits/stdc++.h"
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
char s[MAXN];

int v[MAXN];
int bit[MAXN];

void upd(int i){
    i += 2;
    while(i > 0){
        bit[i]++;
        i -= (i&-i);
    }
}

int qry(int i){
    i += 2;
    int ans = 0;
    while(i < MAXN){
        ans += bit[i];
        i += (i&-i);
    }
    return ans;
}

map<char, set<int>> pos;

int main (){
	scanf("%d", &n);
    scanf(" %s", s);
	for(int a=0;a<n;a++){
        pos[s[a]].insert(a);
	}

    ll cus = 0;
    for(int i=0;i<n;i++){
        int j = n -1 -i;
        char c = s[j]; 
        int p = *pos[c].begin();
        //printf("quero %c pos %d\n", c, p);
        v[p] = i;
        pos[c].erase(p);
    }
    for(int a=0;a<n;a++){
        cus += qry(v[a]);    
        upd(v[a]);
    }
    printf("%lld\n", cus);
}

