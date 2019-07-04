//Leapgfrog CH 1
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
int s[MAXN];

int main (){
    for_tests(t, tt){
        char s[5123];
        scanf(" %s", s);
        n = strlen(s);
        int cnt = 0;
        for(char c: s)
            cnt += (c == 'B');
        printf("Case #%d: ", tt);
        if(cnt >= n/2 && cnt <= n-2)
            puts("Y");
        else
            puts("N");
    }
}

