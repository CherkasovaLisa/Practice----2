#include <iostream> // Используем заголовочный файл потока ввода/вывода
#include <cmath> // Используем заголовочный файл математических функций
#include <numbers>
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

    static int Factorial(int num)
    {
        int factorial = 1;

        for (int i = 1; i <= num; i++)
        {
            factorial = factorial * i;
        }

        cout << "Факториал: " << factorial << endl;

        return factorial;
    }
};

int main()
{
    Console::SetRussianOnWindows();
    {
        Console::SetRussianOnWindows();

        int choice = -1;

        while (choice != 0)
        {
            cout << "=== Калькулятор площадей ===" << endl;
            cout << "Выберите формулу для подсчёта:" << endl;
            cout << "1) Площадь круга" << endl;
            cout << "2) Площадь прямоугольника" << endl;
            cout << "3) Площадь треугольника по формуле Герона" << endl;
            cout << "4) Площадь треугольника через основание и высоту" << endl;
            cout << "5) Факториал" << endl;
            cout << "0) Выход" << endl;
            cout << "Введите номер: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                double radius;

                cout << "Введите радиус: ";
                cin >> radius;

                Calculator::CircleArea(radius);
                break;
            }

            case 2:
            {
                double first;
                double second;

                cout << "Введите первую сторону прямоугольника: ";
                cin >> first;

                cout << "Введите вторую сторону прямоугольника: ";
                cin >> second;

                Calculator::RectangleArea(first, second);
                break;
            }

            case 3:
            {
                double first;
                double second;
                double third;

                cout << "Введите первую сторону треугольника: ";
                cin >> first;

                cout << "Введите вторую сторону треугольника: ";
                cin >> second;

                cout << "Введите третью сторону треугольника: ";
                cin >> third;

                Calculator::TriangleArea(first, second, third);
                break;
            }

            case 4:
            {
                double base;
                double height;

                cout << "Введите основание треугольника: ";
                cin >> base;

                cout << "Введите высоту треугольника: ";
                cin >> height;

                Calculator::TriangleArea(base, height);
                break;
            }

            case 5:
            {
                int num;

                cout << "Введите число для расчёта факториала: ";
                cin >> num;

                Calculator::Factorial(num);
                break;
            }

            case 0:
            {
                cout << "Выход из программы." << endl;
                break;
            }

            default:
            {
                cout << "Некорректный ввод." << endl;
                break;
            }
            }

            cout << endl;
        }

        return 0;
    }
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