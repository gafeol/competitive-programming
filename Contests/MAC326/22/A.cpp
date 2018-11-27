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
char s[MAXN], o[MAXN];

map<string, double> dp;

double p;

double go(string s){
	string ori = s;
	if(dp.find(s) != dp.end()) return dp[s];
	while(next_permutation(s.begin(), s.end())) {
		dp[ori] += p*go(s);
	} 
	return dp[ori];
}

int main (){
	{
		string s = "";
		for(int i=0;i<9;i++){
			s += (i+'0');
			p = 1;
			for(int a=0;a<=i;a++){
				p *= 1./(a+1);
			}
			sort(s.begin(), s.end(), [](char a, char b){ return a > b;});
			dp[s] = 1;
			double som = p;
			while(prev_permutation(s.begin(), s.end())){
				dp[s] = som;
				som += p*dp[s];
			}
		}
	}
	for_tests(t, tt){
		scanf(" %s", s);
		n = strlen(s);
		vector<char> x(n);
		for(int a=0;a<n;a++){
			x[a] = s[a];	
		}
		sort(x.begin(), x.end());
		for(int a=0;a<n;a++){
			s[a] = lower_bound(x.begin(), x.end(), s[a]) - x.begin() + '0';
		}
		if(dp[s] == 1.)
			printf("%.9f\n" , 0.);
		else
			printf("%.9f\n", dp[s]);
	}
}

