#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_ADAPTER_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_ADAPTER_PATTERN_H

#include <iostream>

namespace design_pattern {
/*
������ģʽ��һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڣ�ʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ����
���������������Ͷ���������
*/

// ��������:���������������Ǽ̳й�ϵ
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

//����������:�������а��������߶���
class CalculateObjectAdapter: public CalculateTarget{
public:
    double calculate(double numa, double numb) {
        return calc_adaptee.minus(numa, numb);
    }
private:
    CalculateAdaptee calc_adaptee;
};

} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_ADAPTER_PATTERN_H
