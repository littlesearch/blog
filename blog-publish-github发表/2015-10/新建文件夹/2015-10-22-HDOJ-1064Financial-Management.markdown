---
layout: post
title: "HDOJ 1064Financial Management"
date: 2015-10-22 03:58:51 +0800
comments: true
categories: acm-c
tags: [acm,c++]
keyword: 陈浩翔, 谙忆
description: Problem Description Larry graduated this year and finally has a job. He’s making a lot of money, but somehow never seems to have enough. Larry has decided that he needs to grab hold of his financial p 
---

Problem Description  
Larry graduated this year and finally has a job. He’s making a lot of money, but somehow never seems to have enough. Larry has decided that he needs to grab hold of his financial portfolio and solve his financing problems. The first step is to figure out what’s been going on with his money. Larry has his bank account statements and wants to see how much money he has. Help Larry by writing a program to take his closing balance from each of the past twelve months and calculate his average account balance.
 
<!-- more -->
----------


Input  
The input will be twelve lines. Each line will contain the closing balance of his bank account for a particular month. Each number will be positive and displayed to the penny. No dollar sign will be included.
 

Output  
The output will be a single number, the average (mean) of the closing balances for the twelve months. It will be rounded to the nearest penny, preceded immediately by a dollar sign, and followed by the end-of-line. There will be no other spaces or characters in the output.
 

Sample Input  
```
100.00 
489.12 
12454.12 
1234.10 
823.05 
109.20 
5.27 
1542.25 
839.18 
83.99 
1295.01 
1.75
 

Sample Output
$1581.42
```

```C++
#include<stdio.h>
int main()
{
    int i;
    double a,s;
    s=0;
    for(i=1;i<=12;i++)
     {
       scanf("%lf",&a);
       s+=a;
     }
    printf("$%.2lf\n",s/12);
    return 0;
}
```

本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
