#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char str[1000005];
map <string, int> mp;
int main() {
	int n, len;
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		scanf(" %s", str);
		len = strlen(str);
		map <char, char> temp;
		char c = 'a';
		for (int j = 0; j < len; j++) {
			if (temp.find(str[j]) == temp.end()) temp[str[j]] = c++;
			str[j] = temp[str[j]];
		}
		ans += mp[str];
		mp[str]++;
	}

	printf("%lld\n", ans);
	return 0;
}
