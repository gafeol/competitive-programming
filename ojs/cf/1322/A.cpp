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

const int MAXN = 1123456;

int n, m, k;
char s[MAXN];

int main (){
	scanf("%d", &n);
    scanf(" %s", s);
    int cnt = 0;
    int ans = 0;
    for(int a=0;a<n;a++){
        cnt += (s[a] == '(');
        cnt -= (s[a] == ')');
        if(cnt < 0 || (cnt == 0 && s[a] == '('))
            ans++;
    }
    if(cnt != 0){
        puts("-1");
        return 0;
    }
    printf("%d\n", ans);

}

