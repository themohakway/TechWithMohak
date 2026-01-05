#include <iostream>
#include <vector>
#include <algorithm>   // for std::min, std::max, min_element, max_element
#include <cmath>       // for abs, pow, sqrt, ceil, floor, log, sin, etc.
#include <numeric>     // for std::gcd, std::lcm (C++17+)
#include <climits>     // for INT_MAX, INT_MIN, LLONG_MAX, etc.
#include <iomanip>     // for std::setprecision (better float output)

using namespace std;

int main() {
    cout << "=== C++ Math Functions Every FAANG Interviewee MUST Know ===\n";
    cout << "Current date: January 05, 2026\n\n";
    cout << fixed << setprecision(4);  // Show 4 decimal places for floats

    // Sample values for demonstration
    int a = 12, b = 18;
    double x = 3.7, y = -5.6;
    long long big = 123456789012LL;
    vector<int> arr = {4, 2, 9, 1, 7};

    // 1. Absolute Value Functions
    cout << "1. Absolute Value Functions\n";
    cout << "   abs(-10)           = " << abs(-10) << "    // Returns absolute value of int\n";
    cout << "   labs(-100000L)     = " << labs(-100000L) << " // For long\n";
    cout << "   llabs(-big)        = " << llabs(-big) << " // For long long\n";
    cout << "   fabs(-5.6)         = " << fabs(y) << "    // For double/float\n\n";

    // 2. min() and max() + min_element/max_element
    cout << "2. min() and max() Functions\n";
    cout << "   min(5, 8)          = " << min(5, 8) << "    // Smaller of two values\n";
    cout << "   max(5, 8)          = " << max(5, 8) << "    // Larger of two values\n";
    cout << "   Array: ";
    for (int val : arr) cout << val << " ";
    cout << "\n   min_element        = " << *min_element(arr.begin(), arr.end()) << " // Smallest in range\n";
    cout << "   max_element        = " << *max_element(arr.begin(), arr.end()) << " // Largest in range\n\n";

    // 3. Power, Square Root, Cube Root
    cout << "3. pow(), sqrt(), cbrt()\n";
    cout << "   pow(2, 10)         = " << pow(2, 10) << " // 2^10 (returns double!)\n";
    cout << "   sqrt(25.0)         = " << sqrt(25.0) << " // Square root\n";
    cout << "   sqrt(20.0)         = " << sqrt(20.0) << " // ≈4.4721\n";
    cout << "   cbrt(27.0)         = " << cbrt(27.0) << " // Cube root\n";
    cout << "   cbrt(100.0)        = " << cbrt(100.0) << " // ≈4.6416\n\n";

    // 4. Rounding Functions
    cout << "4. Rounding Functions\n";
    cout << "   x = " << x << "\n";
    cout << "   ceil(x)            = " << ceil(x) << "   // Round up to next integer\n";
    cout << "   floor(x)           = " << floor(x) << "  // Round down to previous integer\n";
    cout << "   round(x)           = " << round(x) << "  // Round to nearest integer\n";
    cout << "   trunc(x)           = " << trunc(x) << "  // Truncate toward zero\n";
    cout << "   ceil(-3.7)         = " << ceil(-x) << "  // Note: ceil goes away from zero\n";
    cout << "   floor(-3.7)        = " << floor(-x) << " // floor goes toward zero\n\n";

    // 5. Logarithms (very useful for digit count, binary search, etc.)
    cout << "5. Logarithmic Functions\n";
    int num = 1000;
    cout << "   Number: " << num << "\n";
    cout << "   log(1000) (natural) = " << log(1000) << " // ln(1000) ≈6.9078\n";
    cout << "   log10(1000)         = " << log10(1000) << " // log base 10 = 3\n";
    cout << "   Digits in " << num << " = " << (int)floor(log10(num)) + 1 << " // Standard trick\n\n";

    // 6. GCD and LCM (C++17+) - Super common in number theory problems
    cout << "6. GCD and LCM (C++17)\n";
    cout << "   gcd(" << a << ", " << b << ") = " << gcd(a, b) << " // Greatest Common Divisor\n";
    cout << "   lcm(" << a << ", " << b << ") = " << lcm(a, b) << " // Least Common Multiple\n\n";

    // 7. Trigonometric Functions (used in geometry problems)
    cout << "7. Trigonometric Functions (in radians)\n";
    double angle = M_PI / 4;  // 45 degrees
    cout << "   Angle = π/4 ≈ 45°\n";
    cout << "   sin(angle)         = " << sin(angle) << " // ≈0.7071\n";
    cout << "   cos(angle)         = " << cos(angle) << " // ≈0.7071\n";
    cout << "   tan(angle)         = " << tan(angle) << " // =1.0000\n\n";

    // 8. Useful constants from <climits>
    cout << "8. Important Constants\n";
    cout << "   INT_MAX            = " << INT_MAX << "   // 2^31 - 1\n";
    cout << "   INT_MIN            = " << INT_MIN << "   // -2^31\n";
    cout << "   LLONG_MAX          = " << LLONG_MAX << " // 2^63 - 1\n\n";

    cout << "=== End of Demo ===\n";
    cout << "Pro Tip: In interviews, avoid pow() for large integers (precision + overflow issues).\n";
    cout << "         Always write your own binary exponentiation instead!\n";

    return 0;
}