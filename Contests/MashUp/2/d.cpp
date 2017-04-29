#include <bits/stdc++.h>
using namespace std;

char s[3][200005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) {
		scanf(" %s", s[i]);
	}

	for (int i = 0; i < n; i++) {
		if (s[0][i] != s[1][i] && s[0][i] != s[2][i] && s[1][i] != s[2][i]) printf("%c", s[0][i]);
		else if (s[0][i] == s[1][i]) printf("%c", s[0][i]);
		else if (s[0][i] == s[2][i]) printf("%c", s[0][i]);
		else if (s[1][i] == s[2][i]) printf("%c", s[1][i]);
	}
	printf("\n");
	return 0;
}
