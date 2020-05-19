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
char s[MAXN];

int main (){
    for_tests(t, tt){
        scanf(" %s", s);
        n = strlen(s);
        int cnt[3];
        memset(cnt, 0, sizeof(cnt));
        int b = -1;
        int ans = INT_MAX;
        for(int a=0;a<n;a++){
            while(b+1 < n && min(min(cnt[0], cnt[1]), cnt[2]) == 0){
                cnt[s[b+1]-'1']++; 
                b++;
            }
            if(min(min(cnt[0], cnt[1]), cnt[2]) > 0)
                ans = min(ans, b - a + 1);
            cnt[s[a]-'1']--;
        }
        if(ans == INT_MAX)
            puts("0");
        else
            printf("%d\n", ans);
    }
}

