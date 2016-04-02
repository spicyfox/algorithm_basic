// 조합 - combination

#include <cstdio>
#include <ctime>
using namespace std;

#define ULLONG unsigned long long

const int N = 25;
int DATA[] = {-1, 3, -9, 6, 7,-6, 1,5,4, -2, -1, 3, -9, 6, 7,-6, 1,5,4, -2, -1, 3, -9, 6, 7,-6, 1,5,4, -2};
int PATH[N] = {0,};
ULLONG COUNT = 0;


inline void dfs(int n, int len, int sum) {
	if (n == N) {
		if (sum == 10) {
			// for(int i = 0; i < len; i++) {
			// 	printf("%d ", PATH[i]);
			// }			
			// printf("\n");
			COUNT++;
		}

		return;
	}
	
	PATH[len] = DATA[n];
	dfs(n + 1, len + 1, sum + DATA[n]);
	dfs(n + 1, len, sum);
}

void solve() {
	ULLONG to = (1 << N) - 1;
	int sum;
	for(ULLONG i = 1; i <= to; i++) {
		sum = 0;
		for(ULLONG j = 0; j < N; j++) {
			if ((i & (1 << j))) {
				sum += DATA[j];
			}
    	}
		if (sum == 10) {
			COUNT++;
		}
	}
}

int main() {

	long start = clock();
	dfs(0, 0, 0);
	printf("%lld [%.3fs]\n", COUNT, (float)((clock() - start)/ (float) CLOCKS_PER_SEC));

	COUNT = 0;
	start = clock();
	solve();
	printf("%lld [%.3fs]\n", COUNT, (float)((clock() - start)/ (float) CLOCKS_PER_SEC));
	return 0;
}