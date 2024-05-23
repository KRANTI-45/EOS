#include<stdio.h>
#include<signal.h>
#include<pthread.h>
int arr[10] = {12,23,45,56,78,76,45,23,43,21};
pthread_mutex_t s;
void* selection_sort(void *param)
{
   int *arr;
   int temp = 0;
   arr = (int*)param;
   int array_size = 10;
   int i = 0;
   int j = 0;
   int min_index = 0;
   for(i = 0;i<array_size;i++)
   {
      min_index = i;
      for(j = i+1;j<array_size;j++)
      { 
         if(arr[min_index] > arr[j])
          min_index = j;
      }
      temp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = temp;
   }
}

int main()
{
  int ret = 0;
  pthread_t th;
  ret = pthread_create(&th,NULL,selection_sort,arr);
  if(ret < 0)
  {
      printf("The thread is not created\n");
  }
  pthread_join(th, NULL);
  for(int i = 0;i<10;i++)
  {
     printf("%d ",arr[i]);
  }
  printf("\r\n");
  return 0;
}
