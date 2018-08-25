#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_PROTOTYPE_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_PROTOTYPE_PATTERN_H

#include <iostream>

namespace design_pattern {
class GoldenCudgel {
public:
    GoldenCudgel():_name("InitialGoldenCudgel") {
        _num++;
    }
    GoldenCudgel* clone() {
        GoldenCudgel* clone_golden_cudgel = new GoldenCudgel();
        clone_golden_cudgel->set_name(this->_name);
        return clone_golden_cudgel;
    }
    void set_name(const std::string& name) {
       _name = name; 
    }
    void print() {
        std::cout<<_name<<_num<<std::endl;
    }

private:
    static int _num;
    std::string _name;
};

class MonkeyKing {
public:
    MonkeyKing(GoldenCudgel* golden_cudgel): \
        _golden_cudgel(golden_cudgel) {
        _num++;
    }
    MonkeyKing(const MonkeyKing& monkey_king) {
        _num++;
        _golden_cudgel = monkey_king._golden_cudgel;
    }
    MonkeyKing* clone() {
        GoldenCudgel* clone_golden_cudgel = this->_golden_cudgel->clone();
        return new MonkeyKing(clone_golden_cudgel);
    }
    void print() {
        std::cout<<"MonkeyKing:"<<_num<<" has ";
        if (_golden_cudgel) {
            _golden_cudgel->print();
        } else {
            std::cout<<"no golden_cudgel"<<std::endl;    
        }
    }
    ~MonkeyKing() {
        if (_golden_cudgel) {
            delete _golden_cudgel;
            _golden_cudgel = NULL;
        }
    }
private:
    static int _num;
    GoldenCudgel* _golden_cudgel;
};


} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_PROTOTYPE_PATTERN_H
