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
		printf("Master sends %d to slave\n", num);
		MPI_Send(&num, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
	}
	else if(a == 1)
	{
		MPI_Recv(&id, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		printf("%d is the value received by slave", id);
	}
	
	MPI_Finalize();
}