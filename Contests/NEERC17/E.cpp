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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int cnt[MAXN];

int main (){
	scanf("%d", &n);
    vector<int> ans;
    int u = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        if(s[a] == 0){
            u++;
            continue;
        }
        if(s[a] > 0){
            cnt[s[a]]++;
        }
        else{
            s[a] = -s[a];
            if(cnt[s[a]] > 0)
                cnt[s[a]]--;
            else{
                if(u == 0){
                    puts("No");
                    return 0;
                }
                u--;
                ans.pb(s[a]);
            }
        }
	}
    puts("Yes");
    for(int a=0;a<ans.size();a++)
        printf("%d ", ans[a]);
    for(int a=0;a<u;a++){
        printf("1 ");
    }
    puts("");
    return 0;
}

