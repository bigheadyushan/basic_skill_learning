#include "prototype_pattern.h"
using namespace design_pattern;
int GoldenCudgel::_num = 0;
int MonkeyKing::_num = 0;
int main() {
    GoldenCudgel* golden_cudgel = new GoldenCudgel();
    golden_cudgel->set_name("HapppGoldenCudgel");
    golden_cudgel->print();
    MonkeyKing* monkey_king = new MonkeyKing(golden_cudgel);
    monkey_king->print();
    MonkeyKing* monkey_king_2 = new MonkeyKing(new GoldenCudgel());
    monkey_king_2->print();
    MonkeyKing monkey_king_3(*monkey_king_2);
    monkey_king_3.print();
    MonkeyKing* monkey_king_4 = monkey_king->clone();
    monkey_king_4->print();
    return 0;
}
