#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

set<int> V4, V6, V8;
string si,sj,sp;
int n,p;

int main(){
	for(int i=10; i<=99; i++){
		for(int j=i; j<=99; j++){
			p=i*j;
			if(p>=1000 && p<=9999 && p%2==0){
				si+= '0'+(i/10); si+= '0'+ (i - (i/10)*10);
				sj+= '0'+(j/10); sj+= '0'+ (j - (j/10)*10);
				sp+= '0'+(p/1000);sp+='0'+((p/100)-(p/1000)*10);
				sp+= '0'+((p/10)-(p/100)*10); sp+='0'+(p%10);
				si+=sj;
				sort(si.begin(),si.end()); sort(sp.begin(),sp.end());
				if(si==sp){
					V4.insert(p);
				}
				si.clear();sj.clear();sp.clear();
			}
		}
	}
	for(int i=100; i<=999; i++){
		for(int j=i; j<=999; j++){
			p=i*j;
			if(p>=100000 && p<=999999 && p%2==0){
				si+= '0'+(i/100); si+= '0'+ ((i/10) - (i/100)*10); si+='0'+(i%10);
				sj+= '0'+(j/100); sj+= '0'+ ((j/10) - (j/100)*10); sj+='0'+(j%10);
				sp+= '0'+(p/100000);sp+='0'+((p/10000)-(p/100000)*10);
				sp+= '0'+((p/1000)-(p/10000)*10);
				sp+= '0'+((p/100)-(p/1000)*10);
				sp+= '0'+ ((p/10)-(p/100)*10); sp+='0'+(p%10);
				si+=sj;
				sort(si.begin(),si.end()); sort(sp.begin(),sp.end());
				if(si==sp){
					V6.insert(p);
				}
				si.clear();sj.clear();sp.clear();
			}
		}
	}

	for(int i=1000; i<=9999; i++){
		for(int j=i; j<=9999; j++){
			p=i*j;
			if(p>=10000000 && p<=99999999 && p%2==0){
				si+= '0'+(i/1000);sp+='0'+((i/100)-(i/1000)*10);
				si+= '0'+((i/10)-(i/100)*10); si+='0'+(i%10);
				sj+= '0'+(j/1000);sj+='0'+((j/100)-(j/1000)*10);
				sj+= '0'+((j/10)-(j/100)*10); sj+='0'+(j%10);

				sp+= '0'+(p/10000000);sp+='0'+((p/1000000)-(p/10000000)*10);
				sp+= '0'+((p/100000)-(p/1000000)*10);
				sp+= '0'+((p/10000)-(p/100000)*10);
				sp+= '0'+((p/1000)-(p/10000)*10);
				sp+= '0'+ ((p/100)-(p/1000)*10);sp+='0'+ ((p/10)-(p/100)*10); sp+='0'+(p%10);
				si+=sj;
				sort(si.begin(),si.end()); sort(sp.begin(),sp.end());
				if(si==sp){
					V8.insert(p);
				}
				si.clear();sj.clear();sp.clear();
			}
		}
	}

	while(scanf("%d", &n)!=EOF){
		if(n==4){
			for(set<int>::iterator it = V4.begin(); it!=V4.end(); ++it){
				printf("%d\n", *it);
			}
			printf("\n");
		}else if(n==6){
			for(set<int>::iterator it = V6.begin(); it!=V6.end(); ++it){
				printf("%d\n", *it);
			}
			printf("\n");
		}else{
			for(set<int>::iterator it = V8.begin(); it!=V8.end(); ++it){
				printf("%d\n", *it);
			}
			printf("\n");
		}
	}
}
