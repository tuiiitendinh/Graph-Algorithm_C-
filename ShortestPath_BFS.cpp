#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Dùng cho đồ thị vô hướng, không có trọng số
 * Shortest Path chỉ dùng BFS nếu đồ thị không có chu trình và đồ thị không có trọng số hoặc trọng số đều bằng nhau
 */

void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u);
} 

void ShortestPath(vector <int> adjList[], vector <bool> visitedVertex, int source){
  int v;
  queue <int> Q; //Set up hàng đợi (không ưu tiên)
  vector <int> ShortestPaths(visitedVertex.size());
  ShortestPaths.at(source) = 0;
  for (int i = 0; i < ShortestPaths.size(); i++)
    if (i != source)
      ShortestPaths.at(i) = 1000000; //tất cả khoảng cách đưa về +vô cực
  Q.push(source);

  while (!Q.empty()){
    v = Q.front();
    visitedVertex.at(v) = true;
    Q.pop();
    for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) //Duyệt tất cả
      if (!visitedVertex.at(*it)){
        Q.push(*it); // Push đỉnh chưa duyệt vào Queue

        if (ShortestPaths.at(v) + 1 < ShortestPaths.at(*it))
          ShortestPaths.at(*it) = ShortestPaths.at(v) + 1; // Get giá trị khoảng cách mới
        visitedVertex.at(*it) = true;
      } 
  } 
  cout << "Shortest paths from " << source << ": ";
  for (int i = 0; i < ShortestPaths.size(); i++)
    cout << ShortestPaths.at(i) << " ";
  cout << endl;
} // ShortestPath

int main (void){
  const int numVertices = 6; // 6 đỉnh (0,1,2,3,4,5)
  int source = 0;
  vector<int> adjList[numVertices];
  vector <bool> visitedVertex(numVertices, false);
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 1, 2);
  createAndAddEdge(adjList, 1, 5);
  createAndAddEdge(adjList, 2, 3);
  createAndAddEdge(adjList, 2, 4);
  createAndAddEdge(adjList, 3, 3);
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 5, 5);
  ShortestPath(adjList, visitedVertex, source); 
  //Shortest Path from 0: 0 1 2 3 3 2
} 