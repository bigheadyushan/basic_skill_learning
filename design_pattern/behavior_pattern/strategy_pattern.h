#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_BEHAVIOR_PATTERN_STRATEGY_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_BEHAVIOR_PATTERN_STRATEGY_PATTERN_H

#include <iostream>

namespace design_pattern {

enum ALG {
    ADD = 1,
    MINUS = 2,
};


class CalculateOperator {
public:
    virtual double calculate(double numa, double numb) = 0;
};

class AddOperator: public CalculateOperator {
public:
    double calculate(double numa, double numb) {
        return numa + numb;
    }
};

class MinusOperator: public CalculateOperator {
public:
    double calculate(double numa, double numb) {
        return numa - numb;
    }
};

class AlgCalculate {
public:
    AlgCalculate(CalculateOperator* CalOper, double numa, double numb):
        _CalOper(CalOper), _numa(numa), _numb(numb) {}
    AlgCalculate(enum ALG alg, double numa, double numb):
        _CalOper(NULL), _numa(numa), _numb(numb){
        if (alg == ADD) {
            _CalOper = new AddOperator();
        } else if (alg == MINUS) {
            _CalOper = new MinusOperator();
        }
    }
    void do_alg_calculate() {
        if (_CalOper != NULL) {
            std::cout<<_CalOper->calculate(_numa, _numb)<<std::endl; 
        }
    }
private:
    CalculateOperator* _CalOper;
    double _numa;
    double _numb;
};

template<typename Type> class AlgCalculateTemplete {
public:
    AlgCalculateTemplete(double numa, double numb):
        _numa(numa), _numb(numb) {}
    void do_alg_calculate() {
        std::cout<<_CalOper.calculate(_numa, _numb)<<std::endl; 
    }
private:
    Type _CalOper;
    double _numa;
    double _numb;
};

} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_BEHAVIOR_PATTERN_STRATEGY_PATTERN_H
