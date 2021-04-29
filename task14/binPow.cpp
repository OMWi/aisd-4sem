#include <iostream> 

long long binPow(int num, int power) {
    if (power == 0) {
        return 1;
    }
    if (power % 2) {
        return num * binPow(num, power-1);
    }
    if (!(power % 2)) {
        return binPow(num, power/2) * binPow(num, power/2);
    }
}

int main() {
    int num, power;
    std::cin >> num >> power;
    std::cout << binPow(num, power) << std::endl;

}