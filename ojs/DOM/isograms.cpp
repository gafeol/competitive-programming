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
int cnt[500];

int main (){
    for_tests(t, tt){
        char s[40];
        scanf(" %s", s);
        int n = strlen(s);
        for(int a=0;a<n;a++)
            cnt[s[a]] = 0;
        for(int a=0;a<n;a++)
            cnt[s[a]]++;
        int val = cnt[s[0]];
        bool ok = true;
        for(int a=0;a<n;a++){
            if(cnt[s[a]] != val){
                ok = false;
            }
        }
        printf("Test #%d: ", tt);
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
}

