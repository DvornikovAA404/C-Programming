#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

int **A, **B, **C;
int N;

typedef struct {
    int start_row;
    int end_row;
} ThreadArgs;

void *multiply(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    for (int i = args->start_row; i < args->end_row; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return NULL;
}

void allocate_matrices() {
    A = malloc(N * sizeof(int *));
    B = malloc(N * sizeof(int *));
    C = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = malloc(N * sizeof(int));
        B[i] = malloc(N * sizeof(int));
        C[i] = malloc(N * sizeof(int));
    }
}

void fill_matrices() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }
}

void free_matrices() {
    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

double run_multiplication(int thread_count) {
    pthread_t threads[thread_count];
    ThreadArgs args[thread_count];

    int rows_per_thread = N / thread_count;
    int remainder = N % thread_count;
    int current_row = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < thread_count; i++) {
        args[i].start_row = current_row;
        args[i].end_row = current_row + rows_per_thread + (i < remainder ? 1 : 0);
        pthread_create(&threads[i], NULL, multiply, &args[i]);
        current_row = args[i].end_row;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_ms = (end.tv_sec - start.tv_sec) * 1000.0 +
                        (end.tv_nsec - start.tv_nsec) / 1e6;
    return elapsed_ms;
}

int main() {
    // Define matrix sizes and thread counts
    int sizes[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int thread_counts[] = {1, 2, 4, 8, 16};
    const int NUM_SIZES = sizeof(sizes) / sizeof(sizes[0]);
    const int NUM_THREADS = sizeof(thread_counts) / sizeof(thread_counts[0]);

    // Array to store timing results
    double time_ms[NUM_THREADS][NUM_SIZES];
    memset(time_ms, 0, sizeof(time_ms));

    // Open TSV file for writing
    FILE *tsv = fopen("results.tsv", "w");
    if (!tsv) {
        perror("fopen");
        return 1;
    }
    fprintf(tsv, "MatrixSize\tThreadCount\tTimeMs\n");

    // Run experiments
    for (int s = 0; s < NUM_SIZES; s++) {
        N = sizes[s];
        for (int t = 0; t < NUM_THREADS; t++) {
            int T = thread_counts[t];
            if (T > N) continue; // Skip if thread count exceeds matrix size
            allocate_matrices();
            fill_matrices();
            double elapsed_ms = run_multiplication(T);
            time_ms[t][s] = elapsed_ms;
            printf("N=%d, Threads=%d -> Time = %.2f ms\n", N, T, elapsed_ms);
            fprintf(tsv, "%d\t%d\t%.2f\n", N, T, elapsed_ms);
            free_matrices();
        }
    }
    fclose(tsv);

    // Generate GNUplot script
    FILE *gp = fopen("plot.gp", "w");
    if (!gp) {
        perror("fopen plot.gp");
        return 1;
    }
    fprintf(gp, "set terminal png\n");
    fprintf(gp, "set output 'plot.png'\n");
    fprintf(gp, "set title 'Matrix Multiplication Time vs Size for different Thread Counts'\n");
    fprintf(gp, "set xlabel 'Matrix Size (N)'\n");
    fprintf(gp, "set ylabel 'Time (ms)'\n");

    // Write data blocks for each thread count
    for (int t = 0; t < NUM_THREADS; t++) {
        int T = thread_counts[t];
        fprintf(gp, "$thread%d << EOD\n", T);
        for (int s = 0; s < NUM_SIZES; s++) {
            if (time_ms[t][s] > 0) { // Only include valid data
                fprintf(gp, "%d %.2f\n", sizes[s], time_ms[t][s]);
            }
        }
        fprintf(gp, "EOD\n");
    }

    // Write plot command
    fprintf(gp, "plot ");
    for (int t = 0; t < NUM_THREADS; t++) {
        int T = thread_counts[t];
        fprintf(gp, "$thread%d with lines title '%d threads'", T, T);
        if (t < NUM_THREADS - 1) fprintf(gp, ", ");
    }
    fprintf(gp, "\n");

    fclose(gp);

    // Run GNUplot to generate the plot
    int ret = system("gnuplot plot.gp");
    if (ret != 0) {
        fprintf(stderr, "Warning: GNUplot execution failed. Ensure GNUplot is installed.\n");
    }

    return 0;
}