#include<mpi.h>
#include<stdio.h>

void main(int argc,char** argv)
{
	int a, b, nl;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &a);
	MPI_Comm_size(MPI_COMM_WORLD, &b);
	printf("I'm process %d out of %d processes\n",a, b);
	MPI_Finalize();
	
}