/*Design a scheduling program that is capable of scheduling many processes that comes in at
some time interval and are allocated the CPU not more that 10 time units. CPU must schedule
processes having short execution time first. CPU is idle for 3 time units and does not entertain
any process prior this time. Scheduler must maintains a queue that keeps the order of execution
of all the processes. Compute average waiting and turnaround time.*/


#include<stdio.h> 
#include<unistd.h>
 
int main() 
{ 
 
  int count,j,n,t1,remain,flag=0,tq; 
  int waittime=0,turnaroundtime=0,a[15],b[15],r[20]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival and Brust Time %d :",count+1); 
    scanf("%d",&a[count]); 
    scanf("%d",&b[count]); 
    r[count]=b[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&tq); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(t1=0,count=0;remain!=0;) 
  { 
    if(r[count]<=tq && r[count]>0) 
    { 
      t1+=r[count]; 
      r[count]=0; 
      flag=1; 
    } 
    else if(r[count]>0) 
    { 
      r[count]-=tq; 
      t1+=tq; 
    } 
    if(r[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,t1-a[count],t1-a[count]-b[count]); 
      waittime+=t1-a[count]-b[count]; 
      turnaroundtime+=t1-a[count]; 
      flag=0; 
    } 
    sleep(3);
    
    if(count==n-1) 
      count=0; 
    else if(a[count+1]<=t1) 
      count++; 
    else 
      {
	  count=0;
	  } 
  } 
  
  printf("\nAverage Waiting Time= %f\n",waittime*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaroundtime*1.0/n); 
  
  return 0; 
}
