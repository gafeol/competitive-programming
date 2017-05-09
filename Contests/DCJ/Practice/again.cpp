#include <message.h>
#include <stdio.h>
#include "again.h"

#define MASTER_NODE 0
#define SENDING_DONE -1
#define LARGE_PRIME 1000000007

int main() {
	if (MyNodeId() == MASTER_NODE) {
		long long result = 0;
		for (int node = 1; node < NumberOfNodes(); ++node) {
			while (true) {
				Receive(node);
				long long value = GetLL(node);
				if (value == SENDING_DONE) {
					break;
				} else {
					result = (result + value) % LARGE_PRIME;
				}
			}
		}
		printf("%lld\n", result);
		return 0;
	} else {
		long long soma = 0;
		for (long long i = 0; i < GetN(); ++i) {
			long long ii = i % NumberOfNodes(), jj;
			jj = MyNodeId() - ii; 
			if(jj < 0)
				jj += NumberOfNodes();
			for (long long j = jj; j < GetN(); j += NumberOfNodes()) {
				soma = (soma + GetA(i) * GetB(j))%LARGE_PRIME;
			}
		}
		PutLL(MASTER_NODE, soma);
		Send(MASTER_NODE);
		PutLL(MASTER_NODE, SENDING_DONE);
		Send(MASTER_NODE);
	}
	return 0;
}
