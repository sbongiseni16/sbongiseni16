// complex.cpp
// Multiplying complex numbers

#include <iostream>  // contains the definition of cout, endl
#include <complex>   // contains the complex class definition

using namespace std; // cout, endl, complex are all part of this namespace

int main()
{
    using complex_flt = complex<float>; // An alias for complex<float>
    auto num1 = complex_flt{2.0, 2.0};  // use auto for type deduction
    auto num2 = complex_flt{4.0, -2.0}; // use uniform initialization syntax (curly braces)

    auto answer = num1 * num2; // type deduced for 'answer' is: complex<float>

    cout << "The answer is: " << answer << endl;
    cout << "Or in a more familiar form: " << answer.real()
         << " + " << answer.imag() << "j"
         << endl << endl;

    // answer++;
    // When I uncomment 'answer++', the program does not compile.
    // This is because the increment operator (++) is not defined for the 'std::complex' class.
    // Therefore, for the C++ Standard Library, the increment operator is not applicable to complex numbers.

    return 0;
}
