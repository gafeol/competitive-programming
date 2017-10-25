
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
ll s[MAXN];

typedef complex<long double> Complex;
const long double PI = acos(-1.0L);

vector<Complex> A, B;
// Computes the DFT of vector v if type = 1, or the IDFT if type = -1
// If you are calculating the product of polynomials, don't forget to set both
// vectors' degrees to at least the sum of degrees of both polynomials, regardless
// of whether you will use only the first few elements of the resulting array
vector<Complex> FFT(vector<Complex> v, int type) {
    int n = v.size();
    while (n & (n - 1)) { v.push_back(0); n++; }
    int logn = __builtin_ctz(n);
    vector<Complex> v2(n);
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < logn; j++)
            if (i & (1 << j))
                mask |= (1 << (logn - 1 - j));
        v2[mask] = v[i];
    }
    for (int len = 1; 2 * len <= n; len <<= 1) {
        Complex wm(cos(type * PI / len), sin(type * PI / len));
        for (int i = 0; i < n; i += 2 * len) {
            Complex w = 1;
            for (int j = 0; j < len; j++) {
                Complex t = w * v2[i + j + len], u = v2[i + j];
                v2[i + j] = u + t; v2[i + j + len] = u - t;
                w *= wm;
            }
        }
    }
    if (type == -1) for (Complex &c: v2) c /= n;
    return v2;
}


int mrk[MAXN], mrk2[MAXN];

int main (){
	scanf("%d", &n);
	ll sum = 0;
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
		sum += s[a];
	}
	ll ac = 0;
	mrk[0] = 1;
	mrk2[sum] = 1;
	for(int a=0;a<n;a++){
		ac += s[a];
		debug("a %d\n	mrk %lld\n\tmrk2 %lld\n", a, ac, -ac+sum);
		mrk[ac] = 1;
		mrk2[-ac + sum] = 1;
	}
	for(int a=0;a<=sum*2;a++){
		debug("mrk[%d] %d mrk2[%d] = %d\n", a, mrk[a], a, mrk2[a]);

		A.pb(Complex(mrk[a], 0));
		if(mrk[a] == 1)
			debug("A pb %d\n", a);
		B.pb(Complex(mrk2[a], 0));
		if(mrk2[a] == 1)
			debug("B pb %d\n", a);
	}
	FFT(A, 1); FFT(B, 1);
	for(int a=0;a<A.size();a++){
		debug("A[%d] = (%.3Lf + j%.3Lf) * (%.3Lf + j%.3Lf)\n", a, A[a].real(), A[a].imag(), B[a].real(), B[a].imag());
		A[a] = A[a]*B[a];
	}
	FFT(A, -1); 
	int res = 0;
	for(int a=sum+1;a<A.size();a++){
		debug("A %d: %.3Lf %.3Lf\n", a, A[a].real(), A[a].imag());
		if(A[a].real()+0.5 > 1)
			res++;
	}
	printf("%d\n", res-1);
}

