#include "proxy_pattern.h"
using namespace design_pattern;
int main() {
    Person* xiao_ming = new ProxyPerson();
    xiao_ming->rent_house();
    xiao_ming->pay_deposit();
    delete xiao_ming;
    xiao_ming = NULL;
    Person* xiao_li = new RentPerson("xiao li");
    xiao_ming = new ProxyPerson(xiao_li);
    xiao_ming->rent_house();
    xiao_ming->pay_deposit();
    delete xiao_li;
    xiao_li = NULL;
    delete xiao_ming;
    xiao_ming = NULL;
    return 0;
}
