// menu.cpp : ���� ���� �������� ������� "menu"
// ������� �������� ���������������� ���� ��� �������������� � ������.
#include <iostream>
#include "graph.h"
void menu()
{
    unsigned int num = 0;
    grph::Graph graph;
    for (;;)
    {
        std::cout << "*** ���� ***" << std::endl;
        std::cout << "1. �������� �����" << std::endl; // TODO: ��������� ������� �������������: ���������� ������� �����, ������� � ���������� ����������� �������.
        std::cout << "2. ����� �����" << std::endl;
        std::cout << "3. ���������� �����" << std::endl; 
        std::cout << "4. �������� �����" << std::endl; 
        std::cout << "5. ���������� �������" << std::endl; 
        std::cout << "6. �������� �������" << std::endl; 
        std::cout << "7. ����������� �������" << std::endl; // TODO: ����������� ���� �� ����� ����� �� ��� ���������, � ���� ��� ��������� �����
        std::cout << "8. �������� �����������(���������)" << std::endl; // TODO: �������� �����������(���������) ���� ��� ������ �� ����� ������ �� ��������� (������ ��� ����)
        std::cout << "9. ����� ����������" << std::endl; // TODO: ���������� ����� ���������� ��������� ������������ ��� ����������� ����������� � ����� ������ ��������� �����
        std::cout << "10. ������� �����" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cout << ">> "; std::cin >> num;

        int first;
        int second;

        if (num == 1)
        {
            std::cout << "\t�������� �����." << std::endl;
            graph.createGraph();
        }
        else if (num == 2)
        {
            graph.output();
        }
        else if (num == 3)
        {
            std::cout << "������� ������ ������ ��� ������� ����� �������� �����: ";
            std::cin >> first >> second;
            graph.addEdges(first, second);
        }
        else if (num == 4)
        {
            std::cout << "������� ������ ������ ��� ������� ����� ������� �����: ";
            std::cin >> first >> second;
            graph.eraseEdges(first, second);
        }
        else if (num == 5)
        {
            graph.addVertex();
        }
        else if (num == 6)
        {
            std::cout << "������� ����� ������� ��� ��������: "; std::cin >> first;
            graph.eraseVertex(first);
        }
        else if (num == 7)
        {
            std::string str;
            int start;
            std::cout << "������� ����� ������� � ������� ���������� �����: ";
            std::cin >> start;
            std::cout << "������� ������ ������ ��� ������� ����� ����� �������('a' ��� ���� ������): ";
            std::cin >> str;
            graph.optimalWay(start, str);
        }
        else if (num == 8)
        {
            std::cout << "���� " << graph.connectedness() << std::endl;
        }
        else if (num == 9)
        {
            std::cout << "����� ���������� �����: ";
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