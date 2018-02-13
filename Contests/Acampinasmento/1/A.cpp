#include <bits/stdc++.h>
using namespace std;

ll M[50007][3];
int main(void){
	int n;

	cin >> n;
	for(int i=0;i<n;i++)
		cin >> M[i][0] >> M[i][1];

	M[n][0] = M[0][0];
	M[n][1] = M[0][1];

	double area = 0;
	for(int i=0;i<n;i++){
		area += M[i][0]*M[i+1][1];
		area -= M[i][1]*M[i+1][0];
	}
	area /= 2;
	cout << area << endl;
	return 0;	
}
