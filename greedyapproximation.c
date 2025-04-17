#include<stdio.h>
#define MAX_ITEMS 100
double computeMaxValue(double W,double weight[],double value[],double ratio[],int nitems);
int getnextitem(double weight[],double value[],double ratio[],int nitems);
int main(){
int nitems;
double W;
double weight[MAX_ITEMS];
double value[MAX_ITEMS];
double ratio[MAX_ITEMS];
printf("enter the number of items:\n");
scanf("%d",&nitems);
printf("enter the weights of items:\n");
for(int i=0;i<nitems;i++){
scanf("%lf",&weight[i]);
}
printf("enter the values/profits of the items:\n");
for(int i=0;i<nitems;i++){
scanf("%lf",&value[i]);
}
for(int i=0;i<nitems;i++){
ratio[i]=value[i]/weight[i];
}
printf("enter the capacity of the knapsack:\n");
scanf("%lf",&W);
printf("\nthe maximum value in a knapsack of capacity %.2f is:%.2f\n",W,computeMaxValue(W,weight,value,ratio,nitems));
return 0;
}
double computeMaxValue(double W,double weight[],double value[],double ratio[],int nitems){
double cw=0;
double cv=0;
printf("\nitems considered are:");
while(cw<W){
int item=getnextitem(weight,value,ratio,nitems);
if(item==-1){
break;
}
printf("%d",item+1);
if(cw+weight[item]<=W){
cw+=weight[item];
cv+=value[item];
ratio[item]=0;
}
else{
cv+=(ratio[item]*(W-cw));
cw+=(W-cw);
break;
}
}
return cv;
}
int getnextitem(double weight[],double value[],double ratio[],int nitems){
double highest=0;
int index=-1;
for(int i=0;i<nitems;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}
}
return index;
}

