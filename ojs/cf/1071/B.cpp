#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
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

const int MAXN = 2123;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];
char M[MAXN][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < n);
}

void go(char x, vector<pii> pa){
	if(pa.empty()) return ;
	map<char, vector<pii> > pos;
	sort(pa.begin(), pa.end());
	pa.erase(unique(pa.begin(), pa.end()), pa.end());
	printf("%c", x);
	for(pii p: pa){
		int a = p.fst, b = p.snd;
		int aa = a+1, bb = b;	
		if(valid(aa, bb))
			pos[M[aa][bb]].pb({aa, bb});	
		aa = a; bb = b+1;	
		if(valid(aa, bb))
			pos[M[aa][bb]].pb({aa, bb});	
	}
	for(auto it: pos){
		go(it.fst, it.snd);
		return ;
	}
}

int d[MAXN][MAXN];

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf(" %c", &M[a][b]);			
		}
	}
	if(k == 0){
		vector<pii> aux;
		aux.pb({0,0});
		go(M[0][0], aux);
	}
	else{
		memset(d, INF, sizeof(d));
		set<pip> q;
		d[0][0] = (M[0][0] != 'a');
		q.insert({d[0][0], {0, 0}});
		int mx = 0;
		while(!q.empty()){
			pip t = *q.begin();
			int i = t.snd.fst, j = t.snd.snd;
			mx = max(mx, i+j);
			q.erase(q.begin());
			int ii = i+1, jj = j;
			if(valid(ii, jj)){
				int cus = d[i][j] + (M[ii][jj] != 'a');
				if(cus <= k && d[ii][jj] > cus){
					if(d[ii][jj] != INF)
						q.erase({d[ii][jj], {ii, jj}});
					d[ii][jj] = cus;
					q.insert({d[ii][jj], {ii, jj}});
				}
			}
			ii = i; jj = j+1;
			if(valid(ii, jj)){
				int cus = d[i][j] + (M[ii][jj] != 'a');
				if(cus <= k && d[ii][jj] > cus){
					if(d[ii][jj] != INF)
						q.erase({d[ii][jj], {ii, jj}});
					d[ii][jj] = cus;
					q.insert({d[ii][jj], {ii, jj}});
				}
			}
		}
		map<char, vector<pii> > pos;
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(d[a][b] == INF || a+b != mx) continue;
				int aa = a+1, bb = b;	
				if(valid(aa, bb))
					pos[M[aa][bb]].pb({aa, bb});	
				aa = a; bb = b+1;	
				if(valid(aa, bb))
					pos[M[aa][bb]].pb({aa, bb});	
			}
		}
		for(int a=0;a<=mx;a++){
			printf("a");
		}
		for(auto it: pos){
			go(it.fst, it.snd);	
			break;
		}

	}
}

