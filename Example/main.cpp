#include <bits/stdc++.h>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component.hpp>

int main(void){
    using namespace ftxui;

    double gpoint=0.5;
    int a=gpoint*100.0;
    std::string gptext=std::to_string(a)+"%";

    Element titlebox=hbox({text("我的示例 1")| border,text("垂直布局与水平布局")|border});
    Element myBox=hbox({text("这是一只进度条")| border,gauge(gpoint)|color(Color::BlueLight)|border,text(gptext)|color(Color::Yellow)|border});
    Element appView=vbox({titlebox,myBox})|border;

    auto screen = Screen::Create(Dimension::Full(),Dimension::Fit(appView));
    Render(screen,appView);
    screen.Print();

    return EXIT_SUCCESS;
}
