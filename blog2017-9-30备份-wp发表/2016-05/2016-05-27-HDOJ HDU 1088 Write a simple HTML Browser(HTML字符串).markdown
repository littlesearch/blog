---
layout: post
title: "HDOJ HDU 1088 Write a simple HTML Browser(HTML字符串)"
date: 2016-05-27 02:32:35 +0800
comments: true
categories:❶ ACM,----- HDOJ-JAVA,❺ 算法及基础题,----- String
tags: [html,java,acm]
keyword: 陈浩翔, 谙忆
description: Problem Description 
If you ever tried to read a html document on a Macintosh, you know how hard it is if no Netscape is installed.  
Now, who can forget to install a HTML browser? This is very easy be 
---


Problem Description 
If you ever tried to read a html document on a Macintosh, you know how hard it is if no Netscape is installed.  
Now, who can forget to install a HTML browser? This is very easy be
&#60;!-- more --&#62;
----------

Problem Description
If you ever tried to read a html document on a Macintosh, you know how hard it is if no Netscape is installed. 
Now, who can forget to install a HTML browser? This is very easy because most of the times you don't need one on a MAC because there is a Acrobate Reader which is native to MAC. But if you ever need one, what do you do? 
Your task is to write a small html-browser. It should only display the content of the input-file and knows only the html commands (tags) `&#60;br&#62;` which is a linebreak and `&#60;hr&#62;` which is a horizontal ruler. Then you should treat all tabulators, spaces and newlines as one space and display the resulting text with no more than 80 characters on a line.

 

Input
The input consists of a text you should display. This text consists of words and HTML tags separated by one or more spaces, tabulators or newlines. 
A word is a sequence of letters, numbers and punctuation. For example, "abc,123" is one word, but "abc, 123" are two words, namely "abc," and "123". A word is always shorter than 81 characters and does not contain any '&#60;' or '&#62;'. All HTML tags are either `&#60;br&#62;` or `&#60;hr&#62;`.

 

Output
You should display the the resulting text using this rules: 
  . If you read a word in the input and the resulting line does not get longer than 80 chars, print it, else print it on a new line. 
  . If you read a `&#60;br&#62;` in the input, start a new line. 
  . If you read a `&#60;hr&#62;` in the input, start a new line unless you already are at the beginning of a line, display 80 characters of '-' and start a new line (again). 
The last line is ended by a newline character.

 

Sample Input

```
Hallo, dies ist eine 
ziemlich lange Zeile, die in Html
aber nicht umgebrochen wird.
&#60;br&#62;
Zwei &#60;br&#62; &#60;br&#62; produzieren zwei Newlines. 
Es gibt auch noch das tag &#60;hr&#62; was einen Trenner darstellt.
Zwei &#60;hr&#62; &#60;hr&#62; produzieren zwei Horizontal Rulers.
Achtung       mehrere Leerzeichen irritieren

Html genauso wenig wie


mehrere Leerzeilen.
```

 

Sample Output

```
Hallo, dies ist eine ziemlich lange Zeile, die in Html aber nicht umgebrochen
wird.
Zwei

produzieren zwei Newlines. Es gibt auch noch das tag
--------------------------------------------------------------------------------
was einen Trenner darstellt. Zwei
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
produzieren zwei Horizontal Rulers. Achtung mehrere Leerzeichen irritieren Html
genauso wenig wie mehrere Leerzeilen.

```



```
注意点：
（1） 每行最多80个字符，如果加上最后一个单词大于80，则最后一个单词移到下一行。
（2） &#60;hr&#62;如果处于当前行字符数等于0的情况，则直接输出，否则先输出回车，在输出&#60;hr&#62;,只含有&#60;br&#62;和&#60;hr&#62;标签
(3) 文章最后要有一个回车
```

equals表示的相等，是指向对象的相等；而compareTo的相等，是内容的相等。
不过其中有一个问题，很奇怪~我用equals老是PE，用compareTo就没问题了~~~弄不懂~

代码注释标识了！
有知道原因的大牛，请在评论区指点下，谢啦~
(哈哈~解决啦~其实这2个都可以的~)
之前的PE应该不是这个原因~


```
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String result = new String("");
		String str;
		while (sc.hasNext()) {
			str = sc.next();
			if ("".equals(str)) {
				continue;
			}
			if ("&#60;br&#62;".equals(str)) {
				System.out.println(result);
				result = "";
			} else if ("&#60;hr&#62;".equals(str)) {
				if (result.compareTo("")!=0) {
				//	if (!"".equals(result)) {//这个是一样的！
					System.out.println(result);
				}
				gong.print();
				result = "";
			} else {

				String temp = result;
				if ((temp + " " + str).length() &#60; 80) {
					if (!"".equals(result)) {
						result += " " + str;
					} else {
						result = str;// 每一行的第一个输入
					}
				} else {
					System.out.println(result);
					result = str;
				}
			}
		}
		if (!("".equals(result))) {
			System.out.println(result);
		}
	}
}

class gong {
	static void print() {
		for (int i = 0; i &#60; 80; i++)
			System.out.print("-");
		System.out.println();
	}
}

```