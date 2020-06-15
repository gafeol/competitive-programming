#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123456;
int n, m, k;
ll x[MAXN], y[MAXN], s[MAXN];
ll dp[MAXN];
int ind[MAXN];

deque<int> st;
deque<double> ate;

ll qry(ll y){
    int i = lower_bound(ate.begin(), ate.end(), y) - ate.begin();
    int id = st[i];
    //debug("qry %lld  id %d (st[%d]) e -%lld*%lld + %lld\n", y, id, i, y, x[id], dp[id]);
    return -y*x[id] + dp[id];
}

double interX(int i, int j){
    //debug("inter X %d %d is %.3f\n", i, j, (dp[j] - dp[i])/((double)x[j] - x[i]));
    return (dp[j] - dp[i])/((double)x[j] - x[i]); 
}

void add(int id){
    while(!st.empty() && interX(st.front(), id) >= ate.front()){
        st.pop_front();
        ate.pop_front();
    }
    ate.push_front(interX(st.front(), id));
    st.push_front(id);


//    debug("after add %d\n", id);
//    debug("ate:\n");
//    for(double x: ate)
//        debug("%.3f ", x);
//    debug("\n");
//    debug("st:\n");
//    for(int id: st)
//        debug("%d ", id);
//    debug("\n");
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld%lld%lld", x+a, y+a, s+a);
        ind[a] = a;
	}
    ate.push_back(INT_MAX);
    st.push_back(n);
    sort(ind, ind+n, [&](int a, int b) { return x[a] < x[b]; });
    ll ans = 0;
    for(int ii=0;ii<n;ii++){
        int i = ind[ii];
        dp[i] = x[i]*y[i] - s[i] + qry(y[i]);    
        //debug("reta x*(-%lld) + %lld\n", x[i], dp[i]);
        ans = max(ans, dp[i]);
        add(i);
    }
    printf("%lld\n", ans);
}
