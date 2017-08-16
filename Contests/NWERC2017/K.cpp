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

const int K = 21;
const int N = (1<<K);

double qn[N], qd[N];
int qnf, qnb, qdf, qdb;

int k, r;

int main (){
	scanf(" %d%d", &k, &r); --r;
	double ans = 0;
	for(int l=1;(1<<l) <= r; l++){
		double loc = 1;
		qnf = qnb = 0;
		qdf = qdb = 0;
		for(int i=1;i<(1<<k);i++){
			if(i <= (1<<k) - (1<<l)) qn[qnb++] = i;
			if(i <= r)               qn[qnb++] = i;
			if(i <= (1<<k))          qd[qdb++] = i;
			if(i <= r-(1<<l))        qd[qdb++] = i;
		}

		reverse(qn, qn+qnb);
		reverse(qd, qd+qdb);

		while(qnf < qnb || qdf < qdb){
			if(qnf == qnb || qdf == qdb){
				while(qnf < qnb) loc *= qn[qnf++];
				while(qdf < qdb) loc /= qd[qdf++];
			}

			while(qnf < qnb && loc  < 1e3) loc *= qn[qnf++];
			while(qdf < qdb && 1e-3 < loc) loc /= qd[qdf++];
		}

		cerr << double(l)*loc*(1.-loc) << endl;
		ans += double(l)*loc*(1.-loc);
	}
	printf("%.5lf\n", ans);
}
