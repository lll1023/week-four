#include <stdio.h>
#include <stdlib.h>
#include "qgsort.h"
#include <time.h>
#include <malloc.h>

void readData(FILE *r,int *temp,int n);
void main(){
	
    int n;

      printf("正在比较不同排序的用时\n");
      printf("........................\n");
     //数据量为10000 
      printf("下面是数据量为10000的排序用时,请耐心等待\n");
      FILE *r1=fopen("d:/try/10000.txt","r");
      FILE *r2=fopen("d:/try/10000.txt","r");
      FILE *r3=fopen("d:/try/10000.txt","r");
      FILE *r4=fopen("d:/try/10000.txt","r");
      FILE *r5=fopen("d:/try/10000.txt","r");
      FILE *r6=fopen("d:/try/10000.txt","r");
      n=10000;
      printTime(r1,r2,r3,r4,r5,r6,n);
  
    //数据量为50000    
      printf("下面是数据量为50000的排序用时，请耐心等待\n");
      FILE *r7=fopen("d:/try/50000.txt","r");
      FILE *r8=fopen("d:/try/50000.txt","r");
      FILE *r9=fopen("d:/try/50000.txt","r");
      FILE *r10=fopen("d:/try/50000.txt","r");
      FILE *r11=fopen("d:/try/50000.txt","r");
      FILE *r12=fopen("d:/try/50000.txt","r");
      n=50000;
      printTime(r7,r8,r9,r10,r11,r12,n);
   
    //数据量为200000
         printf("下面是数据量为200000的排序用时，请耐心等待\n");
      FILE *r13=fopen("d:/try/200000.txt","r");
      FILE *r14=fopen("d:/try/200000.txt","r");
      FILE *r15=fopen("d:/try/200000.txt","r");
      FILE *r16=fopen("d:/try/200000.txt","r");
      FILE *r17=fopen("d:/try/200000.txt","r");
      FILE *r18=fopen("d:/try/200000.txt","r");
      n=200000;
      printTime(r13,r14,r15,r16,r17,r18,n);
}

void readData(FILE *r,int *temp,int n){
    int i;
    for(i=0;i<n;i++){
        	fscanf(r,"%d",&temp[i]);	
    }
}

void printTime(FILE *r1,FILE *r2,FILE *r3,FILE *r4,FILE *r5,FILE *r6,int n){

	//读取文件
    int*temp=(int*)malloc(sizeof(int)*n);
    double start,finish;
   
    //计算用时
    //插入排序
      readData(r1,temp,n);
      start=clock();
      insertSort(temp,n);
      finish=clock();
      printf("插入排序用时:%.2f毫秒\n",(finish-start)/CLOCKS_PER_SEC*1000);

    //归并排序
    int instance[n];
      readData(r2,temp,n);
      start=clock();
      MergeSort(temp,0,n-1,instance);
      finish=clock();
      printf("归并排序用时:%.2f毫秒\n",(finish-start)/CLOCKS_PER_SEC*1000);

    //快速排序（递归版）
      readData(r3,temp,n);
      start=clock();
      QuickSort_Recursion(temp,0,n-1);
      finish=clock();
      printf("快速排序（递归版）用时:%.2f毫秒\n",(finish-start)/CLOCKS_PER_SEC*1000);

    //计数排序
      readData(r4,temp,n);
//temp[0]=3;temp[1]=4;temp[2]=56;temp[3]=100;temp[4]=786;temp[5]=1456;temp[6]=78;
    int max=temp[0];
    int i; 
//srand( (unsigned)time( NULL ) );
//for(i=0;i<100;i++){
//	temp[i]=rand();
//}
    for(i=0;i<n;i++){
	    if(max<temp[i]){
	              max=temp[i];
        }
    }
      start=clock();
      CountSort(temp,n,max);
      finish=clock();
      printf("计数排序用时:%.2f毫秒\n",(finish-start)/CLOCKS_PER_SEC*1000);

    //基数计数排序
      readData(r5,temp,n);
      start=clock();
      RadixCountSort(temp,n);
      finish=clock();
      printf("基数计数排序用时:%.2f毫秒\n",(finish-start)/CLOCKS_PER_SEC*1000); 

    //快排非递归版排序
      readData(r6,temp,n);
      start=clock();
      QuickSort(temp,n);
      finish=clock();
      printf("快排非递归版排序用时:%.2f毫秒\n",(finish-start)/CLOCKS_PER_SEC*1000);

      printf(".................................\n");     
      free(temp);
} 
