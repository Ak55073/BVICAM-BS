#include <iostream>

using namespace std;

const int LENGTH = 7;
int graph[LENGTH][LENGTH] = {
    { 0, 2, 0, 1, 0, 0, 0},
    { 0, 0, 0, 3,10, 0, 0},
    { 4, 0, 0, 0, 0, 5, 0},
    { 0, 0, 2, 0, 2, 8, 4},
    { 0, 0, 0, 0, 0, 0, 6},
    { 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0}
};
int parent[LENGTH];
int dist[LENGTH];
int visited[LENGTH];

void path(int i) {
    if (parent[i] == -1)
        return;
    path(parent[i]);
    printf(" %d", i);
}

int minDistance() {
    int minimum = 99, minIndex, i;
    for (i = 0; i < LENGTH; i++) {
        if (visited[i] == 0 && dist[i] < minimum) {
            minimum = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int source) {
    int i, v;
    for (i = 0; i < LENGTH; i++) {
        dist[i] = 99;
        visited[i] = 0;
    }
    dist[source] = 0;
    parent[source] = -1;

    for (i = 0; i < LENGTH - 1; i++) {
        int u = minDistance();
        visited[u] = 1;
        for (v = 0; v < LENGTH; v++) {
            if (visited[v] == 0 && dist[u] != 99 && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

int main() {
    int i, source;
    printf("Dijkstra - Abhinav Kumar\n\n");
    printf("Enter source: ");
    scanf("%d", &source);
    dijkstra(source);
    printf("Source\tVertex\t\tDistance\n");
    for (i = 0; i < LENGTH; i++) {
        printf("%d \t%d \t\t%d =>", source, i, dist[i]);
        path(i);
        printf("\n");
    }
    return 0;
}
