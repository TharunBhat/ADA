#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int high)
{
int i=low,j=mid+1,k=low;
int c[1000000];
while(i<=mid && j<=high){
if(a[i]<a[j]){
c[k]=a[i];
i++;
}
else{
c[k]=a[j];
j++;
}
k++;
}
while(i<=mid){
c[k++]=a[i++];
}
while(j<=high){
c[k++]=a[j++];
}
for(i=low;i<=high;i++){
a[i]=c[i];
}
}
void mergeSort(int a[],int low,int high)
{
if(low<high)
{
int mid=(low+high)/2;
mergeSort(a,low,mid);
mergeSort(a,mid+1,high);
merge(a,low,mid,high);
}
}
int main(){
int n,i;
printf("enter the number of elements:");
scanf("%d",&n);
int arr[n];
srand(time(NULL));
for(int i=0;i<n;++i){
arr[i]=rand()%10000;
}
clock_t start=clock();
mergeSort(arr,0,n-1);
clock_t end=clock();
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("sorted array ");
for(int i=0;i<20;++i){
printf("%d\t",arr[i]);
}
printf("\n");
printf("time taken for sorting:%f seconds\n",time_taken);
return 0;
}
