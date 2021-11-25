/* 
	Determinar si un número entero se encuentra en un conjunto de números enteros, 
	a través del método Las Vegas Randomized Algorithm
	
	Autor: Daniel Yamamoto
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>

//Complejidad O(n)
void printVector(std::vector<int> v) {
    for (auto& x: v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// Complejidad O(n)
void randomBinarySearch(std::vector<int> numbers, int search) {
    int min = 0;
    int max = numbers.size()-1;
    int pivot = min + rand()%(max-min);
    std::vector<int>::iterator it = numbers.begin()+pivot;

    while (*it != search && max > min) {
        // Actualizar pivot al azar entre min y max
        pivot = min + rand()%(max-min);
        // Actualizar limites (min y max)
        if (search > numbers[pivot]) { min = pivot + 1; } 
        else { max = pivot + 1; }
        // Actualizar it
        it = numbers.begin()+pivot;
    } 

    std::cout << std::to_string(search) << (max > min ? " found at " + std::to_string(pivot) : " not found") << std::endl; 
}

int main() {
    srand(time(NULL)); 
    int search, input;
    std::cin >> search;
    std::vector<int> numbers;

    while (std::cin >> input) {
        if (input < 0) break;
        numbers.push_back(input);
    }

    sort(numbers.begin(), numbers.end());
    printVector(numbers);
    randomBinarySearch(numbers, search);
}