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
        cout << "Сумма: " << result << endl;

        return result;
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
        return trimmed;
    }

    // Подзадача 3 Площадь прямоугольника через две стороны
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
        if (first <= 0 || second <= 0 || third <= 0 || first + second <= third || first + third <= second || second + third <= first)
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
    // Факториал
    static int Factorial(int num)
    {
        if (num < 0) {
            cout << "Ошибка: факториал отрицательного числа не определен." << endl;
            return -1;
        }
        // Добавляем защиту от переполнения
        if (num > 12) {
            cout << "Ошибка: число слишком большое, результат переполнит тип int." << endl;
            return -1;
        }
        int result = 1;
        for (int i = 1; i <= num; ++i) {
            result *= i;
        }
        cout << "Факториал числа " << num << " равен " << result << endl;
        return result;
    }
};

int main()
{
    Console::SetRussianOnWindows();

    // === ПОДЗАДАЧА 1: ввод трёх значений ===
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

    // === Демонстрация работы методов ===
    cout << "\n=== Результаты вычислений ===" << endl;
    Calculator::CircleArea(a);
    Calculator::RectangleArea(a, b);
    Calculator::TriangleArea(a, b, c);
    Calculator::TriangleArea(a, b);

    // === Интерактивное меню ===
    int choice;
    while (true)
    {
        cout << "\n--- Меню калькулятора ---" << endl;
        cout << "1. Площадь прямоугольника (стороны)" << endl;
        cout << "2. Площадь круга" << endl;
        cout << "3. Площадь треугольника (3 стороны)" << endl;
        cout << "4. Площадь треугольника (основание и высота)" << endl;
        cout << "5. Факториал числа" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            double x, y;
            cout << "Введите первую сторону: "; cin >> x;
            cout << "Введите вторую сторону: "; cin >> y;
            Calculator::RectangleArea(x, y);
            break;
        }
        case 2:
        {
            double r;
            cout << "Введите радиус: "; cin >> r;
            Calculator::CircleArea(r);
            break;
        }
        case 3:
        {
            double x, y, z;
            cout << "Введите три стороны: ";
            cin >> x >> y >> z;
            Calculator::TriangleArea(x, y, z);
            break;
        }
        case 4:
        {
            double base, height;
            cout << "Введите основание и высоту: ";
            cin >> base >> height;
            Calculator::TriangleArea(base, height);
            break;
        }
        case 5:
        {
            int num;
            cout << "Введите число для факториала: ";
            cin >> num;
            Calculator::Factorial(num);
            break;
        }
        case 0:
            cout << "Выход из программы. До свидания!" << endl;
            return 0;
        default:
            cout << "Ошибка: некорректный ввод." << endl;
            break;
        }
    }

    return 0;
}