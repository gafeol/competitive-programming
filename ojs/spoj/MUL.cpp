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

const int MAXN = 21234;

typedef complex<long double> Complex;
const long double PI = acos(-1.0L);
// Computes the DFT of vector v if type = 1, or the IDFT if type = -1
vector<Complex> FFT(vector<Complex> v, int type) {
	int n = v.size();
	while(n&(n-1)) { v.push_back(0); n++; }
	int logn = __builtin_ctz(n);
	vector<Complex> v2(n);
	for(int i=0; i<n; i++) {
		int mask = 0;
		for(int j=0; j<logn; j++) if(i&(1<<j)) mask |= (1<<(logn - 1 - j));
		v2[mask] = v[i];
	}
	for(int s=0, m=2; s<logn; s++, m<<=1) {
		Complex wm(cos(2.L * type * PI / m), sin(2.L * type * PI / m));
		for(int k=0; k<n; k+=m) {
			Complex w = 1;
			for(int j=0; 2*j<m; j++) {
				Complex t = w * v2[k + j + (m>>1)], u = v2[k + j];
				v2[k + j] = u + t; v2[k + j + (m>>1)] = u - t;
				w *= wm;
			}
		}
	}
	if(type == -1) for(Complex &c: v2) c /= n;
	return v2;
}

int n, m, k;

vector<Complex> A, B, C;

char s[MAXN], v[MAXN];

stack<int> res;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		A.clear();
		B.clear();
		C.clear();
		scanf(" %s %s", s, v);
		int ts = strlen(s), tv = strlen(v);
		for(int a=ts-1;a>=0;a--){
			debug("A %d\n", (s[a]-'0'));
			A.pb(Complex(s[a]-'0', 0));
		}
		for(int a=tv-1;a>=0;a--){
			debug("B %d\n", (v[a]-'0'));
			B.pb(Complex(v[a]-'0', 0));
		}
		while(ts < tv){
			A.pb(0);
			ts++;
		}
		while(tv < ts){
			B.pb(0);
			tv++;
		}
		A = FFT(A, 1);
		B = FFT(B, 1);
		for(int i = 0;i < B.size();i++){
			C.pb(A[i]*B[i]);
		}
		C = FFT(C, -1);
		int c = 0;
		for(Complex u: C){
			int x = u.real() + 0.5L;	
			debug("%d = %.3Lf %.3Lfi\n", x, u.real(), u.imag());
			res.push((x+c)%10);
			c = (x + c)/10;
		}
		while(c != 0){
			res.push(c%10);
			c /= 10;
		}
		while(!res.empty()){
			printf("%d", res.top());
			res.pop();
		}
		printf("\n");
	}
}

