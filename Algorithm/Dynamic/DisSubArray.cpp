//
//  DisSubArray.cpp
//  Algorithm
//
//  Created by xiaoniu on 2019/5/28.
//  Copyright © 2019 com.learn. All rights reserved.
//
//  导弹拦截问题
//  某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹
//  拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每
//  一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于
//  该系统还在试用阶段，所以只有一套系统，因此不可能拦截所有的导弹。
//  输入---导弹依次飞来的高度，不大于30000的正整数
//  389 207 155 300 299 170 158 65
//  输出---这套系统最多能拦截的导弹数


//  对于给定的数组t[N],假设数组a[max]满足条件，那么a0..a[max-1]这个数组对于t0..a[max-1]也是符合条件的。
//  反过来也是成立的，对于给定的数组t[N],假设数组a[max]满足条件，那么a1..a[max]这个数组对于a[1]..t[N]也是符合条件的。
//  tN 389 207 155 300 299 170 158 65
//  i a[]
//  1 389
//  2 389 207
//  3 389 207 155
//  4 389 207 155
//  5 389 207 155 or 389 300 299
//  6 389 300 299 170
//  7 389 300 299 170 158
//  8 389 300 299 170 158 65

#include "DisSubArray.hpp"

#define M 8

int maxDis(int a,int count[],int target[]) {
    // 
    int max = 0;
    int i;
    int j;
    
    for (i=0;i<a;i++) {
        count[i] = 1;
    }
    
    for (i=0; i<a; i++) {
        // 每次增加一个元素，都需要从头进行匹配，不过中间过程的结果已经计算好了
        for(j=0;j<i;j++) {
            if (target[j] > target[i]) {
                count[i] = (count[i] > (count[j]+1)) ? count[i] : (count[j]+1);
                max = max > count[i] ? max : count[i];
            }
        }
    }
    
    printf("\n求得的最大导弹拦截数量%d\n",max); 
    return max;
}


//  N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，而不改变其他同学的位置，使得剩下的K位同学排成合唱队形。
//  合唱队形要求：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，
//  则他们的身高满足T1<T2...<Ti>Ti+1>…>TK(1<=i<=K)。
//  已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成最长的合唱队形。
//  N=8 k不确定，实际上谁最高是不确定的，因为需要假设任意位置都可以为最高
//  167 178 156 181 185 163 164 172 170
//  167 178 181 185 172 170 

int maxQueue(int high[],int length) {
    
    int up[length];
    int down[length];
    int max =0;
    
    for (int i=0;i<length;i++) {
        up[i] = 1;
        down[i] = 1;
    }
    
    // 求i左侧的最大升序
    for (int i=0; i<length; i++) {
        for (int j=0; j<i; j++) {
            if (high[j] < high[j]) {
                up[i] = (up[i] > (up[j]+1)) ? up[i] : (up[j]+1);
            }
        }
    }
    
    for (int i=length-1;i>=0;i--) {
        for (int j=length-1; j>i; j--) {
            if (high[j] < high[i]) {
                down[i] = (down[i] > (down[j]+1)) ? down[i] : (down[j]+1);
            }
        }
    }
    
    int index = 0;
    for (int i=0; i<length; i++) {
        if (up[i]+down[i]-1 > max) {
            max = up[i]+down[i]-1;
            index = i;
        }
    }
    
    printf("求得的最大队列%d\n",max); 
    
    return max;
}


//  在一个地图上有N个地窖（N<=200）,每个地窖中埋有一定数量的地雷。
//  同时，给出地窖之间的连接路径，并规定路径都是单向的,
//  也不存在可以从一个地窖出发经过若干地窖后又回到原来地窖的路径。
//  某人可以从任一处开始挖地雷，然后沿着指出的连接往下挖（仅能选择一条路径），
//  当无连接时挖地雷工作结束。设计一个挖地雷的方案，使他能挖到最多的地雷。

//  设置连通路径以后，这个地雷分布其实可以用一棵树来表示，如此就是求树从根节点往下遍历，

//  随便选一个起点 p,所有点分成两部分，p 和 p 以外 N-1 个点，那么对 p 点而言
//  Max(p) = Max(![p]) + BoomCount[p]
//  求出所有点开始能得到的Max,取最大值

#define N 7

void findBoom() {
    
    // N = 7
    // BoomCount[7] = {4 9 1 3 5 2 6}
    // 0->1
    // 1->3
    // 2->3
    // 2->6
    // 3->5
    // 3->6

    int access[N][N];
    
    access[0][1] = 1;
    access[1][3] = 1;
    access[2][3] = 1;
    access[2][6] = 1;
    access[3][5] = 1;
    access[3][6] = 1;

    struct Point {
        int x;
        int y;
        
        Point(int x,int y) {
            this->x = x;
            this->y = y;
        }
    };
    
    Point points[N] = {Point(0,1),Point(1,3),Point(2,3),Point(2,6),Point(3,5),Point(3,6),Point(4,5)};

    
    // 记录每个点最大挖雷数
    int max[N];
    int boomCount[N] = {4, 9, 1, 3, 5, 2, 6};
    int res = 0;
    
    // 遍历所有点
    for (int x=0; x<N; x++) {
        for (int y=x+1;y<N;y++) {
            if (access[x][y] == 1) {
                printf("x=%d,y=%d\n",x,y);
                
                if (x == 0) {
                    max[0] = boomCount[x]+boomCount[y];
                }
                 
                for (int j=0; j<N; j++) {
                    Point point = points[j];
                    
                    if (point.x < x && point.y == x) {
                        printf("x=%d,y=%d\n",x,y);
                        max[x] = max[x] > (max[point.x] + boomCount[y]) ? max[x] : (max[point.x] + boomCount[y]);
                         printf("max[%d]=%d\n",x,max[x]);
                    }
                }
               
               
            }
        }
    }
    
    
    
    printf("%d",res);
}

