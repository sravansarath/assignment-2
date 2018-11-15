#include<mpi.h>
#include<stdio.h>

void main(int argc, char** argv)
{
	int a, b, num, id;

	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &a);
	MPI_Comm_size(MPI_COMM_WORLD, &b);

	if(a == 0)
	{
		int c = scanf("%d", &num);
		printf("Root node sends %d to all others\n", num);

	}
	
	MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("\n %d is the value received by process %d", num, a);
	
	MPI_Finalize();
	
}