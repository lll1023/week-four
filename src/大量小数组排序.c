#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "qgsort.h"
#include <time.h>

void CopyArray(int*temp);
int main(){
	

      printf("正在计算排序的用时，请耐心等待......\n");
	  srand( (unsigned)time( NULL ) ); 
    int i,j;
    int temp[100];
    double start_time,finish_time,total_time=0;

    //插入排序
      printf(".....................\n");
    for(i=0;i<100*1000;i++){
	    for(j=0;j<100;j++){
	              temp[j]=rand();
        }
            start_time=clock();
            insertSort(temp,100);
            finish_time=clock();
            total_time+=finish_time-start_time;
    } 
      printf("插入排序用时:%.2f毫秒\n",(total_time)/CLOCKS_PER_SEC*1000);

    //归并排序
      printf(".....................\n");
    int instance[100];
    for(i=0;i<100*1000;i++){
	    for(j=0;j<100;j++){
	              temp[j]=rand();
        }
            start_time=clock();
            MergeSort(temp,0,99,instance);
            finish_time=clock();
            total_time+=finish_time-start_time;
    } 
      printf("归并排序用时:%.2f毫秒\n",(total_time)/CLOCKS_PER_SEC*1000);

    //快速排序（递归版） 
	  printf(".....................\n");
    for(i=0;i<100*1000;i++){
	    for(j=0;j<100;j++){
	              temp[j]=rand();
        }
            start_time=clock();
            QuickSort_Recursion(temp,0,99);
            finish_time=clock();
            total_time+=finish_time-start_time;
    } 
      printf("快速排序（递归版）用时:%.2f毫秒\n",(total_time)/CLOCKS_PER_SEC*1000);
  
    //计数排序 
	  printf(".....................\n");
    int max;
    for(i=0;i<100*1000;i++){
	    for(j=0;j<100;j++){
	              temp[j]=rand();
        }
            max=temp[0];
        for(j=0;j<100;j++){
	        if(max<temp[j]){
	                    max=temp[j];
            }
        }
            start_time=clock();
            CountSort(temp,100,max);
            finish_time=clock();
            total_time+=finish_time-start_time;
    } 
      printf("计数排序用时:%.2f毫秒\n",(total_time)/CLOCKS_PER_SEC*1000);    


    //基数计数排序 
	  printf(".....................\n");
    for(i=0;i<100*1000;i++){
	    for(j=0;j<100;j++){
	              temp[j]=rand();
        }
            start_time=clock();
            RadixCountSort(temp,100);
            finish_time=clock();
            total_time+=finish_time-start_time;
    } 
      printf("基数计数排序用时:%.2f毫秒\n",(total_time)/CLOCKS_PER_SEC*1000);

    //快排非递归版 
	  printf(".....................\n");
    for(i=0;i<100*1000;i++){
	    for(j=0;j<100;j++){
	              temp[j]=rand();
        }
            start_time=clock();
            QuickSort(temp,100);
            finish_time=clock();
            total_time+=finish_time-start_time;
    } 
      printf("快速排序（非递归版）用时:%.2f毫秒\n",(total_time)/CLOCKS_PER_SEC*1000);
}
    



