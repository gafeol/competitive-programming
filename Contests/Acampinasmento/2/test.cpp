#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getRandom(const ll &begin = 0, const ll &end = 100) {
	    return begin >= end ? 0 : begin + (ll) ((end - begin)*rand()/(double)RAND_MAX);
};

int n, m;

ll r(){
	return getRandom(-1000000000, 1000000000);
}

int main (){
	srand(time(NULL));
	scanf("%d %d", &n, &m);
	printf("%d\n", n);
	for(int a=0;a<n;a++){
		printf("%lld %lld\n", r(), r());
	}
	printf("%d\n", m);
	for(int a=0;a<m;a++){
		if((rand()%2))
			printf("get %lld %lld\n", getRandom(-1000000000, 1000000000), getRandom(-1000000000, 1000000000));
		else
			printf("add %lld %lld\n", r(), r());
	}
}
