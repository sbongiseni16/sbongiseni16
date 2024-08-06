#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int main() {
    int a, b, c;
    using complex_flt = complex<float>;
    char x = 'b';
    
    while (x != 'q') {
        cout << "Enter values for a('a' cannot be zero), b, and c:  ";
        cin >> a >> b >> c;
        
        float discriminant = b * b - 4 * a * c;
        complex_flt x_1, x_2;
        
        if (discriminant >= 0) {
            // Real solutions
            x_1 = complex_flt((-b + sqrt(discriminant)) / (2.0 * a), 0);
            x_2 = complex_flt((-b - sqrt(discriminant)) / (2.0 * a), 0);
        } else {
            // Complex solutions
            float real_part = -b / (2.0 * a);
            float imaginary_part = sqrt(-discriminant) / (2.0 * a);
            x_1 = complex_flt(real_part, imaginary_part);
            x_2 = complex_flt(real_part, -imaginary_part);
        }
        
        cout << "The roots are x_1 = " << x_1.real() << " + " << x_1.imag() << "j and ";
        cout << "x_2 = " << x_2.real() << " + " << x_2.imag() << "j" << endl;
        cout << "Press q to quit or any other letter if you wish to do another calculation: ";
        cin >> x;
    }
    
    return 0;
}
