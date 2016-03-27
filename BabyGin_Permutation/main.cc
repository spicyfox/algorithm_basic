// Baby-Gin: 순열
#include <iostream>
#include <cstdio>
using namespace std;


#define MAX 6
char NUM[MAX + 1];
bool VISITED[MAX + 1];

bool solveNumCounting() {
	int count[10] = {0,};
	bool triple = false;

	bool triplet = false;
	int i = 1;
	int index;
	for(;i <= MAX; i++) {
		index = NUM[i - 1] - '0';
		count[index]++;
		triplet = (count[index] == 3 ? true: false); 
	}

	if (!triplet) {
		return false;
	}
	
	// run check
	bool run = false;
	for(i = 0; i <= 7; i++) {
		if (count[i] == 1 && count[i + 1] == 1 && count[i + 2] == 1) {
			run = true;
			break;
		}
	}

	return run;

}

char RESULT[MAX + 1] = {0,};
bool FOUND;

void dfs(int n, int k) {
	if (FOUND) {
		return;
	}
	if (n == k) {
		if (RESULT[5] == RESULT[4] && RESULT[4] == RESULT[3]) {
			if ((RESULT[2] + 1) == RESULT[1] && (RESULT[1] + 1) == RESULT[0]) {
				FOUND = true;
			}
		}

		return;
	}

	for(int i = 1; i <= MAX; i++) {
		if (!VISITED[i]) {
			VISITED[i] = true;
			RESULT[n] = NUM[i - 1];
			dfs(n + 1, k);
			VISITED[i] = false;
		}
	}
}

bool solvePermutation() {
	FOUND = false;
	dfs(0, 6);
	return FOUND;
}

int main() {

	int T;
	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for(int testCase = 1; testCase <=T ; testCase++) {
		scanf("%s", &NUM);
		printf("%s => %s\n", NUM, solveNumCounting() ? "True": "False");
		printf("%s => %s\n", NUM, solvePermutation() ? "True": "False");
	}
	return 0;
}