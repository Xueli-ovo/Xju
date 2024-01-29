# 关于本程序

## 简介

这个程序**只是一个练习**哦,暂时还没有开发完毕!这个程序主要在于开发一些好玩的东东......

目前只有一个小小的加密小程序,你可以将参照下面的提示，将源码`clone`下来,然后编译运行~

## 加密小程序

### 原理及作用

使用`C++`编写,实现原理就是让输入的字符的`ASCII`码+1,相应的,解密时就将`ASCII`码-1.

举个例子:
当你输入
	abaaba
那它就会返回
	bcbbcb

### 编译及运行

要编译此程序,先确保你的操作系统为现代Linux发行版。*(例如:Ubuntu 20.04或更高版本)*

以Debian 系操作系统为例:

	#安装依赖库
	sudo apt install g++ cmake make gcc
	
	#克隆此存储库
	cd ~
	git clone https://github.com/Xueli-ovo/Xju
	
	#编译
	cd Xju/Jiami
	cmake .
	make

	#运行
	./Jiami

**感谢你的支持！**
