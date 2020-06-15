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

const int MAXN = 2123456;

int n, m, k;

double res[MAXN];
int qtd[MAXN];
ll sum[MAXN];

bool join(int i, int j){
    return ((sum[i] + sum[j])*(qtd[i]) <= (sum[i])*(qtd[i] + qtd[j]));
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld", sum+a);
        qtd[a] = 1;
	}
    stack<int> q;
    for(int a=n-1;a>=0;a--){
        while(!q.empty() && join(a, q.top())){
            sum[a] += sum[q.top()]; 
            qtd[a] += qtd[q.top()];
            q.pop();
        }
        q.push(a);
    }
    cout << fixed;
    while(!q.empty()){
        int a = q.top();
        q.pop();
        double ans = ((double)sum[a])/qtd[a];
        for(int b=0;b<qtd[a];b++){
            printf("%.12f\n", ans);
        }
    }
}

