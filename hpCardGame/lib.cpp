//lib.cpp
//(C) Xueliovo
//此文件定义了大部分的类库,供 main.cpp 使用.




#include <bits/stdc++.h>
#include <ncurses.h>


class info {
public:
    // 版本信息
    std::string ver = "0.0.1";
    
    int GetVersion(int version = 0) const {
        std::cout << "CardGame Version " << (version == 0 ? ver : std::to_string(version)) << std::endl;
        std::cout << "(C) Xueliovo\n";
        return version;
    }

    // 游戏名字
    std::string name = "hpCardGame";
};

class libtalk {
public:
    std::string welcome = "欢迎来到hpCardGame!\n输入\"help new\"获取新手帮助.";
    int main(std::string com){
	    //此方法用于处理用户输入的命令.
    }



protected:

    void GetHelp(std::string status) {
        std::string ver = "0.0.1";
        std::cout << "帮助实用工具. v" << ver << std::endl;

        if (status == "version") {
            std::cout << "帮助实用工具\n-------------------\n"
                      << "Version " << ver << std::endl;
        } else if (status == "new") {
            std::cout << "欢迎来到hpCardGame,这里是新手教程." << std::endl;
            std::cout << "-------------------" << std::endl;
            std::cout << "基础玩法:\n游戏人数两人,您的目标是击败对手.\n";
            std::cout << "游戏开始时,会先指定玩家名,您需要输入您和对手的名字以开始游戏.\n";
            std::cout << "在游戏中,双方会抽取手牌,您要利用手上的牌来击败对手\n";
            std::cout << "同时,双方出牌会受到体力的限制,使得您要慎重思考如何出牌.\n\n";
	    std::cout << "下面，请您观看一段演示\n";
        } else {
            std::cout << "参数不正确,尝试运行help ?试试.\n";
        }
    }
};

class player {
	public:
		std::string name;//玩家名字
		std::string chara;

		int HP;//血量
		int MP;
		int AP;
		int DP;
}




int shell(){
	libtalk one;
	std::cout<<"hpCardGame Shell\n";
	std::cout<<one.welcome<<endl;

	while (true){
		std::cout<<"shell >";
		std::cin>>one.main;
	}

