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

const int MAXN = 2*41;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

char M[MAXN][MAXN];

pii bef[MAXN][MAXN];

int mrk[MAXN][MAXN];

int tempo;
int i, j;

int vi[] = {0, 2, 0, -2};
int vj[] = {-2, 0, 2, 0};

int vii[] = {0, 1, 0, -1};
int vjj[] = {-1, 0, 1, 0};

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m && M[i][j] !='#');
}

int mi, mj;

bool ch(int a, int b){
	tempo++;
	queue<pii> q;
	q.push({a, b});
	mrk[a][b] = tempo;
	bef[a][b] = pii(a, b);
	while(!q.empty()){
		int ii, jj;
		pii t = q.front();
		q.pop();
		ii = t.fst;
		jj = t.snd;
		//printf("go i %d j %d\n", i, j);
		if(M[ii][jj] == '@'){
			mi = ii;
			mj = jj;
			return true;
		}

		int id[] = {0, 1, 2, 3};
		random_shuffle(id, id+4);
		for(int dd=0;dd<4;dd++){
			int d = id[dd];

			int in = ii + vi[d];
			int iin = ii + vii[d];
			int jn = jj + vj[d];
			int jjn = jj + vjj[d];
			if(valid(in, jn) && valid(iin, jjn) && mrk[in][jn] != tempo){
				mrk[in][jn] = tempo;
				q.push({in, jn});
				bef[in][jn] = pii(ii, jj);
			}
		}
	}
	//printf("return falso\n");
	return false;
}


bool go(int a, int b){
	tempo++;
	queue<pii> q;
	q.push({a, b});
	mrk[a][b] = tempo;
	bef[a][b] = pii(a, b);
	while(!q.empty()){
		int ii, jj;
		pii t = q.front();
		q.pop();
		ii = t.fst;
		jj = t.snd;
		//printf("go i %d j %d\n", i, j);
		if(ii == mi && jj == mj){
			while(bef[ii][jj] != pii(a, b)){
				pii b = bef[ii][jj];
				ii = b.fst;
				jj = b.snd;
			}

			if(ii < a)
				puts("U");
			else if(ii > a)
				puts("D");
			else if(jj < b)
				puts("L");
			else
				puts("R");
			fflush(stdout);

			M[i][j] = '.';
			M[ii][jj] = '1';
			i = ii;
			j = jj;
			return true;
		}

		int id[] = {0, 1, 2, 3};
		random_shuffle(id, id+4);
		for(int dd=0;dd<4;dd++){
			int d = id[dd];

			int in = ii + vi[d];
			int iin = ii + vii[d];
			int jn = jj + vj[d];
			int jjn = jj + vjj[d];
			if(valid(in, jn) && valid(iin, jjn) && mrk[in][jn] != tempo){
				mrk[in][jn] = tempo;
				q.push({in, jn});
				bef[in][jn] = pii(ii, jj);
			}
		}
	}
	//printf("return falso\n");
	return false;
}

int ei, ej;

int main (){
	srand(time(NULL));
	scanf("%d%d", &n, &m);
	n = n*2 + 1;
	m = m*2 + 1;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b] == '1'){
				i = a;
				j = b;
			}
			else if(M[a][b] == '2'){
				ei = a;
				ej = b;
			}
		}
	}
	char c;
	do{
		if(!ch(ei, ej)){
			puts("W");
			fflush(stdout);
		}
		else{
			go(i, j);
		}
		scanf(" %c", &c);
		int d;
		if(c == 'U')
			d = 0;
		if(c == 'D')
			d = 1;
		if(c == 'L')
			d = 3; if(c == 'R')
			d = 2;


		if(c != 'X'){
			int nei = ei + vi[d];
			int nnei = ei + vii[d];
			int nej = ej + vj[d];
			int nnej = ej + vjj[d];
			if(valid(nei, nej) && valid(nnei, nnej)){
				M[ei][ej] = '.';
				M[nei][nej] = '2';
			}
		}
	} while(c != 'X');
	return 0;
}

