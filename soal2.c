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

struct Graph {
    int numVertices;
    int** adjMatrix;
};

// Fungsi unutk mendeteksi siklus di Graph menggunakan prinsip DFS
// Source Code : https://www.geeksforgeeks.org/c/graph-cycle-detection-in-c/
int dfsCycleDetection(struct Graph *graf, int vertex, int* visited) {
    visited[vertex] = 1;

    for (int i = 0; i < graf->numVertices; i++) {
        if (graf->adjMatrix[vertex][i]) {
            if (visited[i]) {
                return 1;
            } else if (!visited[i]) {
                if (dfsCycleDetection(graf, i, visited)) {
                    return 1;
                }
            }
        }
    }

    visited[vertex] = 2;
    return 0;
}

// Fungsi untuk mendeteksi siklus di Graph
// Source Code : https://www.geeksforgeeks.org/c/graph-cycle-detection-in-c/
int detectCycle(struct Graph *graf) {
    int *visited = (int*) malloc(graf->numVertices*sizeof(int));
    for (int i = 0; i < graf->numVertices; i++) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < graf->numVertices; i++) {
        if (!visited[i]) {
            if (dfsCycleDetection(graf, i, visited)) {
                free(visited);
                return 1;
            }
        }
    }
    free(visited);
    return 0;
}

int main() {
    int N, M;

    scanf("%d", &N);
    scanf("%d", &M);

    // Inisialisai Graph
    struct Graph *graf = (struct Graph*) malloc(sizeof(struct Graph));
    graf->adjMatrix = malloc(N * sizeof(int*));
    graf->numVertices = N;
    for (int i=0; i<N; i++) {
        graf->adjMatrix[i] = (int*) malloc(N*sizeof(int));
        for (int j=0; j<N; j++) {
            graf->adjMatrix[i][j] = 0;      // 0 : Tidak Terhubung, 1 : Terhubung
        }
    }

    // Menempatakan edge
    for (int i=0; i<M; i++) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        graf->adjMatrix[b][a] = 1;
    }

    if (detectCycle(graf)) {
        printf("TIDAK BISA");
    } else {
        printf("BISA");
    }

    for (int i=0; i<N; i++) {
        free(graf->adjMatrix[i]);
    }
    free(graf->adjMatrix);
    free(graf);

    return 0;
}
