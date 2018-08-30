#include "facade_pattern.h"
using namespace design_pattern;
int main() {
    Computer* computer = new Computer();
    computer->open();
    delete computer;
    computer = NULL;
    return 0;
}
