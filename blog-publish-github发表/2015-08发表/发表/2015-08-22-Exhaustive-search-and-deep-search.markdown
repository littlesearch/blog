---
layout: post
title: "穷举搜索 回溯与深搜"
date: 2015-08-22 11:39:19 +0800
comments: true
categories: algorithm
tags: [algorithm,C]
keyword: 陈浩翔, 谙忆
description: 计算机常用算法大致有两大类，一类叫蛮力算法，一类叫贪心算法，前者常使用的手段就是搜索，对全部解空间进行地毯式搜索，直到找到指定解或最优解。【建立解空间】 问题的解应该如何描述，如何建立？借助图论的思想，我们可以用图来描述，图的定义为G，由顶点集和边集构成，顶点即实实在在的数 据、对象，而边可以抽象为关系，即顶点间的关系，这种关系不一定非要在数据结构上表现出来，用数据结构的语言来描述，如果关系是一对 
---

计算机常用算法大致有两大类，一类叫蛮力算法，一类叫贪心算法，前者常使用的手段就是搜索，对全部解空间进行地毯式搜索，直到找到指定解或最优解。

<!-- more -->
----------


【建立解空间】
问题的解应该如何描述，如何建立？借助图论的思想，我们可以用图来描述，图的定义为G，由顶点集和边集构成，顶点即实实在在的数 据、对象，而边可以抽象为关系，即顶点间的关系，这种关系不一定非要在数据结构上表现出来，用数据结构的语言来描述，如果关系是一对一，则为线性表，如果 关系是一对多，则为树，如果关系是多对多，则为图，如果完全没有关系，则为集合。但在数据结构中这种关系不一定非要在数据的存储性质上一开始就表现出来， 譬如，你可以用一个数组表示一个线性表，也可以表示完全二叉树，同样也可以用邻接表表示一个图，对于关系的描述不是数据结构本身的描述，而是算法的描述， 正如数据结构是离不开特定的算法一样，不可分开单独而谈。描述了解，那如何建立解空间，即如何对图进行搜索？

【深度优先搜索】
(Depth First Search)是用栈的机制对图的顶点进行深度优先的搜索。简易流程如下：

DFS(V0（起始顶点）)
访问V0
for(v=V0的第一个子结点 到 最后一个子结点（边所对的顶点））
   如果v未被访问，DFS(v);

搜索过程是先往结点深处搜索，一旦有子结点未访问就向下遍历。这样的方法类似回溯算法，先往下试探，如果不行出退回（回溯）。

【回溯】
回溯的经典例子是8皇后问题。
例：在国际象棋地图上（8×8）放上8个皇后，使任意两个皇后都不在同一行或同一列或同一斜行，找出所有解。
每一个皇后的位置可以认为是一个顶点，而皇后之间不在同一行或同一列或同一斜行的性质认为是顶点之间的关系，我们可以用回溯试探的方法考虑：先依次试探每一个皇后的位置，如果有不满足条件的情况则退回，直到完成所有解的计数和输出。

用数组存储：int pos[8];
pos[0]表示第一个皇后的位置（0,1,...7)依次类推。
流程：
dfs(c)//c从0开始
for(v=0;v<8;++v)
   如果pos[c]:=v满足条件，dfs(c+1);
   退回之后pos[c]:=0;

这跟书上的回溯算法不太一样，因为是采用深搜的方法写的，其实思想是一致的，要仔细体会。

八皇后问题 回溯法

问题描述：
八皇后问题是十九世纪著名数学家高斯于1850年提出的。问题是：在8*8的棋盘上摆放8个皇后，使其不能互相攻击，即任意的两个皇后不能处在同意行，同一列，或同意斜线上。可以把八皇后问题拓展为n皇后问题，即在n*n的棋盘上摆放n个皇后，使其任意两个皇后都不能处于同一行、同一列或同一斜线上。

问题分析 ： 

显然，每一行可以而且必须放一个皇后，所以n皇后问题的解可以用一个n元向量X=（x1,x2,.....xn）表示，其中，1≤ i≤ n且1≤ xi≤ n，即第n个皇后放在第i行第xi列上。

由于两个皇后不能放在同一列上，所以，解向量X必须满足的约束条件为:

xi≠ xj;

若两个皇后的摆放位置分别是（i,xi）和（j,xj），在棋盘上斜率为-1的斜线上，满足条件i-j=xi-xj;在棋盘上斜率为1的斜线上，满足条件i+j=xi+xj;

综合两种情况，由于两个皇后不能位于同一斜线上，所以，

解向量X必须满足的约束条件为:

|i-xi|≠ |j-xj|

代码如下：

```
#include<stdio.h>
#include<math.h>
int x[100];
bool place(int k)//考察皇后k放置在x[k]列是否发生冲突
{
    int i;
    for(i=1;i<k;i++)
        if(x[k]==x[i]||abs(k-i)==abs(x[k]-x[i]))
            return false;
        return true;
}

void queue(int n)
{
    int i,k;
    for(i=1;i<=n;i++)
        x[i]=0;
    k=1;
    while(k>=1)
    {
        x[k]=x[k]+1;   //在下一列放置第k个皇后
        while(x[k]<=n&&!place(k))
            x[k]=x[k]+1;//搜索下一列
        if(x[k]<=n&&k==n)//得到一个输出
        {
            for(i=1;i<=n;i++)
                printf("%d ",x[i]);
            printf("\n");
        //return;//若return则只求出其中一种解，若不return则可以继续回溯，求出全部的可能的解
        }
        else if(x[k]<=n&&k<n)
            k=k+1;//放置下一个皇后
        else
        {
            x[k]=0;//重置x[k],回溯
            k=k-1;
        }
    }
}

void main()
{
   int n;
   printf("输入皇后个数n:\n");
   scanf("%d",&n);
   queue(n);
}
```



本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
