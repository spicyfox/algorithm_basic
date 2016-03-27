#include <iostream>
#include <cstdio>
using namespace std;


#define MAX 100

int G[MAX+1][MAX+1];
int E, V;
int D[MAX + 1];

void showPrint() {
	for(int i = 1; i <= V; i++) {
		for(int j = 1; j <= V; j++) {
			printf("%4d ", G[i][j]);
		}
		printf("\n");
	}

	for(int i = 1; i <= V; i++) {
		printf("%4d ", D[i]);
	}
	printf("\n");

}

int bfsShortest(int s) {
	for(int i = 1; i <= V; i++) {
		D[i] = 0xFFFF;
	}

	int queue[MAX];
	int front, rear;
	front = rear = -1;

	D[s] = 0;
	queue[++rear] = s;

	while(front != rear) {
		int v = queue[++front];
		for(int i = 1; i <= V; i++){
			if (G[v][i] && D[i] > D[v] + G[v][i]) {
				D[i] = D[v] + G[v][i];
				queue[++rear] = i;
				//printf("%d ", i);
			}
		}
	}
	//printf("\n");

	return D[V];
}

int main() {

	freopen("sample_input.txt","r", stdin);
	scanf("%d %d", &V, &E);
	for(int i = 1; i <= E; i ++ ) {
		int from,to,c;
		scanf("%d %d %d",&from, &to, &c);
		//G[from][to] = G[to][from] = c;
		G[from][to] = c;
	}
	printf("%d\n", bfsShortest(1));
	//showPrint();
	return 0;
}