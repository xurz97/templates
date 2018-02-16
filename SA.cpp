#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 1e6+5;
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int rank[maxn],height[maxn],sa[maxn];
char str[maxn];
int cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(char *r,int *sa,int n,int m)
{
	int i,j,p,*x=wa,*y=wb,*t;
	for(i=0; i<m; i++) ws[i]=0;
	for(i=0; i<n; i++) ws[x[i]=r[i]]++;
	for(i=1; i<m; i++) ws[i]+=ws[i-1];
	for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
	for(j=1,p=1; p<n; j*=2,m=p)
	{
		for(p=0,i=n-j; i<n; i++) y[p++]=i;
		for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0; i<n; i++) wv[i]=x[y[i]];
		for(i=0; i<m; i++) ws[i]=0;
		for(i=0; i<n; i++) ws[wv[i]]++;
		for(i=1; i<m; i++) ws[i]+=ws[i-1];
		for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
void calheight(char *r,int *sa,int n)
{
	int i,j,k=0;
	for(i=1; i<=n; i++) rank[sa[i]]=i;
	for(i=0; i<n; height[rank[i++]]=k)
		for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
}
int main()
{
	scanf("%s",str);
	int len = strlen(str);
	str[len]=0;
	da(str,sa,len+1,128);
	calheight(str,sa,len);
	for(int i=1;i<=len;i++)
	{
		printf("%s\n",str+sa[i]);	
	}
	for(int i=1;i<=len;i++)
	{
		printf("%d ",sa[i]);
	}
	printf("\n");
	for(int i=0;i<len;i++)
	{
		printf("%d ",rank[i]);
	}
	printf("\n");
	for(int i=1;i<=len;i++)
	{
		printf("%d ",height[i]);
	}
	printf("\n");
	return 0;
}