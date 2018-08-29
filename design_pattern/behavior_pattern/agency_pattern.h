#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_AGENCY_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_AGENCY_PATTERN_H

#include <iostream>

namespace design_pattern {
/*
代理者模式可以封装原对象，可以做原对象做的所有事情。
与中介者的区别，中介者一般不封装原对象，而是引用，
中介者模式负责沟通，不负责帮原对象做事情

下面写的class可以用来：
（1）小王作为小李的中介，帮着小李和房东进行沟通租房
（2）小明作为小李的代理，与中介小王和房东沟通租房
*/

class AgencyPerson;
class Person {
public:
    Person():_agency_person(NULL) {}
    Person(AgencyPerson* agency_person):_agency_person(agency_person) {}
    inline void set_agency_person(AgencyPerson* agency_person) {
        _agency_person = agency_person;
    }
    virtual void rent_house() = 0;
    virtual void pay_deposit() = 0;
    virtual std::string send_message(const std::string& message) = 0;
    virtual void receive_message(const std::string& message) = 0;
    virtual ~Person() {}
protected:
    AgencyPerson* _agency_person;
};

class LandLord: public Person {
public:
    LandLord():_name("land loard") {}
    void rent_house() {}
    void pay_deposit() {}
    std::string send_message(const std::string& message) {
        std::string send_mess = "Landlord[" + _name + "] send: " + message;
        std::cout<<send_mess<<std::endl;
        return message;
    }
    void receive_message(const std::string& message) {
        std::string receive_mess = "Landlord[" + _name + "] receive: " + message;
        std::cout<<receive_mess<<std::endl;
    }
    ~LandLord() {}
private:
    std::string _name;
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
    std::string send_message(const std::string& message) {
        std::string send_mess = "RentPerson[" + _name + "] send: " + message;
        std::cout<<send_mess<<std::endl;
        return message;
    }
    void receive_message(const std::string& message) {
        std::string receive_mess = "RentPerson[" + _name + "] receive: " + message;
        std::cout<<receive_mess<<std::endl;
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
    std::string send_message(const std::string& message) {
        if (_person) {
            std::string send_mess = "the proxy help " + _person->send_message(message);
            return send_mess;
        } else {
            std::string send_mess = "the proxy help send: " + message;
            return send_mess;
        }
    }
    void receive_message(const std::string& message) {
        if (_person) {
            std::cout<<"the proxy help ";
            _person->receive_message(message);
        } else {
            std::cout<<"the proxy help receive"<<message<<std::endl;
        }
    }
    ~ProxyPerson() {}
private:
    Person* _person;
};


class AgencyPerson {
public:
    AgencyPerson():_land_lord(NULL), _rent_person(NULL) {}
    void set_land_lord(Person* land_lord) {
        _land_lord = land_lord;
    }
    void set_rent_person(Person* rent_person) {
        _rent_person = rent_person;
    }
    void send_message(Person* person, const std::string& message) {
        if (person == _land_lord) {
            _rent_person->receive_message(message);
        } else if (person == _rent_person) {
            _land_lord->receive_message(message);
        }
    }
    
private:
    Person* _land_lord;
    Person* _rent_person;
};

} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_AGENCY_PATTERN_H
