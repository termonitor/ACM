//
//  Manacher.cpp
//  Test
//
//  Created by 潘晓明 on 16/10/14.
//  Copyright © 2016年 潘晓明. All rights reserved.
//
//用于回文字符串   
//leetcode 第五题 
//rt:6ms

#include <iostream>
#include <string.h>

using namespace std;

char* pre(string str) {
    unsigned long length = str.size();
    char* preStr = new char[2*length+4];
    preStr[0] = '$';
    preStr[1] = '$';
    for(int i=0; i<length; i++)
    {
        preStr[2*(i+1)] = '#';
        preStr[2*(i+1)+1] = str[i];
    }
    preStr[2*length+2] = '#';
    preStr[2*length+3] = '\0';
    return preStr;
}

string longestPalindrome(string s) {
    unsigned long len = s.size();
    if(len == 1)
        return s;
    char* preStr = pre(s);
    int max = 0, pi = 1;
    size_t length = strlen(preStr);
    int* p = new int[length];
    p[0] = 0;
    for(int i=1; i<length; i++)
    {
        if(i < max) {
            p[i] = min(max-i, p[2*pi-i]);
        } else {
            p[i] = 1;
        }
        while(i-p[i]>0 && i+p[i]<length && preStr[i-p[i]]==preStr[i+p[i]])
        {
            p[i]++;
        }
        if(i+p[i] > max) {
            max =  i+p[i];
            pi = i;
        }
    }
    int maxlen = 0;
    for(int i=0; i<length; i++)
    {
        if(p[i] > maxlen)
        {
            maxlen = p[i];
            pi = i;
        }
    }
    len = maxlen - 1;
    unsigned long start;
    if(pi%2 == 0) {
        start = (pi-1)/2 - len/2;
    } else {
        start = (pi-3)/2 - len/2;
    }

    return s.substr(start, len);
}

int main()
{
    string str = "adcda";
    cout<<longestPalindrome(str)<<endl;
    return 0;
}