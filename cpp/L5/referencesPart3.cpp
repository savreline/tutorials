#include <iostream>
using namespace std;

/* Declaration and Implementation of Sample Class */
class SampleClass {
    private:
        string name;
        int id;

    public:
        SampleClass(string name, int id) : name(name), id(id) {
            
        }
        int getId() const {
            return id;
        }
        void setId(int id) {
            this->id = id;
        }
};

// Pass by value
void foo1(SampleClass s) {
    s.setId(2);
}

// Pass by reference
void foo2(SampleClass &s) {
    s.setId(2);
}

// Pass by pointer
void foo3(SampleClass *s) {
    s->setId(10);
}

// Pass by constant reference
void foo4(const SampleClass &s) {
    cout << "In foo4 and id is: " << s.getId() << endl;
}

int main() {
    SampleClass s("Hello", 1);
    SampleClass *p = &s;

    foo1(s);
    cout << "After foo1 id is: " << s.getId() << endl;
    foo2(s);
    cout << "After foo2 id is: " << s.getId() << endl;   
    foo3(p);
    cout << "After foo3 id is: " << s.getId() << endl;
    foo4(s);

    int x = 1;
    int *y = &x;
    cout << "x:" << x << endl;
    cout << "*&x:" << *&x << endl;
    cout << "y:" << y << endl;
    cout << "*&y:" << &*y << endl;
}
