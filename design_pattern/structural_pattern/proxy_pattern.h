#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_DECORATOR_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_DECORATOR_PATTERN_H

#include <iostream>

namespace design_pattern {
/*
������ģʽ���Է�װԭ���󣬿�����ԭ���������������顣
���н��ߵ������н���һ�㲻��װԭ���󣬶������ã�
�н���ģʽ����ͨ���������ԭ����������

����д��case�ǣ�С����ΪС��Ĵ�������С���ⷿ��
*/

class Person {
public:
    virtual void rent_house() = 0;
    virtual void pay_deposit() = 0;
    virtual ~Person() {}
};

class RentPerson: public Person {
public:
    RentPerson():_name("person") {}
    RentPerson(std::string name):_name(name) {}
    void rent_house() {
        std::cout<<_name<<" rent house"<<std::endl;
    }
    void pay_deposit() {
        std::cout<<_name<<" pay deposit"<<std::endl;
    }
    ~RentPerson() {}
private:
    std::string _name;
};

class ProxyPerson: public Person {
public:
    ProxyPerson():_person(new RentPerson()) {}
    ProxyPerson(Person* person):_person(person) {}
    void rent_house() {
        if (_person) {
            std::cout<<"the proxy help ";
            _person->rent_house();
        }
    }
    void pay_deposit() {
        if (_person) {
            std::cout<<"the proxy help ";
            _person->pay_deposit();
        }
    }
    ~ProxyPerson() {}
private:
    Person* _person;
};

} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_DECORATOR_PATTERN_H
