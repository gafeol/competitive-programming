#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c;

int main(){
	scanf("%lld %lld %lld", &a, &b, &c);
	if(a == 0 && b == 0 && c == 0){
		puts("-1");
		return 0;
	}
	if(a == 0 && b == 0){
		puts("0");
		return 0;
	}
	if(a == 0){	
		printf("1\n%.10Lf\n", (long double)(-c)/((long double)b)); 
		return 0;
	}
	ll d = b*b - 4ll*a*c;
	if(d < 0){
		puts("0");
	}
	else if(d == 0){
		puts("1");
		printf("%.10Lf\n", ((long double)(-b)/((long double) 2.*a)));
	}
	else{
		puts("2");
		long double del = d;
		del = sqrt(del);
		long double x1 = ((long double)-b + del)/((long double) 2.*a);
		long double x2 = ((long double)-b - del)/((long double) 2.*a);
		if(x1 > x2) swap(x1, x2);
		printf("%.10Lf\n", x1); 
		printf("%.10Lf\n", x2); 
	}
}

