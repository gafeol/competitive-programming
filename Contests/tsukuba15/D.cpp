
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

typedef pair<pair<int, int>, pair<int, int> > ppp;

int n, m, k, w, D;
int s[MAXN];
pair<pair<int, int>, pair<int, int> > p(int x, int y, char d) {
	pair<pair<int, int>, pair<int, int> > t;
	return t;
}

int id(char c) {
	if (c == 'N')
		return 0;
	if (c == 'E')
		return 1;
	if (c == 'S')
		return 2;
	if (c == 'W')
		return 3;
}

ppp inter(int x, int y, char d) {
	int dist[] = {D-y, w-x, y, x};
	int dir = id(d);
	int l = (dir + 3) % 4; int mnL = min(dist[dir], dist[l]);
	int r = (dir + 1) % 4; int mnR = min(dist[dir], dist[r]);
	ppp p;
	if (d == 'N') {
		p.fst = make_pair(x - mnL, y + mnL);
		p.snd = make_pair(x + mnR, y + mnR);
	}
	if (d == 'E') {
		p.fst = make_pair(x + mnL, y + mnL);
		p.snd = make_pair(x + mnR, y - mnR);
	}
	if (d == 'S') {
		p.fst = make_pair(x + mnL, y - mnL);
		p.snd = make_pair(x - mnR, y - mnR);
	}
	if (d == 'W') {
		p.fst = make_pair(x - mnL, y - mnL);
		p.snd = make_pair(x - mnR, y + mnR);
	}
	return p;
}

bool f(ppp a, ppp b) {
	if (a.fst.snd == 0) {
		if (b.fst.snd != 0) return true;
		else {
			if (a.fst.fst != b.fst.fst) {
				return a.fst.fst > b.fst.fst;
			}
			else return a.snd < b.snd;
		}
	}
	else {
		if (a.fst.fst == 0) {
			if (b.fst.snd == 0) return false;
			if (b.fst.fst != 0) return true;
			else {
				if (a.fst.snd != b.fst.snd)
					return a.fst.snd < b.fst.snd;
				else return a.snd < b.snd;
			}
		}
		else {
			if (a.fst.snd == D) {
				if (b.fst.snd == 0 || b.fst.fst == 0) return false;
				if (b.fst.snd == D) {
					if (a.fst.fst != b.fst.fst)
						return a.fst.fst < b.fst.fst;
					else return a.snd < b.snd;
				}
				else return true;
			}
			else {
				if (b.fst.snd = 0 || b.fst.snd == D || b.fst.fst == 0) return false;
				else {
					if (a.fst.snd != b.fst.snd)
						return a.fst.snd > b.fst.snd;
					else return a.snd < b.snd;
				}
			}
		}
	}
}

vector<ppp> v;

int main (){
	while(scanf("%d %d %d", &n, &w, &D) != EOF) {
		for(int a=0;a<n;a++){
			int x, y; char d;
			scanf("%d %d %c", &x, &y, &d);
			ppp p = inter(x, y, d);
			v.push_back(make_pair(p.fst, make_pair(0, a)));
			v.push_back(make_pair(p.snd, make_pair(1, a)));
		}
		sort(v.begin(), v.end(), f);
		int resp = 0;
		int i;
		set<int> seen, mk;
		for (auto a : v) {
			//printf("%d %d %d %d\n", a.fst.fst, a.fst.snd, a.snd.fst, a.snd.snd);
		}
		for (i=0;i<v.size();i++) {
			if (v[i].snd.fst == 0) {
				seen.insert(v[i].snd.snd);
				break;
			}
		}
		for (int j=(i+1)%v.size();j!=i;j=(j+1)%v.size()) {
			if (v[j].snd.fst == 0) {
				seen.insert(v[j].snd.snd);
			}
			else {
				if (seen.find(v[j].snd.snd) != seen.end()) {
					seen.erase(v[j].snd.snd);
				}
			}
		}
		seen.insert(v[i].snd.snd);
		for (int j=(i+1)%v.size();j!=i;j=(j+1)%v.size()) {
			if (mk.find(v[j].snd.snd) != mk.end()) {
				if (v[j].snd.fst == 0) break;
				else continue;
			}
			if (seen.find(v[j].snd.snd) != seen.end()) {
				for (auto a : seen) {
					mk.insert(a);
				}
				seen.clear();
				resp++;
			}
			else {
				seen.insert(v[j].snd.snd);
			}
		}
		printf("%d\n", resp);
		v.clear();
	}
}

