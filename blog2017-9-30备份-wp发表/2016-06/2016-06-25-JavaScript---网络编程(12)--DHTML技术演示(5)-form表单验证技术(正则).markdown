---
layout: post
title: "JavaScript---网络编程(12)--DHTML技术演示(5)-form表单验证技术(正则)"
date: 2016-06-25 11:04:54 +0800
comments: true
categories:❷ Java大学之行,----- ④、Web学习之旅,----- ----- HTML/CSS/JS网络编程
tags: [网络编程,javascript,技术,表单,正则]
keyword: 陈浩翔, 谙忆
description: 这里不进行很复杂的后台验证以及JavaScript的正则表达式，只是简单的介绍下这个技术，简单的后台接收与跳转，大概了解怎么验证的就可以。具体的技术，我后面还会继续写博客的。本人也还在学习中。表单验证1-简单验证进行简单的验证，用户名必须为abcd，密码长度必须大于等于6 
然后根据用户输入的数据，在后面给出提示。代码演示：<html>
    <head>
        <title>DHTML 
---


这里不进行很复杂的后台验证以及JavaScript的正则表达式，只是简单的介绍下这个技术，简单的后台接收与跳转，大概了解怎么验证的就可以。具体的技术，我后面还会继续写博客的。本人也还在学习中。表单验证1-简单验证进行简单的验证，用户名必须为abcd，密码长度必须大于等于6 
然后根据用户输入的数据，在后面给出提示。代码演示：&#60;html&#62;
    &#60;head&#62;
        &#60;title&#62;DHTML
&#60;!-- more --&#62;
----------

这里不进行很复杂的后台验证以及JavaScript的正则表达式，只是简单的介绍下这个技术，简单的后台接收与跳转，大概了解怎么验证的就可以。具体的技术，我后面还会继续写博客的。本人也还在学习中。

表单验证1-简单验证
====
进行简单的验证，用户名必须为abcd，密码长度必须大于等于6
然后根据用户输入的数据，在后面给出提示。

代码演示：
-----

```
&#60;html&#62;
	&#60;head&#62;
		&#60;title&#62;DHTML技术演示---表单验证&#60;/title&#62;
		&#60;meta http-equiv="content-type" content="text/html; charset=UTF-8"/&#62;
		&#60;script&#62;
			function checkUserName(){
				//alert("aa");//测试这个失去焦点监听是否管用
				var oUserNameNode = document.getElementsByName("userName")[0];
				var name = oUserNameNode.value;//这个type="text"的value的值是方框内的字符
				//以后有后台时，“abcd”这个数据应该通过ajax技术向后台要
				//这里我们只是做简单的演示-就是填写的name必须是abcd
				if(name=="abcd"){
					document.getElementById("userNameSpan").innerHTML="用户名正确".fontcolor("green");
				}else{
					document.getElementById("userNameSpan").innerHTML="用户名错误".fontcolor("red");
				}
			}
			
			function checkPwd(){
				var oUserPwdNode = document.getElementById("pwd")[0];
				var pwd=oUserPwdNode.value;
				
				if(pwd.length>=6){
					document.getElementById("userPwdSpan").innerHTML="密码格式符合要求".fontcolor("green");
				}else{
					document.getElementById("userPwdSpan").innerHTML="密码长度必须大于等于6".fontcolor("red");					
				}
			}
			
		&#60;/script&#62;
		
	&#60;/head&#62;
	
	&#60;body&#62;
		&#60;form&#62;
			&#60;!--onblur 在对象失去输入焦点时触发。 --&#62;
			用户名:&#60;input type="text" name="userName" onblur="checkUserName()" /&#62;
			&#60;span id="userNameSpan"&#62;&#60;/span&#62;
			&#60;br/&#62;
			&#60;br/&#62;
			&#60;!--为了演示清楚，密码这里也用type="text"了，其实应该用type="password"的--&#62;
			密码:&#60;input type="text" name="pwd" onblur="checkPwd()" /&#62;
			&#60;span id="userPwdSpan"&#62;&#60;/span&#62;			
		&#60;/form&#62;
		
	&#60;/body&#62;
	
&#60;/html&#62;
```

360浏览器8.1 演示结果：
---------------
![](http://img.blog.csdn.net/20160625174213543)

用户名不符合规则：
![](http://img.blog.csdn.net/20160625174223899)

密码不符合规则：
![](http://img.blog.csdn.net/20160625174234336)


注册表单的验证2-正则表达式
==============

代码演示：
-----

```
&#60;html&#62;
	&#60;head&#62;
		&#60;title&#62;DHTML技术演示---注册表单的验证--js中使用正则表达式&#60;/title&#62;
		&#60;meta http-equiv="content-type" content="text/html; charset=UTF-8"&#62;
		&#60;script type="text/javascript"&#62;
			function checkUserName(){
				var oUserNameNode = document.getElementsByName("userName")[0];
				var userName = oUserNameNode.value;
				//用正则检验
				var reg = new RegExp("[a-z]{4}", "i");//包含4个连续的字母就可以，注意"i"的双引号不能省略
				//i---表示忽略大小写
				//var regg =new RegExp("^[a-z]{4}$","i") ;//只含4个连续的字母,注意"i"中的双引号不能省略
				//^代表开始   $代表结束
				
				var oUserNameSpan = document.getElementById("userNameSpan");
				//alert(reg.test(userName));
				
				if (reg.test(userName)) {
					oUserNameSpan.innerHTML = "用户名格式正确".fontcolor("green");
				}
				else {
					oUserNameSpan.innerHTML = "用户名格式错误".fontcolor("red");
				}
			}
		&#60;/script&#62;
	&#60;/head&#62;
	
	&#60;body&#62;
		&#60;!-- 演示JS中正则表达式的用法 --&#62;
		&#60;script type="text/javascript"&#62;
			//var reg = /^[0-9]{6}$/ ; //法一
			var reg = new RegExp("^[0-9]{6}$");//法二
			var str = "123456";
			var bRes = reg.test(str);
			//111使用正则表达式对象中的方法进行验证---只能用于判断是否匹配，功能类似于Java中的String类中的matches()方法
			//alert(bRes);//true
			
			//222使用String对象中的方法进行正则检验---功能更强大，类似于Java当中的Matcher工具
			var res = str.match(reg);//匹配的结果保存在res(是一个数组)中，如果没有匹配到则res为null。
			//alert(res);//123456
			//match方法返回的数组有三个属性：input、index和lastIndex。
			
			//★一点细节---使用new RegExp()方式时，特殊字符要转义
			//var reg2 =/^\d{6}$/;  //"\"不需要转义
			var reg2= new RegExp("^\d{6}$");//※※※注意"\"要转义
			//▲▲▲上面那句是错误的，必须要写成：new RegExp("^\\d{6}$")
			//alert( reg2.test("123456") );
		&#60;/script&#62;
		
		
		&#60;form&#62;
			&#60;!--onblur 在对象失去输入焦点时触发。 --&#62;
			用户名:&#60;input type="text" name="userName" onblur="checkUserName()" /&#62;
			&#60;span id="userNameSpan"&#62;&#60;/span&#62;
		&#60;/form&#62;
		
	&#60;/body&#62;
&#60;/html&#62;
```

360浏览器8.1 演示结果：
---------------
只需要包含连续4个字母就可以了。

![](http://img.blog.csdn.net/20160625202724116)

![](http://img.blog.csdn.net/20160625202732163)

![](http://img.blog.csdn.net/20160625202739516)


注册表单的验证且控制提交--前端校验:
===================

代码文件创建位置：
---------
![](http://img.blog.csdn.net/20160625222741068)


代码演示：
-----

&#60;font color="red" size="6"&#62;3form3.html&#60;/font&#62;
```
&#60;html&#62;
	&#60;head&#62;
		&#60;title&#62;DHTML技术演示---注册表单的验证且控制提交--前端校验&#60;/title&#62;
		&#60;meta http-equiv="content-type" content="text/html; charset=UTF-8"&#62;
		&#60;script type="text/javascript"&#62;
			function checkUserName(){
				var oUserNameNode = document.getElementsByName("userName")[0];
				var userName = oUserNameNode.value;
				//用正则检验
				var reg = new RegExp("[a-z]{4}","i");//包含4个连续的字母就可以，注意"i"的双引号不能省略
				//i---表示忽略大小写
				//var regg =new RegExp("^[a-z]{4}$","i") ;//只含4个连续的字母,注意"i"中的双引号不能省略
				//^代表开始   $代表结束
				
				var oUserNameSpan = document.getElementById("userNameSpan");
				if(reg.test(userName)){
					oUserNameSpan.innerHTML="用户名格式正确".fontcolor("green");
					return true;
				}else{
					oUserNameSpan.innerHTML="用户名格式错误".fontcolor("red");
					return false;					
				}
			}
			
			function checkPwd(){
				var oUserPwdNode = document.getElementsByName("pwd")[0];
				var pwd = oUserPwdNode.value;
				var reg2 = new RegExp("^[\\w\\d]{6,9}$");
				if(reg2.test(pwd)){
					document.getElementById("userPwdSpan").innerHTML="密码格式符合要求".fontcolor("green");
					return true;
				}else{
					document.getElementById("userPwdSpan").innerHTML="密码长度必须是6-9位的数字字母或下划线".fontcolor("red");
					return false;
					
				}
			}
			
			function checkUser(){
				if(checkUserName() && checkPwd() ){//如果还有其他项需要在提交前验证，直接把那个验证函数写这里就行
					return true;
				}else{
					return false;
				}
				
			}
			
		&#60;/script&#62;
		
	&#60;/head&#62;
	
	
	&#60;body&#62;
		&#60;!--通过注册onsubmit事件响应来控制表单的提交，如果return false则不会提交，而return true则会提交。如果不注册onsubmit事件即是return true
		onsubmit 当表单将要被提交时触发。 
  		&#60;form action="/myDhtmlProj/servlet/RegServlet" onsubmit="return true;"&#62;
  		--&#62;
		&#60;form action="/myDhtmlProj/servlet/RegServlet" onsubmit="return checkUser();"&#62;
			用户名：&#60;input type="text" name="userName" onblur="checkUserName()" /&#62;
			&#60;span id="userNameSpan"&#62;&#60;/span&#62;
			&#60;!--为了演示清楚，密码这里也用type="text"了，其实应该用type="password"的--&#62;
			密码：&#60;input type="text" name="pwd" onblur="checkPwd()" /&#62;
			&#60;span id="userPwdSpan"&#62;&#60;/span&#62;
			&#60;br/&#62;
			&#60;input type="submit" value="注册"/&#62;
		&#60;/form&#62;
		&#60;hr/&#62;
		
		&#60;!--表单提交方式2---自己写个按钮来代替form自带的提交按钮--&#62;
		&#60;form id="userinfo" action="/dhtmlProj/servlet/RegServlet" &#62;
			用户名:&#60;input type="text" name="userName" onBlur="checkUserName2()"/&#62;
			&#60;span id="userNameSpan2"&#62;&#60;/span&#62;&#60;br/&#62;
			密码:&#60;input type="text" name="pwd" onBlur="checkPwd2()"/&#62;
			&#60;span id="userPwdSpan2"&#62;&#60;/span&#62;
			&#60;br/&#62;
  		&#60;/form&#62;
		&#60;input type="button" value="注册" onclick="mySubmit()" /&#62;
		&#60;script type="text/javascript"&#62;
			function mySubmit(){
				var oFormNode = document.getElementById("userinfo");
				if(checkUserName2()&&checkPwd2()){
					oFormNode.submit();//submit 提交表单。 
				}
			}
			
			function checkUserName2(){
				var oUserNameNode = document.getElementsByName("userName")[1];
				var userName = oUserNameNode.value;
				//用正则检验
				var reg = new RegExp("[a-z]{4}","i");//包含4个连续的字母就可以，注意"i"的双引号不能省略
				//i---表示忽略大小写
				//var regg =new RegExp("^[a-z]{4}$","i") ;//只含4个连续的字母,注意"i"中的双引号不能省略
				//^代表开始   $代表结束
				
				var oUserNameSpan = document.getElementById("userNameSpan2");
				if(reg.test(userName)){
					oUserNameSpan.innerHTML="用户名格式正确".fontcolor("green");
					return true;
				}else{
					oUserNameSpan.innerHTML="用户名格式错误".fontcolor("red");
					return false;					
				}
			}
			
			function checkPwd2(){
				var oUserPwdNode = document.getElementsByName("pwd")[1];
				var pwd = oUserPwdNode.value;
				var reg2 = new RegExp("^[\\w\\d]{6,9}$");
				if(reg2.test(pwd)){
					document.getElementById("userPwdSpan2").innerHTML="密码格式符合要求".fontcolor("green");
					return true;
				}else{
					document.getElementById("userPwdSpan2").innerHTML="密码长度必须是6-9位的数字字母或下划线".fontcolor("red");
					return false;
					
				}
			}
			
		&#60;/script&#62;
		
	&#60;/body&#62;
&#60;/html&#62;
```


&#60;font color="red" size="6"&#62;show.jsp:&#60;/font&#62;

```
&#60;%@ page language="java" import="java.util.*" pageEncoding="utf-8"%&#62;
&#60;%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%&#62;

&#60;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"&#62;
&#60;html&#62;
	&#60;head&#62;
		&#60;title&#62;这是注册后的显示页面&#60;/title&#62;
	&#60;/head&#62;
	
	&#60;body&#62;
		&#60;%
			out.println(request.getAttribute("uName"));
			out.println(request.getAttribute("pwd"));
		 %&#62;
		&#60;%	
			for(int i=0;i&#60;3;i++){
			//这个下面可以写html代码
		%&#62;
			&#60;div&#62;欢迎&#60;/div&#62;
		&#60;% 
			//这个上面可以写html代码
			} 
		%&#62;
	&#60;/body&#62;
&#60;/html&#62;
```

&#60;font color="red" size="6"&#62;RegServlet.java&#60;/font&#62;
这个是new一个Servlet。
会自动给我们配好web.xml
![](http://img.blog.csdn.net/20160625223202570)

```
package cn.hncu.user;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class RegServlet extends HttpServlet {
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doPost(request, response);
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");//设置编码
		String name = request.getParameter("userName");//userName为提交过来的表单中的一个input的name属性
		String pwd = request.getParameter("pwd");
		//System.out.println(name);
		request.setAttribute("uName", "hncu---"+name);
		request.setAttribute("pwd", "pwd---"+pwd);
		
		request.getRequestDispatcher("/dhtml/6formsubmit/jsps/show.jsp").forward(request, response);
		//输出，导向另外的页面显示
	}

}

```

&#60;font color="red" size="6"&#62;web.xml&#60;/font&#62;

```
&#60;?xml version="1.0" encoding="UTF-8"?&#62;
&#60;web-app version="2.5" 
	xmlns="http://java.sun.com/xml/ns/javaee" 
	xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" 
	xsi:schemaLocation="http://java.sun.com/xml/ns/javaee 
	http://java.sun.com/xml/ns/javaee/web-app_2_5.xsd"&#62;
  &#60;display-name&#62;&#60;/display-name&#62;
  &#60;servlet&#62;
    &#60;description&#62;This is the description of my J2EE component&#60;/description&#62;
    &#60;display-name&#62;This is the display name of my J2EE component&#60;/display-name&#62;
    &#60;servlet-name&#62;RegServlet&#60;/servlet-name&#62;
    &#60;servlet-class&#62;cn.hncu.user.RegServlet&#60;/servlet-class&#62;
  &#60;/servlet&#62;

  &#60;servlet-mapping&#62;
    &#60;servlet-name&#62;RegServlet&#60;/servlet-name&#62;
    &#60;url-pattern&#62;/servlet/RegServlet&#60;/url-pattern&#62;
  &#60;/servlet-mapping&#62;	
  &#60;welcome-file-list&#62;
    &#60;welcome-file&#62;index.jsp&#60;/welcome-file&#62;
  &#60;/welcome-file-list&#62;
&#60;/web-app&#62;

```

360浏览器8.1 演示图片：
---------------

![](http://img.blog.csdn.net/20160625223313180)

当格式都填写正确时，点注册按钮，自动跳转到另外的页面。
![](http://img.blog.csdn.net/20160625223328211)

有一个格式错误时，点注册按钮不会有反应的。
![](http://img.blog.csdn.net/20160625223338211)

![](http://img.blog.csdn.net/20160625223346602)


注册表单的验证且控制提交--前端校验--最终版本:
=========================

代码演示：
-----

```
&#60;html&#62;
	&#60;head&#62;
		&#60;title&#62;DHTML技术演示---注册表单的验证且控制提交--前端校验--最终版本&#60;/title&#62;
		&#60;meta http-equiv="content-type" content="text/html; charset=UTF-8"/&#62;
		
		&#60;script type="text/javascript"&#62;
			function check(name,reg,spanId,okInfo,errInfo){
				var value = document.getElementsByName(name)[0].value;
				//用正则检验
				var oSpanNode = document.getElementById(spanId);
				if(reg.test(value)){
					oSpanNode.innerHTML=okInfo.fontcolor("green");
					return true;
				}else{
					oSpanNode.innerHTML=errInfo.fontcolor("red");
					return false;
				}
				
			}
			
			function checkUserName(){
				var reg = new RegExp("[a-z]{4}","i");//包含4个连续的字母,注意"i"中的双引号不能省略
				return check("userName",reg,"userNameSpan","用户名格式正确","用户名格式错误");
			}
			
			function checkPwd(){
				var reg = new RegExp("^[\\w\\d]{6,9}$");
				return check("pwd",reg,"userPwdSpan","密码格式符合要求","密码长度必须是6-9位的数字字母或下划线");
			}
			
			function checkPwd2(){
				var flag;
				var pwd = document.getElementsByName("pwd")[0].value;
				var pwd2 = document.getElementsByName("pwd2")[0].value;
				var oSpanNode = document.getElementById("userPwd2Span");
				if(pwd==pwd2){
					oSpanNode.innerHTML="两次密码一致".fontcolor("green");
					flag = true;
				}else{
					oSpanNode.innerHTML="两次密码不一致".fontcolor("red");
					flag = false;
				}
				return flag;
			}
			
			function checkMail(){
				var reg = /^\w+@\w+(\.\w+)+$/i;
				return check("mail",reg,"userMailSpan","邮箱格式正确","邮箱格式不正确");
			}
			
			function checkUser(){//控制表单的提交
				if(checkUserName() && checkPwd() && checkPwd2() && checkMail() ){
					return true;
				}else{
					return false;
				}
			}
			
		&#60;/script&#62;
		
		
	&#60;/head&#62;
	
	&#60;body&#62;
		&#60;form action="/myDhtmlProj/servlet/RegServlet" onsubmit="return checkUser();"&#62;
			用户名：&#60;input type="text" name="userName" onblur="checkUserName()" /&#62;
			&#60;span id="userNameSpan"&#62;&#60;/span&#62;
			&#60;br/&#62;
			输入密码：&#60;input type="text" name="pwd" onblur="checkPwd()" /&#62;
			&#60;span id="userPwdSpan"&#62;&#60;/span&#62;
			&#60;br/&#62;
			确认密码：&#60;input type="text" name="pwd2" onBlur="checkPwd2()"/&#62;
			&#60;span id="userPwd2Span"&#62;&#60;/span&#62;
			&#60;br/&#62;
			邮件地址：&#60;input type="text" name="mail" onblur="checkMail()" /&#62;
			&#60;span id="userMailSpan"&#62;&#60;/span&#62;
			&#60;br/&#62;
			&#60;input type="submit" value="注册"&#62;
		&#60;/form&#62;
		
		
		
	&#60;/body&#62;
&#60;/html&#62;
```


360浏览器8.1 演示结果：
---------------
![](http://img.blog.csdn.net/20160625230227110)

只有全部格式填写正确后再点注册按钮才会有响应。
![](http://img.blog.csdn.net/20160625230235958)

全部格式填写正确后，点注册按钮后的页面，其实就是跳到show.jsp页面了。（自己可以随便定位到哪的）
![](http://img.blog.csdn.net/20160625230243517)