#include <iostream>
#include <string>
#include <memory>
using namespace std;

#define J

#ifdef A
class Base {
public:
    Base() { cout << "Base constructor called\n"; }
    virtual ~Base() { cout << "Base destructor called\n"; }
};
class Derived : public Base {
public:
    Derived() { cout << "Derived constructor called\n"; }
    ~Derived() { cout << "Derived destructor called\n"; }
};
int main() {
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}
#endif

#ifdef B
class Base {
public:
    void method1() {
        std::cout << "Base::method1()" << std::endl;
        method2();
    }
    void method2() {
        std::cout << "Base::method2()" << std::endl;
    }
};
class Derived : public Base {
public:
    void method2() {
        std::cout << "Derived::method2()" << std::endl;
    }
};
int main() {
    Derived derived;
    derived.method1();
    return 0;
}
#endif
#ifdef C
class Base {
public:
    void method1() {
        cout << "Base::method1()" << endl;
        method2();
    }
    virtual void method2() { cout << "Base::method2()" << endl; }
};
class Derived : public Base {
public:
    void method2() override { cout << "Derived::method2()" << endl; }
};
int main() {
    Base* ptr = new Derived();
    ptr->method1();
    delete ptr;
    return 0;
}
#endif

#ifdef D
class Base {
public:
    void method() { cout << "Base::method()" << endl; }
};
class Derived : public Base {
public:
    void method() { cout << "Derived::method()" << endl; }
};
int main() {
    Base* ptr = new Derived();
    ptr->method();
    Derived* derivedPtr = new Derived();
    derivedPtr->method();
    delete ptr;
    delete derivedPtr;
    return 0;
}
#endif
#ifdef E
#include <iostream>
class Base {
public:
    virtual void method() { cout << "Base::method()" << endl; }
};
class Derived : public Base {
public:
    void method() override { cout << "Derived::method()" << endl; }
};
int main() {
    Base* ptr = new Derived();
    ptr->method(); 
    Derived* derivedPtr = new Derived();
    derivedPtr->method();
    delete ptr;
    delete derivedPtr;
    return 0;
}
#endif

#ifdef F
class Base {
public:
    virtual string classname() { return "Base"; }
};
class Derived : public Base {
public:
    string classname() override { return "Derived"; }
};
int main() {
    Base* base = new Base();
    Derived* derived = new Derived();
    cout << base->classname() << endl;
    cout << derived->classname() << endl;
    delete base;
    delete derived;
    return 0;
}
#endif

#ifdef G
class Base {
public:
    virtual string classname() { return "Base"; }
    virtual bool isA(string classname) { return classname == "Base"; }
};
class Derived : public Base {
public:
    virtual string classname() override { return "Derived"; }
    virtual bool isA(string classname) override { return classname == "Derived" or Base::isA(classname); }
};
int main() {
    Base* base = new Base();
    Base* derived = new Derived();
    cout << base->classname() << endl;
    cout << derived->classname() << endl;    
    cout << base->isA("Base") << endl;       
    cout << derived->isA("Base") << endl;    
    cout << base->isA("Derived") << endl;    
    cout << derived->isA("Derived") << endl; 
    delete base;
    delete derived;
    return 0;
}
#endif
#ifdef H
class Base {
public:
    virtual void foo() {}
};
class Derived : public Base {
public:
    void bar() {}
};
void func1(Base obj) {
    Derived* ptr = dynamic_cast<Derived*>(&obj);
    if (ptr != nullptr) {                          
        ptr->bar();                                
        cout << "func1(Base obj)" << endl;
    }
}
void func2(Base* obj) {
    Derived* ptr = dynamic_cast<Derived*>(obj);
    if (ptr != nullptr) {
        ptr->bar(); 
        cout << "func2(Base* obj)" << endl;
    }
}
void func3(Base& obj) {
    Derived* ptr = dynamic_cast<Derived*>(&obj);
    if (ptr != nullptr) {
        ptr->bar(); 
        cout << "func3(Base& obj)";
    }
}
int main() {
    Base* obj1 = new Derived();
    func1(*obj1);
    func2(obj1); 
    func3(*obj1);
    delete obj1;
    Base* obj2 = new Base()
    func1(*obj2); 
    func2(obj2);  
    func3(*obj2); 
    delete obj2;
    return 0;
}
#endif
#ifdef I
class Base {
public:
    Base() {
        cout << "Base() (Base default constructor called)" << endl;
    }
    Base(Base* obj) {
        cout << "Base(Base* obj) (Base first copy constructor called)" << endl;
    }
    Base(Base& obj) {
        cout << "Base(Base& obj) (Base second copy constructor called)" << endl;
    }
    virtual ~Base() {
        cout << "virtual ~Base() (Base destructor called)" << endl;
    }
    virtual string classname() { return "Base"; }
    virtual bool isA(string classname) { return (classname == "Base"); }
};
class Desc : public Base {
public:
    Desc() {
        cout << "Desc() (Desc default constructor called)" << endl;
    }
    Desc(Desc* obj) {
        cout << "Desc(Desc* obj) (Desc first copy constructor called)" << endl;
    }
    Desc(Desc& obj) {
        cout << "Desc(Desc& obj) (Desc second copy constructor called)" << endl;
    }
    ~Desc() {
        cout << "~Desc() (Desc destructor called)" << endl;
    }
    string classname() override { return "Desc"; }
    bool isA(string classname) override { return (classname == "Desc" or Base::isA(classname)); }
};
void func1(Base obj) {
    cout << "func1 called with " << obj.classname() << endl;
}
void func2(Base* obj) {
    cout << "func2 called with " << obj->classname() << endl;
    Desc* d = dynamic_cast<Desc*>(obj);
    if (d) { cout << "object is of type Desc" << endl; }
    else { cout << "object is not of type Desc" << endl; }
}
void func3(Base& obj) {
    cout << "func3 called with " << obj.classname() << endl;
}
int main() {
    Base base;
    Desc desk;
    cout << "Calling func1..." << endl;
    func1(base);
    func1(desk);
    cout << "Calling func2..." << endl;
    func2(&base);
    func2(&desk);
    cout << "Calling func3..." << endl;
    func3(base);
    func3(desk);
    return 0;
}
#endif
#ifdef J
class Base {
public:
    Base() { std::cout << "Base default constructor" << std::endl; }
    Base(Base* obj) { std::cout << "Base pointer constructor" << std::endl; }
    Base(Base& obj) { std::cout << "Base reference constructor" << std::endl; }
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};
Base func1() {
    Base b;
    std::cout << "func1: Created static Base object" << std::endl;
    return b;
}
Base* func2() {
    Base b;
    std::cout << "func2: Created static Base object" << std::endl;
    return &b;
}
Base& func3() {
    Base b;
    std::cout << "func3: Created static Base object" << std::endl;
    return b;
}
Base func4() {
    Base* b = new Base();
    std::cout << "func4: Created dynamic Base object" << std::endl;
    return *b;
}
Base* func5() {
    Base* b = new Base();
    std::cout << "func5: Created dynamic Base object" << std::endl;
    return b;
}
Base& func6() {
    Base* b = new Base();
    std::cout << "func6: Created dynamic base object" << std::endl;
    return *b;
}
int main() {
    Base b;
    Base* pb = new Base();
    Base& lb = b;
    std::cout << "Checking the mechanism for returning objects from a function" << std::endl;
    std::cout << "------------------" << std::endl;
    b = func1();
    pb = func2();
    lb = func3();
    std::cout << "First three functions passed" << std::endl;
    std::cout << "------------------" << std::endl;
    b = func4();
    pb = func5();
    lb = func6();
    std::cout << "Last three functions passed" << std::endl;
    std::cout << "------------------" << std::endl;
}
#endif

#ifdef K
class MyClass {
private:
    int num_;
public:
    MyClass(int num) : num_(num) {
        std::cout << "Constructor called" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }
    int GetNum() {
        return num_;
    }
};
void Function1(std::unique_ptr<MyClass> ptr) {
    std::cout << "Function1 called with " << ptr->GetNum() << std::endl;
}
void Function2(std::shared_ptr<MyClass> ptr) {
    std::cout << "Functional called with " << ptr->GetNum() << std::endl;
}
int main() {
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(42);
    std::cout << "ptr1 points to " << ptr1->GetNum() << std::endl;
    Function1(std::move(ptr1));
    std::cout << "ptr1 is " << (ptr1 ? "not null" : "null") << std::endl;
    std::shared_ptr<MyClass> ptr2 = std::make_shared<MyClass>(24);
    std::cout << "ptr2 points to " << ptr2->GetNum() << std::endl;
    Function2(ptr2); 
    std::cout << "ptr2 still points to " << ptr2->GetNum() << std::endl;
    std::cout << "ptr2 use_count is " << ptr2.use_count() << std::endl;

    std::shared_ptr<MyClass> ptr3 = std::make_shared<MyClass>(100);
    std::shared_ptr<MyClass> ptr4 = std::make_shared<MyClass>(200);
    std::shared_ptr<MyClass> tmp1(ptr3);
    std::shared_ptr<MyClass> tmp2(ptr4);
    ptr3.swap(ptr4);
    std::cout << ptr3->GetNum() << std::endl;
    ptr4.swap(ptr3);
    std::cout << ptr3->GetNum() << std::endl;
    std::cout << "ptr3 use_count is " << ptr3.use_count() << std::endl; 
    std::cout << "ptr4 use_count is " << ptr4.use_count() << std::endl;
    return 0;
}
#endif

















#ifdef notF
class Base {
public:
    virtual string classname() const { return "Base"; }
};
class Derived : public Base {
public:
    string classname() const override { return "Derived"; }
};
void printClassname(Base* obj) {
    if (Derived* derived = dynamic_cast<Derived*>(obj)) {
        cout << "Derived" << endl;
    }
    else { cout << "Base" << endl; }
}
int main() {
    Base* base = new Base();
    Derived* derived = new Derived();
    printClassname(base);
    printClassname(derived);
    delete base;
    delete derived;
    return 0;
}#endif



#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructor" << std::endl; }
    ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor" << std::endl; }
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

Base func1() {
    static Base b;
    return b;
}

Base* func2() {
    static Derived d;
    return &d;
}

Base& func3() {
    static Derived d;
    return d;
}

Base func4() {
    return *new Derived();
}

Base* func5() {
    return new Derived();
}

Base& func6() {
    return *new Derived();
}

int main() {
    Base b1 = func1();
    Base* b2 = func2();
    Base& b3 = func3();
    Base b4 = func4();
    Base* b5 = func5();
    Base& b6 = func6();

    delete b5;
    delete& b4;
    delete& b6;

    return 0;
}










//
#endif
#ifdef not2J







#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor called" << std::endl;
    }

    ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

Base func1() {
    static Base b;
    return b;
}

Base* func2() {
    static Base b;
    return &b;
}

Base& func3() {
    static Base b;
    return b;
}

Base func4() {
    Base* b = new Base();
    return *b;
}

Base* func5() {
    Base* b = new Base();
    return b;
}

Base& func6() {
    Base* b = new Base();
    return *b;
}

int main() {
    // Test func1
    Base b1 = func1();
    std::cout << std::endl;

    // Test func2
    Base* b2 = func2();
    std::cout << std::endl;

    // Test func3
    Base& b3 = func3();
    std::cout << std::endl;

    // Test func4
    Base b4 = func4();
    delete& b4;
    std::cout << std::endl;

    // Test func5
    Base* b5 = func5();
    delete b5;
    std::cout << std::endl;

    // Test func6
    Base& b6 = func6();
    delete& b6;
    std::cout << std::endl;

    return 0;
}
#endif