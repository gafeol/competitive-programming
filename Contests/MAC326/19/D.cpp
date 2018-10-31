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

const int MAXN = 2123456;

int n, m, k;
char s[10][MAXN];

char rd(int dj){
	if(s[3][dj+1] == '.' && s[4][dj] == 'x') return '0';
	else if(s[0][dj] == '.' && s[3][dj+2] == '.') return '1';
	else if(s[1][dj] == '.' && s[4][dj] == 'x') return '2';
	else if(s[0][dj] == 'x' && s[1][dj] == '.' && s[3][dj] == 'x') return '3';
	else if(s[6][dj+2] == '.' && s[0][dj+2] == '.' && s[2][dj+2] == '.') return '4';
	else if(s[5][dj+4] == 'x' && s[5][dj] == '.' && s[2][dj+4] == '.') return '5';
	else if(s[1][dj] == 'x' && s[1][dj+4] == '.') return '6';
	else if(s[3][dj] == '.') return '7';
	else if(s[4][dj] == 'x') return '8';
	else if(s[0][dj] == 'x') return '9';
	else return '+';
}

string ans[10];

void print(int x){
	for(int a=0;a<7;a++){
		if(ans[a].size() > 0)
			ans[a] += '.';
	}
	if(x == 0){
		ans[0] += "xxxxx";
		ans[1] += "x...x";
		ans[2] += "x...x";
		ans[3] += "x...x";
		ans[4] += "x...x";
		ans[5] += "x...x";
		ans[6] += "xxxxx";
	}
	else if(x == 1){
		ans[0] += "....x";
		ans[1] += "....x";
		ans[2] += "....x";
		ans[3] += "....x";
		ans[4] += "....x";
		ans[5] += "....x";
		ans[6] += "....x";
	}
	else if(x == 2){
		ans[0] += "xxxxx";
		ans[1] += "....x";
		ans[2] += "....x";
		ans[3] += "xxxxx";
		ans[4] += "x....";
		ans[5] += "x....";
		ans[6] += "xxxxx";
	}
	else if(x == 3){
		ans[0] += "xxxxx";
		ans[1] += "....x";
		ans[2] += "....x";
		ans[3] += "xxxxx";
		ans[4] += "....x";
		ans[5] += "....x";
		ans[6] += "xxxxx";
	}
	else if(x == 4){
		ans[0] += "x...x";
		ans[1] += "x...x";
		ans[2] += "x...x";
		ans[3] += "xxxxx";
		ans[4] += "....x";
		ans[5] += "....x";
		ans[6] += "....x";
	}
	else if(x == 5){
		ans[0] += "xxxxx";
		ans[1] += "x....";
		ans[2] += "x....";
		ans[3] += "xxxxx";
		ans[4] += "....x";
		ans[5] += "....x";
		ans[6] += "xxxxx";
	}
	else if(x == 6){
		ans[0] += "xxxxx";
		ans[1] += "x....";
		ans[2] += "x....";
		ans[3] += "xxxxx";
		ans[4] += "x...x";
		ans[5] += "x...x";
		ans[6] += "xxxxx";
	}
	else if(x == 7){
		ans[0] += "xxxxx";
		ans[1] += "....x";
		ans[2] += "....x";
		ans[3] += "....x";
		ans[4] += "....x";
		ans[5] += "....x";
		ans[6] += "....x";
	}
	else if(x == 8){
		ans[0] += "xxxxx";
		ans[1] += "x...x";
		ans[2] += "x...x";
		ans[3] += "xxxxx";
		ans[4] += "x...x";
		ans[5] += "x...x";
		ans[6] += "xxxxx";
	}
	else{
		ans[0] += "xxxxx";
		ans[1] += "x...x";
		ans[2] += "x...x";
		ans[3] += "xxxxx";
		ans[4] += "....x";
		ans[5] += "....x";
		ans[6] += "xxxxx";
	}
}


int main (){
	n = 7;
	for(int a=0;a<n;a++){
		scanf(" %s", s[a]);
	}
	m = strlen(s[0]);
	int n[2];
	int t = 0;
	n[0] = n[1] = 0;
	for(int db = 0;db < m;db += 6){
		char c = rd(db);
		if(c == '+')
			t++;
		else{
			n[t] *= 10;	
			n[t] += c-'0';
		}
	}
	int res = n[0] + n[1];
	int dz = 1000000000;
	bool bg = false;
	while(dz > 0){
		if(res/dz > 0 || bg){
			bg = true;
			print(res/dz);
		}
		res %= dz;
		dz = dz/10;
	}
	if(!bg)
		print(0);
	for(int a=0;a<7;a++)
		cout << ans[a] << endl;
}

