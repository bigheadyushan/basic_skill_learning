#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_BUILDER_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_BUILDER_PATTERN_H

#include <iostream>

namespace design_pattern {
//Ôì·¿×Ó
class Builder {
public:
    //common fun put in base class
    void prepare_materail() {
        std::cout<<"prepare_materail"<<std::endl;    
    }
    virtual void lay_foundation() = 0;
    virtual void build_walls() = 0;
    virtual void build_ceil() = 0;
    virtual void fit_up() = 0;
};

class VillaBuilder: public Builder {
    void lay_foundation() {
        std::cout<<"lay villa foundation"<<std::endl;
    }
    void build_walls() {
        std::cout<<"build villa walls"<<std::endl;
    }
    void build_ceil() {
        std::cout<<"build villa ceil"<<std::endl;
    }
    void fit_up() {
        std::cout<<"fit up villa"<<std::endl;
    }
};

class LoftBuilder: public Builder {
    void lay_foundation() {
        std::cout<<"lay loft foundation"<<std::endl;
    }
    void build_walls() {
        std::cout<<"build loft walls"<<std::endl;
    }
    void build_ceil() {
        std::cout<<"build loft ceil"<<std::endl;
    }
    void fit_up() {
        std::cout<<"fit up loft"<<std::endl;
    }
};

class Director {
public:
    Director(): _builder(NULL) {}
    Director(Builder* builder): _builder(builder) {}
    void find_builder(Builder* builder) {
        _builder = builder;
    }
    void direct_build() {
        if (_builder != NULL) {
            _builder->prepare_materail();
            _builder->lay_foundation();
            _builder->build_walls();
            _builder->build_ceil();
            _builder->fit_up();
        } else {
            std::cout<<"director not find builder"<<std::endl;
        }
    }
private:
    Builder* _builder;
};

} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_BUILDER_PATTERN_H
