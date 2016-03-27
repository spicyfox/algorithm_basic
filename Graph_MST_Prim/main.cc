// MST - Minimum Spanning Tree
// Spanning Tree(신장트리): n개의 정점으로 이루어진 무방향 그래프트에서
// n개의 정점과 n-1개의 간선으로 이루어진 트리
// MST: 가중치 합이 최소인 신장 트리

#include <cstdio>

#define MAX 100


int G[MAX][MAX];
int V, E;
bool USED[MAX];
int PARENT[MAX] = {0,};
int KEY[MAX];

int getMinKeyVertex() {
    int minWeight = 0xFFFF;
    int found = -1;
    for(int i = 0; i < V; i++) {
        if (!USED[i] && KEY[i] < minWeight) {
            minWeight = KEY[i];
            found = i;
        }
    }
    if (found >= 0) {
        USED[found] = true;
    }

    printf(">> %d\n", found);
    return found;
}

void show() {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%3d ", G[i][j]);
        }
        printf("\n");
    }
}
// 임의의 정점을 시작으로 해서, 모든 정점을 Priority Queue에 넣고, 
// KEY 값이 가장 작은 정점 가져 온후, 인접 정점들에 대해, Queue에 아직 있는 정점에 대해 KEY 값 갱신
//
// 결과: PARENT - 부모 node,  KEY - 가중치 

int bfsPrim(int start) {
    for(int i = 0; i < V; i++) {
        KEY[i] = 0xFFFF;
        PARENT[i] = 0;
        USED[i] = false;
    }

    KEY[start] = 0;

    int count = V;
    while (count > 0) {
        int v = getMinKeyVertex();      // Priority Queue에서 가장 작은 정점 가져온다.
        for(int i = 0; i < V; i++) {    // 인접 정접들에 대해
            if (!USED[i] && G[v][i] && KEY[i] > G[v][i]) {
                KEY[i] = G[v][i];       // KEY 값 갱신
                PARENT[i] = v;          // 부모값 갱신
                printf("==> %d %d %d\n", v, i, KEY[i]);
            }
        }
        count--;
    }

    for(int i = 0; i < V; i++) {
        printf("%3d", PARENT[i]);
    }
    printf("\n");
    for(int i = 0; i < V; i++) {
        printf("%3d", KEY[i]);
    }
    printf("\n");
}


int main() {
    freopen("sample_input.txt", "r", stdin);
    scanf("%d %d", &V, &E);
    for(int i = 0; i <E; i++) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        G[start][end] = G[end][start] = weight;
    }
    show();
    bfsPrim(0);
    return 0;
}