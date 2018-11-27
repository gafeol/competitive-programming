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


int aq[MAXN];
int x[MAXN];


int main (){
	double A;
	scanf("%lf", &A);
	A /= 365.;
	scanf("%d", &n);
	int lstid = 0;
	int lq = 0;
	int ms, bef, aft;
	for(int a=0;a<n-2;a++){
		char tp[20];
		int id, x, fim;
		scanf("%d %d %s %d", &id, &x, tp, &fim);
		if(tp[0] == 'c')
			::x[id] = x;
		else
			::x[id] = -x;
		aq[id] = fim;
		if(id > lstid+1){
			ms = lstid+1;
			bef = lq;
			aft = fim - ::x[id];
		}
		lq = fim;
		lstid = id;
	}

	double B;
	scanf("%lf", &B);

	set<tuple<double, int, int> >  q;

	for(int val = -1000;val<=1000;val++){
		if(bef + val < 0) continue;
		x[ms] = val;
		int falta = aft - (bef + val);
		x[ms+1] = falta;
		double it = 0;
		int tot = 0;
		for(int i=1;i<=n;i++){
			tot += x[i];
			it += tot*A;
		}
		q.insert({abs(B - it), val, falta});	
	}
	double _h;
	int val1, val2;
	tie(_h, val1, val2) = *q.begin();
	q.erase(q.begin());
	printf("%d %d ", ms, abs(val1));
	if(val1 < 0)
		printf("debit ");
	else
		printf("credit ");
	printf("%d\n", bef + val1);
	printf("%d %d ", ms+1, abs(val2));
	if(val2 < 0)
		printf("debit ");
	else
		printf("credit ");
	printf("%d", bef + val1+val2);
}

