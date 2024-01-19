#include <iostream>
#include <string>
#include<stdlib.h>
using namespace std;

// 加密函数
string encrypt(string input) {
    for (int i = 0; i < input.length(); i++) {
        input[i] = input[i] + 1; // 每个字符的ASCII码值加1
    }
    return input;
}

// 解密函数
string decrypt(string input) {
    for (int i = 0; i < input.length(); i++) {
        input[i] = input[i] - 1; // 每个字符的ASCII码值减1
    }
    return input;
}

int main() {
    
    int ask1;
    string input;

    cout<<"---------------------------------\n";
    cout<<"加密解密实用工具 1.0             \n";
    cout<<"---------------------------------\n";

    cout<<"欢迎使用！\n请选择想要进行的操作：\n1.加密\n2.解密\n3.退出\n4.显示此提示消息\n";
ASK:
    cout<<"Jiami Tools : 输入4来获取帮助.\n";
    cout<<"Jiami Tools : (1,2,3,4) > ";
    cin>>ask1;
    if (ask1==1)
    {
	cout << "Jiami Tools : 请输入需要加密的字符串 > ";
    	cin>>input;
	system("clear");

    	string encrypted = encrypt(input);
    	cout << "Jiami Tools : 加密后的字符串为 : " << encrypted << endl;
	goto ASK;
    }
    else if (ask1==2)
    {
        cout << "Jiami Tools : 请输入需要解密的字符串 > ";
        cin>>input;

	string decrypted = decrypt(input);
        cout << "Jiami Tools : 解密后的字符串 : " << decrypted << endl;
	goto ASK;
    }
    else if (ask1==3)
    {
	system("clear");
	cout<<"Jiami Tools : 退出.\n";
	cout<<"感谢您的使用，接下来您将返回Shell.\n";
	return 1;
    }
    else if (ask1==4)
    {
	cout<<"Jiami Tools : 操作提示\n1.加密\n2.解密\n3.退出\n4.显示此帮助信息\n";
	goto ASK;
    }
    else
    {
	cout<<"Jiami Tools : 输入的命令好像不对.";
	goto ASK;
    }
    
    return 0;
}
