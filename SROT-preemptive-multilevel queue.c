#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct Queue
{
int pid;
int arrvalTime;
int burstTime;
};
float processFun(struct Queue* q, int size,struct Queue* Que);
void minArrTime(struct Queue* que,int size);
void minBurstTime(struct Queue* que,int size);
int checkAllProFinsh(struct Queue* Que,int size);
float calTotBurstTime(struct Queue* Que,int n)
{
float burstTime=0;
for(int i=0;i<n;i++)
burstTime+=(Que+i)->burstTime;
return burstTime;
}
int main()
{
int i,n1,n2;
float totTurnAroundTime,avgTurnAroundTime,avgWaitingTime,totBurstTime;
printf("\nSHORTEST JOB REMAINING FIRST (WITH PREEMPTIVE and MULTILEVEL QUEUE)\n");
printf("\nNo of Processes in Queue1: ");
scanf("%d",&n1);
struct Queue *q1=(struct Queue*)malloc(n1*sizeof(struct Queue));
struct Queue *Que1=(struct Queue*)malloc(n1*sizeof(struct Queue));
printf("\nEnter the following Details for Processes in Queue1:\n");
for(i=0;i<n1;i++)
{
printf("For Process %d:\n",i+1);
(q1+i)->pid=i+1;
(Que1+i)->pid=i+1;
printf("PId: %d\n", (q1+i)->pid);
printf("Arrival Time: ");
scanf("%d",&(q1+i)->arrvalTime);
(Que1+i)->arrvalTime=(q1+i)->arrvalTime;
printf("Burst Time: ");
scanf("%d",&(q1+i)->burstTime);
(Que1+i)->burstTime=(q1+i)->burstTime;
printf("\n");
}
printf("No of Processes in Queue2: ");
scanf("%d",&n2);
struct Queue *q2=(struct Queue*)malloc(n1*sizeof(struct Queue));
struct Queue *Que2=(struct Queue*)malloc(n1*sizeof(struct Queue));
printf("\nEnter the following Details for Processes in Queue2:\n");
for(i=0;i<n2;i++)
{
printf("For Process %d:\n",i+1);
(q2+i)->pid=i+1;
(Que2+i)->pid=i+1;
printf("PId: %d\n", (q2+i)->pid);
printf("Arrival Time: ");
scanf("%d",&(q2+i)->arrvalTime);
(Que2+i)->arrvalTime=(q2+i)->arrvalTime;
printf("Burst Time: ");
scanf("%d",&(q2+i)->burstTime);
(Que2+i)->burstTime=(q2+i)->burstTime;
printf("\n");
}
printf("\n");
printf("\nDetais Of Processes in Queue1\n");
printf("\n Process: | Arrival Time: | Burst Time: | ");
for(i=0;i<n1;i++)
{
printf("\n P%d %d %d ",(q1+i)->pid,(q1+i)->arrvalTime,(q1+i)->burstTime);
}
printf("\n");
printf("\nDetais Of Processes in Queue2\n");
printf("\n Process: | Arival Time: | Burst Time: | ");
for(i=0;i<n2;i++)
{
printf("\n P%d %d %d ",(q2+i)->pid,(q2+i)->arrvalTime,(q2+i)->burstTime);
}
printf("\n\n");
totTurnAroundTime=processFun(q1,n1,Que1);
avgTurnAroundTime=totTurnAroundTime/n1;
totBurstTime=calTotBurstTime(q1,n1);
avgWaitingTime=(totTurnAroundTime-totBurstTime)/n1;
