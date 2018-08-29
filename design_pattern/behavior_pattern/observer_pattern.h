#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_BEHAVIOR_PATTERN_OBSERVER_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_BEHAVIOR_PATTERN_OBSERVER_PATTERN_H

#include <iostream>
#include <vector>

namespace design_pattern {

class SubjectState {
public:
    SubjectState():state("none") {}
    std::string state;
};

class Observer {
public:
    virtual void update() = 0;
    virtual std::string get_name() {
        return "";
    }
};

class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;

    virtual std::string get_state() {
        return "";
    }
};


class ConcreteObserver: public Observer {
public:
    ConcreteObserver(const std::string& name, const std::string& behavior, Subject* subject):
        _name(name),  _behavior(behavior), _subject(subject) {}
    void update() {
        if (_subject->get_state() == "come") {
            std::cout<<"teacher come, "<<_name<<" not " <<_behavior<<std::endl;
        } else {
            std::cout<<"teacher not come, "<<_name<< " continue "<<_behavior<<std::endl;
        }
    }
    std::string get_name() {
        return _name;    
    }
private:
    std::string _name;
    std::string _behavior;
    Subject* _subject;
};

class ConcreteSubject: public Subject {
public:
    ConcreteSubject() {}
    ConcreteSubject(const std::string& name):_name(name) {}
    void attach(Observer* observer) {
        observer_vec.push_back(observer);
    }
    void detach(Observer* observer) {
        std::vector<Observer*>::iterator vec_iter = observer_vec.begin();
        for (; vec_iter != observer_vec.end();) {
            if ((*vec_iter)->get_name() == observer->get_name()) {
                vec_iter = observer_vec.erase(vec_iter);
            } else {
                ++vec_iter;
            }
        }
    }
    void notify() {
        std::vector<Observer*>::iterator vec_iter = observer_vec.begin();
        for (; vec_iter != observer_vec.end(); ++vec_iter) {
            (*vec_iter)->update();
        }
    }
    void change_state(const std::string& state) {
        subject_state.state = state; 
    }
    void set_name(const std::string& name) {
        _name = name;
    }
    std::string get_state() {
        return subject_state.state;
    }
private:
    std::string _name;
    std::vector<Observer*> observer_vec;
    SubjectState subject_state;
};

} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_BEHAVIOR_PATTERN_OBSERVER_PATTERN_H
