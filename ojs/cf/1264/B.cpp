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

const int MAXN = 100345;

int n, m, k;
int s[MAXN];
int cnt[4];

vector<int> solve(int beg){
    int ori[4];
    for(int a=0;a<4;a++)
        ori[a] = cnt[a];
    vector<int> ans;
    int u = beg;
    while(1){
        if(u > 3 || cnt[u] == 0) 
            break;  
        cnt[u]--;
        ans.pb(u);
        if(u-1 >= 0 && cnt[u-1] > 0)
            u--;
        else
            u++;
    }

    for(int a=0;a<4;a++)
        cnt[a] = ori[a];
    return ans;
}

int main (){
    for(int a=0;a<4;a++){
        scanf("%d", cnt+a);
        n += cnt[a];
    }
    vector<int> ans;
    int i = 0;
    do {
        ans = solve(i);
        i++;
    } while(ans.size() != n && i < 4);

    if(ans.size() < n)
        puts("NO");
    else{
        puts("YES");
        for(int x: ans)
            printf("%d ", x);
        puts("");
    }
}

