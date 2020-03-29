#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct os
{
	int sum,student_arrival_time[100],student_burst_time[100],sum1,faculty_arrival_time[100],faculty_burst_time[100];
}q;
void student()
{
int k,i,total;
for(i=0;i<q.sum;i++)
{
	printf("enter the burst time for the student %d query(in minutes)\n",(i+1));
	scanf("%d",&q.student_burst_time[i]);
	printf("ENTER THE ARRIVAL TIME IN 24 HOURS FORMAT AND ENTER TIME BETWEEN 10 AND 12 ONLY . EG- FOR 10:00 ENTER 1000\n");
	printf("enter the arrival time for the student %d query\n",(i+1));
	scanf("%d",&q.student_arrival_time[i]);
	if(q.student_arrival_time[i]>=1000 & q.student_arrival_time[i]<=1200)
	{
		printf("Thanks for your help , your query will be resolved shortly.\n\n");
	}
	else
	{
		printf("admin not available\n\n");
		q.student_arrival_time[i]=0;
		printf("ENTER THE TIME AGAIN\n\n");
		scanf("%d",&q.student_arrival_time[i]);
	}
}
}
void faculty()
{
int j,i;
for(j=0;j<q.sum1;j++)
{
	printf("enter the burst time for the  faculty %d query",(j+1));
	scanf("%d",&q.faculty_burst_time[j]);
	printf("enter the arrival time for the  faculty %d query\n",(j+1));
	printf("ENTER THE TIME IN 24 HOURS FORMAT. EG- FOR 10:00 ENTER 1000\n");
	scanf("%d",&q.faculty_arrival_time[j]);
	if(q.faculty_arrival_time[j]>=1000 & q.faculty_arrival_time[j]<=1200)
	{
		printf("Thanks for your help , your query will be resolved shortly.\n\n");
	}
	else
	{
		printf("admin not available\n\n");
		q.faculty_arrival_time[j]=0;
		printf("ENTER THE TIME AGAIN\n\n");
		scanf("%d",&q.faculty_arrival_time[j]);
	}	
}

}
void schedule()
{
	int temp,ttime=0;
if(q.faculty_arrival_time[0]!=0 & q.student_arrival_time[0]!=0)
{	
if(q.student_arrival_time[0]<q.faculty_arrival_time[0])
{
temp=q.student_arrival_time[0];	
}
else if(q.student_arrival_time[0]>q.faculty_arrival_time[0])
{
	temp=q.faculty_arrival_time[0];
}
else
{
	temp=q.student_arrival_time[0];
}
}
else
{
	if(q.faculty_arrival_time[0]>q.student_arrival_time[0])
	{
		temp=q.faculty_arrival_time[0];
	
	}
	else
	{
		temp=q.student_arrival_time[0];
	
	}
}
int j=0,k=0,i=0,quantum;
printf("\nenter the quantum\n");
scanf("%d",&quantum);
printf("\nPROCESS NUMBER \t REMAINING TIME\t \tTIME");
while(k<(q.sum+q.sum1))
{
for(j=0;j<q.sum1;j++)
{
if(temp>=q.faculty_arrival_time[j])
{
	{	 
	if(q.faculty_burst_time[j]>0)
    { 
if(q.faculty_burst_time[j]>=quantum)
    {
	printf("\n\t\t\t\t\t%d-",temp); 
temp+=quantum;
ttime+=quantum;
q.faculty_burst_time[j]=q.faculty_burst_time[j]-quantum;
printf("\nfaculty\t%d\t\t %d \t\t %d",(j+1),q.faculty_burst_time[j],temp);
if(q.faculty_burst_time[j]==0)
k++;
   }
else 
{ 
printf("\n\t\t\t\t\t%d-",temp); 
temp+=q.faculty_burst_time[j];
ttime+=q.faculty_burst_time[j];
q.faculty_burst_time[j]=0;
k++;
printf("\nfaculty\t%d\t\t %d \t\t %d",(j+1),q.faculty_burst_time[j],temp);
}
}
}
}
}
for(i=0;i<q.sum;i++)
{
if(temp>=q.student_arrival_time[i])
{
	{	 
	if(q.student_burst_time[i]>0)
    { 
if(q.student_burst_time[i]>=quantum)
    { 
    printf("\n\t\t\t\t\t%d-",temp); 
temp+=quantum;
ttime+=quantum;
q.student_burst_time[i]=q.student_burst_time[i]-quantum;
printf("\nstudent\t%d\t\t %d \t\t %d",(i+1),q.student_burst_time[i],temp);
if(q.student_burst_time[i]==0)
k++;
   }
else 
{ 
printf("\n\t\t\t\t\t%d-",temp); 
temp+=q.student_burst_time[i];
ttime+=q.student_burst_time[i];
q.student_burst_time[i]=0;
k++;
printf("\nstudent\t%d\t\t %d \t\t %d",(i+1),q.student_burst_time[i],temp);
}
}
else
{
	if((q.student_arrival_time[i+1]-temp)>0)
	{
	printf("\n%d -",temp);
	temp=temp+(q.student_arrival_time[i+1]-temp);
	printf("%d no process was running at this time ",temp);
    }
}
}
}
}
}
printf("\nTotal Time spent on handling queries %d\n",ttime);
float e = (q.sum+q.sum1);
printf("Average Time spent on handling queries %f\n",(ttime/e));
}
int main_page()
{
	int i,process_number;
	q.sum=0,q.sum1=0;
	printf("enter the number of processes");
	scanf("%d",&process_number);
	int query_number[process_number];
	for(i=0;i<process_number;i++)
	{
	 printf("KINDLY ENTER A NUMBER:\n");
	printf("1: student query\n");
	printf("2: faculty query\n");
	printf("3: exit\n");
	scanf("%d",&query_number[i]);
}
	for(i=0;i<process_number;i++)
	{
	if(query_number[i]==1)
	{
		q.sum=q.sum+1;
	}
	else if(query_number[i]==2)
	{
		q.sum1=q.sum1+1;
	}
}
	
}



int main()
{
main_page();
student();
faculty();
schedule();
} 
