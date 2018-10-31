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
ll s[6];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	for(int a=0;a<4;a++)
		scanf("%lld", s+a);
	if(s[0]+s[1]+s[2]+s[3] == 0){
		puts("0");
		return 0;
	}

	if(s[0] + s[2] + s[3] == 0){
		if(s[1] == 1)
			puts("01");
		else
			puts("impossible");
		return 0;
	}

	if(s[0] + s[1] + s[3] == 0){
		if(s[2] == 1)
			puts("10");
		else
			puts("impossible");
		return 0;
	}

	ll n0 = 2;
	while((n0*(n0-1))/2 < s[0])
		n0++;
	ll n1 = 2;
	while((n1*(n1-1))/2ll < s[3])
		n1++;

	if(s[0] == 0){
		if(s[1] + s[2] != 0)
			n0 = 1;
		else
			n0 = 0;
	}

	if(s[3] == 0){
		if(s[1] + s[2] != 0)
			n1 = 1;
		else
			n1 = 0;
	}

	//printf("n0 %lld n1 %lld\n", n0, n1);
	if((n1*(n1-1))/2 == s[3] && s[0]+s[1]+s[2] == 0){
		while(n1--)
			printf("1");
		return 0;
	}
	if((n0*(n0-1))/2 == s[0] && s[1]+s[2]+s[3] == 0){
		while(n0--)
			printf("0");
		return 0;
	}
	if((n0*(n0-1))/2ll != s[0] || (n1*(n1-1))/2ll != s[3]){
		puts("impossible");
		return 0;
	}

	vector<int> ans;
	s[0] = n0;
	s[3] = n1;

	while(s[0] + s[1] + s[2] + s[3] != 0){
		if(s[0] && s[1] >= s[3]){
		//	puts("0");
			ans.pb(0);
			s[1] -= s[3];
			s[0]--;
		}
		else if(s[3] && s[2] >= s[0]){
			//puts("1");
			ans.pb(1);
			s[2] -= s[0];
			s[3]--;
		}
		else{
			puts("impossible");
			return 0;
		}
	}
	for(int a: ans)
		printf("%d", a);
}

