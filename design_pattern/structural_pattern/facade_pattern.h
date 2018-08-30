#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_FACADE_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_FACADE_PATTERN_H

#include <iostream>

namespace design_pattern {
/*
���ģʽ��Ϊ���ӵ���ϵͳ�ṩһ��ͳһ�Ľӿ�
��򿪼�����Ĳ�������Ҫ�򿪼������������꣬��ʾ���ȸ�����ϵͳ
���ģʽֻ�ṩһ���򵥵Ľӿ�ͳһ����
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
