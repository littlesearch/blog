---
layout: post
title: "【5】JAVA---地址App小软件（DeletePanel.class）（表现层）"
date: 2016-03-31 12:17:11 +0800
comments: true
categories:❷ Java大学之行,----- ②、Java设计模块,----- ----- Java地址App
tags: [软件,app,界面,数据,class]
keyword: 陈浩翔, 谙忆
description: 删除地址的表现层类。 
如果没有选中要删除的地址信息，会出现窗口提示： 
删除地址界面：（无法修改数据，只能看） 
/*
 * DeletePanel.java
 *
 */package cn.hncu.addr.ui;import javax.swing.JFrame;
import javax.swing.JOptionPane;import cn.hncu.addr.business.Add 
---


删除地址的表现层类。 
如果没有选中要删除的地址信息，会出现窗口提示： 
删除地址界面：（无法修改数据，只能看） 
/*
 * DeletePanel.java
 *
 */package cn.hncu.addr.ui;import javax.swing.JFrame;
import javax.swing.JOptionPane;import cn.hncu.addr.business.Add
&#60;!-- more --&#62;
----------

删除地址的表现层类。
如果没有选中要删除的地址信息，会出现窗口提示：
![](http://img.blog.csdn.net/20160331001617173)

删除地址界面：（无法修改数据，只能看）
![](http://img.blog.csdn.net/20160331001651204)

```java
/*
 * DeletePanel.java
 *
 */

package cn.hncu.addr.ui;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

import cn.hncu.addr.business.AddrBusiness;

/**
 *
 * @author  __chx__
 */
public class DeletePanel extends javax.swing.JPanel {
	private JFrame mainFrame = null;
	private String oldStrAdd = null;

	
	public DeletePanel(JFrame mainFrame, String oldStrAdd) {
		this.mainFrame = mainFrame;
		this.oldStrAdd = oldStrAdd;
		initComponents();

		myInitComponents();
	}

	private void myInitComponents() {
		String[] oldstrs = oldStrAdd.split(",");
		String oldname = oldstrs[0];
		String oldxingbie = oldstrs[1];
		String oldage = oldstrs[2];
		String olddianhua = oldstrs[3];
		String oldaddress = oldstrs[4];

		jtfName.setText(oldname);
		jtfxingbie.setText(oldxingbie);
		jtfAge.setText(oldage);
		jtfDianhua.setText(olddianhua);
		jtfAddress.setText(oldaddress);
		
		
		jtfName.setEditable(false);
		jtfxingbie.setEditable(false);
		jtfAge.setEditable(false);
		jtfDianhua.setEditable(false);
		jtfAddress.setEditable(false);

	}

	
	private void initComponents() {

		jLabel2 = new javax.swing.JLabel();
		jtfName = new javax.swing.JTextField();
		jlbName1 = new javax.swing.JLabel();
		jlbxingbie = new javax.swing.JLabel();
		jlbAge = new javax.swing.JLabel();
		jlbDianhau = new javax.swing.JLabel();
		jlbAddress = new javax.swing.JLabel();
		jtfAddress = new javax.swing.JTextField();
		jtfDianhua = new javax.swing.JTextField();
		jtfAge = new javax.swing.JTextField();
		jtfxingbie = new javax.swing.JTextField();
		jbtnsure = new javax.swing.JButton();
		jbtnreturn = new javax.swing.JButton();

		setMinimumSize(new java.awt.Dimension(800, 600));
		setLayout(null);

		jLabel2.setFont(new java.awt.Font("Microsoft YaHei UI", 3, 48));
		jLabel2.setForeground(new java.awt.Color(255, 51, 0));
		jLabel2.setText("\u5220\u9664\u5730\u5740\u4fe1\u606f");
		add(jLabel2);
		jLabel2.setBounds(230, 20, 330, 90);
		add(jtfName);
		jtfName.setBounds(200, 160, 130, 23);

		jlbName1.setFont(new java.awt.Font("Microsoft YaHei UI", 1, 18));
		jlbName1.setText("\u59d3\u540d\uff1a");
		add(jlbName1);
		jlbName1.setBounds(140, 150, 60, 40);

		jlbxingbie.setFont(new java.awt.Font("Microsoft YaHei UI", 1, 18));
		jlbxingbie.setText("\u6027\u522b\uff1a");
		add(jlbxingbie);
		jlbxingbie.setBounds(140, 190, 60, 40);

		jlbAge.setFont(new java.awt.Font("Microsoft YaHei UI", 1, 18));
		jlbAge.setText("\u5e74\u9f84\uff1a");
		add(jlbAge);
		jlbAge.setBounds(140, 230, 60, 40);

		jlbDianhau.setFont(new java.awt.Font("Microsoft YaHei UI", 1, 18));
		jlbDianhau.setText("\u7535\u8bdd\uff1a");
		add(jlbDianhau);
		jlbDianhau.setBounds(140, 270, 60, 40);

		jlbAddress.setFont(new java.awt.Font("Microsoft YaHei UI", 1, 18));
		jlbAddress.setText("\u5730\u5740\uff1a");
		add(jlbAddress);
		jlbAddress.setBounds(140, 310, 60, 40);
		add(jtfAddress);
		jtfAddress.setBounds(200, 320, 410, 23);
		add(jtfDianhua);
		jtfDianhua.setBounds(200, 280, 330, 23);
		add(jtfAge);
		jtfAge.setBounds(200, 240, 260, 23);
		add(jtfxingbie);
		jtfxingbie.setBounds(200, 200, 190, 23);

		jbtnsure.setFont(new java.awt.Font("Microsoft YaHei UI", 1, 24));
		jbtnsure.setForeground(new java.awt.Color(255, 0, 51));
		jbtnsure.setText("\u5220\u9664");
		jbtnsure.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				jbtnsureActionPerformed(evt);
			}
		});
		add(jbtnsure);
		jbtnsure.setBounds(140, 430, 110, 70);

		jbtnreturn.setFont(new java.awt.Font("Microsoft YaHei UI", 1, 24));
		jbtnreturn.setForeground(new java.awt.Color(0, 204, 204));
		jbtnreturn.setText("\u53d6\u6d88");
		jbtnreturn.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				jbtnreturnActionPerformed(evt);
			}
		});
		add(jbtnreturn);
		jbtnreturn.setBounds(490, 430, 110, 70);
	}

	private void jbtnreturnActionPerformed(java.awt.event.ActionEvent evt) {
		mainFrame.setContentPane(new ListPanel(mainFrame));
		mainFrame.validate();
	}

	private void jbtnsureActionPerformed(java.awt.event.ActionEvent evt) {
		// 表现层代码的基本写法

		// 3.调用逻辑层
		AddrBusiness set = new AddrBusiness();
		boolean flag = set.delete(oldStrAdd);

		// 4.根据逻辑层的返回结果，导向不同的结果界面
		if (flag) {
			mainFrame.setContentPane(new ListPanel(mainFrame));
			mainFrame.validate();
		} else {
			JOptionPane.showMessageDialog(this, "温馨提示：\n本次删除失败!\n请自行检查错误！");
		}

	}

	private javax.swing.JLabel jLabel2;
	private javax.swing.JButton jbtnreturn;
	private javax.swing.JButton jbtnsure;
	private javax.swing.JLabel jlbAddress;
	private javax.swing.JLabel jlbAge;
	private javax.swing.JLabel jlbDianhau;
	private javax.swing.JLabel jlbName1;
	private javax.swing.JLabel jlbxingbie;
	private javax.swing.JTextField jtfAddress;
	private javax.swing.JTextField jtfAge;
	private javax.swing.JTextField jtfDianhua;
	private javax.swing.JTextField jtfName;
	private javax.swing.JTextField jtfxingbie;

}
```