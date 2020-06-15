#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
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

map<pic, pic> adj;

char invc(char c){
	if(c == 'A') return 'F';
	if(c == 'B') return 'E';
	if(c == 'C') return 'H';
	if(c == 'D') return 'G';
	if(c == 'E') return 'B';
	if(c == 'F') return 'A';
	if(c == 'G') return 'D';
	if(c == 'H') return 'C';

}

int vi[] = {-1, 0, 1, 0}; 
int vj[] = {0, 1, 0, -1};

int cvt(int i, int j, int d){
	int ii = i+vi[d];
	int jj = j+vj[d];
	return 1 + ii*m + jj;	
}


int dir(char c){
	if(c == 'A' || c == 'B')
		return 0;
	else if(c == 'C' || c== 'D')
		return 1;
	else if(c == 'F' || c == 'E')
		return 2;
	else
		return 3;
}

bool bd(int u, char c){
	int d = dir(c);
	u--;
	int i = u/m;
	int j = u%m;
	//printf("real %d %d\n", i, j);
	//printf("c %c d %d\n", c, d);
	int ii = i+vi[d];
	int jj = j+vj[d];
	//printf("aft %d %d\n", ii, jj);
	return (ii < 0 || jj < 0 || ii >= n || jj >= m);
}

pic inv(pic x){
	int u = x.fst-1;
	char c = x.snd;
	int i = u/m;
	int j = u%m;

	int d = dir(c);

	return pic(cvt(i, j, d), invc(c));
}


void go(pic x){
	///printf("-> %d%c\n", x.fst, x.snd);
	int u = x.fst;
	char c = x.snd;

	if(bd(u, c)){
		printf("%d%c\n", u, c);
		return ;
	}
	x = inv(x);	
	//printf("-> %d%c\n", x.fst, x.snd);

	go(adj[x]);
}

int main (){
	int tt = 1;
	while(scanf("%d%d", &n, &m) && n+m){
		printf("Board %d:\n", tt++);
		adj.clear();
		int x;
		while(scanf("%d", &x) && x != 0){
			char c;
			while( (c = getchar()) != '\n'){
				char a = getchar();
				char b = getchar();
				adj[pic(x, a)] = pic(x, b);	
				adj[pic(x, b)] = pic(x, a);	
			}
		}
		char c;
		do{
			int x;
			scanf("%d", &x);
			char a = getchar();
			printf("%d%c is connected to ", x, a);
			go(adj[pic(x, a)]);
		} while((c = getchar()) != '\n');
		puts("");
	}
}

