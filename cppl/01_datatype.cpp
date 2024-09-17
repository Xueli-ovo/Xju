#include <bits/stdc++.h>

using namespace std;

int note01(){
    cout<<"第一课\t数据类型\n";
    cout<<"\n1)sizeof\n"<<"可以用于求出数据类型占多少字节\n";

    cout<<"\n2)整型\n"<<"分为short,int,long,long long\n";

    cout<<"\n3)浮点型\n"<<"分为float和double\n";
    cout<<"默认情况编译器认为是双精度,两个类型的区别在于有效数字范围的不同.\n";
    cout<<"单精度数字后面需要加f,如3.14f\n";
    cout<<"科学记数法,3e2等于3x10^2\n";

    cout<<"\n4)字符型\n"<<"关键字char,作用是存储单个字符.\n";
    cout<<"示例:\'a\',使用单引号括起来,并只有一个字符.\n";

    cout<<"\n5)转义字符\n"<<"用于表示一些不能显示出来的ASCII字符\n";
    cout<<"现阶段我们常用的转义字符有： \\n \\\\ \\t \n";

    cout<<"\n6)字符串型\n"<<"用于表示一串字符\n";
    cout<<"C风格字符串:\tchar a[]=\"text\";\n";
    cout<<"C++风格字符串:\tstring a=\"text\";\n";
    cout<<"注意:第二种方法需要头文件std.\n";

    cout<<"\n7)布尔类型\n"<<"布尔数据类型代表真或假的值\n";
    cout<<"只有两个值,ture和false,本质上是0和1\n";

    cout<<"\n\n笔记回顾完成!\n\n";

    return 0;
}