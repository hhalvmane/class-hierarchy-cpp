#include <iostream>

using namespace std;

class GrandParent {
    string a;
protected:
    string p_a;
 public:
    void messageG() { cout << "GrandParent class: "; }
    void seta(string x) { a = x; }
    void showa() { cout << a << endl; }

};

class Parent : public GrandParent {
    string b;
public:
    void messageP() { cout << "Parent class: "; }
    string prv;
};

class Parent2 : protected GrandParent {
protected: 
    // public і protected від GrandParent
public:
    void messageP2() { cout << "Parent2 class: "; }

    void setp_a(string x) { p_a = x; }
    void showp_a() { cout << p_a << endl;}
};

class Child : private Parent, public Parent2 {
    // private Рarent
public:
    // public Parent2 
    void messageC() { cout << "Child class: "; }
    void setprv(string x) { prv = x; }
    void showprv() { cout << prv << endl; }
};

int main()
{
    GrandParent obj1;
    obj1.messageG();
    obj1.seta("sets a string from private");
    obj1.showa();

    Parent obj2;
    obj2.messageP();
    obj2.seta("sets a string from GP public using a function");
    obj2.showa();

    Parent2 obj3;
    obj3.messageP2();
    obj3.setp_a("sets a string from GP protected using a function");
    obj3.showp_a();

    Child obj4;
    obj4.messageC();
    obj4.setprv("sets a string from Parent public");
    obj4.showprv();
    obj4.setp_a("sets a string from Parent2 public");
    obj4.showp_a();

    return 0;
}