#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_DESIGN_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_DESIGN_PATTERN_H

#include <iostream>

namespace design_pattern {

enum CTYPE {
    COREA = 1,
    COREB = 2,
};

class SingleCore {
public:
    virtual void show() = 0;
};

class SingleCoreA: public SingleCore {
public:
    inline void show() {
        std::cout<<"SingleCore A"<<std::endl;
    }
};

class SingleCoreB: public SingleCore {
public:
    inline void show() {
        std::cout<<"SingleCore B"<<std::endl;     
    }
};

class MultiCore {
public:
    virtual void show() = 0;
};

class MultiCoreA: public MultiCore {
public:
    inline void show() {
        std::cout<<"MultiCore A"<<std::endl;
    }
};

class MultiCoreB: public MultiCore {
public:
    inline void show() {
        std::cout<<"MultiCore B"<<std::endl;
    }
};


class SingleCoreFactory {
public:
    SingleCore* create_single_core(enum CTYPE ctype) {
        switch(ctype) {
            case COREA: 
                return new SingleCoreA();
                break;
            case COREB:
                return new SingleCoreB();
                break;
            default:
                return NULL;
        }
    }
};

class MultiCoreFactory {
public:
    MultiCore* create_multi_core(enum CTYPE ctype) {
        switch(ctype) {
            case COREA: 
                return new MultiCoreA();
                break;
            case COREB:
                return new MultiCoreB();
                break;
            default:
                return NULL;
        }
    }
};

class SingleCoreAbstractFactory {
public:
    virtual SingleCore* create_single_core() = 0;
};

class MultiCoreAbstractFactory {
public:
    virtual MultiCore* create_multi_core() = 0;
};

class SingleCoreAFactory: public SingleCoreAbstractFactory {
public:
    SingleCore* create_single_core() {
        return new SingleCoreA();
    }
};

class SingleCoreBFactory: public SingleCoreAbstractFactory {
public:
    SingleCore* create_single_core() {
        return new SingleCoreB();
    }
};


class MultiCoreAFactory: public MultiCoreAbstractFactory {
public:
    MultiCore* create_multi_core() {
        return new MultiCoreA();
    }
};

class MultiCoreBFactory: public MultiCoreAbstractFactory {
public:
    MultiCore* create_multi_core() {
        return new MultiCoreB();
    }
};

class CoreAbstractFactory {
public:
    virtual SingleCore* create_single_core() = 0;
    virtual MultiCore* create_multi_core() = 0;
};

class CoreAFactory: public CoreAbstractFactory {
public:
    SingleCore* create_single_core() {
        return new SingleCoreA();
    }
    MultiCore* create_multi_core() {
        return new MultiCoreA();
    }
};

class CoreBFactory: public CoreAbstractFactory {
public:
    SingleCore* create_single_core() {
        return new SingleCoreB();
    }
    MultiCore* create_multi_core() {
        return new MultiCoreB();
    }
};

} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_DESIGN_PATTERN_H
