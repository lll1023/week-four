#include <stdio.h>
#include <stdlib.h>
#include "qgsort.h"
#include <time.h>
#include <malloc.h>

void readData(FILE *r,int *temp,int n);
void main(){
	
    int n;

      printf("���ڱȽϲ�ͬ�������ʱ\n");
      printf("........................\n");
     //������Ϊ10000 
      printf("������������Ϊ10000��������ʱ,�����ĵȴ�\n");
      FILE *r1=fopen("d:/try/10000.txt","r");
      FILE *r2=fopen("d:/try/10000.txt","r");
      FILE *r3=fopen("d:/try/10000.txt","r");
      FILE *r4=fopen("d:/try/10000.txt","r");
      FILE *r5=fopen("d:/try/10000.txt","r");
      FILE *r6=fopen("d:/try/10000.txt","r");
      n=10000;
      printTime(r1,r2,r3,r4,r5,r6,n);
  
    //������Ϊ50000    
      printf("������������Ϊ50000��������ʱ�������ĵȴ�\n");
      FILE *r7=fopen("d:/try/50000.txt","r");
      FILE *r8=fopen("d:/try/50000.txt","r");
      FILE *r9=fopen("d:/try/50000.txt","r");
      FILE *r10=fopen("d:/try/50000.txt","r");
      FILE *r11=fopen("d:/try/50000.txt","r");
      FILE *r12=fopen("d:/try/50000.txt","r");
      n=50000;
      printTime(r7,r8,r9,r10,r11,r12,n);
   
    //������Ϊ200000
         printf("������������Ϊ200000��������ʱ�������ĵȴ�\n");
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

	//��ȡ�ļ�
    int*temp=(int*)malloc(sizeof(int)*n);
    double start,finish;
   
    //������ʱ
    //��������
      readData(r1,temp,n);
      start=clock();
      insertSort(temp,n);
      finish=clock();
      printf("����������ʱ:%.2f����\n",(finish-start)/CLOCKS_PER_SEC*1000);

    //�鲢����
    int instance[n];
      readData(r2,temp,n);
      start=clock();
      MergeSort(temp,0,n-1,instance);
      finish=clock();
      printf("�鲢������ʱ:%.2f����\n",(finish-start)/CLOCKS_PER_SEC*1000);

    //�������򣨵ݹ�棩
      readData(r3,temp,n);
      start=clock();
      QuickSort_Recursion(temp,0,n-1);
      finish=clock();
      printf("�������򣨵ݹ�棩��ʱ:%.2f����\n",(finish-start)/CLOCKS_PER_SEC*1000);

    //��������
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
      printf("����������ʱ:%.2f����\n",(finish-start)/CLOCKS_PER_SEC*1000);

    //������������
      readData(r5,temp,n);
      start=clock();
      RadixCountSort(temp,n);
      finish=clock();
      printf("��������������ʱ:%.2f����\n",(finish-start)/CLOCKS_PER_SEC*1000); 

    //���ŷǵݹ������
      readData(r6,temp,n);
      start=clock();
      QuickSort(temp,n);
      finish=clock();
      printf("���ŷǵݹ��������ʱ:%.2f����\n",(finish-start)/CLOCKS_PER_SEC*1000);

      printf(".................................\n");     
      free(temp);
} 
