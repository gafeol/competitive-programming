#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n;

char s[1123][6];

bool tem(int i, int j){
	return (s[i][j] == s[i][j+1] && s[i][j] == 'O');
}

int main (){
	scanf("%d", &n);
	int res = 0;
	for(int a=0;a<n;a++){
		scanf(" %s", s[a]);
		if(tem(a, 0) || tem(a, 3))
			res = 1;
	}
	if(res)
		puts("YES");
	else{
		puts("NO");
		return 0;
	}
	res = 0;
	for(int a=0;a<n;a++){
		if(res == 0){
			if(tem(a, 0)){
				printf("++|%c%c\n", s[a][3], s[a][4]);
				res = 1;
			}
			else if(tem(a, 3)){
				printf("%c%c|++\n", s[a][0], s[a][1]);
				res = 1;
			}
			else
				printf("%s\n", s[a]);
		}
		else
			printf("%s\n", s[a]);
	}
}
