#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_FACADE_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_FACADE_PATTERN_H

#include <iostream>

namespace design_pattern {
/*
外观模式是为复杂的子系统提供一个统一的接口
如打开计算机的操作，需要打开计算机主机，鼠标，显示器等各种子系统
外观模式只提供一个简单的接口统一操作
*/

class MainCore {
public:
    void open() {
        std::cout<<"open main core"<<std::endl;
    }
};

class Mouse {
public:
    void open() {
        std::cout<<"open mouse"<<std::endl;
    }
};

class Monitor {
public:
    void open() {
        std::cout<<"open monitor"<<std::endl;
    }
};

class Computer {
public:
    void open() {
        main_core.open();
        mouse.open();
        monitor.open();
        std::cout<<"computer is open"<<std::endl;
    }
private:
    MainCore main_core;
    Mouse mouse;
    Monitor monitor;
};

} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_FACADE_PATTERN_H
