#include "matplotlibcpp.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace plt = matplotlibcpp;

int main()
{
    std::vector<double> x, y, z;
    double theta, r;
    double z_inc = 4.0 / 99.0; double theta_inc = (8.0 * M_PI) / 99.0;

    for (double i = 0; i < 100; i += 1) {
        theta = -4.0 * M_PI + theta_inc * i;
        z.push_back(-2.0 + z_inc * i);
        r = z[i] * z[i] + 1;
        x.push_back(r * sin(theta));
        y.push_back(r * cos(theta));
    }

    PyObject* ax = plt::chart(111);               // создание графического поля (один график)
    plt::Clear3DChart(ax);                        // предварительная очистка поля

    plt::plot3D(ax, x, y, z, "red", 1.0);         // построение 3D графика
    plt::Chart3DAxesNames(ax, "x", "y", "z");     // присвоение имён осям

    plt::xlim(-5.0, 5.0);                         // установка диапазона отображаемых значений по X, Y, Z
    plt::ylim(-4.0, 6.0);
    plt::set_zlim(ax, -3.0, 3.0);

    plt::show();                                  // отображение графика
}