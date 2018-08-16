#include "design_pattern.h"
int main() {
    design_pattern::SingleCoreFactory* single_factory = new design_pattern::SingleCoreFactory();
    design_pattern::SingleCore* single_core_A = single_factory->create_single_core(design_pattern::COREA);
    single_core_A->show();
    design_pattern::SingleCore* single_core_B = single_factory->create_single_core(design_pattern::COREB);
    single_core_B->show();
    
    design_pattern::MultiCoreFactory* multi_factory = new design_pattern::MultiCoreFactory();
    design_pattern::MultiCore* multi_core_A = multi_factory->create_multi_core(design_pattern::COREA);
    multi_core_A->show();
    design_pattern::MultiCore* multi_core_B = multi_factory->create_multi_core(design_pattern::COREB);
    multi_core_B->show();
    return 0;
}
