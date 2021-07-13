#include<stdio.h>
#include<stdlib.h>

const int LENGTH = 9;
int matrix[LENGTH][LENGTH], size = 0;
int queue[LENGTH], front = -1, rear = -1, visited[LENGTH];

void insertVertex(int v) {
    size = size + 1;
    matrix[size][0] = v;
    matrix[0][size] = v;
    for (int i = 1; i <= size; i++) {
        matrix[size][i] = 0;
        matrix[i][size] = 0;
    }
}

void deleteVertex(int v) {
    int i, j, k;
    j = 0;
    for (i = 1; i <= size; i++) {
        if (matrix[i][j] == v) {
            matrix[i][j] = 0;
            for (k = 0; k <= size; k++) {
                matrix[i][k] = 0;
            }
        }
    }
    i = 0;
    for (j = 1; j <= size; j++) {
        if (matrix[i][j] == v) {
            matrix[i][j] = 0;
            for (k = 0; k <= size; k++) {
                matrix[k][j] = 0;
            }
        }
    }
}

void insertEdge(int sEdge, int dEdge) {
    matrix[sEdge][dEdge] = 1;
    matrix[dEdge][sEdge] = 1;
}

void deleteEdge(int sEdge, int dEdge) {
    matrix[sEdge][dEdge] = 0;
    matrix[dEdge][sEdge] = 0;
}

void display() {
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            printf("\t%d", matrix[i][j]);
        }
        printf("\n");
    }
}

void enqueue(int x) {
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = rear + 1;
    }
    queue[rear] = x;
}

int dequeue() {
    int temp;
    temp = queue[front];
    if (rear == front)
        front = rear = -1;
    else
        front = front + 1;
    return temp;
}

int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

void BFS(int i) {
    enqueue(i);
    visited[i] = 1;
    printf("%d", i);
    while (!isEmpty()) {
        i = dequeue();
        for (int j = 1; j <= size; j++) {
            if (matrix[i][j] == 1 && visited[j] != 1) {
                enqueue(j);
                visited[j] = 1;
                printf(" %d", j);
            }
        }
    }
}

int main() {
    printf("Graph - Abhinav Kumar\n\n");
    printf("Select: ");
    printf("\n 1.Insert a new Vertex");
    printf("\n 2.Delete a Vertex");
    printf("\n 3.Insert a new Edge");
    printf("\n 4.Delete an Edge");
    printf("\n 5.Display the Adjacency Matrix");
    printf("\n 6.Traversal(BFS)");
    printf("\n 0.Exit");
    int v, choice, sE, dE, src;
    while (true) {
        printf("\nEnter your choice: ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            printf("\nInput the Vertex to Insert: ");
            scanf("%d", & v);
            insertVertex(v);
            break;
        case 2:
            printf("\nInput the Vertex to Delete: ");
            scanf("%d", & v);
            insertVertex(v);
            break;
        case 3:
            printf("\nInput the Source Vertex: ");
            scanf("%d", & sE);
            printf("\nInput the Destination Vertex: ");
            scanf("%d", & dE);
            insertEdge(sE, dE);
            break;
        case 4:
            printf("\nInput the Source Vertex: ");
            scanf("%d", & sE);
            printf("\nInput the Destination Vertex: ");
            scanf("%d", & dE);
            deleteEdge(sE, dE);
            break;
        case 5:
            printf("\n\nAdjacency Matrix: \n");
            display();
            break;
        case 6:
            printf("\nInput the Source: ");
            scanf("%d", & src);
            printf("\nTraversal of Graph (BFS): ");
            BFS(src);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\n Wrong Choice.\n");
            break;
        }
    }
}
