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

#define int ll

int s[5];

vector <char> res;

bool put(int n, int m){
	//printf("put %d %d\n", n, m);
	int in = n, im = m;
	int q1=0, q2=0;
	while(n > 0 && m > 0){
		while(q1 + m <= s[1]){
			res.pb('0');
			q1 += m;
			n--;
		}
		q2 += n;
		m--;
		res.pb('1');
	}
	while(n > 0){
		res.pb('0');
		n--;
	}
	while(m > 0){
		res.pb('1');
		m--;
	}
	return (s[1] == q1 && s[2] == q2);
}

int reso(int c){
	int del = 1 + 8*c;
	int sd = sqrt(del);
	if(sd * sd != del)
		return -1;
	if((1+sd)&1)
		return -1;
	return (1 + sd)/2;
}

main (){
	int sum = 0;
	for(int a=0;a<4;a++){
		scanf("%lld", &s[a]);
		sum += s[a];
	}
	if(sum == 0){
		puts("0");
		return 0;
	}
	int n0 = reso(s[0]);
	int n1 = reso(s[3]);
	if(n1 == 1){
		if(s[1] + s[2] == 0)
			n1 = 0;
		else if(s[1] + s[2] != n0){
			puts("Impossible");
			return 0;
		}
	}
	if(n0 == 1){
		if(s[1] + s[2] == 0)
			n0 = 0;
		else if(s[1] + s[2] != n1){
			puts("Impossible");
			return 0;
		}
	}
	if(n0 < 0 || n1 < 0){
		puts("Impossible");
		return 0;
	}
	if(put(n0, n1)){
		for(char c: res){
			printf("%c", c);
		}
		return 0;
	}
	res.clear();
	swap(s[1], s[2]);
	if(put(n1, n0)){
		for(char c: res){
			if(c == '0')
				putchar('1');
			else
				putchar('0');
		}
		return 0;
	}
	puts("Impossible");
}
