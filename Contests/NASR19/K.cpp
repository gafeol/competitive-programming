#include <bits/stdc++.h>
using namespace std;
#define double long double
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
pii s[MAXN];


double inter(pii a, pii b){
    if(a.fst == b.fst){
        return DBL_MAX;
    }
    return ((double)b.snd - a.snd)/(a.fst - b.fst);
}

int f(vector<int> &v, int o){
    map<int,int> cnt;
    int mai = 0;
    int lst = v.back();
    v.pop_back();
    int tam = v.size();
    for(int i=0;i<tam;i++)
        v.pb(v[i]);
    v.pb(lst); 
    v.pb(o);
    for(int x: v){
        cnt[x]++;
        mai = max(mai, cnt[x]);
    }
    return mai;
}

int main (){
	scanf("%d", &n);
    int ori[MAXN];
	for(int i=0;i<n;i++){
        ori[i] = i;
        int a, b;
        scanf("%d%d", &a, &b);
        s[i] = {a, -b};
	}
    if(n == 2){
        puts("1");
        return 0;
    }
    vector<tuple<double, int, int>> X;
    for(int a=0;a<n;a++){
        for(int b=a+1;b<n;b++){
            if(inter(s[a], s[b]) < DBL_MAX/2)
                X.pb({inter(s[a], s[b]), a, b});
        }
    }
    sort(X.begin(), X.end());
    vector<int> ans[MAXN];
    for(tuple<double, int, int> tp: X){
        double x;
        int i, j;
        tie(x, i, j) = tp;
        ans[ori[i]].pb(j);
        ans[ori[j]].pb(i);
        swap(ori[i], ori[j]);
    }
    int mai = -1;
    for(int a=0;a<n;a++){
        mai = max(mai, f(ans[a], a));
    }
    printf("%d\n", mai);
}

