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
pii s[MAXN], ss[MAXN], mx, mn;

int main (){
	scanf("%d%d%d", &n, &m, &k);
    mx.fst = mx.snd = INT_MIN;
    mn.fst = mn.snd = INT_MAX;
	for(int a=0;a<k;a++){
        scanf("%d%d", &s[a].fst, &s[a].snd);
	}
	for(int a=0;a<k;a++){
        scanf("%d%d", &ss[a].fst, &ss[a].snd);
        mx.fst = max(mx.fst, ss[a].fst - s[a].fst);
        mx.snd = max(mx.snd, ss[a].snd - s[a].snd);
        mn.fst = min(mn.fst, ss[a].fst - s[a].fst);
        mn.snd = min(mn.snd, ss[a].snd - s[a].snd);
	}
    vector<char> ans;
        for(int a=0;a<n-1;a++)
            ans.pb('U');
        for(int a=0;a<m-1;a++)
            ans.pb('L');
        for(int a=0;a<m;a++){
            for(int b=0;b<n-1;b++){
                if(a&1)
                    ans.pb('U');
                else
                    ans.pb('D');
            }
            if(a < m-1)
                ans.pb('R');
        }
        printf("%d\n", ans.size());
        for(char c: ans)
            printf("%c", c);
        puts("");
}

