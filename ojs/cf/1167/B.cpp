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
int s[MAXN];

int inter(vector<int> v, vector<int> u){
    for(int a=0;a<2;a++){
        for(int b=0;b<2;b++){
            if(v[a] == u[b])
                return v[a];
        }
    }
    assert(false);
}

int notin(vector<int> v, int x){
    for(int a: v){
        if(a != x) 
            return a;
    }
}

int main (){
    vector<int> val = {4, 8, 15, 16, 23, 42};
    n = 6;
    map<int, vector<int> > mrk;
	for(int a=0;a<n;a++){
        for(int b=a+1;b<n;b++){
            int mul = val[a]*val[b];
            mrk[val[a]*val[b]] = {val[a], val[b]};
        }
	}
    vector<vector<int>> ans;
    for(int i=2;i<6;i++){
        printf("? 1 %d\n", i);
        fflush(stdout);
        int mul;
        scanf("%d", &mul);
        ans.pb(mrk[mul]); 
    }
    int fst = inter(ans[0], ans[1]); 

    vector<int> res;
    res.pb(fst);

    map<int, bool> seen;

    seen[fst] = true;
    for(int i=0;i<ans.size();i++){
        int val = notin(ans[i], fst);
        seen[val] = true;
        res.pb(val);
    }


    for(int v: val){
        if(seen[v]) continue;
        res.pb(v);
    }

    printf("!");
    for(int x: res){
        printf(" %d", x);
    }
    puts("");
    fflush(stdout);

}

