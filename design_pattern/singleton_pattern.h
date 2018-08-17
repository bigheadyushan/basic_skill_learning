#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_SINGLETON_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_SINGLETON_PATTERN_H

#include <iostream>

namespace design_pattern {
class Singleton {
public:
    static Singleton* get_singleton() {
        if (singleton_ptr == NULL) {
            singleton_ptr = new Singleton();
        }
        return singleton_ptr;
    }
    void print() {
        std::cout << "this is singleton" << std::endl;
    }
private:
    static Singleton* singleton_ptr;
    Singleton() {}
};


} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_SINGLETON_PATTERN_H
