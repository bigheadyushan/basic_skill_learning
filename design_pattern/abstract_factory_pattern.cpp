#include "design_pattern.h"
int main() {
    design_pattern::CoreAbstractFactory* core_abstract_factory 
            = new design_pattern::CoreAFactory();
    design_pattern::SingleCore* single_core = core_abstract_factory->create_single_core();
    single_core->show();
    design_pattern::MultiCore* multi_core = core_abstract_factory->create_multi_core();
    multi_core->show();
    return 0;
}
