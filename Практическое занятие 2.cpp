g#include <iostream> // Используем заголовочный файл потока ввода/вывода
#include <cmath> // Используем заголовочный файл математических функций

#include "Переменные.cpp"
#include "Консоль.cpp"

using namespace std; // Используем стандартную библиотеку

/*
    Групповое занятие: совместными усилиями реализовать доп. функции калькулятора

    1) Назначьте руководителя проекта
    Руководитель проекта должен создать репозиторий проекта калькулятора и добавить туда своих напарников.
    Затем распределите подзадачи на каждого участника.

    2) Каждый участник проекта должен запуллить проект из репозитория себе и создать ветку,
    назвать её своим ФИО латиницей, выполнить свою подзадачу в ней, после чего создать
    запрос на слияние ветвей (merge request)

    3) Команда просматривает каждую ветку, оставляет свои комментарии по доработке, если необходимо, затем
    руководитель проекта производит слияние в мастер-ветку. Итоговый проект должен корректно проводить вычисления

    ПОДЗАДАЧИ:

    1. Доработать int main()
        1.1 Вывести в консоль указания пользователю для работы с программой
        1.2 Реализовать ввод трех значений с консоли и хранение этих переменных для других методов
    2. Описать метод рассчёта площади круга
    3. Описать метод рассчёта площади прямоугольника
    4. Описать метод рассчёта площади треугольника по формуле Герона
    5. Описать метод рассчёта площади треугольника через основание и высоту

    В конце прошу округлять вычисления до двух знаков после запятой, используя
    double rounded = round(value * 100.0) / 100.0 - вернёт число с двумя знаками после запятой
    Помимо вычислений, каждый метод должен делать аккуратный вывод результата в консоль
    */

int main()
{
    Console::SetRussianOnWindows();
    // Подзадача 1

    // Для проверки задания: снять комментарии, заполнить методы переменными, 
    // запустить и посмотреть консольный вывод
    Calculator::Sum(3., 5.);
    // Calculator::CircleArea();
    // Calculator::RectangleArea();
    // Calculator::TriangleArea();
    // Calculator::TriangleArea();
}
int sum(int a, int b)
{
    int sum = a + b;
    return sum;
}
int vich(int c, int d)
{
    int vich = c - d;
    return vich;
}
int ymn(int e, int f)
{
    int ymn = e * f;
    return ymn;
}
int del(int g, int h)
{
    int del = g / h;
    return del;
}

class Calculator
{
public:

    /// <summary>
    /// Вычисляет сумму двух чисел с плавающей запятой
    /// </summary>
    /// <param name="a">Первое значение</param>
    /// <param name="b">Второе значение</param>
    /// <returns>Итоговая сумма</returns>
    static double Sum(double a, double b)
    {
        // Вычисляем
        double sum = a + b;
        // Округляем
        double result = round(sum * 100.0) / 100.0;
        // Выводим в консоль рассчёты
        cout << "Сумма: " << sum << endl;

        return sum;
    }

    // Подзадача 2
    static double CircleArea(double radius)
    {
        return 0;
    }

    // Подзадача 3
    static double RectangleArea(double first, double second)
    {
        return 0;
    }

    // Подзадача 4: Метод расчёта площади треугольника по формуле Герона
    static double TriangleArea(double first, double second, double third)
    {
        // Проверка на существование треугольника (неравенство треугольника)
        if (first <= 0,  second <= 0,  third <= 0 || first + second <= third,  first + third <= second,  second + third <= first) 
        {
            cout << "Ошибка: треугольник с такими сторонами не существует." << endl;
            return -1.0;
        }
        double p = (first + second + third) / 2.0;
        double value = sqrt(p * (p - first) * (p - second) * (p - third));
        double result = round(value * 100.0) / 100.0;
        cout << "Площадь треугольника со сторонами " << first << ", " << second << " и " << third << " равна: " << result << endl;
        return result;
    }

    int main() {
        double a, b, c;
        std::cout << "Введите длины трех сторон треугольника: ";
        std::cin >> a >> b >> c;

        double area = TriangleArea(a, b, c);

        if (area < 0) 
        {
            std::cout << "Такой треугольник не существует!" << std::endl;
        }
        else {
            std::cout << "Площадь треугольника: " << area << std::endl;
        }

        return 0;
    }

    // Подзадача 5: Метод расчёта площади треугольника через основание и высоту
    static double TriangleArea(double base, double height)
    {
        if (base < 0 || height < 0) 
        {
            cout << "Ошибка: основание и высота не могут быть отрицательными." << endl;
            return -1.0;
        }
        double value = 0.5 * base * height;
        double result = round(value * 100.0) / 100.0;
        cout << "Площадь треугольника с основанием " << base << " и высотой " << height << " равна: " << result << endl;
        return result;
    }
};
