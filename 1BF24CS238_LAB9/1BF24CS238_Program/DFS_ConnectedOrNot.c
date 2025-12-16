#include <stdio.h>

int graph[20][20], visited[20], n;

void DFS(int node){
    visited[node] = 1;
    for(int i = 0; i < n; i++){
        if(graph[node][i] == 1 && !visited[i]){
            DFS(i);
        }
    }
}

int main(){
    int start;
    int connected = 1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    DFS(start);

    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            connected = 0;
            break;
        }
    }

    if(connected){
        printf("Graph is Connected\n");
    } else {
        printf("Graph is Not Connected\n");
    }

    return 0;
}
