#include <iostream>
using namespace std;
const double s = 0.541666666666667;
#include <ctime>

double f1(double x) { // первая функция
    return sqrt(x);
}
double f2(double x) { // вторая функция
    return pow(x, 7);
}
double reversef1(double x) {
    return x * x;
}
double reversef2(double x) {
    return pow(x, 0.77777777);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n[] = { 100, 10000, 1000000 }; // массив количетсва случайных точек
    int randomCounter = 0;
    double x, y;

    cout << "Вычисление площади фигуры по методу Монте-Карло" << endl;
    cout << "Точная площадь: " << s << endl << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Число испытаний: " << n[i] << endl;

        for (int j = 0; j < n[i]; j++) {
            x = (double)rand() / RAND_MAX; // генерирование координаты x
            y = (double)rand() / RAND_MAX; // генерирование координаты y
            double ymax = f1(x); // максимальное значение y
            double ymin = f2(x); // минимальное значение y
            double xmin = reversef1(y); // минимальное значение x
            double xmax = reversef2(y); // максимальное значение x

            if (y <= ymax and y >= ymin and x >= xmin and x <= xmax) { // если точка попадает в диапазон
                randomCounter++; // то увеличить счетчик на единицу
            }
        }
        double res = (double)randomCounter / n[i]; // расчет площади
        cout << "Площадь фигуры: " << res << endl;
        cout << "Ошибка вычисления: " << abs(s - res) << endl << endl; // вывод погрешности
        randomCounter = 0; // обнуление счетчика
    }
}