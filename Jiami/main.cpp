#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

// 加密函数 - 加密算法1
string encryptAlgorithm1(const string& input) {
    string result = input;
    for (char &c : result) {
        c = c + 2; // 每个字符的ASCII码值加1
	if (c > 126) {
            c = c % 126 + 32; // 确保加密后的字符在可显示字符的范围内
        }
    }
    return result;
}

// 加密函数 - 加密算法2
string encryptAlgorithm2(const string& input) {
    string result = input;
    for (char &c : result) {
        c = c * 2; // 每个字符的ASCII码值乘以2
	if (c > 126) {
            c = c % 126 + 32; // 确保加密后的字符在可显示字符的范围内
        }
    }
    return result;
}

// 解密函数 - 解密算法1
string decryptAlgorithm1(const string& input) {
    string result = input;
    for (char &c : result) {
        c = c - 2; // 每个字符的ASCII码值减1
    }
    return result;
}

// 解密函数 - 解密算法2
string decryptAlgorithm2(const string& input) {
    string result = input;
    for (char &c : result) {
        c = c / 2; // 每个字符的ASCII码值除以2
    }
    return result;
}

int main() {

    int choice, algorithmChoice;
    string input;
    
    system("clear");

    cout << "---------------------------------\n";
    cout << "加密解密实用工具 1.0             \n";
    cout << "---------------------------------\n";

    cout << "欢迎使用！\n请选择想要进行的操作：\n1.加密\n2.解密\n3.退出\n4.显示此提示消息\n";

    while (true) {
        cout << "Jiami Tools : 输入4来获取帮助.\n";
        cout << "Jiami Tools : (1,2,3,4) > ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Jiami Tools : 请选择加密算法 : \n1. 加密算法1\n2. 加密算法2\n";
		cout << ">";
                cin >> algorithmChoice;
                cout << "Jiami Tools : 请输入需要加密的字符串 > ";
                cin >> input;
                if (algorithmChoice == 1) {
                    cout << "\nJiami Tools : 加密后的字符串为 : " << encryptAlgorithm1(input) << endl;
		    cout << "Jiami Tools : 请记住你现在使用的算法编号为1\n";
                } else if (algorithmChoice == 2) {
                    cout << "\nJiami Tools : 加密后的字符串为 : " << encryptAlgorithm2(input) << endl;
		    cout << "\n请注意,该加密算法生成的字符串无法解密,相关事项请输入4查看说明.\n";
                } else {
                    cout << "\nJiami Tools : 无效的算法选择\n";
                }
                break;
            case 2:
                cout << "\nJiami Tools : 解密算法目前仅支持编号为1的算法:\n1. 解密算法1\n2.回到菜单\n";
		cout << "Jiami Tools : 输入编号 >";
                cin >> algorithmChoice;
                cout << "\nJiami Tools : 请输入需要解密的字符串 > ";
                cin >> input;
                if (algorithmChoice == 1) {
                    cout << "Jiami Tools : 解密后的字符串 : " << decryptAlgorithm1(input) << endl;
                } else if (algorithmChoice == 2) {
                    break;
                } else {
                    cout << "Jiami Tools : 无效的选择\n";
                }
                break;
            case 3:
		system("clear");
                cout << "Jiami Tools : 退出.\n";
                cout << "感谢您的使用，接下来您将返回Shell.\n";
                return 0;
            case 4:
		system("clear");
                cout << "Jiami Tools : 操作提示\n1.加密\n2.解密\n3.退出\n4.显示此帮助信息\n";
		cout << "有关加密算法的信息:\n加密算法1:安全性一般，容易被破解，可以解密.\n加密算法2:安全性较高,不能通过密文破解明文,因此适合用在软件中核对用户密码\n \n";
                break;
            default:
                cout << "Jiami Tools : 输入的命令好像不对.\n";
                break;
        }
    }

    return 0;
}

