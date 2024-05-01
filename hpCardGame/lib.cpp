//lib.cpp
//(C) Xueliovo
//此文件定义了大部分的类库,供 main.cpp 使用.


#include <bits/stdc++.h>
#include <ncursesw/ncurses.h>
#include <locale>

#define NAME "hpCardGame"
#define VERSION "Dev 1.2"

class libtalk {
public:
    //具体对话
    std::string welcome = "欢迎来到hpCardGame!\n";
    std::string event = "游戏未开始.按下[P]进行基本设置,按下[S]开始游戏.";
    std::string jianwei_main = "[Q]退出 [D]教程 [S]开始游戏 [R]刷新界面 [P]设置";//键位提示-主要
    //~具体对话
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
        else if (com=="ver"){
            //打印版本
            std::cout<<NAME<<VERSION<<std::endl;
        }
        else if (com=="echo"){
            //复读机喵~
            std::cout<<"复读机:";
            std::cin>>str;

            std::cout<<str<<std::endl;
        }
        else{
            //不正确的命令.
            std::cout<<"shell:命令未找到.\n";
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
            ?\t显示此帮助信息\n\
            command\t显示Shell帮助\n";
        }
        else if (status=="command"){
            std::cout<<"可用Shell命令:\n\
            help\t进入帮助程序\n\
            ver\t显示游戏版本\n\
            exit\t退出当前Shell\n\
            shell\t进入新的Shell\n\
            game\t进入游戏\n\
            echo\t复读机\n";
        }
        else {
            std::cout << "参数不正确,尝试输入?试试.\n";
        }
    }
};

class Player {
	public:
		std::string name="Player";//玩家名字
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

class Game{
    public:

    int scrX, scrY;
    bool is_running=false;
    int time;
    int map=1;
    libtalk a;
    Player one;

    Game(bool debug=false){
        

        setlocale(LC_ALL,"zh_CN.UTF-8");
        initscr();
        noecho();
        cbreak();
        getmaxyx(stdscr,scrY,scrX);

        if (scrY<20 || scrX<65){
            clear();
            move(0,0);
            printw("屏幕大小不够,程序退出.\n");
            return;
        }
        start_color();

        if(debug){
            move(scrX/2-1,scrY/2-1);
            printw("Max x=%d,Max y=%d",scrY,scrX);
            refresh();
        }

        move(0,0);
        printw(a.welcome.c_str());//欢迎消息

        basic_interface();
        main_interface();
        listen();

        getch();

    }



    int basic_interface(){
        move(0,0);
        printw(a.welcome.c_str());//欢迎消息

        //绘制界面
        //move(y,x)
        move(3,0);
        for (int i=0;i<scrX;i++)printw("=");
        move(scrY-5,0);
        for (int i=0;i<scrX;i++)printw("=");
        //绘制界面-键位提示
        move(2,0);
        printw(a.jianwei_main.c_str());
        move(scrY-3,0);
        printw(a.event.c_str());
        refresh();

        return 0;
    }

    int main_interface(){
        move(4,0);
        printw("玩家名:%s\n",one.name.c_str());
        printw("关卡:%d",map);

        return 0;
    }

    int listen(){
        int ch;
        char name[100]; // 用来存储用户输入的名字
        int name_index = 0; // 用户输入的名字的索引
        if (!is_running){
            //获取主界面按键
            while (true)
            {
                ch = getch();
                if (ch=='q' || ch=='Q'){
                    return 0;
                }
                else if (ch=='r' || ch=='R'){
                    interface();
                    refresh();
                }
                else if (ch=='p' || ch=='P'){
                    //获取用户输入
                    move(4,0);
                    printw("请在这里输入你的玩家名字:");
                    refresh();

                    echo(); // 启用回显，让用户输入的字符显示在屏幕上
                    while ((ch = getch()) != '\n' && name_index < 99) {
                        name[name_index++] = ch;
                        refresh();
                    }
                    name[name_index] = '\0'; // 添加字符串结束符
                    noecho(); // 禁用回显
                    name_index = 0;
                    one.name=name;
                    clrtoeol();

                    main_interface();
                    refresh();
                     // 重置名字索引
                }
                else if (ch=='d' || ch=='d'){
                    move(4,0);
                    printw("选择一个文档以打开:\n1.主文档\n2.咒语表\n输入编号:");

                    echo();
                    ch=getch();
                    if (ch=='1')prt_doc("./doc/main.txt");
                    if (ch=='2')prt_doc("./doc/spell.txt");

                    interface();
                }
            }
            
        }
    }

    int interface(){
        clear();
        basic_interface();
        main_interface();
        refresh();

        return 0;
    }

    int prt_doc(std::string path){
        int ch;
        clear();
        noecho();
        move(0,0);
        //获取本地教程文档
        //打开文件并判断是否打开
        std::ifstream file;
        file.open(path.c_str(),std::ios::in);
        if (file.is_open()) printw("打开文档成功:%s\n---按下键翻页---\n",path.c_str());
        else 
        {
            printw("打开文档失败.\n可能是:\n1.输入的文档名称有误.\n2.没有权限.\
            \n3.程序放置的位置不对(路径错误)\n请重新检查!\n");
            getch();
            file.close();
            return 8;
        }

        std::string line;
        int line_count = 0;
        while (std::getline(file, line)) {
            if (line_count == page_size) {
                int ch = getch();
                if (ch == KEY_DOWN) {
                    clear();
                    line_count = 0;
                } else if (ch == KEY_UP) {
                    for (int i = 0; i < page_size; ++i) {
                        if (std::getline(file, line)) {
                            printw("%s\n", line.c_str());
                        }
                    }
                    refresh();
                    line_count = page_size;
                }
            }
            printw("%s\n", line.c_str());
            getch();
            refresh();
            clrtoeol();
            refresh();
            line_count++;
        }
        printw("\n按下\"Q\"退出...");
        ch=getch();
        while(ch!='q')ch=getch();

        return 0;
    }

    ~Game(){
        clear();
        printw("游戏将结束...\n按下任意键回到Shell\n");
        getch();
        endwin();
    }

    private:
    int page_size=10;
};


int shell(std::string command){
    libtalk one;
    
    if (command==""){
        std::string str;

        std::cout<<"\nhpCardGame Shell\n";
        std::cout<<one.welcome<<std::endl;
        std::cout<<"\n注意:这个Shell是为了好玩才搞的,本身没有任何功能捏\n进入真正的游戏就输入game吧!\
        想看看这个Shell就输入help吧!\n要离开,请输入exit吧!\n";

        while (true){
            std::cout<<"shell >";
            std::cin>>str;
            if (str=="shell"){
                return shell("");
            }
            else if (str=="exit"){
                return 0;
            }
            else if (str=="game"){
                Game *main=new Game();//参数里加上true可以调试哦!

                delete main;
            }
            else{
                one.main(str);
            }
        }
    }
    else if (command=="game"){
        Game *main=new Game();//参数里加上true可以调试哦!

        delete main;
    }
    else{
        one.main(command);
    }
}

void mainmenu(){
    //主菜单
    std::cout<<"hpCardGame 主菜单"<<std::endl;
    std::cout<<"=======\n";
    std::cout<<"[1]开始新的游戏\n";
    std::cout<<"[2]读取旧有存档\n";
    std::cout<<"[3]打开Shell\n";
    std::cout<<"退出请按其他任意键\n";
    std::cout<<"\n请选择:";

    char a=getchar();
    if (a=='1'){
        Game *main=new Game();

        delete main;
    }
    else if (a=='2'){
        //暂未开发
    }
    else if (a=='3'){
        shell("");
    }
    else{
        return;
    }
}

