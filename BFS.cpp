#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void createAndAddEdge(vector <int> adjList[], int u, int v){
    //bước này để xử lý đồ thị không có trọng số
    adjList[u].push_back(v);
    adjList[v].push_back(u); 
} 

//hàm BFS
void BFS(vector <int> adjList[], vector <bool> visitedVertex, int source){
  queue <int> Q; //khởi tạo Queue
  int v;
  Q.push(source);
  // Khi Queue != rỗng
  while (!Q.empty()){
    v = Q.front();
    visitedVertex.at(v) = true;
    Q.pop();
    //Xuất các đỉnh đồ thị ra màn hình
    cout << v << " "; 
    for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // duyệt qua tất cả các đỉnh
      // Nếu đỉnh chưa được duyêt
      if (!visitedVertex.at(*it)){
        Q.push(*it); // Push các đỈnh chưa duyệt vào Queue
        visitedVertex.at(*it) = true;
      } 
  } 
  cout << endl;
}

int main (void){
  // Ý tưởng là add ma trận kề thành một mảng các vectors
  const int numVertices = 6; // 6 vertices (0,1,2,3,4,5)
  int source = 0;
  vector<int> adjList[numVertices]; // Tạo mảng các vectors
  vector <bool> visitedVertex(numVertices, false);
  
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 5);
  createAndAddEdge(adjList, 2, 3);
  createAndAddEdge(adjList, 2, 4);
  createAndAddEdge(adjList, 3, 3);
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 5, 5);

  BFS(adjList, visitedVertex, source); 
  //Kết quả: 0 1 2 5 3 4
} 
