#include <bits/stdc++.h>
using namespace std;

int n, m, k;

const long long MAXX = ((long long)3)*INT_MAX + 10LL;

map<long long, int> bit, bit2;

int tot;

int qry(long long i){
	i += 2;
	int ans = 0;
	while(i < MAXX){
		if(bit.find(i) != bit.end())
			ans += bit[i];
		i += (i &-i);
	}
	return ans;
}

int qry2(long long i){
	i += 2;
	int ans = 0;
	while(i > 0){
		if(bit2.find(i) != bit2.end())
			ans += bit2[i];
		i -= (i &-i);
	}
	return ans;
}

void upd(long long i){
	i += 2;
	while(i > 0){
		bit[i]++;
		i -= (i&-i);
	}
}

void upd2(long long i){
	i += 2;
	while(i < MAXX){
		bit2[i]++;
		i += (i&-i);
	}
}


int reversePairs(vector<int>& nums) {
	int res = 0;
	for(long long i: nums){
		if(i < 0){
			i = abs(i);
			res += qry(0) + qry2(2*i - 1);
			upd2(i);
		}
		else{
			res += qry(2*i + 1);
			upd(i);	
		}
	}
	return res;
}


int main (){
	vector<int> n = {2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647};
	printf("%d\n", reversePairs(n));
}

