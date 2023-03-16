#include <iostream>
#include <vector>
#include <string>

void print_subranges(std::vector<int> range)
{
    //Получаем размер множества
    size_t size = range.size();

    //Получаем кол-во подмножеств
    size_t n = std::pow(2,size);

    for(size_t i = 0;i < n;++i)
    {
        std::cout << "Y" << i + 1 << " -> ";
        size_t lastElement = 0;

        //Выводим бинарную последовательность для i подмножества
        for(int b = size -1;b >= 0;--b)
        {
            if(i & (1 << b))
            {
                std::cout << '1';
                lastElement = b;
            }
            else
            {
                std::cout << '0';
            }
        }

        std::cout << " => ";
        std::cout << "{ ";

        //Выводим подмножество на основе бинарной последовательности
        for(int b = size -1;b >= 0;--b)
        {
            if(i & (1 << b))
            {
                if(b != lastElement)
                    std::cout << range[size - 1 - b] << ", ";
                else
                    std::cout << range[size - 1 - b] << ' ';
            }
        }

        std::cout << "}" << std::endl;
    }
}

int main()
{

    std::string value_string;
    int value;
    bool error;

    //Считываем размер множества, пока пользователь не введет верный размер
    do
    {
        std::cout << "Enter element count : ";
        std::cin  >> value_string;

        try
        {
            value = std::stoi(value_string);
        }
        catch(const std::exception& e)
        {
            std::cout << "Cannot convert to number" << std::endl;
            value = 0;
        }

        if(value == 0 || value < 0)
            std::cout << "Size should be number more 0" << std::endl;

    }while(value <= 0);

    size_t size = value;

    //Создаем переменную хранящюю само множество
    std::vector<int> range(size);

    //Вводим все элементы множества
    std::cout << "Enter elements:" << std::endl;
    for(size_t i = 0;i < size;++i)
    {
        do
        {
            error = false;
            std::cout << "range[" << i << "] = ";
            std::cin >> value_string;

            try
            {
                range[i] = std::stoi(value_string);
            }
            catch(const std::exception& e)
            {
                std::cout << "Cannot convert to number" << std::endl;
                error = true;
            }
        }while(error);
    }

    print_subranges(range);

    return 0;
}