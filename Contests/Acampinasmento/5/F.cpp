#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

const int MAXN = 1123456;

ll n;

ll n1[MAXN];
ll qt[MAXN];

ll fib[MAXN], sf[MAXN];

vector<int> no, s;

int j;

void re(ll i){
	i--;
	//printf("re %lld\n",i); 
	int lz = 1;
	for(int a=j;a>=0;a--){
		//printf("a %d\n", a);
		// i = 1 -> 00000
		if(a == 0){
	//		printf("a == 0 i %lld\n", i);
			if(i >= 1)
				no.pb(1);
			else
				no.pb(0);
			continue;
		}
		if(i >= fib[a]){
	//		printf("i %lld >= sf[%d] %lld\n", i, a, fib[a]);
			lz = 0;
			no.pb(1);
			no.pb(0);
			i -= fib[a];
			a--;
		}
		else if(!lz)
			no.pb(0);
	}
	for(int a=0;a<no.size();a++){
		//printf("%d", no[a]);
	}
	puts("");
}

ll dp[MAXN][3];
ll qtd[MAXN][3];

ll go2(int i, int lo){
	if(i >= s.size())
		return 0;
	if(dp[i][lo] != -1) return dp[i][lo];
	if(i == 0)
		return dp[i][lo] = go2(i+2, lo) + sf[s.size()-2];
	dp[i][lo] = 0;

	dp[i][lo] = go2(i+1, max(lo, (int)(s[i] == 1)));
	if(lo || s[i] == 1){
		if(i == s.size()-1)
			dp[i][lo] += go2(i+2, lo) + 1;
		else
			dp[i][lo] += go2(i+2, lo) + sf[s.size() - i - 2];
	}
	return dp[i][lo];
}

ll go(int i, int lo){
	if(i >= s.size()){
		dp[i][lo] = 0;
		qtd[i][lo] = 1;
		return 1;
	}
	if(dp[i][lo] != -1) return qtd[i][lo];
	if(i == 0){
		qtd[i][lo] = go(i+2, lo);
		dp[i][lo] = dp[i+2][lo] + qtd[i+2][lo];
		return qtd[i][lo];
	}
	dp[i][lo] = 0;
	qtd[i][lo] = 0;

	qtd[i][lo] = go(i+1, max(lo, (int)(s[i] == 1)));
	dp[i][lo] = dp[i+1][max(lo, (int)(s[i] == 1))];

	if(lo || s[i] == 1){
		if(i == s.size()-1){
			qtd[i][lo] += go(i+2, lo);
			dp[i][lo] += dp[i+2][lo] + 1;
		}
		else{
			qtd[i][lo] += go(i+2, lo);
			dp[i][lo] += dp[i+2][lo] + qtd[i+2][lo];
		}
	}
	return qtd[i][lo];
}

int main (){
	//freopen("fibonacci.in", "r", stdin);
	//freopen("fibonacci.out", "w", stdout);
	scanf("%lld", &n);
	n1[1] = 1;
	n1[2] = 1;
	qt[1] = 1;
	qt[2] = 1;
	ll a;
	ll mx = 0;
	ll res = 0;
	for(a=1;1;a++){
		if(a > 2){
			n1[a] = n1[a-2] + n1[a-1] + qt[a-2];
			qt[a] = qt[a-1] + qt[a-2];
		}
		mx = max(mx, qt[a]);
		if(n < qt[a]*a)
			break;
		n -= qt[a]*a;
		res += n1[a];
	}
	ll tam = a;
	ll i = n/a + (n%a != 0);
	//printf("a %lld\n", a);
	//printf("tam %lld i %lld\n", tam, i);
	if(n == 0){
		printf("%lld\n", res);
		return 0;
	}
	fib[0] = 1;
	sf[0] = 1;
	fib[1] = 1;
	sf[1] = 2;

	for(j=2;;j++){
		fib[j] = fib[j-1] + fib[j-2];
		sf[j] = sf[j-1] + fib[j];
		if(sf[j-2] >= mx) break;
	}
	for(int a=0;a<=j;a++)
		fib[a]++;
	re(i);
	s.pb(1);
	while(s.size() + no.size() < tam){
		s.pb(0);
	}
	for(int i=0;i<no.size();i++){
		s.pb(no[i]);
	}
	//printf("NMERO: "); 
	for(int a=0;a<s.size();a++){
		printf("%d", s[a]);
	}
	puts("");
	//printf("ate tam rs %lld\n", res);
	//printf("n %lld tam %lld\n", n, tam); 


	if((n%tam) != 0){
		//printf("limpa de %d a %d\n", (int)(n%a), (int)s.size()-1);
		for(int i=(int)s.size()-1;i>=(n%a);i--){
			//printf("limpa %d\n", s[i]);
			if(s[i] == 1)
				res--;
		}
	}
	memset(dp, -1, sizeof(dp));
	go(0, 0);
	res += dp[0][0];
	printf("%lld\n", res);
}
