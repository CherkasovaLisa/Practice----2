#include <iostream> // Используем заголовочный файл потока ввода/вывода
#include <cmath> // Используем заголовочный файл математических функций
#include <numbers>
#include "Changeble.cpp"
#include "Consos.cpp"

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
        //flooo
        // Считаем по формуле площади круга площадь круга
        double CircleArea = radius * radius * std::numbers::pi;
        // Округляем:
        double trimmed = round(CircleArea * 100.0) / 100.0;
        // Выводим в консоль рассчёты:
        cout << "Площадь круга: " << trimmed << endl;
        return CircleArea;
    }

    // Подзадача 3
    static double RectangleArea(double first, double second)
    {
        // Проверка на отрицательные значения
        if (first < 0.0 || second < 0.0)
        {
            cout << "Ошибка: стороны не могут быть отрицательными." << endl;
            return -1.0; // Возвращаем -1 для индикации ошибки ввода
        }

        // Вычисляем площадь
        double area = first * second;

        // Округляем до двух знаков после запятой
        double result = round(area * 100.0) / 100.0;

        // Выводим результат в консоль
        cout << "Площадь прямоугольника со сторонами " << first << " и " << second << " равна " << result << endl;

        return result;
    }

    // Подзадача 4: Метод расчёта площади треугольника по формуле Герона
    static double TriangleArea(double first, double second, double third)
    {
        // Проверка на существование треугольника (неравенство треугольника)
        if (first <= 0, second <= 0, third <= 0 || first + second <= third, first + third <= second, second + third <= first)
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

    static int Factorial(int a)
    {
        double b = 1;
        while (a > 0)
        {
            b *= a; a -= 1;
        };
        return b;
    };
};
int main()
{
    setlocale(LC_ALL, "");
    Console::SetRussianOnWindows();
    while (true)
    {
        cout << "=== Калькулятор площадей ===" << endl;
        cout << "Введите три числовых значения." << endl;
        cout << "Они будут использоваться для дальнейших вычислений." << endl;
        cout << endl;

        double a = 0.0;
        double b = 0.0;
        double c = 0.0;

        cout << "Введите первое значение: ";
        cin >> a;

        cout << "Введите второе значение: ";
        cin >> b;

        cout << "Введите третье значение: ";
        cin >> c;

        cout << endl;
        cout << "Введенные значения:" << endl;
        cout << "1) " << a << endl;
        cout << "2) " << b << endl;
        cout << "3) " << c << endl;

        cout << "0 - exit; \n1 - пл. груга; \n2 - пл. прямоугольника; \n3 - пл. треугольника (по стр.); \n4 - пл. треугол. (осн и выс) \n5 - факториал" << endl;
        cout << "Введите номерн функции:" << endl;
        int swich = 0; cin >> swich;
        switch (swich) {
        case 0: return 0;
        case 1: double radius; cout << "Введите радиус:"; cin >> radius; cout << Calculator::CircleArea(radius) << endl; break;
        case 2:  cout << Calculator::RectangleArea(a, b) << endl; break;
        case 3: cout << Calculator::TriangleArea(a, b, c) << endl; break;
        case 4: cout << Calculator::TriangleArea(a, b) << endl; break;
        case 5: cout << Calculator::Factorial(a) << endl; break;
        default:cout << "Подумай. \nещё. \nраз." << endl; break;
        }

    };
};