#include<conio.h>
#include<stdio.h>

void findWaitingtime();
void findTurnAroundTime();
void findCompleteTime();
void findPriority();

void findWaitingtime(int processes[], int n, int bt[], int wt[],int tat[])
{
	int i;
	for(i=0; i<n; i++)
	{
		wt[i]= tat[i]-bt[i];
	}
}

void findTurnAroundTime(int processes[], int n, int ct[], int tat[], int at[])
{
	int i;
	for(i=0; i<n; i++)
	{
		tat[i]= ct[i]- at[i];
	}
}

void findCompleteTime(int processes[], int n, int at[], int bt[], int ct[])
{
	int pos, i,j,K=1;
	for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
		}
		ct[i]=K+bt[pos];
		K=ct[i];
	}
}

void findPriority(int processes[], int wt[], int tat[], int p[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		p[i]=(wt[i]/tat[i])+1;
	}
}

void findavgTime(int processes[], int n, int bt[], int at[])
{
	int z,i;
	int wt[n], tat[n], ct[n], p[n];
	findCompleteTime(processes, n, at, bt, ct);
	findTurnAroundTime(processes, n, ct, tat, at);
	findWaitingtime(processes, n, bt, wt, tat);
	findPriority(processes, wt, tat, p, n);
	printf("Processes	Brust Time	Arrival Time	Waiting Time	Turn Around Time    Completion Time	    Priority\n");
	int total_wt=0,total_tat=0;
	for(i=0; i<n; i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		int compl_time=tat[i]+at[i];
		z=i+1;
		printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t\t %d\n",z,bt[i],at[i],wt[i], tat[i], ct[i], p[i]);
	}
	printf("Average waiting Time= %d ",(float)total_wt/(float)n);
	printf("Average Turn Around Time= %d",(float)total_tat/(float)n);
}

int main()
{
	int n;
	int i;
	int processes[n];
	int at[n];
	int bt[n];
	printf("Enter the quantity of Processes: ");
	scanf("%d",&n);
	printf("Enter the elements of Processes.\n");
	for(i=0; i<n; i++)
	{
		printf("Enter Arrival Time or AT for %d : ",(i+1));
		scanf("%d",&at[i]);
		printf("Enter Brust Time or BT for %d : ",(i+1));
		scanf("%d",&bt[i]);
	}
	findavgTime(processes, n, bt, at);
	return 0;
}
