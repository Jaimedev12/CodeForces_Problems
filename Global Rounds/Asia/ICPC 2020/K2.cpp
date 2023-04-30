#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct node{
	char op;
	int  s;
}a[100050];

int cmp(node a,node b){
	if(a.s == b.s){
		return a.op < b.op;
	}else
		return a.s < b.s;
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    double s1 = 0,s2 = 0;

    for(int i = 1;i<=n;i++){
        scanf("%c%d",&a[i].op,&a[i].s);
        getchar();
        if(a[i].op == '+') s1++;
        else s2++;
    }

    sort(a+1,a+n+1,cmp);

    for (int i = 0; i <= n; i++) {
        cout << a[i].op  << " " << a[i].s << endl;
    }

    double ans = 0.0,t = 1.0;

    for(int i = 1;i<=n;i++){
        
        if(a[i].op == '-') ans += t * 1.0 / s2;
        else t = t - 1.0 / s1; 
    }
    printf("%.10lf",ans);
    return 0;
}