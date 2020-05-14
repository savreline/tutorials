#include <iostream>
using namespace std;

/* Global Counts */
int count, count1, count2;

/* Example 1 */
void example1(int n) {
    for (int i = 0; i < n; i++)
        count++;
}

/* Example 2 */
void example2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            count++;
    }
}

/* Example 3 */
void example3(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++)
            count++;
    }
}

/* Example 4 */
void example4(int n) {
    for (int i = 0; i * i < n; i++)
        count++;
}

/* Example 5 */
void example5(int n) {
    for (int i = 1; i < n; i += i)
        count++;
}

/* Example 6 */
void example6(long int n) {
    cout << (long) n * n * n << endl;
    for (long int i = n * n * n; i > 0; i /= 3)
        count++;
}

/* Example 7 */
void example7(int n) {
    for (int i = 0; i < n; i += 5)
        count++;
}

/* Example 8 */
void example8(int n) {
    int m = 0;
    int i = n;
    while (i > 0) {
        i /= 4;
        m++;
    }

    for (i = 0; i < n * m; i++)
        count++;
}

/* Example 9 */
void example9(int n) {
    for (int i = 0; i < n * n; i++) {
        for (int j = 0; j * j * j < n; j++)
            count1++;
        for (int j = 1; j < n; j *= 2)
            count2++;
    }
}

int main() {
    int n = 2000;

    count = 0; example1(n);
    cout << "example1: " << count << endl;

    count = 0; example2(n);
    cout << "example2: " << count << endl;

    count = 0; example3(n);
    cout << "example3: " << count << endl;

    count = 0; example4(n);
    cout << "example4: " << count << endl;

    count = 0; example5(n);
    cout << "example5: " << count << endl;

    count = 0; example6(n);
    cout << "example6: " << count << endl;

    count = 0; example7(n);
    cout << "example7: " << count << endl;

    count = 0; example8(n);
    cout << "example8: " << count << endl;

    count1 = 0; count2 = 0; example9(n);
    cout << "example9: " << count1 << ", " << count2 << endl;
}
