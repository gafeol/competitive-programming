#include <message.h>
#include <stdio.h>
#include "again.h"

#define MASTER_NODE 0
#define SENDING_DONE -1
#define LARGE_PRIME 1000000007

int main() {
	if (MyNodeId() == MASTER_NODE) {
		long long result = 0;
		long long soma = 0, sumb = 0;
		long long sa[110], sb[110];
		for (int node = 1; node < NumberOfNodes(); ++node) {
			Receive(node);
			long long soma = (soma + GetLL(node))%LARGE_PRIME;
			Receive(node);
			long long somb = (somb + GetLL(node))%LARGE_PRIME; 
			for(int pc = 0;pc < NumberOfNodes();pc++){
				Receive(node);
				sa[pc] = (sa[pc] + GetLL(node)) % LARGE_PRIME;
				Receive(node);
				sb[pc] = (sb[pc] + GetLL(node)) % LARGE_PRIME;
			}
		}
		result = (soma * somb)%LARGE_PRIME;
		for(int pc = 0;pc < NumberOfNodes();pc++){
			result = (result - sa[pc] * sb[(NumberOfNodes() - pc)%NumberOfNodes()]);
		}
		printf("%lld\n", result);
		return 0;
	} else {
		int no = NumberOfNodes() - 1;
		long long soma = 0, sumb = 0;
		long long sa[110], sb[110];
		for (long long i = (MyNodeId()-1)*(GetN()/no); i < (MyNodeId())*(GetN()/no); ++i) {
			soma = (soma + GetA(i))%LARGE_PRIME;
			somb = (somb + GetB(i))%LARGE_PRIME;
			sa[i%NumberOfNodes()] = (sa[i%NumberOfNodes()] + GetA(i))%LARGE_PRIME;
			sb[i%NumberOfNodes()] = (sb[i%NumberOfNodes()] + GetB(i))%LARGE_PRIME;
		}
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
