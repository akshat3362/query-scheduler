#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void student(int process_number)
{
int k,i,arrival_time[process_number],burst_time[process_number],total,sum=0;
for( i=0;i<process_number;i++)
{
	printf("enter the burst time for the %d query(in minutes)\n",(i+1));
	scanf("%d",&burst_time[i]);
	printf("ENTER THE ARRIVAL TIME IN 24 HOURS FORMAT AND ENTER TIME BETWEEN 10 AND 12 ONLY . EG- FOR 10:00 ENTER 1000\n");
	printf("enter the arrival time for the %d query\n",(i+1));
	scanf("%d",&arrival_time[i]);
	if(arrival_time[i]>=1000 & arrival_time[i]<=1200)
	{
		printf("Thanks for your help , your query will be resolved shortly.\n\n");
	}
	else
	{
		printf("admin not available\n\n");
		arrival_time[i]=0;
		printf("ENTER THE TIME AGAIN\n\n");
		scanf("%d",&arrival_time[i]);
	}
}
printf("-------------------------------------------------------\n");
printf("PROCESS NUMBER \t BURST TIME\t ARRIVING TIME\n");
for(i=0;i<process_number;i++)
{
	printf("%d \t\t %d \t\t %d\n",(i+1),burst_time[i],arrival_time[i]);
}
printf("--------------------------------------------------------\n");
int remaining_time[process_number],quantum,waiting_time,turnaround_time;
printf("enter the quantum time\n");
scanf("%d",&quantum);
printf("-----------------ROUND ROBIN ALGORITHM-------------------------------\n");
int j=0,ttime=0;
printf("\nPROCESS NUMBER \t REMAINING TIME\t TOTAL TIME");
int temp;
temp=arrival_time[0];
while(j<process_number)
{ 
	for(i=0;i<process_number;i++)
 {
 	if(temp>=arrival_time[i])
 	{	 
	if(burst_time[i]>0)
    { 
if(burst_time[i]>=quantum)
    { 
temp+=quantum;
ttime+=quantum;
burst_time[i]=burst_time[i]-quantum;
printf("\n%d\t\t %d \t\t %d",(i+1),burst_time[i],temp);
if(burst_time[i]==0)
j++;
   }
else 
{ 
temp+=burst_time[i];
ttime+=burst_time[i];
burst_time[i]=0;
j++;
printf("\n%d\t\t %d \t\t %d",(i+1),burst_time[i],temp);
}
}
else
{
	if((arrival_time[i+1]-temp)>0)
	{
	printf("\n%d -",temp);
	temp=temp+(arrival_time[i+1]-temp);
	printf("%d no process was running at this time ",temp);
    }
}
}
}
}
printf("\nTotal Time spent on handling queries %d\n",ttime);
float e = process_number;
printf("Average Time spent on handling queries %f\n",(ttime/e));
}
void faculty(int process_number)
{
int i, arrival_time[process_number],burst_time[process_number];
for(i=0;i<process_number;i++)
{
	printf("enter the burst time for the %d query",(i+1));
	scanf("%d",&burst_time[i]);
	printf("enter the arrival time for the %d query\n",(i+1));
	printf("ENTER THE TIME IN 24 HOURS FORMAT. EG- FOR 10:00 ENTER 1000\n");
	scanf("%d",&arrival_time[i]);
	if(arrival_time[i]>=1000 & arrival_time[i]<=1200)
	{
		
	}
	else
	{
		printf("Sorry admin not available\n");
	}
}

	
}
int main_page()
{
	int query_number,process_number;
	printf("KINDLY ENTER A NUMBER:\n");
	printf("1: student query\n");
	printf("2: faculty query\n");
	printf("3: exit\n");
	scanf("%d",&query_number);
	switch(query_number)
	{
		case 1:
			printf("enter the number of process\n");
			scanf("%d",&process_number);
			student(process_number);
			break;
		case 2:
			printf("enter the number of process\n");
			scanf("%d",&process_number);
			faculty(process_number);
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("PLEASE ENTER A VALID NUMBER\n");
			main_page();
			break;
	}
}

int main()
{
main_page();
} 
