#include <iostream>
#include <string>
using namespace std;

// 加密函数
string encrypt(const string& input) {
    string result = input;
    for (char &c : result) {
        c = c + 1; // 每个字符的ASCII码值加1
    }
    return result;
}

// 解密函数
string decrypt(const string& input) {
    string result = input;
    for (char &c : result) {
        c = c - 1; // 每个字符的ASCII码值减1
    }
    return result;
}

int main() {

    int choice;
    string input;

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
                cout << "Jiami Tools : 请输入需要加密的字符串 > ";
                cin >> input;
                cout << "Jiami Tools : 加密后的字符串为 : " << encrypt(input) << endl;
                break;
            case 2:
                cout << "Jiami Tools : 请输入需要解密的字符串 > ";
                cin >> input;
                cout << "Jiami Tools : 解密后的字符串 : " << decrypt(input) << endl;
                break;
            case 3:
                cout << "Jiami Tools : 退出.\n";
                cout << "感谢您的使用，接下来您将返回Shell.\n";
                return 0;
            case 4:
                cout << "Jiami Tools : 操作提示\n1.加密\n2.解密\n3.退出\n4.显示此帮助信息\n";
                break;
            default:
                cout << "Jiami Tools : 输入的命令好像不对.\n";
                break;
        }
    }

    return 0;
}
