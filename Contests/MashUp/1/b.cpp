#include <bits/stdc++.h>

using namespace std;

int n;
double v[10];
double tot = 0.0;

bool check(int id) {

	for(int i=0;i<n;i++) {
		if(i == id) continue;
	//	printf("%.0f/%0f = %f\n", v[id]-v[i], tot, (v[id]-v[i])/tot);
		if((v[id]-v[i])/tot < 0.1) return 0;
	}
	return 1;
}

int main() {
	
	cin >> n;

	int idmax = 0;
	for(int i=0;i<n;i++) {
		cin >> v[i];
		if(v[i] > v[idmax]) {
			idmax = i;
		}
		tot += v[i];
	}

	//printf("[%d] %.0f %.0f\n", idmax, v[idmax], tot);
	if(v[idmax]/tot >= 0.45 || (v[idmax]/tot >= 0.40 && check(idmax))) {
		printf("1\n");
	} else printf("2\n");

	



}
