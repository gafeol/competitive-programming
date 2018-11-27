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
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

set<int> q;

set<pii> dj;
unordered_map<int, vector<int> > adj;
unordered_map<int, int> d;

int main (){
	for_tests(t, tt){
		scanf("%d%d", &k, &n);
		for(int a=0;a<n;a++){
			int r, m;
			scanf("%d%d", &r, &m); 
			for(int i=0;i<=1000;i++){
				if(r + m*i >= k) 
					break;
				q.insert(r+m*i);
				if(r + m*(i+1) < k)
					adj[r+m*i].pb(r + m*(i+1));
				if(r + m*(i-1) >= 0)
					adj[r+m*i].pb(r + m*(i-1));
			}
		}
		q.insert({k, 0});
		dj.insert({0, 0});
		d[0] = 0;
		int res = 0;
		while(!dj.empty()){
			int fl = dj.begin()->snd;
			dj.erase(dj.begin());

			for(int nxt: adj[fl]){
				if(d.find(nxt) == d.end() || d[nxt] > d[fl]){
					if(d.find(nxt) != d.end())
						dj.erase({d[nxt], nxt});
					d[nxt] = d[fl];
					dj.insert({d[nxt], nxt});
				}
				
			}

			if(q.upper_bound(fl) != q.end()){
				int prox = *q.upper_bound(fl);
				int cus = abs(prox - fl);
				if(d.find(prox) == d.end() || d[prox] > d[fl] + cus){
					if(d.find(prox) != d.end())
						dj.erase({d[prox], prox});
					d[prox] = d[fl] + cus;
					dj.insert({d[prox], prox});
				}
			}
			if(q.lower_bound(fl) != q.begin()){
				int bef = *(--q.lower_bound(fl));
				int cus = abs(fl - bef);
				if(d.find(bef) == d.end() || d[bef] > d[fl] + cus){
					if(d.find(bef) != d.end())
						dj.erase({d[bef], bef});
					d[bef] = d[fl] + cus;
					dj.insert({d[bef], bef});
				}
			}
		}

		unordered_map<int, int>::iterator bf;
		int res = -1, ir;
		for(auto it: d){
			if(it == d.begin()){
				bf = it;
				continue;
			}
			int va = bf.snd, pa = bf.fst;
			int vb = it.snd, pb = it.fst;
			int dif = abs(va - vb);
			int mid = (pa + pb - dif)/2;
			int rp = pa + mid;
			if(va < vb)
				rp += dif;
			if(res < min(abs(rp - pa) + va, abs(pb - rp) + vb)){
				res = min(abs(rp - pa) + va, abs(pb - rp) + vb);
				ir = rp;
			}
			bf = it;
		}
		int v = bf.snd, p = bf.fst;
		if(res < min(abs(k-1-
	}
}

