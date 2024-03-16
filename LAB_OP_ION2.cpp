/*Реализовать функцию вычисления 
(ax + b)((a - 1)x + (b - 1))...((a - k)x + (b - k))...(x + 1)

по заданным a, b, x.
При условии, что
если a-k < 1, то a-k = 1,
если b-k < 1, то b-k = 1.

вход 2, 3, 1 
выход 30    */

#include <iostream>
int calculate(int a, int b, int x) {
    int result = a * x + b; // первый множитель, будет накапливаться результат
    int multiplier = x + 1; // значение для остановки цикла 

    for (int k = 1; ; k++) {
        int sub_a = (a - k) < 1 ? 1 : (a - k); // если a-k < 1, то a-k = 1, иначе a - k 
        int sub_b = (b - k) < 1 ? 1 : (b - k);
        int term = sub_a * x + sub_b; // получение каждого последующего множителя

        result *= term;

        if (term == multiplier)
            break;
    }

    return result;
}

int main() {
    int a, b, x;
    std::cout << "Введите числа: ";
    std::cin >> a >> b >> x;
    std::cout << "Результат вычислений: " << calculate(a, b, x) << std::endl;
    return 0;
}
