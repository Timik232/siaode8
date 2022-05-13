// siaode8.cpp : 
// Простого обмена (пузырек) 	Шейкерная сортировка	Рандомизированная быстрая сортировка
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
void random_generate(vector <int> &numbers) //генерирует 1000 чисел
{
    int buf;
    for (int i = 0; i < 1000; i++)
    {
        buf = rand() % 1000;
        numbers.push_back(buf);
    }
}
void manually(vector <int> &numbers)
{
    cout << "Enter amount of elements\n";
    int n;
    cin >> n;
    cout << "Enter " << n << "elements\n";
    for (int i = 0; i < n; i++)
    {
        int buf;
        cin >> buf;
        numbers.push_back(buf);
    }
}
void print(vector <int> &numbers)
{
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << endl;
}
void bubble(vector <int> &numbers)
{
    int f;
    for (int j = 1; j < numbers.size(); j++)
    {
        f = 0;
        for (int i = 0; i < numbers.size() - j; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                swap(numbers[i], numbers[i + 1]);
                f = 1;
            }
        }
        if (f == 0)
            break;
    }
}
void shaker(vector <int> &numbers)
{
    int control = numbers.size() - 1;
    int left = 0;
    int right = numbers.size() - 1;
    do {
        for (int i = left; i < right; i++) 
        {
            if (numbers[i] > numbers[i + 1]) 
            {
                swap(numbers[i], numbers[i + 1]);
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) 
        {
            if (numbers[i] < numbers[i - 1]) 
            {
                swap(numbers[i], numbers[i - 1]);
                control = i;
            }
        }
        left = control;
    } while (left < right);
}
void QuickSort(vector <int> &numbers, int n1, int n2)
{
    int i, j;
    int x, buf;
    i = n1;
    j = n2;
    x = numbers[n1 + rand() % (n2 - n1 + 1)]; //получаем случайный элемент, относительно которого будем сортировать
    do
    {
        while (numbers[i] < x)
            i++;
        while (x < numbers[j])
            j--;
        if (i <= j)
        {
            buf = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = buf;
            i++;
            j--;
        }
    } while (i <= j);
    if (n1 < j) QuickSort(numbers, n1, j);
    if (n2 > i) QuickSort(numbers, i, n2);
}
int main()
{
    vector <int> numbers;
    //manually(numbers);
    random_generate(numbers);
    //print(numbers); //посмотреть какие числа
    unsigned int start_time = clock();
    bubble(numbers);
    unsigned int end_time = clock();
    cout << "Time of bubble sort: " << end_time - start_time << endl;
    //print(numbers); //посмотреть отсортировал ли
    numbers.clear();
    random_generate(numbers);
    start_time = clock();
    shaker(numbers);
    end_time = clock();
    cout << "Time of shaker sort: " << end_time - start_time << endl;
    //print(numbers); //посмотреть отсортировал ли
    numbers.clear();
    random_generate(numbers);
    start_time = clock();
    //следующие две переменные нужны для рекуррентого вызова внутри функции сортировки
    int n1 = 0; //начало
    int n2 = numbers.size()-1; //конец
    QuickSort(numbers,n1,n2);
    end_time = clock();
    cout << "Time of quick sort: " << end_time - start_time;
    //print(numbers);
}