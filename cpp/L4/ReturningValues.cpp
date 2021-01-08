#include <iostream>
using namespace std;

struct Point { 
    int x, y, z;
}; 

// Bundling return values into a struct
Point foo(int x, int y, int z) { 
    x = x + 10; 
    y = y + 20; 
    z = z + 30; 
    Point p = {x, y, z}; 
    return p; 
} 

// Using pointers
void foo(int *x, int *y, int *z) { 
    *x = *x + 10; 
    *y = *y + 20; 
    *z = *z + 30;
}

int main() { 
    int x = 10, y = 20, z = 30; 
    Point p = foo(x, y, z); 
    
    x = p.x, y = p.y; z = p.z; 
    cout << "x is " << x << endl; // 20
    cout << "y is " << y << endl; // 40 
    cout << "z is " << z << endl; // 60 
    
    int *a, *b, *c; 
    a = &x, b = &y, c = &z; 
    
    foo(a, b, c); 
    cout << "x is " << x << endl; // 30 
    cout << "y is " << y << endl; // 60 
    cout << "z is " << z << endl; // 90
}
