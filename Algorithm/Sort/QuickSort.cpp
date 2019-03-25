//
//  QuickSort.cpp
//  Algorithm
//
//  Created by xiaoniu on 2019/3/11.
//  Copyright © 2019 com.learn. All rights reserved.
//

#include "QuickSort.hpp"

void qucik_sort(int a[],int low,int high) {
    
    if (low >= high) {
        return;
    }
    
    int first = low;
    int last = high;
    int key = a[first];
    
    while (first < last) {
        while (first < last && a[last] >= key) {
            last--;
        }
        // 找到比第一个小的，移到低端
        a[first] = a[last];
        
        while (first<last && a[first] <= key) {
            first++;
        }
        a[last] = a[first];
    }
    
    a[first] = key;
    
    qucik_sort(a, low,first-1);
    qucik_sort(a, first+1,high);
}

/**
 从数组中找出两个数和为指定d值

 @param nums 数组
 @param numsSize 数组长度
 @param target 指定值
 @return 返回一直值
 */
int* twoSum(int* nums, int numsSize, int target) {
    qucik_sort(nums,0,numsSize-1);
    
    int i=0;
    while (i< numsSize-1 && nums[i] <= target/2) {
        i++;
    }
    
    if (i==0) {
        return {};
    }
    
    int m = 0;
    int n = i;
    
    while (m<i) {
        int sum = nums[m]+nums[n];
        while (n<numsSize  && sum < target) {
            n++; 
        }
        
        if (sum == target) {
            printf("%d,%d\n",m,n);
        }
        n=i;
        m++;
    }
    
    return nums;
}


void my_qsort(int a[],int left,int right) {
    
    if (left >= right) {
        return;
    }
    
    int low = left;
    int high = right;
    
    int key = a[low];
    
    while (low < high) {
        while (high > low && a[high] >= key) {
            high--;
        }
        
        // a[low]的值已经被记录，可以用来做交换空间
        a[low] = key;
        
        while (low < high && a[low] <= key) {
            low++;
        }
        
        a[high] = a[low];
    }
    
    a[low] = key;
    my_qsort(a,left,low-1);
    my_qsort(a,low+1,right);
}
