#include <iostream>
#include <vector>
using namespace std;

// Cái này thì m.n biết rồi :> 
void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); 
} 

//Đệ quy DFS
void RecursiveDFS(vector <int> adjList[], vector <bool> visitedVertex, int source){
  visitedVertex.at(source) = true;
  //Xuất các đỉnh đồ thị
  cout << source << " "; 
  for (vector<int>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
    if (!visitedVertex[*it])
     // Duyệt rất nhiều lần vì nó đệ quy mà
      RecursiveDFS(adjList, visitedVertex, *it);
}

int main (void){
    // Tạo ma trận kề như mọi khi thôi :>
  const int numVertices = 5; // 6 đỉnh (0,1,2,3,4,5)
  int source = 0;
  vector<int> adjList[numVertices]; 
  // tạo ra một vectors các đỉnh đã duyệt, gán bằng giá trị false để không duyệt lại tạo thành chu trình
  vector <bool> visitedVertex(numVertices, false); // have a visted vector initialized to false
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 3);
  createAndAddEdge(adjList, 1, 4);
  createAndAddEdge(adjList, 3, 3); 
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 2, 2);
  RecursiveDFS(adjList, visitedVertex, source); 
  cout << endl;
  //Ket Qua: 0 1 3 4 2

}