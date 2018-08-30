#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_BRIDGE_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_BRIDGE_PATTERN_H

#include <iostream>
#include <map>
namespace design_pattern {
/*
桥接模式将抽象部分与实现部分分类，使两部分能够独立地变化
*/

class PhoneSoft {
public:
    virtual void run() = 0;
};

class PhoneGame: public PhoneSoft {
public:
    void run() {
        std::cout<<"run phone game"<<std::endl;
    }
};

class PhonePicture: public PhoneSoft {
public:
    void run() {
        std::cout<<"run phone picture"<<std::endl;
    }
};

class PhoneBrand {
public:
    virtual void install_soft(const std::string& soft_name,
        PhoneSoft* phone_soft) = 0;
    virtual void run_soft(const std::string& soft_name) = 0;
protected:
    std::map<std::string, PhoneSoft*> _install_soft_map;
};

class IPhone: public PhoneBrand {
public:
    void install_soft(const std::string& soft_name, 
        PhoneSoft* phone_soft) {
        _install_soft_map[soft_name] = phone_soft;
        std::cout<<soft_name<<"is installed"<<std::endl;
    }

    void run_soft(const std::string& soft_name) {
        std::map<std::string, PhoneSoft*>::iterator iter_map =
            _install_soft_map.find(soft_name);
        if (iter_map == _install_soft_map.end()) {
            std::cout<<soft_name<<" no install"<<std::endl;
        } else {
            iter_map->second->run();
        }
    }
};

class XiaoMi: public PhoneBrand {
public:
    void install_soft(const std::string& soft_name, 
        PhoneSoft* phone_soft) {
        _install_soft_map[soft_name] = phone_soft;
        std::cout<<soft_name<<"is installed"<<std::endl;
    }

    void run_soft(const std::string& soft_name) {
        std::map<std::string, PhoneSoft*>::iterator iter_map =
            _install_soft_map.find(soft_name);
        if (iter_map == _install_soft_map.end()) {
            std::cout<<soft_name<<" no install"<<std::endl;
        } else {
            iter_map->second->run();
        }
    }
};


} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_BRIDGE_PATTERN_H
