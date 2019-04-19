struct Q
{
int ad;
int bTime;
int arvalTime;
};
float processFun(struct Q* q, int size,struct Q* Que);
void minArrTime(struct Q* que,int size);
void minbTime(struct Q* que,int size);
int checkAllProFinish(struct Q* Que,int size);
float calTotbTime(struct Q* Que,int n)
{
float bTime=0;
for(int i=0;i<n;i++)
bTime+=(Que+i)->bTime;
return bTime;
}
int main()
{
int i,a1,a2;
float totalTurnAroundTime, averageTurnAroundTime, averageWaitTime, totalbTime;
printf("\nShortest Job Remaining First (With Preemptive and Multilevel Queue)\n");
printf("\nNo of Processes in Queue1: ");
scanf("%d",&a1);
struct Q *q1=(struct Q*)malloc(a1*sizeof(struct Q));
struct Q *Que1=(struct Q*)malloc(a1*sizeof(struct Q));
printf("\nEnter the following Details for Processes in Queue1:\n");
for(i=0;i<a1;i++)
{
printf("For Process %d:\n",i+1);
(q1+i)->ad=i+1;
(Que1+i)->ad=i+1;
printf("ad: %d\n", (q1+i)->ad);
printf("Arrival Time: ");
scanf("%d",&(q1+i)->arvalTime);
(Que1+i)->arvalTime=(q1+i)->arvalTime;
printf("Burst Time: ");
scanf("%d",&(q1+i)->bTime);
(Que1+i)->bTime=(q1+i)->bTime;
printf("\n");
}
printf("No of Processes in Queue2: ");
scanf("%d",&n2);
struct Q *q2=(struct Q*)malloc(a1*sizeof(struct Q));
struct Q *Que2=(struct Q*)malloc(a1*sizeof(struct Q));
printf("\nEnter the following Details for Processes in Queue2:\n");
for(i=0;i<n2;i++)
{
printf("For Process %d:\n",i+1);
(q2+i)->ad=i+1;
(Que2+i)->ad=i+1;
printf("ad: %d\n", (q2+i)->ad);
printf("Arrival Time: ");
scanf("%d",&(q2+i)->arvalTime);
(Que2+i)->arvalTime=(q2+i)->arvalTime;
printf("Burst Time: ");
scanf("%d",&(q2+i)->bTime);
(Que2+i)->bTime=(q2+i)->bTime;
printf("\n");
}
printf("\n");
printf("\nFor -> Details Of Processes in Queue1\n");
printf("\n Process: || Arrival Time: || Burst Time: || ");
for(i=0;i<a1;i++)
{
printf("\n P%d %d %d ",(q1+i)->ad,(q1+i)->arvalTime,(q1+i)->bTime);
}
printf("\n");
printf("\nFor -> Details Of Processes in Queue2\n");
printf("\n Process: || Arrival Time: || Burst Time: || ");
for(i=0;i<n2;i++)
{
printf("\n P%d %d %d ",(q2+i)->ad,(q2+i)->arvalTime,(q2+i)->bTime);
}
printf("\n\n");
totalTurnAroundTime=processFun(q1,a1,Que1);
averageTurnAroundTime=totalTurnAroundTime/a1;
totalbTime=caltotalbTime(q1,a1);
averageWaitTime=(totalTurnAroundTime-totalbTime)/a1;
printf("\nFor Queue1");
printf("\nAverage Turn Around Time: %.2f\n", averageTurnAroundTime);
printf("\nAverage Waiting Time: %.2f\n",averageWaitTime);
printf("\n\n");
totalTurnAroundTime=processFun(q2,a2,Que2);
averageTurnAroundTime=totalTurnAroundTime/a2;
totalbTime=caltotalbTime(q2,a2);
averageWaitTime=(totalTurnAroundTime-totalbTime)/a2;
printf("\nFor Queue2");
printf("\nAverage Turn Around Time: %.2f\n", averageTurnAroundTime);
printf("\nAverage Waiting Time: %.2f\n",averageWaitTime);
printf("\n\n");
return 0;
}
float processFun(struct Q* q, int size,struct Q* Que)
{
int timeCounter=0,flg=0;
float at=0,wat=0;
while(!checkAllProFinish(Que,size))
{
if(flg==0)
{
minArrTime(Que,size);
timeCounter+=Que->arvalTime;
flg++;
}
else
{
minbTime(Que,size);
}
int chk=0;
for(int i=0;i<size;i++)
{
if((Que+i)->bTime!=0 && timeCounter>=(Que+i)->arvalTime)
{
chk=1;
break;
}
}
if(chk==0)
{
minArrTime(Que,size);
for(int i=0;i<size;i++)
{
if((Que+i)->bTime!=0)
{
int x=timeCounter;
timeCounter+=((Que+i)->arvalTime)-x;
break;
}
}
}
for(int i=0;i<size;i++)
{
if((Que+i)->bTime!=0 && timeCounter>=(Que+i)->arvalTime)
{
if((Que+i)->bTime>2)
{
(Que+i)->bTime=(Que+i)->bTime-2;
timeCounter+=2;
}
else
{
timeCounter+=(Que+i)->bTime;
(Que+i)->bTime=0;
int x=timeCounter;
at+=x-((Que+i)->arvalTime);
}
break; 
}
}
}
return at;
}
