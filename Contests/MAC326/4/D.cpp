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
		//write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 26;

int n, m, k;
int pot[30];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int s[MAXN][4];

map<pii, int> mx, bit;

inline void go(int a, int b, int c, int bm){
	int ab = a - b, bc = b-c;
	if(mx.find(pii(ab, bc)) == mx.end() || mx[pii(ab,bc)] < a){
		debug("salva", ab, bc, "a", a, "b", b, "c", c, "bm",  bm);
		mx[pii(ab,bc)] = a;
		bit[pii(ab,bc)] = bm;
	}
}

int res[4];

inline void go2(int a, int b, int c, int bm){
	int ab = -a + b, bc = -b+c;
	if(mx.find(pii(ab, bc)) != mx.end()){
		int val = mx[pii(ab, bc)];
		if(res[0] < val + a){
			res[0] = val + a;
			res[1] = bit[pii(ab, bc)];
			res[2] = bm;
		}
	}
}

inline void test(int i, int j){
	debug("i", i, "j", j, "pot", pot[j-i]);
	for(int bm=0;bm < pot[j-i];bm++){
		int A = 0, B = 0, C = 0;
		int bbm = bm;
		for(int a=0;a<j-i;a++){
			if(bm%3 != 0)
				A += s[i+a][0];
			if(bm%3 != 1)
				B += s[i+a][1];
			if(bm%3 != 2)
				C += s[i+a][2];
			bm /= 3;
		}
		bm = bbm;
		go(A, B, C, bm);
	}
}

inline void test2(int i, int j){
	for(int bm=0;bm < pot[j-i];bm++){
		int A = 0, B = 0, C = 0;
		int bbm = bm;
		for(int a=0;a<j-i;a++){
			if(bm%3 != 0)
				A += s[i+a][0];
			if(bm%3 != 1)
				B += s[i+a][1];
			if(bm%3 != 2)
				C += s[i+a][2];
			bm /= 3;
		}
		bm = bbm;
		go2(A, B, C, bm);
	}
}




int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		for(int b=0;b<3;b++)
			scanf("%d", &s[a][b]);
	res[0] = INT_MIN;
	pot[0] = 1;
	for(int a=1;a<=n/2 + 2;a++)
		pot[a] = 3*pot[a-1];
	test(0, n/2);	
	
	test2(n/2, n);

	if(res[0] == INT_MIN){
		puts("Impossible");
	}
	else{
		debug("res0", res[0]);
		int cnt = 0;
		string ans;
		for(int a=0;a<n/2;a++){
			ans = "";
			if((res[1])%3 != 0)
				printf("L");
			if((res[1])%3 != 1)
				printf("M");
			if((res[1])%3 != 2)
				printf("W");
			puts("");
			res[1]/=3;
		}
		for(int a=n/2;a < n;a++){
			ans = "";
			if((res[2])%3 != 0)
				printf("L");
			if((res[2])%3 != 1)
				printf("M");
			if((res[2])%3 != 2)
				printf("W");
			puts("");
			res[2]/=3;
		}
	}
}

