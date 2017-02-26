//
//  main.cpp
//  Test
//
//  最大子数组问题
//
//  Created by 潘晓明 on 15/10/22.
//  Copyright © 2015年 潘晓明. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int num[100];


//线性时间求解O(n)
int MaxSubSum(int *arr, int len) {
    int MaxSum = 0;
    int Sum = 0;
    for(int i=0;i<len;i++) {
        Sum += arr[i];
        if(Sum > MaxSum)
            MaxSum = Sum;
        if(Sum < 0)
            Sum = 0;
    }
    return MaxSum;
}

//合并
int Merge(int *arr, int low, int mid, int high) {
    int leftsum = 0;
    int rightsum = 0;
    int sum = 0;
    for(int i=mid;i>=low;i--) {
        sum += arr[i];
        if(sum > leftsum)
            leftsum = sum;
    }
    sum = 0;
    for(int i=mid+1;i<=high;i++) {
        sum += arr[i];
        if(sum > rightsum)
            rightsum = sum;
    }
    return leftsum+rightsum;
}

//分治法求解
int MainSum(int *arr, int low, int high) {
    if(low == high)
        return arr[low];
    else {
        int mid = (low+high)/2;
        int leftsum, rightsum, midsum;
        leftsum = MainSum(arr, low, mid);
        rightsum = MainSum(arr, mid+1, high);
        midsum = Merge(arr, low, mid, high);
        if(leftsum > rightsum && leftsum > midsum)
            return leftsum;
        else if(rightsum > leftsum && rightsum > midsum)
            return rightsum;
        else
            return midsum;
    }
}

int main(int argc, const char * argv[]) {
    
    cin>>n;
    
    for(int i=0;i<n;i++) {
        cin>>num[i];
    }
    
    cout<<MaxSubSum(num, n)<<endl;
    cout<<MainSum(num, 0, n-1)<<endl;
    return 0;
}
