#include "builder_pattern.h"
using namespace design_pattern;
int main() {
    Builder* villa_builder = new VillaBuilder();
    Builder* loft_builder = new LoftBuilder();
    Director* director = new Director();
    director->direct_build();
    director->find_builder(villa_builder);
    director->direct_build();
    director->find_builder(loft_builder);
    director->direct_build();
    return 0;
}
