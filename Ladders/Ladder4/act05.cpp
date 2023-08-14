
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1002;

int trainA[MAXN],trainB[MAXN],trainC[MAXN<<1];
int mat[MAXN][MAXN];
int n1, n2;
bool flag;

void dfs(int lena,int lenb,int lenc) {

    if(lena==n1+1&&lenb==n2+1){
        flag=1;
        return;
    }

   if(mat[lena][lenb]) return;

   if(!flag&&trainA[lena]==trainC[lenc]){
        mat[lena][lenb]=1;
        dfs(lena+1,lenb,lenc+1);
   }

   if(!flag&&trainB[lenb]==trainC[lenc]){
       mat[lena][lenb]=1;
      dfs(lena,lenb+1,lenc+1);
   }
}
void input(int n,int a[])
{
    for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
}
int main()
{
    while(scanf("%d%d",&n1,&n2)&&n1+n2!=0)
    {
        input(n1,trainA);
        trainA[n1+1]=-1;
        input(n2,trainB);
        trainB[n2+1]=-1;
        input(n1+n2,trainC);
        flag=0;
        memset(mat,0,sizeof(mat));
        dfs(1,1,1);
        if(flag)printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}