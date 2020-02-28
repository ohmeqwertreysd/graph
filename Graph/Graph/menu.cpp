// menu.cpp : Этот файл содержит функцию "menu"
// Которая вызывает пользовательское меню для взаимодействия с графом.
#include <iostream>
#include "graph.h"
void menu()
{
    unsigned int num = 0;
    grph::Graph graph;
    for (;;)
    {
        std::cout << "*** Меню ***" << std::endl;
        std::cout << "1. Создание графа" << std::endl; // TODO: Структура задаётся пользователем: количество узловых точек, наличие и пропускная способность каналов.
        std::cout << "2. Вывод графа" << std::endl;
        std::cout << "3. Добавление ребра" << std::endl; 
        std::cout << "4. Удаление ребра" << std::endl; 
        std::cout << "5. Добавление вершины" << std::endl; 
        std::cout << "6. Удаление вершины" << std::endl; 
        std::cout << "7. Оптимальный маршрут" << std::endl; // TODO: Оптимальный путь из любой точки во все остальные, в одну или несколько точек
        std::cout << "8. Проверка целостности(связности)" << std::endl; // TODO: Проверка целостности(связности) сети при выходе из строя одного из элементов (канала или узла)
        std::cout << "9. Точки сочленения" << std::endl; // TODO: Нахождение точек сочленения компонент двусвязности для определения критических с точки зрения надёжности узлов
        std::cout << "10. Очистка графа" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << ">> "; std::cin >> num;

        int first;
        int second;

        if (num == 1)
        {
            std::cout << "\tСоздание графа." << std::endl;
            graph.createGraph();
        }
        else if (num == 2)
        {
            graph.output();
        }
        else if (num == 3)
        {
            std::cout << "Введите номера вершин для которых нужно добавить ребро: ";
            std::cin >> first >> second;
            graph.addEdges(first, second);
        }
        else if (num == 4)
        {
            std::cout << "Введите номера вершин для которых нужно удалить ребро: ";
            std::cin >> first >> second;
            graph.eraseEdges(first, second);
        }
        else if (num == 5)
        {
            graph.addVertex();
        }
        else if (num == 6)
        {
            std::cout << "Введите номер вершины для удаления: "; std::cin >> first;
            graph.eraseVertex(first);
        }
        else if (num == 7)
        {
            std::string str;
            int start;
            std::cout << "Введите номер вершины с которой начинается поиск: ";
            std::cin >> start;
            std::cout << "Введите номера вершин для которых нужно найти маршрут('a' для всех вершин): ";
            std::cin >> str;
            graph.optimalWay(start, str);
        }
        else if (num == 8)
        {
            std::cout << "Граф " << graph.connectedness() << std::endl;
        }
        else if (num == 9)
        {
            std::cout << "Точки сочленения графа: ";
            auto points = graph.articulationPoints();
            for (auto it = points.begin(); it != points.end(); it++)
            {
                std::cout << "'" << *it << "'";
                if (it != (points.end() - 1))
                {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
        else if (num == 10)
        {
            graph.eraseGraph();
        }
        else if (num == 0)
        {
            break;
        }
    }
}