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

const int MAXN = 312345;

int n, m, k;
char s[2][MAXN];
char res[MAXN];

bool cmp(char a, char b){
	return a > b;
}

int main (){
	scanf(" %s %s", s[0], s[1]);
	int t[2];
	t[0] = strlen(s[0]);
	t[1] = strlen(s[1]);
	sort(s[0], s[0] + t[0]);
	sort(s[1], s[1] + t[1], cmp);
	int i[2], f[2];
	f[0] = (t[0]+1)/2 -1;
	f[1] = t[1]/2 -1;
	i[0] = i[1] = 0;
	int ini = 0, fim = t[0]-1;
	int id = 0;
	int cnt = 0;
	while(ini <= fim){
		int ot = id^1;
		if(!id){
			if(s[ot][i[ot]] <= s[id][i[id]])
				res[fim--] = s[id][f[id]--];
			else
				res[ini++] = s[id][i[id]++];
		}
		else{
			if(s[ot][i[ot]] >= s[id][i[id]])
				res[fim--] = s[id][f[id]--];
			else
				res[ini++] = s[id][i[id]++];
		}
		id ^= 1;
		cnt++;
	}
	for(int a=0;a<t[0];a++){
		printf("%c", res[a]);
	}
	printf("\n");
}
