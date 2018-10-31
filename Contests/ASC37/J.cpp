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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

struct event {
	int p1, p2;
	bool operator< (const event &a) const {
		return p2-p1 < a.p2-a.p1;
	}
};

vector<int> L, R;
int resp[2];
vector<event> e;

int main (){
	int l, a;
	while (scanf("%d %d", &l, &a) != EOF) {
		L.clear();
		R.clear();
		e.clear();
		for (int i=0;i<a;i++) {
			int p; char c;
			scanf("%d %c", &p, &c);
			if (c == 'R') R.pb(p);
			else L.pb(p);
		}
		resp[0] = resp[1] = -1;
		sort(L.begin(), L.end());
		sort(R.begin(), R.end());
		if (R.size()) {
			resp[0] = R[0];
			int p1 = 0;
			int p2 = L.size();
			for (int i=0;;i++) {
				if (i % 2 == 0) {
					p2--;
					if (p2 < 0) break;
					if (R[p1] < L[p2]) resp[0] = L[p2];
				} else {
					p1++;
					if (p1 >= R.size()) break;
					if (R[p1] < L[p2]) resp[0] = R[p1];
				}
			}
		}
		if (L.size()) {
			resp[1] = L.back();
			int p1 = -1;
			int p2 = (int)L.size()-1;
			for (int i=0;;i++) {
				if (i % 2 == 1) {
					p2--;
					if (p2 < 0) break;
					if (R[p1] < L[p2]) resp[1] = L[p2];
				} else {
					p1++;
					if (p1 >= R.size()) break;
					if (R[p1] < L[p2]) resp[1] = R[p1];
				}
			}
		}
		int t1 = -1;
		if (R.size()) t1 = l - R[0];
		int t2 = -1;
		if (L.size()) t2 = L.back();
		printf("The last ant will fall down in %d seconds - started at ", max(t1, t2));
		if (t1 == t2) {
			if (resp[0] > resp[1]) swap(resp[0], resp[1]);
			printf("%d and %d.\n", resp[0], resp[1]);
		} else if (t1 > t2) {
			printf("%d.\n", resp[0]);
		} else {
			printf("%d.\n", resp[1]);
		}
	}
}

