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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	freopen("trip.in", "r", stdin);
	int t;
	scanf(" %d", &t);
	while (t--) {
		int n, m, k, q, z;
		scanf(" %d%d%d%d%d", &n, &m, &k, &q, &z);
		vector<vector<double>> A(n), B(n);
		for (int i = 0; i < n; i++) {
			A[i].resize(n);
			for (int j = 0; j < n; j++)
				scanf(" %lf", &A[i][j]);

		}
		for (int i = 0; i < n; i++) {
			B[i].resize(m);
			for (int j = 0; j < m; j++)
				scanf(" %lf", &B[i][j]);
		}
		vector<double> c(k);
		for (int i = 0; i < k; i++)
			scanf(" %lf", &c[i]);
		
		vector<vector<double>> M(k), C(k);
		for (int i = 0; i < k; i++) {
			M[i].resize(n);
			C[i].resize(m);
			if (i == 0) M[i][0] = 1.0;
			else {
				for (int j = 0; j < n; j++)
					for (int l = 0; l < n; l++)
						M[i][l] += M[i - 1][j] * A[j][l];
			}
			for (int j = 0; j < n; j++)
				for (int l = 0; l < m; l++)
					C[i][l] += M[i][j] * B[j][l];
			fprintf(stderr, "%d:\n", i);
			for (int j = 0; j < n; j++)
				fprintf(stderr, "%lf%c", M[i][j], " \n"[j + 1 == n]);
			for (int j = 0; j < m; j++)
				fprintf(stderr, "%lf%c", C[i][j], " \n"[j + 1 == m]);
		}
		double ans = M[q][z] * B[z][c[q]];
		ans /= C[q][c[q]];
		printf("%.3lf\n", ans);
	}
}

