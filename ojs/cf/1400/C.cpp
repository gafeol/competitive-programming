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
char s[MAXN];
vector<int> ans;
bool ok;

int val(int i){
    if(i < 0 || i >= n)
        return -1;
    return ans[i];
}

void mk(int i, int val){
    if(i < 0 || i >= n){
        ok = false;
        return;
    }

    if(ans[i] == -1)
        ans[i] = val;
    else if(ans[i] != val)
        ok = false;
}

int main (){
    for_tests(t, tt){
        ok = true;
        scanf(" %s", s);
        n = strlen(s);
        scanf("%d", &k);
        ans.clear();
        ans.resize(n, -1);
        for(int a=0;a<n;a++){
            if(s[a] == '0'){
                if(a - k >= 0)
                    mk(a-k, 0); 
                if(a + k < n)
                    mk(a+k, 0);
            }
        }
        for(int a=0;a<n;a++){
            if(s[a] == '1'){
                if(a-k < 0  || val(a-k) == 0){
                    mk(a+k, 1);
                    continue;
                }
                if(a+k >= n || val(a+k) == 0){
                    mk(a-k, 1);
                    continue;
                }
                mk(a-k, 1);
            }
        }
        if(!ok){
            puts("-1");
        }
        else{
            for(int a=0;a<n;a++){
                if(ans[a] == -1)
                    ans[a] = 0;
                printf("%d", ans[a]);
            }
            puts("");
        }
    }
}

