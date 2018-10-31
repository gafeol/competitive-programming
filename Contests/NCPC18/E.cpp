#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int ss[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

unordered_map<int, unordered_map<int, double> > dp;

bool cmp(int a, int b){
	return a > b;
}

int st(int bm){
	int A[5];
	for(int i=4;i>=0;i--){
		A[i] = bm%7;
		bm /= 7;
	}
	sort(A, A+5, cmp);
	bm = 0;
	for(int i=0;i<5;i++){
		bm *= 7;
		bm += A[i];
	}
	return bm;
}

int S, d;

double go(int bma, int bmb){
	bma = st(bma);
	bmb = st(bmb);
	if(dp[bma].find(bmb) != dp[bma].end())
		return dp[bma][bmb];
	double &r = dp[bma][bmb];
	int A[5], B[5];
	int obma = bma, obmb = bmb;
	int na = 0, nb = 0;

	//printf("go %d %d\n", bma, bmb);
	int sum = 0;
	for(int i=4;i>=0;i--){
		A[i] = (bma%7);
		//printf("%d ", A[i]);
		sum += A[i];
		bma /= 7;
		na += (A[i] > 0);
	}
	//puts("");
	for(int i=4;i>=0;i--){
		B[i] = (bmb%7);
		//printf("%d ", B[i]);
		sum += B[i];
		bmb /= 7;
		nb += (B[i] > 0);
	}
	//puts("");
	//printf("na %d nb %d\n", na, nb);
	//printf("S %d sum %d\n", S, sum);
	if(nb == 0)
		return r = 1.;
	if(S - sum >= d)
		return r = 0;
	r = 0;
	for(int a=0;a<5;a++){
		if(A[a] == 0) continue;
		A[a]--;
		int nbma = 0;
		for(int i=0;i<5;i++){
			nbma *= 7ll;
			nbma += A[i];
		}
		//printf("res %d %d += %.3f * %.3f\n", obma, obmb, 1./(na+nb), go(nbma, obmb));
		r  += (1./(na+nb))*go(nbma, obmb);
		A[a]++;
	}
	for(int a=0;a<5;a++){
		if(B[a] == 0) continue;
		B[a]--;
		int nbmb = 0;
		for(int i=0;i<5;i++){
			nbmb *= 7ll;
			nbmb += B[i];
		}
		//printf("res %d %d += %.3f * %.3f\n", obma, obmb, 1./(na+nb), go(obma, nbmb));
		r += (1./(na+nb))*go(obma, nbmb);
		B[a]++;
	}
	//printf("dp[%d][%d] %.3f\n", obma, obmb, r);
	return r;	
}

int main (){
	scanf("%d%d%d", &n, &m, &d);
	int bm = 0;

	for(int a=0;a<5;a++){
		if(a < n)
			scanf("%d", s+a);
		else
			s[a] = 0;
		bm *= 7;
		bm += s[a];
		S += s[a];
	}
	int bbm = 0;
	for(int a=0;a<5;a++){
		if(a < m)
			scanf("%d", ss+a);
		else
			ss[a] = 0;
		bbm *= 7;
		bbm += ss[a];
		S += ss[a];
	}
	printf("%.15f\n", go(bm, bbm));
}

