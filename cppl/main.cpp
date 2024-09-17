#include <bits/stdc++.h>

using namespace std;

int note01();

int main(){

    cout << "欢迎来到C++个人学习笔记!\n";
    cout << "输入笔记对应的数字或字母,进入案例学习\n\n";

    cout << "[1]数据类型与 sizeof 关键字.\n";

    cout<<"按下[q]直接退出\n";
    cout<<"按下任意其他按键进入小程序\n";

    int a=getchar();
    if (a=='1') note01();
    else if (a=='q' || a =='Q') return 0;

    cout<<"\n------------\n";
    cout<<"欢迎来到小程序!输入字母进入互动\n\n";

    cout<<"按下[q]直接退出\n";
    cout<<"按下任意其他按键进入笔记\n";

    a=getchar();
    if (a=='q' || a =='Q') return 0;

    main();
}