#include <stdio.h>

int main(int argc , char *argv[])
{
  int array[] = {5,2,7,3,1,6,9,8,0};
  int len = sizeof(array)/sizeof(int);
  printf("Old Array order:\n");
  showSortArray(array,len);
  /**********1*************
  bubble_sort(array,len);
  jiwei_sort(array,len);
  SelectSort(array,len);
  InsertSort(array,len);
  Partition(array,0,len-1);
  ************************/
  ShellSort(array,len);
  showSortArray(array,len);
  
  printf("\nSort end ......\n");
}

void swap(int array[],int i,int j)
{
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void showSortArray(int array[],int len)
{
  int i=0;
  for(i=0;i<len;i++)
  {
    printf("%d ",array[i]);
  }
}

void bubble_sort(int array[],int len)
{
  printf("\nBubble Sort Start.....\n");
  int i,j=0;
  int logol = 1;
  for(i=0;i<len-1;i++)
  {
    logol = 0;
    for(j=0;j<len-i-1;j++)
    {
      if(array[j]>array[j+1])
      {
        logol = 1;
        swap(array,j,j+1);
      }
    }
    if(logol == 0)
    {
      break;
    }
  }
}

void jiwei_sort(int array[],int len)
{
  printf("\nJiwei Sort Start.....\n");
  int left  = 0;
  int right = len-1;
  int i,j=0;
  int logol = 1;
  while(left<right && logol)
  {
    logol = 0;
    for(i=left;i<right;i++)
    {
      if(array[i] > array[i+1])
      {
        logol = 1;
        swap(array,i,i+1);
      }
    }
    right--;
    for(j=right;j>left;j--)
    {
      if(array[j]<array[j-1])
      {
        logol = 1;
        swap(array,j,j-1);
      }
    }
    left++;
  }
}


void SelectSort(int array[],int len)
{
  printf("\nSelect Sort Start.....\n");
  int i,j,min=0;
  for(i=0;i<len-1;i++)
  {
    min = i;
    for(j=i+1;j<len;j++)
    {
      if(array[j]<array[min])
      {
        min = j;
      }
    }
    if(min!=i)
    {
      swap(array,min,i);
    }
  }
}

void InsertSort(int array[],int len)
{
  printf("\nInsert Sort Start.....\n");
  int i,j,get=0;
  for(i=1;i<len;i++)
  {
    get = array[i];
    j = i-1;
    while(j>=0 && array[j]>get)
    {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = get;
  }
}

void Partition(int array[],int start,int end)
{
  printf("\nQuick Sort Start.....\n");
  int low = start;
  int high = end;
  int target = array[low];
  if(low>=high)
  {
    return;
  }
  else
  {
    while(low < high)
    {
      while(low<high && array[high]>target)
      {
        high--;
      }
      array[low] = array[high];
      while(low<high && array[low]<target)
      {
        low++;
      }
      array[high] = array[low];
    }
    array[low] = target;
  }
  showSortArray(array,end);
  Partition(array,start,low-1);
  Partition(array,low+1,end);
}

void ShellSort(int array[],int len)
{
  printf("\nShell Sort Start.....\n");
  int d = (len+1)/2;
  int i = 0;
  while(d)
  {
    for(i=0;i+d<len;i++)
    {
      if(array[i]>array[i+d])
      {
        swap(array,i,i+d);
      }
    }
    d--;
  }
}
