#include <bits/stdc++.h>
using namespace std;


// De quantos jeitos posso conseguir o valor de 200 dolares 

vector<int> moedas = {1, 2, 5, 10, 20, 50, 100};

const int GOAL = 200;

int go(int i, int sum){
	if(sum > GOAL) 
		return 0;

	if(i == moedas.size())
		return (sum == GOAL);

	int nways = 0;
	for(int quantity = 0;sum + moedas[i]*quantity <= GOAL;quantity++){
		nways += go(i+1, sum + moedas[i]*quantity);
	}
	return nways;
}

int main (){
	printf("%d\n", go(0, 0));
}

