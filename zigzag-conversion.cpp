//
//  ZigZag_Conversion.cpp
//  Test
//
//  Created by 潘晓明 on 16/10/15.
//  Copyright © 2016年 潘晓明. All rights reserved.
//
//Z型字符串  
//leetcode 第六题 
//模拟法，构造出Z型的字符数组，然后再转化为字符串，效率上比较低，还有其他的解法以及优化点值得研究
//rt:89ms

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
//    string s = "PAYPALISHIRING";
    string s = "hnbrhfunvfcbvriybfujvlcixlcmjaqqpujyzdowlqzghjfkp";
    int numRows = 2;
    unsigned long len = s.size();
    unsigned long column = (len/2)+1;
    char** zigZag = new char*[numRows];
    for(int i=0; i<numRows; i++)
        zigZag[i] = new char[column];
    for(int i=0; i<numRows; i++)
        for(int j=0; j<column; j++)
            zigZag[i][j] = ' ';
    int m=0, n=0;
    //0往下，1往上
    int dir = 0;
    for(int k=0; k<len; k++)
    {
        if(dir == 0) {
            if(m+1 < numRows)
                zigZag[m++][n] = s[k];
            else {
                zigZag[m][n] = s[k];
                m--;
                n++;
                dir = 1;
            }
        } else {
            if(m-1 >= 0) {
                zigZag[m--][n++] = s[k];
            } else {
                zigZag[m][n] = s[k];
                m++;
                dir = 0;
            }
        }
    }
    int k=0;
    for(int i=0; i<numRows; i++)
        for(int j=0; j<column; j++)
            if(zigZag[i][j] != ' ')
                s[k++] = zigZag[i][j];
    cout<<s<<endl;
    
    return 0;
}