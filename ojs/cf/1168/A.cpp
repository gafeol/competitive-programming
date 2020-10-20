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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

bool go(int k){
    int ult = 0;
    for(int a=0;a<n;a++){
        if(s[a] <= ult){
            if(ult - s[a] > k)
                return false;
        }
        else{
            if(ult + m - s[a] > k){
                ult = s[a];
            }
        }
    }
    return true;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    int i =0, j = m+1;
    while(i < j){
        int mid = (i+j)/2;
        if(go(mid))
            j = mid;
        else
            i = mid+1;
    }
    printf("%d\n", i);
}

