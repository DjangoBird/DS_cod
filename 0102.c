#include <stdio.h>
#define MAXLINE 100000
int main (){
int k,m;
scanf("%d %d",&k,&m);
int s[MAXLINE];
int i=0;
for (i=0;i<k-1;i++){
s[i]=0;
}
s[k-1]=1;
for (i=k;i<m+1;i++){
	int j=0;
	for(j=1;j<k+1;j++)
	s[i]+=s[i-j];
}
printf("%d\n",s[m]);
return 0;
}


