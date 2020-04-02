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

const int MAXN = 2123;

int n, m, k;
char s[MAXN];

int main (){
    scanf(" %s", s);
    n = strlen(s);

    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += (s[i] == ')');
    }
    int res = 0;
    int f =0;
    int bst = -1;
    for(int a=0;a<n;a++){
        f += (s[a] == '(');
        cnt -= (s[a] == ')');
        if(res < min(f, cnt)){
            res = min(f, cnt);
            bst = a;
        }
    }

    if(bst == -1){
        puts("0");
        return 0;
    }

    puts("1");
    vector<int> ans;
    cnt = res;
    for(int a=0;a<n && cnt;a++){
        if(s[a] == '('){
            cnt--;
            ans.pb(a);
        }
    }
    cnt = res;
    for(int a=n-1;a>=0 && cnt;a--){
        if(s[a] == ')'){
            cnt--;
            ans.pb(a);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for(int x: ans)
        printf("%d ", x+1);
    puts("");
}

