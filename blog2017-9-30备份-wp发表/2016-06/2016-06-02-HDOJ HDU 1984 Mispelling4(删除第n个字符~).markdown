---
layout: post
title: "HDOJ HDU 1984 Mispelling4(删除第n个字符~)"
date: 2016-06-02 01:42:28 +0800
comments: true
categories:❶ ACM,----- HDOJ-JAVA,❺ 算法及基础题,----- String,----- 基础题
tags: [java,acm,String]
keyword: 陈浩翔, 谙忆
description: Problem Description 
Misspelling is an art form that students seem to excel at. Write a program that removes the nth character from an input string.Input 
The first line of input contains a single inte 
---


Problem Description 
Misspelling is an art form that students seem to excel at. Write a program that removes the nth character from an input string.Input 
The first line of input contains a single inte
&#60;!-- more --&#62;
----------

Problem Description
Misspelling is an art form that students seem to excel at. Write a program that removes the nth character from an input string.

 

Input
The first line of input contains a single integer N, (1 ≤ N ≤ 1000) which is the number of datasets that follow.
Each dataset consists of a single line of input containing M, a space, and a single word made up of uppercase letters only. M will be less than or equal to the length of the word. The length of the word is guaranteed to be less than or equal to 80.
 

Output
For each dataset, you should generate one line of output with the following values: The dataset number as a decimal integer (start counting at one), a space, and the misspelled word. The misspelled word is the input word with the indicated character deleted.

 

Sample Input
4
4 MISSPELL
1 PROGRAMMING
7 CONTEST
3 BALLOON
 

Sample Output
1 MISPELL
2 ROGRAMMING
3 CONTES
4 BALOON


&#60;font color="red" size="4"&#62;
大水题！！！
就是一个字符串删除第n(从1开始)个字符就可以了。
&#60;/font&#62;

```
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int p=1;
		int t =sc.nextInt();
		while(t--&#62;0){
			int a = sc.nextInt();
			String str=sc.next();
			System.out.print((p++)+" ");
			for(int i=0;i&#60;str.length();i++){
				if(i!=(a-1)){
					System.out.print(str.charAt(i));
				}
			}
			System.out.println();
		}
	}
}

```