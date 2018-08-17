#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_ADAPTER_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_ADAPTER_PATTERN_H

#include <iostream>

namespace design_pattern {
/*
适配器模式将一个类的接口转换成客户希望的另外一个接口，使得原本由于接口不兼容而不能一起工作的那些类可以一起工作
它包括类适配器和对象适配器
*/

// 类适配器:适配器与适配者是继承关系
class CalculateTarget {
public:
    virtual double calculate(double numa, double numb) {
        return numa + numb;
    }
};

class CalculateAdaptee {
public:
    double minus(double numa, double numb) {
        return numa - numb;
    }
};

class CalculateClassAdapter: public CalculateTarget, public CalculateAdaptee{
public:
    double calculate(double numa, double numb) {
        return minus(numa, numb);
    }
};

//对象适配器:适配器中包含适配者对象
//另外还有双向对象适配器（适配器中同时包含目标和适配者）
class CalculateObjectAdapter: public CalculateTarget{
public:
    double calculate(double numa, double numb) {
        return calc_adaptee.minus(numa, numb);
    }
private:
    CalculateAdaptee calc_adaptee;
};

//缺省适配器
class Target {
public:
    virtual void func_a() = 0;
    virtual void func_b() = 0;
    virtual void func_c() = 0;
};

class DefaultAdapter: public Target {
public:
    void func_a() {}
    void func_b() {}
    void func_c() {}
};

class MyApp: public DefaultAdapter{
public:
   void func_a() {
       std::cout<<"MyApp a"<<std::endl;
   }
};

} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_ADAPTER_PATTERN_H
