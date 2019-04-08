// Running median solution

#include <bits/stdc++.h>
using namespace std;

int n, m, k;

class RM{
	private:
		multiset<int> mx;
		multiset<int, greater<int>> mn;
	int getMx(){
		assert(!mx.empty());
		return *mx.begin();
	}

	int getMn(){
		assert(!mn.empty());
		return *mn.begin();
	}

	int popMx(){
		int val = *mx.begin();	
		mx.erase(mx.begin());
		return val;
	}

	int popMn(){
		int val = *mn.begin();
		mn.erase(mn.begin());
		return val;
	}

	void insertMn(int val){
		mn.insert(val);
	}

	void rebalance(){
		while(mx.size() > mn.size() + 1){
			insertMn(popMx());
		}
	}

	void insertMx(int val){
		mx.insert(val);
	}

	public:
	double median(){
		if(mx.size() == mn.size())
			return (getMx() + getMn())/2.;
		else
			return getMx();
	}

	void insert(int val){
		insertMn(val);
		insertMx(popMn());
		rebalance();
	}
};

int main (){
	scanf("%d", &n);
	vector<int> s(n);	
	RM obj;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		obj.insert(s[a]);
		printf("%.1f\n", obj.median());
	}

}

