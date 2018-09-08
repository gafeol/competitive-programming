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

ll solve(ll cst, const multiset<int>& tz, const multiset<int>& to){
	ll loc = 0;

	for(auto it = tz.rbegin(); it != tz.rend(); ++it) {
		cst -= ll(*it);
		loc += cst;
	}
	for(auto i : to) {
		cst += ll(i);
		loc += cst;
	}
	return loc;
}

int main (){
	prep_cin();
	int n;
	cin >> n;

	vector<int> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++){
		char c;
		cin >> ws >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i < n; i++){
		char c;
		cin >> ws >> c;
		b[i] = c - '0';
	}

	multiset<int> toz, too;
	vector<int> choice;
	for (int i = 0; i < n; i++){
		if (a[i] == 1 && b[i] == 1)
			choice.push_back(i);
		if (a[i] == 1 && b[i] == 0)
			toz.insert(c[i]);
		if (a[i] == 0 && b[i] == 1)
			too.insert(c[i]);
	}
	sort(choice.begin(), choice.end(), [&](int i, int j){ return c[i] < c[j]; });

	ll cst = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i])
			cst += ll(c[i]);

	ll ans = solve(cst, toz, too);
	for (int i = choice.size() - 1; i + 1; --i) {
		toz.insert(c[choice[i]]);
		too.insert(c[choice[i]]);
		ans = min(ans, solve(cst, toz, too));
	}
	write(cout, ans);
}
