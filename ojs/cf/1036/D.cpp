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

const int MAXN = 312345;

int n[4], m, k;
ll s[2][MAXN];
ll som[2];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){

	for(int t=0;t<2;t++){
		scanf("%d", &n[t]);
		for(int a=0;a<n[t];a++){
			scanf("%lld", &s[t][a]);
			som[t] += s[t][a];
		}
	}
	if(som[0] != som[1]){
		puts("-1");
		return 0;
	}
	int i[2];
	i[0] = 1;
	i[1] = 1;
	som[0] = s[0][0];
	som[1] = s[1][0];
	int ans = 0;
	while(i[0] < n[0]){
		while(som[0] != som[1]){
			if(som[0] < som[1]){
				som[0] += s[0][i[0]];
				i[0]++;
			}
			else{
				som[1] += s[1][i[1]];
				i[1]++;
			}
		}
		ans++;
		som[0] = s[0][i[0]++];
		som[1] = s[1][i[1]++];
	}
	if(som[0] != 0){
		ans++;
	}
	printf("%d\n", ans);
}

