#include "observer_pattern.h"
using namespace design_pattern;
int main() {
    ConcreteSubject* xiaoliang = new ConcreteSubject("xiaoliang");
    ConcreteObserver* xiao_xu = new ConcreteObserver("xiaoxu", "watch film", xiaoliang);
    xiaoliang->attach(xiao_xu);
    ConcreteObserver* xiao_jia = new ConcreteObserver("xiao_jia", "watch tv", xiaoliang);
    xiaoliang->attach(xiao_xu);
    ConcreteObserver* xiao_dong = new ConcreteObserver("xiao_dong", "play game", xiaoliang);
    xiaoliang->attach(xiao_xu);
    ConcreteObserver* xiao_yue = new ConcreteObserver("xiao_yue", "talk", xiaoliang);
    xiaoliang->attach(xiao_yue);

    xiaoliang->change_state("none");
    xiaoliang->notify();
    xiaoliang->change_state("come");
    xiaoliang->notify();

    return 0;
}
