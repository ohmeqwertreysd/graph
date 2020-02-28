// graph.h : ���� ���� �������� ���������� ������ ����� � ������� ��� �������������� � ���
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <utility>
#include <map>
#include <string>

namespace grph
{
	class Graph
	{
	private:
		// ���� - ������ ���, ��� ������ ������� pair ��� �������� �������, � ������ ������� - ������ ���������� ���������� �� �������� �������
		std::vector<std::pair<int, std::vector<int>>> _graph; 
	protected:
		int indexOf(int); // ����� ���������� ������� �� �������� �������
	public:
		Graph();
		Graph(std::vector<std::pair<int, std::vector<int>>>);
		~Graph();

		void createGraph(); // �������� �����
		void eraseGraph(); // �������� �����

		void addVertex(); // ���������� ������� � ����
		void eraseVertex(int); // �������� ������� �� �����

		void addEdges(int, int); // ���������� ����� � ����
		void eraseEdges(int, int); // �������� ����� �� �����

		void output(); // ����� ����� � �������

		void optimalWay(int, std::string); // ����������� ����
		std::vector<int> articulationPoints(); // ����� ���������� �����
		std::string connectedness(); // ��������� ����� (����� ������ � ������)
	};
}
#endif // !GRAPH_H

