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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k, mxsz;
int s[MAXN], c[MAXN];

int go(int mn){
    int i = 0, j = mxsz;
    while(i < j){
        int m = (i + j + 1)/2;
        if(c[m] > mn)
            i = m;
        else
            j = m-1;
    }

    return i;
}

int main (){
	scanf("%d%d", &n, &mxsz);
    multiset<int> q;
	for(int a=0;a<n;a++){
        int x;
        scanf("%d", &x);
        q.insert(x);
	}
    c[0] = n;
    for(int a=1;a<=mxsz;a++){
        scanf("%d", c+a);
    }
    vector<vector<int>> ans;
    while(!q.empty()){
        vector<int> res;
        res.pb(*q.rbegin());
        q.erase(q.find(*q.rbegin()));
        debug("add ini %d\n", res.back());
        while(1){
            int mxposs = go(res.size());
            debug("mxposs %d\n", mxposs);
            auto it = q.upper_bound(mxposs);
            if(q.empty() || it == q.begin()){
                ans.pb(res); 
                break;
            }
            int val =  *(--it);
            q.erase(q.find(val));
            res.pb(val);
            debug("add %d\n", res.back());
        }
    }
    printf("%d\n", (int)ans.size());
    for(vector<int> &v: ans){
        printf("%d ", (int)v.size());
        for(int x: v)
            printf("%d ", x);
        puts("");
    }
}

