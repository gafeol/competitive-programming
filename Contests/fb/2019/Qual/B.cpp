//Leapgfrog CH 2
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

const int MAXN = 212345;

int n, m, k;
char s[5123];

int main (){
    for_tests(t, tt){
        scanf(" %s", s);
        n = strlen(s);
        int cnt = 0;
        for(int i=0;i<n;i++){
            char c = s[i];
            cnt += (c == 'B');
        }
        printf("Case #%d: ", tt);
        if(cnt >= min(n/2, 2) && cnt <= n-2)
            puts("Y");
        else
            puts("N");
    }
}

