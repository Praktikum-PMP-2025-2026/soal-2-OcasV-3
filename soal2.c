/*
* EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
* Modul : 5 - Foundation of Algorithm
* Hari dan Tanggal : Senin, 11 Mei 2026 
* Pembuat : Farras Fuady Hakim
* Nama File : 13224047.c
* Deskripsi : Menerima jumlah misi dan ketergantungannya terhadap suatu misi dan mengeluarkan apakah misi-misi valid (tidak ada siklus).
*/

#include <stdio.h>
#include <stdlib.h>

#define NMax 10
#define MMax 15

typedef struct Graph {
    int numVertices;
    int adjMatrix[NMax][MMax];
}Graph;

// Fungsi unutk mendeteksi siklus di Graph menggunakan prinsip DFS
// Source Code : https://www.geeksforgeeks.org/c/graph-cycle-detection-in-c/
int dfsCycleDetection(struct Graph* graph, int vertex, int* visited, int parent) {
    visited[vertex] = 1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i]) {
            if (!visited[i]) {
                if (dfsCycleDetection(graph, i, visited, vertex)) {
                    return 1;
                }
            }
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

// Fungsi untuk mendeteksi siklus di Graph
// Source Code : https://www.geeksforgeeks.org/c/graph-cycle-detection-in-c/
int detectCycle(struct Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (dfsCycleDetection(graph, i, visited, -1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int N, M;

    scanf("%d%d", &N, &M);

    Graph *graf = malloc(sizeof(Graph));

    graf->numVertices = N;

    for (int i=0; i<M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graf->adjMatrix[a][b] = 1;
    }
    if (detectCycle) {
        printf("BISA");
    } else {
        printf("TIDAK BISA");
    }

    return 0;
}
