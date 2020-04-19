#include <stdio.h>
#include "qgsort.h"
#include "LinkStack.h"
#include <malloc.h>
#include <stdlib.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n){
	if(a==NULL||n==0||n==1){
	    return ;
    }
    int   i,j,now;
    for(i=1;i<n;i++){
	        now=a[i];
        for(j=i;j>0;j--){
	        if(now<a[j-1]){
	                    a[j]=a[j-1];
            }else{
                break;        
            }
        }
            a[j]=now;
    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	if(a==NULL||temp==NULL){
	    return;
    }
    int  i=begin,j=mid+1,k=0;
    while(i<=mid&&j<=end){
	    if(a[i]<a[j]){
	              temp[k++]=a[i++];
        }else{
	              temp[k++]=a[j++];
        }
    }
    while(i<=mid){
	        temp[k++]=a[i++];
    }
    while(j<=end){
	        temp[k++]=a[j++];
    }
    for(i=0;i<k;i++){
	        a[begin+i]=temp[i];
    }
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
	if(begin<end){
	    int mid=(begin+end)/2;
           MergeSort(a,begin,mid,temp);
           MergeSort(a,mid+1,end,temp);
           MergeArray(a,begin,mid,end,temp);
    }
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end){
	if(end<begin){
	    return;
    }
    int i=begin,j=end;
    int temp=a[begin];
    while(i<j){
	    while(i<j&&a[j]>=temp){
	              j--;
        }
        while(i<j&&a[i]<=temp){
	              i++;
        }
        if(i<j){
	        int instance=a[i];
                  a[i]=a[j];
                  a[j]=instance;
        }
    }
      a[begin]=a[i];
      a[i]=temp;
      QuickSort_Recursion(a,begin,i-1);
      QuickSort_Recursion(a,i+1,end);
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size){
    	LinkStack s;
      initLStack(&s);
    int high=0,low=0;
    int mid=Partition(a,0,size-1);
    if(0<mid-1){
	        pushLStack(&s,0);
            pushLStack(&s,mid-1);
    }
    if(mid+1<size-1){
	        pushLStack(&s,mid+1);
            pushLStack(&s,size-1);
    }

    while(!isEmptyLStack(&s)){
            popLStack(&s,&high);
            popLStack(&s,&low);
            mid=Partition(a,low,high);
        if(low<mid-1){
	              pushLStack(&s,low);
                  pushLStack(&s,mid-1);
        }
        if(high>mid+1){
	              pushLStack(&s,mid+1);
                  pushLStack(&s,high);
        }
    }
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end){
	int temp=a[begin];
    while(begin<end){
        while(begin<end&&a[end]>=temp){
	              end--;
        }
            a[begin]=a[end];
        while(begin<end&&a[begin]<=temp){
	              begin++;
        }
            a[end]=a[begin];	
    }
      a[begin]=temp;
    return begin;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max){
	int min=a[0];
    int  i,j,num;

    //�ҳ���Сֵ 
    for(i=0;i<size;i++){
	    if(min>a[i]){
	              min=a[i];
        }
    }

    int *index=(int*)malloc(sizeof(int)*(max-min+1));
    if(index==NULL){
        	printf("ָ�봴��ʧ��\n");
    }
    int *temp=(int*)malloc(sizeof(int)*size);
    for(i=min;i<=max;i++){
	        num=0;
        for(j=0;j<size;j++){
	        if(a[j]<=i){
	                    num++;
            }
        }
            index[i-min]=num;
    }
    for(i=size-1;i>=0;i--){
	   int current=a[i]-min;
           index[current]=index[current]-1;
           j=index[current];
           temp[j]=a[i];
    }
    for(i=0;i<size;i++){
	        a[i]=temp[i];
    }    
      free(index);
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size){
	int max=a[0],count=0,temp[size];
    int i,j,cur,num,index[10]; 

    //�ҳ����ֵ 
    for(i=0;i<size;i++){
	    if(max<a[i]){
	              max=a[i];
        }
    }
   
    //��������ֵ��λ��
    while(max){
	        max=max/10;
            count++;
    }
    
    for(i=1;i<=count;i++){
	
        //���������
            clearForZero(index,10);        
 
        //�ҳ����ڸ�����ֵ�ĸ��� 
	    for(j=0;j<size;j++){
	              cur=getIndex(a[j],i);
                  index[cur]++;
        }

        //�����С�ڻ���ڸ�����ֵ�ĸ��� 
        for(j=1;j<10;j++){
	              index[j]+=index[j-1];
        }
        
        //�������� 
        for(j=size-1;j>=0;j--){
	              cur=getIndex(a[j],i);
                  num=index[cur];
                  index[cur]=num-1;
                  temp[num-1]=a[j];
        }
        for(j=0;j<size;j++){
	              a[j]=temp[j];
        }
    }
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size){
	int *p1=&a[0],*p2=&a[size-1],*p=&a[0];
    int temp;
    while(p2>=p){
	    //������β�ַ�Ϊ0��2 
        while(p1==p&&*p==0){
	              p1++;
                  p++;
        }
        while(*p2==2){
	              p2--;
        }

	    if(*p==2){
	              temp=*p2;
            *p2=*p;
            *p=temp;
                  p2--;
        }else if(*p==0){
	              temp=*p1;
            *p1=*p;
            *p=temp;
                  p1++;
        }else if(*p==1){
	              p++;
        }
    }
}


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
void getNumberK(int *a,int size,int k,int *big,int *small){
	if(k>size){
	        printf("���鳤��Ϊ%d\n",size);
        return;
    }
      insertSort(a,size);
    *big=a[size-k];  
    *small=a[k-1];
}


int getIndex(int num,int order){
	int k=1,i=1,index;
    for(i=1;i<=order;i++){
	        index=(num/k)%10;
            k*=10;
    }
    return index;
}

void clearForZero(int* index,int length){
	int i;
    for(i=0;i<length;i++){
	        index[i]=0;
    }
}
