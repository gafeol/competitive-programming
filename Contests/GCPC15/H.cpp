#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int seen[500];
vector<int> conn[500];

int dfs(int node) {
	seen[node] = 1;
	for (int i=0;i<conn[node].size();i++) {
		if (seen[conn[node][i]] == 0) dfs(conn[node][i]);
	}
}

int parse(string c) {
	int flag = 0;
	const char *s = "PROGRAM";
	for (int i=0;i<c.size();i++) {
		if (flag == 9) return 0;
		if (c[i] == ':') flag++;
		else if (flag >= 2) {
			//printf("%c %c %d\n", c[i], s[flag-2], flag);
			if (c[i] == s[flag-2]) flag++;
			else flag = 0;
		}
	}
	//printf("flag = %d\n", flag);
	return flag==9;
}

int main() {
	int n;
	int t = 0;
	scanf("%d", &n);
	set<int> s;
	for (int i=0;i<n;i++) {
		string p;
		int k;
		cin >> p >> k;
		int val;
		if (m.find(p) == m.end()) {
			val = m[p] = t++;
		}
		val = m[p];	
		if (parse(p)) {
			s.insert(m[p]);
		}
		for (int j=0;j<k;j++) {
			cin >> p;
			int val2;
			if (m.find(p) == m.end()) {
				val2 = m[p] = t++;
			}
			val2 = m[p];
			conn[val2].push_back(val);
			//printf("%d %d\n", val, val2);
		}
	}
	for (auto a : s) {
		dfs(a);
	}
	int count = 0;
	for (int i=0;i<t;i++) {
		if (seen[i] == 0) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
