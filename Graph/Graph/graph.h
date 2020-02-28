// graph.h : Этот файл содержит объявление класса Графа и методов для взаимодействия с ним
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
		// Граф - вектор пар, где первый элемент pair это название вершины, а второй элемент - вектор содержащий расстояние до соседней вершины
		std::vector<std::pair<int, std::vector<int>>> _graph; 
	protected:
		int indexOf(int); // Метод нахождения индекса по названию вершины
	public:
		Graph();
		Graph(std::vector<std::pair<int, std::vector<int>>>);
		~Graph();

		void createGraph(); // Создание графа
		void eraseGraph(); // Удаление графа

		void addVertex(); // Добавление вершины в граф
		void eraseVertex(int); // Удаление вершины из графа

		void addEdges(int, int); // Добавление ребра в граф
		void eraseEdges(int, int); // Удаление ребра из графа

		void output(); // Вывод графа в консоль

		void optimalWay(int, std::string); // Минимальный путь
		std::vector<int> articulationPoints(); // Точки сочленения графа
		std::string connectedness(); // Связность графа (Метод поиска в ширину)
	};
}
#endif // !GRAPH_H

