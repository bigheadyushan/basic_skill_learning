#include "agency_pattern.h"
using namespace design_pattern;
int main() {
    //case1:С��ֱ���뷿����ͨ�ⷿ
    Person* xiao_li = new RentPerson("xiao li");
    Person* land_lord = new LandLord();
    land_lord->receive_message(xiao_li->send_message("how much ?"));
    xiao_li->receive_message(land_lord->send_message("1000 RMB per month"));
    xiao_li->rent_house();
    xiao_li->pay_deposit();

    //case2:С��ͨ������С���뷿����ͨ
    Person* xiao_ming = new ProxyPerson(xiao_li);
    land_lord->receive_message(xiao_ming->send_message("how much ?"));
    xiao_ming->receive_message(land_lord->send_message("1000 RMB per month")); 

    //case3:С��ͨ���н�С���뷿����ͨ
    AgencyPerson* xiao_wang = new AgencyPerson();
    xiao_li->set_agency_person(xiao_wang);
    xiao_wang->set_rent_person(xiao_li);
    land_lord->set_agency_person(xiao_wang);
    xiao_wang->set_land_lord(land_lord);
    xiao_li->send_message("how much ?");
    land_lord->send_message("1000 RMB per month");

    return 0;
}
