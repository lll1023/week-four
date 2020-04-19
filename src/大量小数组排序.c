#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "qgsort.h"
#include <time.h>

void CopyArray(int*temp);
int main(){
	

      printf("���ڼ����������ʱ�������ĵȴ�......\n");
	  srand( (unsigned)time( NULL ) ); 
    int i,j;
    int temp[100];
    double start_time,finish_time,total_time=0;

    //��������
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
      printf("����������ʱ:%.2f����\n",(total_time)/CLOCKS_PER_SEC*1000);

    //�鲢����
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
      printf("�鲢������ʱ:%.2f����\n",(total_time)/CLOCKS_PER_SEC*1000);

    //�������򣨵ݹ�棩 
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
      printf("�������򣨵ݹ�棩��ʱ:%.2f����\n",(total_time)/CLOCKS_PER_SEC*1000);
  
    //�������� 
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
      printf("����������ʱ:%.2f����\n",(total_time)/CLOCKS_PER_SEC*1000);    


    //������������ 
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
      printf("��������������ʱ:%.2f����\n",(total_time)/CLOCKS_PER_SEC*1000);

    //���ŷǵݹ�� 
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
      printf("�������򣨷ǵݹ�棩��ʱ:%.2f����\n",(total_time)/CLOCKS_PER_SEC*1000);
}
    



