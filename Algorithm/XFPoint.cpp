//
//  XFPoint.cpp
//  Algorithm
//
//  Created by xiaoniu on 2018/12/21.
//  Copyright © 2018 com.learn. All rights reserved.
//
/// 指针主要是C语言及其超集在使用,高级语言不需要了解变量的内存地址,比如java
///
/// 变量内存地址：程序运行时，会被加载到内存当中，变量肯定需要存储在某个地方（内存卡）。
/// 内存单元是以字节为单位的，4GB = 4 * 1024(M) * 1024(KB) * 1024(B)
/// 假设int占4个字节，那int a = 5;

#include "XFPoint.hpp"

// --------------------------------------------------------------- 

void pointParas(int **p2) {
    int b = 3;
    
    printf("参数传递后参数地址：%p\n",&p2);
    *p2 = &b;
}

void testPoint4() {
    
    int a = 5;
    int* p = &a;
    
    printf("参数传递前地址：%p\n",&p);
    
    pointParas(&p);
    
    printf("%d = p\n",*p);
}

// --------------------------------------------------------------- 

void testPoint2(int* p) {
    int a = 3;
    
    // C语言是一般数据类型是值传递，外界传入时，参数是新生成的变量，只是值和原来的相同
    // 指针类型参数就是直接传地址过去，可以通过打印参数的地址进行确认
    // 修改指针p的指向的，不会影响外面实参
    
    printf("%p = &p\n",&p);
    printf("%p = p\n",p);
    printf("%d = p\n",*p);
    
    p = &a;
    
    printf("%p = &p\n",&p);
    printf("%p = p\n",p);
    printf("%d = p\n",*p);
    printf("\n");
}

void testPoint() {
    int a = 5;
    printf("int a = 5\n");
    printf("%lu = sizeof(a)\n",sizeof(a));
    printf("%p = &a\n",&a);
    
    printf("----------------------------\n");
    
    // p = a的地址
    int* p = &a;
    
    printf("int* p = &a\n");
    printf("%p = p\n",p);
    // *p 取出p地址记录的值
    printf("%d = *p\n",*p);
    printf("%p = &p\n",&p);
    
    printf("----------------------------\n");
   
    // p 自己也是变量，也需要地方存放，p1= p的地址
    int** p1 =&p;
    printf("int** p1 =&p\n");
    printf("%p = p1\n",p1);   
    printf("%p = *p1\n",*p1);
    
    printf("----------------------------\n");
    // 
    int* p2 = p;
    printf("int* p2 = p\n");
    printf("%p = p2\n",p2);
    printf("%p = &p2\n",&p2);
    
    printf("------------testPoint4() Start----------------\n");
    
    testPoint4();
}

