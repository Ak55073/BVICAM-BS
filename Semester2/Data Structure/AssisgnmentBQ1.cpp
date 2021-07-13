#include <iostream>

using namespace std;

const int LENGTH = 5;
char NODES[] = {'A', 'B', 'C', 'D', 'E'};
int graph[LENGTH][LENGTH] = {
    { 0, 1, 0, 0, 0},
    { 1, 0, 0, 0, 2},
    { 0, 0, 0, 1, 1},
    { 0, 0, 1, 0, 1},
    { 0, 2, 1, 1, 0}
};
int path[LENGTH*LENGTH];
int ind =0;

bool visitedAll(){
    for(int i=0; i<LENGTH; i++){
        for(int j=0; j<LENGTH; j++){
            if (graph[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

bool passDoor(int source, int destination){
    path[ind++] = source;
    for(int i=0; i<LENGTH; i++){
        if (graph[source][i] != 0){
            graph[source][i]--;
            graph[i][source]--;
            bool visit = passDoor(i, destination);
            if(visit){
                return visit;
            }
            graph[source][i]++;
            graph[i][source]++;
        }
    }
    if (visitedAll()){
        return true;
    } else{
        ind--;
        return false;
    }
}

int main() {
    int source_vertex, end_vertex;
    printf("Assignment Question 1 - Abhinav Kumar\n\n");
    printf("Enter source vertex: ");
    scanf("%d",&source_vertex);

    printf("Enter destination vertex: ");
    scanf("%d",&end_vertex);

    passDoor(source_vertex, end_vertex);

    printf("Possible path: ");
    for(int i=0; i<ind; i++){
        if(i != 0)
            printf(" -> ");
        printf("%c", NODES[path[i]]);
    }

    if (visitedAll()){
        printf("\n\nPossible to visit all door only once");
    } else{
        printf("\n\nNot possible to visit all door only once");
    }

    if (path[ind--] == end_vertex){
        printf("\nPath end at destination\n");
    } else{
        printf("\nPath does not end at destination\n");
    }


    return 0;
}
