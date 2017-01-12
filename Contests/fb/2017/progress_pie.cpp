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

const double DEL = 1e-8;

int sqdist(int x, int y, int xx, int yy){
	return (x - xx)*(x - xx) + (y - yy)*(y - yy);
}

double pi = acos(-1);

double angulo(double x, double y){
	double a = (double)sqdist(50, 50, x, y);
	double b = (double)sqdist(50, 50, 50, 100);
	double c = (double)sqdist(50, 100, x, y);
	return acos((a + b - c)/(2.*sqrt(a)*sqrt(b)));
}

int main (){
	int n;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x, y;
		int p;
		scanf("%d %d %d", &p, &x, &y);
		printf("Case #%d: ", a+1);
		if(sqdist(x, y, 50, 50) > 50*50 || p == 0){
			printf("white\n");
			continue;
		}
		if(x == 50 && y == 50){
			printf("black\n");
			continue;
		}
		if(x == 50){
			if(y >= 50)
				printf("black\n");
			else{
				if(p >= 50)
					printf("black\n");
				else
					printf("white\n");
			}
			continue;
		}
			
		double por = p+DEL;
		double ang = angulo(x, y);
		if(x < 50)
			ang = 2.*pi - ang;
		double pp = (100. * ang)/(2.*pi);
		if(pp < por)
			printf("black\n");
		else
			printf("white\n");
	}
}
