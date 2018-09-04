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
const int MAXX = 10000007;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> div[MAXX];

bool mrk[MAXX];

set<int> has[MAXX];
set<int> pos;
int cnt[MAXX];
int res[MAXN];

void rmv(int i){
	for(p: div[s[i]]){
		cnt[p]--;
	}
}

void go(int i, int j, int bef){
	if(i == j){
		res[i] = bef;
	}
	if(pos.empty()){
		puts("impossible");
		exit(0);
	}
	int m = *pos.begin();
	res[m] = bef;
	int l = m - 1 -i + 1;		
	int r = j - m;
	if(l > r){
		for(int a=m;a<=j;a++)
			rmv(a);
		go(i, m-1, m);	
		//clear()
		for(int a=m+1;a<=j;a++)
			add(a);
		go(m+1, j, m);
	}
	else{
		for(int a=i;a<=m;a++)
			rmv(a);
		go(m+1, j, m);
		//clear();
		for(int a=i;a<m;a++)
			add(a);
		go(i, m-1, m);

	}
}


int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	for(int i=2;i<MAXX;i++){
		if(!div[i].empty()) continue;
		for(ll b = i; ((ll)i)*b < MAXX;b++)
			div[b*i].pb(i);
	}
	for(int a=0;a<n;a++){
		pos.insert(a);
		for(int d:div[s[a]]){
			if(cnt[d] == 1){
				auto it = pos.find(has[d]);
				if(it != pos.end())
					pos.erase(it);
			}
			else if(cnt[d] == 0){
				has[d] = a;	
			}
			cnt[d]++;
		}
	}
	go(0, n-1);
}
