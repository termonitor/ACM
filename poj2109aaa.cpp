#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

#define Length 110
#define Last Length-2
#define Greater 1
#define Equal 0
#define Less -1

//大整数乘法 
char* IntegerMultiplication(const char *a,const char *b,char *product)
{
    int i,j,k=Last,first,value,temp[Length];
    memset(temp,0,sizeof(temp));
    for(i=strlen(a)-1;i>=0;i--)
    {
        first=k--;
        value=a[i]-'0';
        for(j=strlen(b)-1;j>=0;j--)
        {
            temp[first--] += value*(b[j]-'0');
        }
    } 
    for(i=Last;i>=first;i--) 
    {
        product[i] = temp[i]%10+'0';
        temp[i-1] += temp[i]/10; 
    } 
    //使first下标为首个不为0的数字 
    while(product[first]=='0'&&first<Last)
    {
        first++;
    } 
    return &product[first]; 
}

//比较两个字符串数字的大小 
int Compare(char *numA,char *numB)
{
    //去除0前导 
    for(;*numA=='0';numA++);
    for(;*numB=='0';numB++);
    int lenA = strlen(numA);
    int lenB = strlen(numB); 
    if(lenA == lenB)
    {
        return strcmp(numA,numB);
    }
    if(lenA > lenB)
    {
        return Greater;
    }
    return Less;
}

//求base^exp,结果存放在res中，pRes指向结果的首位数字的位置 
char* Power(char *base,int exp,char *res)
{
    res[Last]='1';
    char *pRes=&res[Last],*temp=base;
    while(exp!=0)
    {
        if(exp%2==1)
        {
            pRes=IntegerMultiplication(base,pRes,res);
        }
        exp/=2;
        if(exp!=0)
        {
            base=IntegerMultiplication(base,base,temp);
        }
    }
    return pRes;
}

int main()
{
    char p[Length],cMid[Length]={0},res[Length]={0};
    unsigned int n,lenP,lenRoot,i,min,max,mid;
    while(cin>>n>>p)
    {
        lenP=strlen(p);
        lenRoot=(int)ceil((double)lenP/n);
        for(i=1,min=1;i<lenRoot;i++)
            min*=10;
        for(i=1,max=9;i<lenRoot;i++)
        {
            max*=10;
            max+=9;
        } 
        bool finish=false;
        while(!finish)
        {
            mid=(min+max)/2;
            if(min>=max)
                break;
            sprintf(cMid,"%d",mid);
            memset(res,0,sizeof(res));
            switch(Compare(Power(cMid,n,res),p))
            {
                case Greater: max=mid-1;break;
                case Equal: finish=true;break;
                case Less: min=mid+1;break;
                default:break; 
            }
        }
        sprintf(cMid,"%d",mid);
        if(Compare(Power(cMid,n,res),p)==Greater)
        {
            mid--;
        }
        cout<<mid<<endl;
    }
    //system("Pause");
    return 0; 
}
