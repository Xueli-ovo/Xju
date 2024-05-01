//hpCardGame - main.cpp
//(C) Xueliovo
//此文件定义了主程序.

#include <bits/stdc++.h>
#include <ncurses.h>
#include <locale>

using namespace std;
#define NAME "hpCardGame"
#define VERSION "Dev 1.2"

int shell(string command);

int main()
{
	setlocale(LC_ALL, "zh_CN.UTF-8");

	cout<<NAME<<VERSION<<endl;

	cout<<"*小贴士*你编译好的程序放在\"hpCardGame\"目录里了吗?\n*这很重要*"<<endl;
	
	//调试完记得要改回来!
	//shell("game");
	shell("");

	return 0;
}
