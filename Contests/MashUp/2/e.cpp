 #include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)

char s[200005];
int seen[200005], ch[200005];
vector <int> v[200005], ans;
int np[200005], nf[200005];
void dfs(int x, char sig) {
	seen[x] = 1;
	if (s[x] != '0') sig = s[x];
	int cont = 0;
	for (auto a : v[x]) {
		if (!seen[a]) cont++;
	}
	if (cont == 0) {
		nf[x] = 1;
		if (sig == '+') np[x] = 1;
		return;
	}
	for (auto a : v[x]) {
		if (!seen[a]) {
			dfs(a, sig);
			nf[x] += nf[a];
			np[x] += np[a];
		}
	}
}

void dfs2(int x) {	
	seen[x] = 1;
	if(np[x] == 0) return;
	if (nf[x] != np[x]) {
		for (auto a : v[x]) {
			if (!seen[a]) dfs2(a);
		}
	}
	else ans.pb(x);
}

int main() {
	int n, x, y;
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &x, &y);
		v[x-1].pb(y-1);
		v[y-1].pb(x-1);
	}
	
	if (s[0] == '0') s[0] = '-';
	dfs(0, s[0]);
	memset(seen, 0, sizeof(seen));
	dfs2(0);
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (auto a : ans)
		printf("%d ", a+1);
	printf("\n");
}
