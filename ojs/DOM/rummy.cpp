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

int eq(vector<int> &v){
    int mxsum = 0;
    for(int x=1;x<=13;x++){
        int sum = 0;
        for(int val: v){
            if(val == x){
                sum += val;
            }
        }
        if(sum >= x*3)
            mxsum = max(mxsum, sum);
    }
    return mxsum;
}

int sq(vector<int> &v){
    int mxsum = 0;
    for(int ini=1;ini<=13;ini++){
        int sum = 0;
        int cnt = 0;
        int val = ini;
        for(int x: v){
            if(x == val){
                sum += x;
                val += 1;
                cnt++;
            }
        }
        if(cnt >= 3){
            mxsum = max(mxsum, sum);
        }
    }
    return mxsum;
}

int go(vector<int> &v){
    int sum = 0;
    for(int x:v)
        sum += x;
    return sum -  max(eq(v), sq(v));     
}

int main (){
    vector<int> v;
    n = 7;
	for(int a=0;a<n;a++){
        int x;
        scanf("%d", &x);
        v.pb(x);
	}
    int res = INT_MAX;
    sort(v.begin(), v.end());
    for(int bm=0;bm<(1<<n);bm++){
        vector<int> s1, s2;
        for(int i=0;i<n;i++){
            if((bm&(1<<i)))
                s1.pb(v[i]);
            else
                s2.pb(v[i]);
        }
        res = min(res, go(s1) + go(s2));
    }
    printf("%d\n", res);
}
