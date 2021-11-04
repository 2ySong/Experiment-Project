#include <stdio.h>
#include <mpi.h>

int main(int argc,char *argv[])
{
    int myid,np,i,j;
    int tag=666;
    double pi=0.0;
    double fVal;
//    int n=1000000;
    int n=10000;
    MPI_Status status;
    double h=(double)1/n;
    double local=0.0;
    double start,end;
    double a;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&np);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    start=MPI_Wtime();
    for(i=myid;i<n;i+=np)
    {
        a=(i+0.5)*h;
        fVal=4.0/(1.0+a*a);
        local+=fVal ;
    }
    local=local*h;
    if(myid!=0)
    {
        MPI_Send(&local,1,MPI_DOUBLE,0,myid,MPI_COMM_WORLD);
    }
    if(myid==0)
    {
        pi=local;
        for(j=1;j<np;j++)
        {
            MPI_Recv(&local,1,MPI_DOUBLE,j,j,MPI_COMM_WORLD,&status);
            pi+=local;
        }
    }
    end=MPI_Wtime();
    if(myid==0)
    {
        printf("PI = %.15f\n",pi);
        printf("Time = %lf\n",end-start);
        printf("np = %d\n",np);
    }
    MPI_Finalize();
    return 0;
}