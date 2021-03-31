#include <iostream>
#include <vector>
#include <queue> 
#include <functional> 
using namespace std;

typedef pair<int, int> Pair; 
const int numVertices = 4; // 4 đỉnh (0,1,2,3)
vector <bool> visitedVertex(numVertices, false);

void createAndAddEdge(vector <Pair> adjList[], int u, int weight, int v){
  adjList[u].push_back(make_pair(weight, v));
  adjList[v].push_back(make_pair(weight, u)); 
}

void PrimsAlgorithm(vector <Pair> adjList[], int source){
  priority_queue<Pair, vector<Pair>, greater<Pair> > PQ; //Hàng đợi ưu tiên
  Pair info;
  int minCost = 0;
  PQ.push(make_pair(0, source)); ////Khởi tạo giá trị khoảng cách mặc định = 0;
  while (!PQ.empty()){
    info = PQ.top(); // get giá trị trọng số nhỏ nhất
    source = info.second; // get đỉnh
    PQ.pop(); // pop trước khi kiểm tra chu trình
    if (visitedVertex.at(source)) // Kiểm tra chu trình
      continue; 
    visitedVertex.at(source) = true; //Gắn cờ vào đỉnh
    cout << "Mark vertex " << info.second << " and add weight " << info.first << endl;
    minCost += info.first; // Add to minCost
    // Duyệt tất cả đỉnh
    for (vector<Pair>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++) 
      if (!visitedVertex.at(it->second)) // Nếu đỉnh chưa được duyệt
        PQ.push(make_pair(it->first, it->second)); // Push đỉnh và trọng số vào hàng đợi ưu tiên
  } 
   cout << "Minimum cost to connect all vertices : " << minCost << endl;
} // PrimsAlgorithm

int main (void){
  int source = 0;
  vector<Pair> adjList[numVertices];
  createAndAddEdge(adjList, 0, 1, 1);
  createAndAddEdge(adjList, 0, 2, 3);
  createAndAddEdge(adjList, 1, 4, 2);
  createAndAddEdge(adjList, 1, 3, 3);
  createAndAddEdge(adjList, 2, 5, 3);
  PrimsAlgorithm(adjList, source); 
  //Đường đi ngắn nhất có trọng số là: 7;
} 