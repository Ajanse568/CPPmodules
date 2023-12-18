//
// Created by allej on 12/11/2023.
//

#ifndef __CLASSES_HPP
#define __CLASSES_HPP

class Base {
public:
    virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void    identify(Base *p);
void    identify(Base &p);

#endif //__CLASSES_HPP
