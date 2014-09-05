#include<iostream>
using namespace std;

char grid[12][12];
int fgrid[12][12];
int step;

void action(int r,int c)
{
    int r1,c1,d;
    fgrid[r][c] = 1;
    step=2;
    while(grid[r][c]!='0')
    {
        d = grid[r][c];
        c1 = c;
        r1 = r;
        switch(d)
        {
            case 'W':c1--;break;
            case 'E':c1++;break;
            case 'S':r1++;break;
            case 'N':r1--;break;
        }
        if(grid[r1][c1]!='0'&&fgrid[r1][c1]==0)
        {
           fgrid[r1][c1] = step;
           step++; 
        }
        else if(grid[r1][c1]=='0')
        {
            cout<<fgrid[r][c]<<" step(s) to exit"<<endl;
            break;
        }
        else if(fgrid[r1][c1]!=0)
        {
            cout<<fgrid[r1][c1]-1<<" step(s) before a loop of "<<step-fgrid[r1][c1]<<" step(s)"<<endl;
            break;
        }
        r = r1;
        c = c1;
    }
}

int main()
{
    int row,col,start;
    while(cin>>row>>col>>start)
    {
        if(row==0||col==0||start==0)
            break;
        memset(grid,'0',sizeof(char)*12*12);
        memset(fgrid,0,sizeof(int)*12*12);
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                cin>>grid[i][j];
        step = 0;
        action(1,start);
    }
    //system("Pause");
    return 0;
}
