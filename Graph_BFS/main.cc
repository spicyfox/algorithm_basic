#include <cstdio>
using namespace std;

#define MAX 100

int G[MAX + 1][MAX + 1] = {0,};
int VISITED[MAX + 1] = {0,};

int E;
int V;

void bfs(int start) {

    int queue[MAX + 1];
    int D[MAX + 1];
    for(int i = 1; i <= V; i++) {
        D[i] = 0xFFFF;
    }

    int front, rear;
    front = rear = -1;
    queue[++rear] = start;
    D[start] = 0;

    while(front != rear) {
        int v = queue[++front];

        printf("%d ", v);
        for(int i = 1; i <= V; i++) {
            if (G[v][i] && D[i] > (D[v] + G[v][i])) {
                queue[++rear] = i;
                D[i] = D[v] + G[v][i];
            }
        }
    }

    printf("\n");
    for(int i = 1; i <= V; i++) {
        printf("%d ",D[i]);
    }
    printf("\n");
}

int main() {

    freopen("sample_input.txt", "r", stdin);
    scanf("%d %d", &V, &E);
    for(int i = 1; i <= E; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        G[from][to] = 1;
    }
    bfs(1);
    return 0;
}