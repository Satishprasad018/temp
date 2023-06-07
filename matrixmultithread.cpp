// CPP Program to multiply two matrix using pthreads
#include <bits/stdc++.h>
using namespace std;

// maximum size of matrix
#define MAX 4

// maximum number of threads
#define MAX_THREAD 4

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;

void* multi(void* arg)
{
	int i = step_i++; //i denotes row number of resultant matC

	for (int j = 0; j < MAX; j++)
	for (int k = 0; k < MAX; k++)
		matC[i][j] += matA[i][k] * matB[k][j];
}

// Driver Code
int main()
{
	// Generating random values in matA and matB
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			matA[i][j] = rand() % 10;
			matB[i][j] = rand() % 10;
		}
	}

	// Displaying matA
	cout << endl
		<< "Matrix A" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matA[i][j] << " ";
		cout << endl;
	}

	// Displaying matB
	cout << endl
		<< "Matrix B" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matB[i][j] << " ";
		cout << endl;
	}

	// declaring four threads
	pthread_t threads[MAX_THREAD];

	// Creating four threads, each evaluating its own part
	for (int i = 0; i < MAX_THREAD; i++) {
		int* p;
		pthread_create(&threads[i], NULL, multi, (void*)(p));
	}

	// joining and waiting for all threads to complete
	for (int i = 0; i < MAX_THREAD; i++)
		pthread_join(threads[i], NULL);

	// Displaying the result matrix
	cout << endl
		<< "Multiplication of A and B" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matC[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define M 3
#define K 2
#define N 3
#define NUM_THREADS 10
int A [M][K] = { {1,4}, {2,5}, {3,6} };
int B [K][N] = { {8,7,6}, {5,4,3} };
int C [M][N];
struct v {
   int i; /* row
   int j; /* column
};
void *runner(void *param); /* the thread
int main(int argc, char *argv[]) {
   int i,j, count = 0;
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         struct v *data = (struct v *) malloc(sizeof(struct v));
         data->i = i;
         data->j = j;
         pthread_t tid;       //Thread ID
         pthread_attr_t attr; //Set of thread attributes
         pthread_attr_init(&attr);
         pthread_create(&tid,&attr,runner,data);
         pthread_join(tid, NULL);
         count++;
      }
   }
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         printf("%d ", C[i][j]);
      }
      printf("\n");
   }
}
void *runner(void *param) {
   struct v *data = param; // the structure that holds our data
   int n, sum = 0; //the counter and sum
   for(n = 0; n< K; n++){
      sum += A[data->i][n] * B[n][data->j];
   }
   C[data->i][data->j] = sum;
   pthread_exit(0);
}
*/
