#include <iostream>
using namespace std;

class Subject {
public:
    virtual void Request() = 0;
    virtual ~Subject() { }
};

class ConcreteSubject :public Subject {
public:
    void Request() {
        cout << "ConcreteSubject::Request..." << endl;
    }
};

class Proxy {
public:
    Proxy(Subject* subject) {
        _sub = subject;
    }

    void Reuqest() {
        cout << "Proxy::Request..." << endl;
        _sub->Request();
    }

private:
    Subject *_sub;
};
//判断是管理员还是学生，不然不能删改
//int main() {
//    Subject *sub = new ConcreteSubject();
//    Proxy *p = new Proxy(sub);
//    p->Reuqest();
//
//    delete sub;
//    delete p;
//
//    return 0;
//}
