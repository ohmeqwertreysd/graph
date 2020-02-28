// graph.cpp : ���� ���� �������� ����������� ��� ������� ������ �����
#include "graph.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <stack>
namespace grph
{
	Graph::Graph()
	{
		_graph = 
		{
				{0 ,{0, 5, 1, 11, 0, 0, 0, 0, 0, 0, 0, 0,  0}},
				{1 ,{5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 7, 0,   1}},
				{2 ,{1, 5, 0, 11, 0, 0, 0, 5, 0, 11, 0, 0, 0}},
				{3 ,{11, 0, 11, 0, 7, 3, 0, 0, 0, 0, 0, 0, 0}},
				{4 ,{0, 0, 0, 7, 0, 0, 3, 0, 0, 0, 0, 0,   0}},
				{5 ,{0, 0, 0, 3, 0, 0, 7, 0, 0, 0, 0, 0,   0}},
				{6 ,{0, 0, 0, 0, 3, 7, 0, 0, 0, 0, 0, 0,   0}},
				{7 ,{0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0,   0}},
				{8 ,{0, 0, 0, 0, 0, 0, 0, 5, 0, 7, 0, 0,   0}},
				{9 ,{0, 0, 11, 0, 0, 0, 0, 0, 7, 0, 0, 0,  0}},
				{10 ,{0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11,  0}},
				{11 ,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0,  1}},
				{12 ,{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,   0}}
		};
	}

	Graph::Graph(std::vector<std::pair<int, std::vector<int>>> graph) : _graph(graph) {}

	Graph::~Graph() {}

	void Graph::createGraph()
	{
		_graph.clear();
		std::cout << "������� ������: ";
		int size;
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			addVertex();
		}

		std::cout << "�������� �����." << std::endl;
		unsigned char ch = '\0';
		do
		{
			int first;
			int second;
			std::cout << "������� ������ ������ ��� ������� ����� �������� �����: ";
			std::cin >> first >> second;
			addEdges(first, second);
			std::cout << "���������� ����������?(y/n): "; std::cin >> ch;
		} while (ch != 'n');
	}

	void Graph::eraseGraph()
	{
		for (auto& n : _graph)
		{
			n.second.erase(n.second.begin(), n.second.end());
		}
		_graph.erase(_graph.begin(), _graph.end());
	}

	void Graph::output()
	{
		std::cout << "    ";
		for (size_t num = 0; num < _graph.size(); num++)
		{
			std::cout << std::setw(4) << _graph[num].first << std::setw(4) << "|";
		}

		std::cout << '\n' << std::string(8 * _graph.size() + 4, '-') << '\n';

		for (auto column = _graph.begin(); column != _graph.end(); column++)
		{
			std::cout << column->first << "  |";
			for (size_t row = 0; row < column->second.size(); row++)
			{
				std::cout << std::setw(4) << column->second[row] << std::setw(4) << "|";
			}
			std::cout << '\n' << std::string(8 * _graph.size() + 2, '-') << '\n';
		}
	}

	int Graph::indexOf(int num)
	{
		for (int count = 0; count < _graph.size(); count++)
		{
			if (_graph[count].first == num)
			{
				return count;
			}
		}
		return -1;
	}

	void Graph::addVertex()
	{
		static int id = 1;
		_graph.push_back({ id++, {} });
		for (auto& n : _graph)
		{
			n.second.resize(_graph.size());
		}
		std::cout << "��������� �������: '" << id << "'" << std::endl;
	}

	void Graph::eraseVertex(int num)
	{
		num = indexOf(num);
		if (num >= 0)
		{
			_graph.erase(_graph.begin() + num);
			for (auto& n : _graph)
			{
				n.second.erase(n.second.begin() + num);
			}
			return;
		}
		std::cout << "�� ������� ����� �������. ���������� ��� ���." << std::endl;
	}

	void Graph::addEdges(int first, int second)
	{
		first = indexOf(first);
		second = indexOf(second);

		if (first >= 0 && second >= 0)
		{
			unsigned char ch = '\0';
			if (_graph[first].second[second] != 0 || _graph[second].second[first] != 0)
			{
				std::cout << "����� ����� ��� ����������. �������� ���?(y/n): ";
				std::cin >> ch;
				if (ch == 'y')
				{
					_graph[first].second[second] = _graph[second].second[first] = 0;
				}
				else if (ch == 'n')
				{
					return;
				}
			}
			int weight;
			std::cout << "������� ��� �����: "; std::cin >> weight;
			std::cout << "����� ���������������(y)/�����������������(n): "; std::cin >> ch;
			if (ch == 'y')
			{
				_graph[first].second[second] = weight; _graph[second].second[first] = 0;
			}
			else if (ch == 'n')
			{
				_graph[first].second[second] = _graph[second].second[first] = weight;
			}
			return;
		}
		std::cout << "�� ������� ����� �������. ���������� ��� ���." << std::endl;
	}

	void Graph::eraseEdges(int first, int second)
	{
		first = indexOf(first);
		second = indexOf(second);
		if (first >= 0 && second >= 0)
		{
			_graph[first].second[second] = _graph[second].second[first] = 0;
			std::cout << "����� �������." << std::endl;
			return;
		}
		std::cout << "�� ������� ����� �����. ���������� ��� ���." << std::endl;
	}

	void Graph::optimalWay(int start, std::string whereTo)
	{
		std::vector<int> points; // ����� �� ������� ����� ����� ����
		if (whereTo != "a") // ���� ������� �� ��� �����
		{
			std::string num;
			std::istringstream ss(whereTo);
			while (ss >> num)
			{
				points.push_back(indexOf(std::stoi(num))); // ����������� ��������� ������ ����� � ������ 
			}
		}
		else // ���� ������� ��� �����
		{
			for (auto n : _graph)
			{
				points.push_back(indexOf(n.first)); // ��������� �� � ������
			}
		}

		start = indexOf(start);
		std::vector<int> distance(_graph.size(), std::numeric_limits<int>::max()); // ����������� ���������� �� ������ / ���������� ������� ���������� ������������� ����������
		distance[start] = 0; // ���������� ��������� ����� ����� 0
		std::vector<bool> intree(_graph.size(), false);  // ���������� �������
		std::vector<int> prev(_graph.size()); // ������ ������� 

		for (;;) // ��������� ��������� ������ ����������� �����
		{
			int index = -1; // ������ �������
			int min = std::numeric_limits<int>::max(); // ����������� ���������� �� �������� �������
			for (size_t i = 0; i < _graph.size(); i++)
			{
				if (!intree[i] && distance[i] < min) // ���� ������� �� �������� � �� ����� ������ �����������
				{
					min = distance[i]; // ��������� ������� 
					index = i; // ������ ������ �������
				}
			}
			if (index == -1) // ���� ��������� ������� �� �������
			{
				break; // ������� �� ����� ��������� ���������
			}
			for (size_t i = 0; i < _graph.size(); i++)
			{
				if (!intree[i] && _graph[index].second[i] > 0 && min + _graph[index].second[i] < distance[i]) // ���� �������� ������� �� �������� � �� ��� ����� ���������
				{
					distance[i] = min + _graph[index].second[i]; // ��������� ����� �������� ������� �� ����������� ���������� �� ���
					prev[i] = index; // ���������� ������� �� ������� ������
				}
			}
			intree[index] = true; // ���������� ������� � ����������
		}

		// �������������� ����
		for (auto n : points)
		{
			if (n == start)
			{
				continue;
			}
			std::stack<int> way;
			int index = n;
			for (;;)
			{
				way.push(_graph[index].first);
				if (index == start)
				{
					break;
				}
				index = prev[index];
			}
			if (intree[n])
			{
				std::cout << "���������� ���������� �� '" << _graph[start].first << "' �� " << _graph[n].first << "' - " << distance[n] << std::endl;
				std::cout << "����: ";
			}
			else
			{
				std::cout << "�� ������� ����� ���������� �� '" << _graph[start].first << "' �� " << _graph[n].first << "'" << std::endl;
				continue;
			}
			while (!way.empty())
			{

				std::cout << way.top();
				if (way.size() > 1)
				{
					std::cout << " -> ";
				}
				way.pop();
			}
			std::cout << std::endl;
		}
	}

	std::vector<int> Graph::articulationPoints()
	{
		std::vector<int> answ; // ������ ����� ����������
		for (auto n : _graph)
		{
			Graph graph(_graph); // ����� ����� ��� �������� �����
			graph.eraseVertex(n.first); // ������� ����
			if (graph.connectedness() == "���������") // ���� ���� ���� ��������� 
			{
				answ.push_back(n.first); // �������� � ������ �������� ���� �������
			}
		}
		return answ;
	}

	std::string Graph::connectedness()
	{
		std::vector<bool> intree(_graph.size()); // ���������� �������
		std::queue<int> que; // ������� ��� ������ ����� � �������
		int start = _graph.begin()->first; // ������� ����� ������ ������� �� ������� ���������
		que.push(start); // ��������� ��������� � �������
		intree[indexOf(start)] = true; // �������� ��� ����������

		while (!que.empty() && std::find(intree.begin(), intree.end(), false) != intree.end()) // ���� ������� �� ������ � � ������� ������ ���� ������������ �����
		{
			int n = indexOf(que.front()); // ���������� �� ������� ������� ��� ������ ��� ���
			que.pop();

			for (size_t i = 0; i < _graph.size(); i++) // �������� �������� ������
			{
				if (!intree[i] && _graph[n].second[i] != 0) // ���� �������� ������� �� �������� � �� ��� ���� ����
				{
					intree[i] = true; // �������� �� ��� ����������
					que.push(_graph[i].first); // � ��������� � �������
				}
			}
		}
		// ���� �������� ������������ �������, �� ���� ��������
		return (std::find(intree.begin(), intree.end(), false) == intree.end()) ? "�������" : "���������";
	}
}