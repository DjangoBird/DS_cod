#include <stdio.h>
int main(){
int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  int temp=0;
  if(b>a){
    temp=a;
  	a=b;
    b=temp;
  }
  if(c>a){
  	temp=a;
    a=c;
    c=temp;
  }
  if(c>b){
  	temp=b;
    b=c;
    c=temp;
  }
  printf("%d %d %d\n",a,b,c);
  return 0;
}
