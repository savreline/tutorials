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
        string getName() { 
            return name; 
        }
        int getId() {
            return id; 
        }
};

int main() {
    SampleClass s("Hello", 1);
    SampleClass* p = &s;

    // Those notations are equivalent
    cout << "Result of getName is: " << (*p).getName() << endl;
    cout << "Result of getName is: " << p->getName() << endl;

    int x = 1;
    int* y = &x;

    int a, b, c;
    int *q, *r, *t = NULL;

    // Use this check whenever you are expecting null pointers
    if (t) {
        cout << "Pointer t is NOT NULL" << endl;
    } else {
        cout << "Pointer t is IS NULL" << endl;
    }
} 
