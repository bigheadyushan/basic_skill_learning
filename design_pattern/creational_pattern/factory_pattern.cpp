#include "factory_pattern.h"
int main() {
    //simple factory pattern
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

    // factory_method_pattern
    design_pattern::SingleCoreAbstractFactory* single_core_factory 
            = new design_pattern::SingleCoreAFactory();
    design_pattern::SingleCore* single_core = single_core_factory->create_single_core();
    single_core->show();
    
    design_pattern::MultiCoreAbstractFactory* multi_core_factory 
            = new design_pattern::MultiCoreBFactory();
    design_pattern::MultiCore* multi_core = multi_core_factory->create_multi_core();
    multi_core->show();

    // abstract_factory_pattern 
    design_pattern::CoreAbstractFactory* core_abstract_factory 
            = new design_pattern::CoreAFactory();
    design_pattern::SingleCore* single_core_A1 = core_abstract_factory->create_single_core();
    single_core_A1->show();
    design_pattern::MultiCore* multi_core_A2 = core_abstract_factory->create_multi_core();
    multi_core_A2->show();
 
    return 0;
}
