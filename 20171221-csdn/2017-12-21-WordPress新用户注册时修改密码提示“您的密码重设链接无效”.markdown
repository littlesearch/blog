---
layout: post
title: "WordPress新用户注册时/修改密码提示“您的密码重设链接无效”"
date: 2017-12-21 20:36:54 +0800
comments: true
categories: WordPress
tags: [WordPress]
keyword: WordPress
description:  
---


在使用Wordpress密码找回功能及新用户注册邮件中的重置密码链接时，Wordpress提示“您的密码重设链接无效，请在下方请求新链接。”、“该key似乎无效”、“invalid key”。

也就是出现如下问题:
![](https://i.imgur.com/NblzOs8.png)  

这个其实是链接出现了问题，你会发现你打开的链接最后多了一个">"号。
![](https://i.imgur.com/IvSXsiH.png) 

http://chenhaoxiang.cn/wp-login.php?action=rp&amp;key=n1wUXmApeFNFWFOogtLo&login=chx

在这里，我的链接出来">"这个问题外，还有中间的"amp;"的问题，经过测试，此字段为QQ邮箱的问题，换邮箱就没有这个问题了。

有如下两种修改方式:  
第一种，是去修改Wordpress的源码
![](https://i.imgur.com/XdgOmHq.png)  
找到:
```php
	$message .= '<' . network_site_url("wp-login.php?action=rp&key=$key&login=" . rawurlencode($user_login), 'login') . ">\r\n";
```
![](https://i.imgur.com/n0eiD4A.png)
修改为:
```php
	$message .= network_site_url("wp-login.php?action=rp&key=$key&login=" . rawurlencode($user_login), 'login') . "\r\n";
```


第二种就是修改主题的functions.php文件内容：
```php
/**
* 修复WordPress找回密码提示“抱歉，该key似乎无效”问题
*/
function reset_password_message( $message, $key ) {
    if ( strpos($_POST['user_login'], '@') ) {
    $user_data = get_user_by('email', trim($_POST['user_login']));
} else {
    $login = trim($_POST['user_login']);
    $user_data = get_user_by('login', $login);
}
    $user_login = $user_data->user_login;
    $msg = __('有人要求重设如下帐号的密码：'). "\r\n\r\n";
    $msg .= network_site_url() . "\r\n\r\n";
    $msg .= sprintf(__('用户名：%s'), $user_login) . "\r\n\r\n";
    $msg .= __('若这不是您本人要求的，请忽略本邮件，一切如常。') . "\r\n\r\n";
    $msg .= __('要重置您的密码，请打开下面的链接：'). "\r\n\r\n"; 
    $msg .=  network_site_url("wp-login.php?action=rp&key=$key&login=" . rawurlencode($user_login), 'login') . "\r\n\r\n";
    $msg .=  "提示:若打开链接提示key无效，链接中若有'amp;'字符，请删除该4个字符再访问" ;
    return $msg;
}
add_filter('retrieve_password_message', reset_password_message, null, 2);
////////////

```

将该方法直接加入到functions.php文件内即可。
建议添加到第一行的
```
<?php
```
后面  
  
![](https://i.imgur.com/BgYGqQF.png)  

注意:
第一种方法在每次升级Wordpress后会被覆盖，需要重新修改。
第二种方法是修改主题，所有在更换主题后，需要重新修改。 

感谢 http://www.cnblogs.com/liudecai/p/6474611.html 的博主提供的方式


本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn/2017/12/21/2056/'><font color="green">http://chenhaoxiang.cn/2017/12/21/2056/</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>谙忆的博客</a>】</strong></p>
</blockquote>

