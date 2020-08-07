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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;

map<map<char, int>, int> cnt;
char s[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        cnt.clear();
        scanf(" %s", s);
        int sz = strlen(s);
        int ans = 0;
        for(int i=0;i<sz;i++){
            map<char, int> q;
            for(int j=i;j<sz;j++){
                q[s[j]]++;
                ans += cnt[q];
                cnt[q]++;
            }
        }
        printf("%d\n", ans);
	}
}

