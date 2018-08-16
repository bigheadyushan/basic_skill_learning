#include "design_pattern.h"
int main() {
    design_pattern::SingleCoreAbstractFactory* single_core_factory 
            = new design_pattern::SingleCoreAFactory();
    design_pattern::SingleCore* single_core = single_core_factory->create_single_core();
    single_core->show();
    
    design_pattern::MultiCoreAbstractFactory* multi_core_factory 
            = new design_pattern::MultiCoreBFactory();
    design_pattern::MultiCore* multi_core = multi_core_factory->create_multi_core();
    multi_core->show();
    return 0;
}
