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
        bool ok = true;
        for(int a=1;a<n;a++)
            ok &= (s[a] == s[a-1]);
        if(ok)
            printf("%s\n", s);
        else{
            int lst = s[0]-'0';
            printf("%d", lst);
            for(int a=1;a<n;a++){
                if(lst == s[a]-'0')
                    printf("%d", (lst^1));
                printf("%c", s[a]);
                lst = s[a]-'0';
            }
            puts("");
        }
    }
}
