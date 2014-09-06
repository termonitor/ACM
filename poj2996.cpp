#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<string> white,black;

int charTonum(char a)
{
    switch(a)
    {
        case 'n':
        case 'N':return 1;
        case 'b':
        case 'B':return 2;
        case 'r':
        case 'R':return 3;
        case 'q':
        case 'Q':return 4;
        case 'k':
        case 'K':return 5;
    }
    return -1;
}

bool wcmp(string a,string b)
{
    int alen,blen;
    alen = a.length();
    blen = b.length();
    if(alen==2 && blen==2)
    {
        if(a[1]<b[1])
            return true;
        else if(a[1]==b[1])
            if(a[0]<b[0])
                return true;
    }
    else if(alen==3 && blen==2)
    {
        return true;
    }
    else if(alen==2 && blen==3)
    {
        return false;
    }
    else
    {
        if(a[0]==b[0])
        {
            if(a[2]<b[2])
                return true;
            else if(a[2]==b[2])
                if(a[1]<b[1])
                    return true;
        }
        else if(charTonum(a[0])>charTonum(b[0]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool bcmp(string a,string b)
{
    int alen,blen;
    alen = a.length();
    blen = b.length();
    if(alen==2 && blen==2)
    {
        if(a[1]>b[1])
            return true;
        else if(a[1]==b[1])
            if(a[0]<b[0])
                return true; 
    }
    else if(alen==3 && blen==2)
    {
        return true;
    }
    else if(alen==2 && blen==3)
    {
        return false;
    }
    else
    {
        if(a[0]==b[0])
        {
            if(a[2]>b[2])
                return true;
            else if(a[2]==b[2])
                if(a[1]<b[1])
                    return true; 
        } 
        else if(charTonum(a[0])>charTonum(b[0]))
        {
            return true;
        } 
    } 
    return false;
}

int main()
{
    int num = 0;
   // freopen("in.txt","r",stdin);
    for(int i=0;i<17;i++)
    {
        string str;
        cin>>str;
        if(str[0]=='+')
        {
            num++;
            continue;
        }
        for(int j=0;j<str.length();j++)
        {
            string temp = "";
            if(str[j]>='a' && str[j] <= 'z')
            {
                //╨звс
               // 2 6 10 14
               //(j-2)/4+1
                if(str[j]=='p')
                {
                    temp += 'a'+(j-2)/4;
                    temp += '0'+9-num;
                }
                else
                {
                    temp += str[j]-32;
                    temp += 'a'+(j-2)/4; 
                    temp += '0'+9-num;   
                }
                black.push_back(temp);
            }
            else if(str[j]>='A' && str[j]<='Z')
            {
                if(str[j]=='P')
                {
                    temp += 'a'+(j-2)/4;
                    temp += '0'+9-num;
                }
                else
                {
                    temp += str[j];
                    temp += 'a'+(j-2)/4;
                    temp += '0'+9-num;
                }
                white.push_back(temp);
            }
            else
            {
                continue;
            }
        }
    }
    vector<string>::iterator itw = white.begin();
    vector<string>::iterator itb = black.begin();
    sort(itw,itw+white.size(),wcmp);
    sort(itb,itb+black.size(),bcmp);
    cout<<"White: ";
    for(;itw!=white.end();itw++)
    {
        if(itw!=white.end()-1)
            cout<<*itw<<",";
        else
            cout<<*itw<<endl;
    }
    cout<<"Black: ";
    for(;itb!=black.end();itb++)
    {
        if(itb!=black.end()-1)
            cout<<*itb<<",";
        else
            cout<<*itb<<endl;
    }
  //  while(1);
  //  system("Pause");
    return 0;   
}
