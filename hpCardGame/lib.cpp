//lib.cpp
//(C) Xueliovo
//此文件定义了大部分的类库,供 main.cpp 使用.




#include <bits/stdc++.h>
#include <ncurses.h>

std::string NAME="\nhpCardGame\n";
std::string VERSION="\nDev 0.0.1\n";


class libtalk {
public:
    std::string welcome = "欢迎来到hpCardGame!\n输入\"help new\"获取新手帮助.";
    int main(std::string com){
	    //此方法用于处理用户输入的命令.
        //找到protected定义的命令里然后执行.
        std::string str;


        if (com=="help"){
            //获取参数.

            std::cout<<"\nhelp >";
            std::cin>>str;

            GetHelp(str);

        }
    }



protected:

    void GetHelp(std::string status) {
        //shell >help

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
        }
        else if (status=="?") {
            std::cout<<"可用参数:\n\
            version\t显示help命令的版本\n\
            new\t显示基本玩法并观看演示\n\
            ?\t显示此帮助信息\n";
        }
        else {
            std::cout << "参数不正确,尝试输入?试试.\n";
        }
    }
};

class player {
	public:
		std::string name;//玩家名字
		std::string chara;//角色名字

        /*

        HP--血量
        MP--魔力值
        AP--攻击
        DP--防御

        */

		int HP=150;
		int MP;
		int AP=5;
		double DP=0.2;
};

class game{
    public:

    bool is_running=false;
    int time;
    int map;
};


int shell(){
    std::string str;

	libtalk one;
	std::cout<<"hpCardGame Shell\n";
	std::cout<<one.welcome<<std::endl;

	while (true){
		std::cout<<"shell >";
		std::cin>>str;
        if (str=="shell"){
            return shell();
        }
        else if (str=="exit"){
            return 0;
        }
        else{
            one.main(str);
        }
	}
}


