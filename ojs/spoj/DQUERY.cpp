#include <bits/stdc++.h>
#include <unistd.h>

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

const int MAXN = 30234;
const int MAXM = 212345;

int n, m, k;
int s[MAXN];

int mrk[1000009];

int sq;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

struct qry{
	int l, r;
	int id; 
} q[MAXM];

bool cmp(qry a, qry b){
	return (a.l/sq < b.l/sq || (a.l/sq == b.l/sq && a.r < b.r));
}

int res;

int i, j;

ll SPD = 50000;

void print(){
	for(int a=0;a<n;a++){
		printf("%3d", s[a]);
		char c = '#';
		if(a/sq != (a+1)/sq){
			printf("%3c", c);
		}
	}
	puts("");
	for(int a=0;a<n;a++){
		char c = ' ';
		if(a == i || a == j){
			if(a == i)
				c = 'i';
			else
				c = 'j';
		}
		printf("%3c", c);
		c = '#';
		if(a/sq != (a+1)/sq){
			printf("%3c", c);
		}
	}
	puts("");
	usleep(SPD);
}

void add(int i){
	if(mrk[s[i]] == 0)
		res++;
	mrk[s[i]]++;
}

void rmv(int i){
	mrk[s[i]]--;
	if(mrk[s[i]] == 0)
		res--;
}

int main (){
	scanf("%d", &n);
	sq = sqrt(n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		scanf("%d%d", &q[a].l, &q[a].r);
		q[a].l--;
		q[a].r--;
		if(q[a].l > q[a].r)
			swap(q[a].l, q[a].r);
		q[a].id = a;
	}
	sort(q, q+m, cmp);

	i = 0; j = -1;
	int ans[MAXM];
	for(int a=0;a<m;a++){
		while(j < q[a].r){
			add(++j);
			print();
		}
		while(i > q[a].l){
			add(--i);
			print();
		}
		while(i < q[a].l){
			rmv(i++);
			print();
		}
		while(j > q[a].r){
			rmv(j--);
			print();
		}
		ans[q[a].id] = res;
	}
	for(int a=0;a<m;a++){
		printf("%d\n", ans[a]);
	}
}

