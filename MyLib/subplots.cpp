#include "matplotlibcpp.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace plt = matplotlibcpp;

int main()
{
    int n = 50;
    std::vector<double> x(n), y(n), z(n);
    for (int i = 0; i < n; ++i) {
        x.at(i) = i;
        y.at(i) = sin(2 * M_PI * i / 50.0);
        z.at(i) = cos(2 * M_PI * i / 50.0);
    }

    std::vector<PyObject*> plots;
    for (auto& place : { 221, 222, 223, 224 }) {
        plots.push_back(plt::chart2D(place));           // создание полей для подграфиков
    }

    std::vector<std::string> plot_names;
    for (auto& name : { "1st subplot", "2nd subplot", "3rd subplot", "4th subplot" }) {
        plot_names.push_back(name);                     // имена для подграфиков
    }

    plt::suptitle("My plot");                           // имя для общего графического поля
    for (int i = 0; i < 4; ++i) {
        plt::PlotTitle(plots.at(i), plot_names.at(i));  // присвоение имён подграфикам
    }

    plt::plot2D(plots.at(0), x, y, "red", 1.0);
    plt::scatter2D(plots.at(1), x, x, "blue", 0.5);
    plt::plot2D(plots.at(2), x, z, "green", 2.0);
    plt::plot2D(plots.at(3), z, y, "yellow", 3.0);

    plt::show();
}