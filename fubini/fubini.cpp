
#include <iostream>
#include <functional>

using namespace std;

// Example: Compute the double integral of f(x, y) = x + y
// over the rectangle [0,1] x [0,2] using Fubini's theorem.

double integrate_y(double x, function<double(double, double)> f) {
    // Integrate f(x, y) with respect to y from 0 to 2
    int n = 1000;
    double a = 0, b = 2;
    double h = (b - a) / n;
    double sum = 0.5 * (f(x, a) + f(x, b));
    for (int i = 1; i < n; ++i) {
        double y = a + i * h;
        sum += f(x, y);
    }
    return sum * h;
}

/**
 * @brief Computes the double integral of a function f(x, y) over the region x in [0, 1], y in [0, 1].
 *
 * This function numerically evaluates the double integral:
 *      ∬_{[0,1]×[0,1]} f(x, y) dy dx
 * using the composite trapezoidal rule for the outer integral with respect to x.
 * The inner integral with respect to y is performed by the helper function integrate_y(x, f),
 * which should compute ∫_{y=0}^{1} f(x, y) dy for a fixed x.
 *
 * @param f A function of two variables, f(x, y), to be integrated.
 * @return The approximate value of the double integral over the unit square.
 *
 * @note The accuracy depends on the number of subdivisions (n = 1000).
 * @note Requires the existence of integrate_y(double x, function<double(double, double)> f).
 */
double double_integral(function<double(double, double)> f) {
    // Integrate with respect to x from 0 to 1
    int n = 1000;
    double a = 0, b = 1;
    double h = (b - a) / n;
    double sum = 0.5 * (integrate_y(a, f) + integrate_y(b, f));
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += integrate_y(x, f);
    }
    return sum * h;
}

int main() {
    auto f = [](double x, double y) { return x + y; };
    double result = double_integral(f);
    cout << "Approximate value of the double integral: " << result << endl;
    // Exact value: ∫₀¹∫₀² (x + y) dy dx = 2 + 1 = 3
    return 0;
}