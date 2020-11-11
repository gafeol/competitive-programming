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
char s[MAXN];

int main (){
	scanf("%d", &n);
    int um = 0, carry = 0;
	for(int a=0;a<n;a++){
        scanf(" %c", s+a);
        int x = s[a]-'0';
        if(x == ((carry + um)&1)){
            printf("0");
        }
        else{
            um++;
            printf("1");
        }
        carry = (carry + um)/2;
	}
    puts("");
    return 0;
}

