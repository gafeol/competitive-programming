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

const int MAXN = 312345;

typedef complex<long double> Complex;
const long double PI = acos(-1.0L);

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
			A.pb(Complex(s[a]-'0', 0));
		}
		for(int a=tv-1;a>=0;a--){
			B.pb(Complex(v[a]-'0', 0));
		}
		int len = 2*max(ts, tv);
		while(ts < len){
			A.pb(Complex(0, 0));
			ts++;
		}
		while(tv < len){
			B.pb(Complex(0, 0));
			tv++;
		}
		A = FFT(A, 1);
		B = FFT(B, 1);
		for(int i = 0;i < A.size();i++){
			A[i] = A[i]*B[i];
		}
		A = FFT(A, -1);
		int c = 0;
		for(Complex u: A){
			int x = u.real()+0.5;	
			res.push((x+c)%10);
			c = (x + c)/10;
		}
		while(c != 0){
			res.push(c%10);
			c /= 10;
		}
		int zer = 1;
		while(!res.empty()){
			if(zer == 0 || res.top() != 0){
				printf("%d", res.top());
				zer = 0;
			}
			res.pop();
		}
		if(zer)
			printf("0");
		printf("\n");
	}
}

