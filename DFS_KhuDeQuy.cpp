#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); 
} 

void DFS(vector <int> adjList[], vector <bool> visitedVertex, int source){
  // Tạo stack để lưu trữ các đỉnh đã duyệt
  stack <int> S; 
  int v;
  S.push(source);
  while (!S.empty()){
    v = S.top();
    visitedVertex.at(v) = true;
    S.pop();
    cout << v << " "; //Xuất các đỉnh đã duyệt
    //Duyệt tất cả và backtrack lại, nếu đỉnh chưa được duyệt
    for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++)
      if (!visitedVertex.at(*it)){
        //Push các đỉnh chưa duyệt vào stack
        S.push(*it); 
        visitedVertex.at(*it) = true;
      }
  } 
  cout << endl;
} // DFS

int main (void){
  const int numVertices = 5; 
  int source = 0;
  vector<int> adjList[numVertices];
  vector <bool> visitedVertex(numVertices, false);
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 3);
  createAndAddEdge(adjList, 1, 4);
  createAndAddEdge(adjList, 3, 3);
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 2, 2);
  DFS(adjList, visitedVertex, source); 
  //Ket Qua: 0 2 1 4 3

} // main()