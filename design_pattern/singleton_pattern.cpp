#include "singleton_pattern.h"
using namespace design_pattern;
Singleton* Singleton::singleton_ptr = NULL;
int main() {
    Singleton* singleton = Singleton::get_singleton();
    singleton->print();
    return 0;
}
