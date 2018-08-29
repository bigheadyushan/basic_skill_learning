#include "adapter_pattern.h"
using namespace design_pattern;
int main() {
    //¿‡  ≈‰
    CalculateTarget* calc_target = new CalculateClassAdapter();
    std::cout<<calc_target->calculate(1.0, 2.0)<<std::endl;
    delete calc_target;
    calc_target = new CalculateObjectAdapter();
    std::cout<<calc_target->calculate(1.0, 2.0)<<std::endl;
    delete calc_target;
    calc_target = NULL;
    Target* target = new MyApp();
    target->func_a();
    delete target;
    target = NULL;
    return 0;
}
