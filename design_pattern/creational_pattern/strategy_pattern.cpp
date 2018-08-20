#include "strategy_pattern.h"
using namespace design_pattern;
int main() {
    //use calculate class
    AlgCalculate* alg_calc = 
        new AlgCalculate(new AddOperator, 1.0, 2.0);
    alg_calc->do_alg_calculate();
    delete alg_calc;
    AlgCalculate* alg_calc1 = 
        new AlgCalculate(new MinusOperator, 1.0, 2.0);
    alg_calc1->do_alg_calculate();
    delete alg_calc1;

    // use tag
    AlgCalculate* alg_calc2 =
        new AlgCalculate(ADD, 1.0, 2.0);
    alg_calc2->do_alg_calculate();
    delete alg_calc2;

    // use template
    AlgCalculateTemplete<AddOperator> add_alg_calc(1.0, 2.0);
    add_alg_calc.do_alg_calculate();
    return 0;
}
