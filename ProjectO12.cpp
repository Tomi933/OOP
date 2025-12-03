#include <iostream>
#include <string>
#include <exception>
#include <Windows.h>
using namespace std;

class Empty {};

class Error
{
    string message;
public:
    Error(string m) : message(m) {}
    string What() const { return message; }
};

class E : public exception
{
    string message;
public:
    E(string m) : message(m) {}
    const char* what() const noexcept override { return message.c_str(); }
};

double Solve1(double a, double b, double c)
{
    if (a == 0) throw 1;
    if (a + b == 0) throw 2;

    double x = (-b * c) / (a + b);

    if (x == -c) throw 3;

    return x;
}

double Solve2(double a, double b, double c) throw()
{
    if (a == 0) throw 1.5;
    if (a + b == 0) throw 2.5;

    double x = (-b * c) / (a + b);

    if (x == -c) throw 'x';

    return x;
}

double Solve3(double a, double b, double c) throw(int)
{
    if (a == 0) throw 10;
    if (a + b == 0) throw 20;

    double x = (-b * c) / (a + b);

    if (x == -c) throw 30;

    return x;
}

double Solve4(double a, double b, double c) throw(Empty)
{
    if (a == 0 || a + b == 0)
        throw Empty();

    double x = (-b * c) / (a + b);

    if (x == -c)
        throw Empty();

    return x;
}

double Solve5(double a, double b, double c) throw(Error)
{
    if (a == 0) throw Error("a = 0: Помилка x");
    if (a + b == 0) throw Error("a + b = 0: Помилка");

    double x = (-b * c) / (a + b);

    if (x == -c) throw Error("x = -c: Помилка");

    return x;
}

double Solve6(double a, double b, double c) throw(E)
{
    if (a == 0) throw E("a = 0");
    if (a + b == 0) throw E("a + b = 0");

    double x = (-b * c) / (a + b);

    if (x == -c) throw E("x = -c");

    return x;
}


void MyUnexpected()
{
    cout << "unexpected error! - bad_exception\n";
    throw;
}

void MyTerminate()
{
    cout << "terminate called: no handler\n";
    abort();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    set_unexpected(MyUnexpected);

    double a, b, c;
    cout << "a = ? "; cin >> a;
    cout << "b = ? "; cin >> b;
    cout << "c = ? "; cin >> c;

    try
    {
        //cout << Solve1(a,b,c) << endl;
        /*cout << Solve2(a,b,c) << endl;
        cout << Solve3(a,b,c) << endl;
        cout << Solve4(a,b,c) << endl;*/
        //cout << Solve5(a,b,c) << endl;
        cout << Solve6(a, b, c) << endl;
    }
    catch (int v)
    {
        cout << "catch(int): Solve1/Solve3 -> " << v << endl;
    }
    catch (double v)
    {
        cout << "catch(double): Solve1/Solve2 -> " << v << endl;
    }
    catch (char)
    {
        cout << "catch(char): Solve2" << endl;
    }
    catch (Empty)
    {
        cout << "catch(Empty): Solve4" << endl;
    }
    catch (Error e)
    {
        cout << "catch(Error) -> " << e.What() << endl;
    }
    catch (E& e)
    {
        cout << "catch(E&) -> " << e.what() << endl;
    }
    catch (bad_exception)
    {
        cout << "catch(bad_exception)" << endl;
    }

    return 0;
}