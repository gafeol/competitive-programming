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

const int MAXN = 2123;

int n, m, k;
int h[MAXN], v[MAXN];
int win[MAXN];

bool go(int t){
    for(int a=0;a<n;a++)
        h[a] += t;
    
    for(int a=n-1;a>=0;a--){
        if(h[a] > v[a]){
            win[a] = 1; 
        }
        else if(h[a] == v[a])
            win[a] = (a+1 < n ? win[a+1] : 1);
        else
            win[a] = 0;

    }

    for(int a=0;a<n;a++)
        h[a] -= t;
    return win[0];
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", h+a);
	}
	for(int a=0;a<n;a++){
        scanf("%d", v+a);
	}
    int i = 0, j = 1300;
    while(i < j){
        int m = (i + j)/2;
        if(go(m))
            j = m;
        else
            i = m+1;
    }
    printf("%d\n", i);
}

