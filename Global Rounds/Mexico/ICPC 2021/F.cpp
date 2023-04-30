#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,x,y,z;
int now,a,b,c,d;
string s,whatKK;

void work(int &a,int &b,int &c,int &d){
    d  += y;
    c += x+d/1000;
    d %= 1000;
    b += c/60;
    c %= 60;
    a +=  (b/60);
    b %= 60;
}

int main(){
    scanf("%d %d.%d",&n,&x,&y);
    scanf("%d",&now);
    
    for(int i=1;i<=n;++i){
        printf("%d\n",i);
        scanf("%d:%d:%d,%d",&a,&b,&c,&d);
        work(a,b,c,d);
        printf("%02d:%02d:%02d,%03d --> ",a,b,c,d);

        scanf(" --> %d:%d:%d,%d",&a,&b,&c,&d);
        work(a,b,c,d);
        printf("%02d:%02d:%02d,%03d",a,b,c,d);

        whatKK.clear();

        now = i+1;
        while(now){
            whatKK = char('0'+now%10)+whatKK;
            now /= 10;
        }

        while(getline(cin,s)){
            if(s == whatKK)
                break;
            else
                cout << s <<"\n";
        }   
    }
}