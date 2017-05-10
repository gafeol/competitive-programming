#include <message.h>
#include <stdio.h>
#include "again.h"
#include <algorithm>
using namespace std;

#define MASTER_NODE 0
#define SENDING_DONE -1
#define LARGE_PRIME 1000000007

int main() {
	if (MyNodeId() == MASTER_NODE) {
		long long soma = 0, somb = 0;
		long long sa[110], sb[110];
		for (int node = 1; node < NumberOfNodes(); ++node) {
			Receive(node);
			long long vala = GetLL(node);
			Receive(node);
			long long valb = GetLL(node);
			soma = (soma + vala) % LARGE_PRIME;
			somb = (somb + valb) % LARGE_PRIME;
			for(int pc = 0;pc < NumberOfNodes();pc++){
				Receive(node);
				sa[pc] = (sa[pc] + GetLL(node)) % LARGE_PRIME;
				Receive(node);
				sb[pc] = (sb[pc] + GetLL(node)) % LARGE_PRIME;
			}
		}

		long long res = (soma*somb)%LARGE_PRIME;
		for(int pc = 0;pc < NumberOfNodes();pc++){
			result = (result - sa[pc] * sb[(NumberOfNodes() - pc)%NumberOfNodes()]);
		}
		printf("%lld\n", res);
		return 0;
	} else {
		long long soma = 0, somb = 0;
		long long no = NumberOfNodes() - 1;
		for (long long i = (MyNodeId()-1)*2000000ll; i < min((long long)GetN(), MyNodeId()*2000000ll); ++i) {
			soma = (soma + GetA(i))%LARGE_PRIME;
			somb = (somb + GetB(i))%LARGE_PRIME;
			sa[i%NumberOfNodes()] = (sa[i%NumberOfNodes()] + GetA(i))%LARGE_PRIME;
			sb[i%NumberOfNodes()] = (sb[i%NumberOfNodes()] + GetB(i))%LARGE_PRIME;
			printf("%lld  %lld %lld %lld %lld\n", i, GetA(i), soma, GetB(i), somb);
		}
		printf("%d %lld %lld\n", MyNodeId(), soma, somb);
		PutLL(MASTER_NODE, soma);
		Send(MASTER_NODE);
		PutLL(MASTER_NODE, somb);
		Send(MASTER_NODE);
		for(long long i = 0;i < NumberOfNodes();i++){
			PutLL(MASTER_NODE, sa[i]);
			Send(MASTER_NODE);
			PutLL(MASTER_NODE, sb[i]);
			Send(MASTER_NODE);
		}
	}
	return 0;
}
