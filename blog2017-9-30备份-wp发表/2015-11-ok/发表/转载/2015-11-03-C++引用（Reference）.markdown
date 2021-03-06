---
layout: post
title: "C++引用（Reference）"
date: 2015-11-03 10:13:35 +0800
comments: true
categories:❸ C/C++,----- 数据结构,----- 好文/知识点
tags: [c语言]
keyword: 陈浩翔, 谙忆
description: 引用(Reference)是C++语言相对于C语言的又一个扩充，类似于指针，只是在声明的时候用&取代了*。引用可以看做是被引用对象的一个别名，在声明引用时，必须同时对其进行初始化。引用的声明方法如下： 
    类型标识符 &引用名 = 被引用对象[例1]C++引用示例：int a = 10;
int &b = a;
cout<<a<<" "<<b<<endl;
cout<<&a<<" "<<&b< 
---


引用(Reference)是C++语言相对于C语言的又一个扩充，类似于指针，只是在声明的时候用&取代了*。引用可以看做是被引用对象的一个别名，在声明引用时，必须同时对其进行初始化。引用的声明方法如下： 
    类型标识符 &引用名 = 被引用对象[例1]C++引用示例：int a = 10;
int &b = a;
cout&#60;&#60;a&#60;&#60;" "&#60;&#60;b&#60;&#60;endl;
cout&#60;&#60;&a&#60;&#60;" "&#60;&#60;&b&#60;
&#60;!-- more --&#62;
----------

引用(Reference)是C++语言相对于C语言的又一个扩充，类似于指针，只是在声明的时候用&取代了*。引用可以看做是被引用对象的一个别名，在声明引用时，必须同时对其进行初始化。引用的声明方法如下：
    类型标识符 &引用名 = 被引用对象

[例1]C++引用示例：

```cpp
int a = 10;
int &b = a;
cout&#60;&#60;a&#60;&#60;" "&#60;&#60;b&#60;&#60;endl;
cout&#60;&#60;&a&#60;&#60;" "&#60;&#60;&b&#60;&#60;endl;
```

在本例中，变量b就是变量a的引用，程序运行结果如下：
10 10
0018FDB4 0018FDB4

从这段程序中我们可以看出变量a和变量b都是指向同一地址的，也即变量b是变量a的另一个名字，也可以理解为0018FDB4空间拥有两个名字：a和b。由于引用和原始变量都是指向同一地址的，因此通过引用也可以修改原始变量中所存储的变量值，如例2所示，最终程序运行结果是输出两个20，可见原始变量a的值已经被引用变量b修改。

[例2]通过引用修改原始变量中的值：

```cpp
int a = 10;
int &b = a;
b = 20;
cout&#60;&#60;a&#60;&#60;" "&#60;&#60;b&#60;&#60;endl;
```

如果我们不希望通过引用来改变原始变量的值时，我们可以按照如下的方式声明引用：
    const 类型标识符 & 引用名 = 被引用的变量名

这种引用方式成为常引用。如例3所示，我们声明b为a的常引用，之后尝试通过b来修改a变量的值，结果编译报错。虽然常引用无法修改原始变量的值，但是我们仍然可以通过原始变量自身来修改原始变量的值，如例3中，我们用a=20;语句将a变量的值由10修改为20，这是没有语法问题的。

[例3]不能通过常引用来修改原始值：

```cpp
int a = 10;
const int &b = a;
b = 20;   //compile error
a = 20;
```
通过例2，我们可以知道通过引用我们可以修改原始变量的值，引用的这一特性使得它用于函数传递参数或函数返回值时非常有用。
1) 函数引用参数

如果我们在声明或定义函数的时候将函数的形参指定为引用，则在调用该函数时会将实参直接传递给形参，而不是将实参的拷贝传递给形参。如此一来，如果在函数体中修改了该参数，则实参的值也会被修改。这跟函数的普通传值调用还是有区别的。

[例3]函数的引用传值：

```cpp
#include&#60;iostream&#62;
using namespace std;

void swap(int &a, int &b);

int main()
{
    int num1 = 10;
    int num2 = 20;
    cout&#60;&#60;num1&#60;&#60;" "&#60;&#60;num2&#60;&#60;endl;
    swap(num1, num2);
    cout&#60;&#60;num1&#60;&#60;" "&#60;&#60;num2&#60;&#60;endl;
    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
```
运行结果：
10 20
20 10

在本例中我们将swap函数的形参声明为引用，在调用swap函数的时候程序是将变量num1和num2直接传递给形参的，其中a是num1的别名，b是num2的别名，在swap函数体中交换变量a和变量b的值，也就相当于直接交换变量num1和变量num2的值了，因此程序最后num1=20，num2=10。
2) 函数引用返回值

在C++中非void型函数需要返回一个返回值，类似函数形参，我们同样可以将函数的返回值声明为引用。普通的函数返回值是通过传值返回，即将关键字return后面紧接的表达式运算结果或变量拷贝到一个临时存储空间中，然后函数调用者从临时存储空间中取到函数返回值，如例4所示。

[例4]函数的普通返回值：

```cpp
#include&#60;iostream&#62;
using namespace std;

int valplus(int &a);

int main()
{
    int num1 = 10;
    int num2;
    num2 = valplus(num1);
    cout&#60;&#60;num1&#60;&#60;" "&#60;&#60;num2&#60;&#60;endl;
    return 0;
}

int valplus(int &a)
{
    a = a + 5;
    return a;
}
```

在例4中，valplus函数采用的是普通的传值返回，也即将变量a的结果加上5之后，将结果拷贝到一个临时存储空间，然后再从临时存储空间拷贝给num2变量。 当我们将函数返回值声明为引用的形式时，如例5所示。虽然例5运行结果和例4是相同的，但例5中的valplus函数在将a变量加上5之后，其运算结果是直接拷贝给num2的，中间没有经过拷贝给临时空间，再从临时存储空间中拷贝出来的这么一个过程。这就是普通的传值返回和引用返回的区别。

[例5]函数的引用返回值：

```cpp
#include&#60;iostream&#62;
using namespace std;
int & valplus(int &a);
int main()
{
    int num1 = 10;
    int num2;
    num2 = valplus(num1);
    cout&#60;&#60;num1&#60;&#60;" "&#60;&#60;num2&#60;&#60;endl;
    return 0;
}
int & valplus(int &a)
{
    a = a + 5;
    return a;
}
```

此外，我们还需要注意一个小问题。如果我们将例5中的valplus函数定义成例6中所示的形式，那么这段程序就会产生一个问题，变量b的作用域仅在这个valplus函数体内部，当函数调用完成，b变量就会被销毁。而此时我们若将b变量的值通过引用返回拷贝给变量num2的时候，有可能会出现在拷贝之前b变量已经被销毁，从而导致num2变量获取不到返回值。虽然这种情况在一些编译器中并没有发生，但是我们在设计程序的时候也是应该尽量避免这一点的。

在例4和例5中，我们就是为了避免这一点才采用的引用传递参数。普通的传值返回则不存在这样的问题，因为编译器会将返回值拷贝到临时存储空间后再去销毁b变量的。

[例6]一个可能获取不到返回值的例子：(声明记得改)

```cpp
int & valplus(int a)
{
    int b = a+5;
    return b;
}
```
此教程来自C语言中文网