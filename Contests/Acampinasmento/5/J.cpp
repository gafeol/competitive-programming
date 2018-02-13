#include <bits/stdc++.h>

using namespace std;

const int N = 1e2;
char str[(int)1e6];
int p[N], w[N], v[N];

int find(int x) {
	return (p[x] == x) ? x : p[x] = find(p[x]);
}

void join(int a, int b) {
	if ((a = find(a)) == (b = find(b))) return;
	if (w[a] < w[b]) swap(a, b);
	p[b] = a;
	w[a] += w[b];
	v[a] += v[b];
	int c = a;
	int d = b;
	if (a+'A' > 'Z') c += 'a' - 'A' - 26;
	if (b+'A' > 'Z') d += 'a' - 'A' - 26;
	//printf("joining %c and %c (%d, %d)\n", c+'A', d+'A', a, b);
}

vector<pair<int, int> > rep;

int k[N];

int solve(int i, int sv, int sc) {
	if (sv > 5 || sc > 21) return 0;
	if (i == rep.size()) {
		return 1;
	}
	int p1 = rep[i].first;
	int p2 = rep[i].second;
	int x = solve(i+1, sv + v[p1], sc + w[p1] - v[p1]);
	if (x == 1) {
		k[i] = 0;
		return 1;
	}
	x = solve(i+1, sv + v[p2], sc + w[p2] - v[p2]);
	if (x == 1) {
		k[i] = 1;
		return 1;
	}
	return 0;
}

const char *cons = "BCDFGHJKLMNPQRSTVWXYZ";
const char *vog = "AEIOU";
char str2[(int)1e6];

int main () {
	freopen("javanese.in", "r", stdin);
	freopen("javanese.out", "w", stdout);
	for (int i=0;i<52; i++) {
		p[i] = i;
		w[i] = 1;
		v[i] = (i >= 26) ? 1 : 0;
	}
	set<int> s;
	char c = 0;
	int begin = 0;
	int i = 0;
	while (scanf("%s", str2) != EOF) {
		int k = strlen(str2);
		for (int j=0;j<k;j++) {
			str[i++] = str2[j];
		}
		str[i++] = ' ';
	}
	str[i] = '\0';
	int n = strlen(str);
	for (int i=0;i<n;i++) {
		if (str[i] > 'Z' || str[i] < 'A') {
			begin = i+1;
			continue;
		}
		if ((i-begin)%2 == 0) {
			join(str[begin]-'A',str[i]-'A'); 
			join(str[begin]-'A'+26,str[i]-'A'+26); 
		} else {
			join(str[begin]-'A',str[i]-'A'+26);
			join(str[begin]-'A'+26,str[i]-'A');
		}
		s.insert(str[i]);
	}
	set<pair<int, int> > rp;
	set<int> vis;
	for (auto a : s) {
		int x = find(a-'A'), y = find(a-'A'+26);
		if (vis.find(min(x, y)) == vis.end())
			rp.insert(make_pair(x, y));
		vis.insert(min(x, y));
		if (find(a-'A') == find(a-'A'+26)) {
			printf("impossible\n");
			return 0;
		}
	}
	rep = vector<pair<int, int> >(rp.begin(), rp.end());
	int ok = solve(0, 0, 0);
	if (ok == 0) {
		printf("impossible\n");
		return 0;
	}
	int nc = 0;
	int nv = 0;
	map<int, int> ma;
	for (int i=0;i<rep.size();i++) {
		int t[2] = {rep[i].first, rep[i].second};
		//printf("%d %d -> %d\n", t[0], t[1], k[i]);
		for (int j=0;j<26;j++) {
			if (t[k[i]] == find(j)) {
				ma[j+'A'] = cons[nc++];
			} else if (t[k[i]] == find(j+26)) {
				ma[j+'A'] = vog[nv++];
			}
			//printf("i = %d || nv = %d, nc = %d\n", i, nv, nc);
		}
	}
	/*for (auto a : ma) {
	  printf("%c -> %c\n", a.first, a.second);
	  }*/
	for (int i=0;i<n;i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] = ma[str[i]];
	} printf("%s\n", str);
}











