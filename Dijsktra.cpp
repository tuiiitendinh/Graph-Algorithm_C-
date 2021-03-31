#include <iostream>
#include <vector>
#include <queue> 
#include <functional> 
using namespace std;

/* Sử dụng hàng đợi ưu tiên thấp
 * Độ phức tạp: O(Đỉnh + Cạnh.log(Đỉnh)).*/

typedef pair<int, int> Pair; 
const int numVertices = 6; // 6 đỉnh (0,1,2,3,4,5)
vector <bool> visitedVertex(numVertices, false);
int ShortestPath[numVertices]; // Tạo mảng để lưu các đường đi đã duyệt

void createAndAddEdge(vector <Pair> adjList[], int u, int weight, int v){
  adjList[u].push_back(make_pair(weight, v));
}

void DijkstrasAlgorithm(vector <Pair> adjList[], int source){
  priority_queue<Pair, vector<Pair>, greater<Pair> > PQ; // Hàng đợi ưu tiên
  Pair info;
  int weight;
  ShortestPath[source] = 0; //Khởi tạo giá trị khoảng cách mặc định = 0;

  for (int i = 0; i < numVertices; i++)
    if (i != source)
      ShortestPath[i] = 100000; // Đưa tất cả mọi giá trị khác về +vô cực

  PQ.push(make_pair(0, source)); //Trọng số = 0

    
  while (!PQ.empty()){
    info = PQ.top(); // Dùng để get giá trị có trọng số nhỏ nhất
    PQ.pop(); // Loại ra trước khi kiểm tra có tạo thành chu trình hay không?
    source = info.second; // Add dỉnh
    weight = info.first; // Khoảng cách hiện tại

    if (visitedVertex.at(source)) // Kiểm tra chu trình
      continue; // Không có chu trình, tiếp tục

    visitedVertex.at(source) = true; // Gắn cờ vào các đỉnh để không phải duyệt lại

    //Cập nhật khoảng cách
    for (vector<Pair>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
       if ((weight + (it->first)) < ShortestPath[it->second]){ // Quay lui để tìm đường đi tối ưu hơn
         ShortestPath[it->second] = weight + (it->first); // Cập nhật lại giá trị khoảng cách
         PQ.push(make_pair(ShortestPath[it->second], it->second)); // Push đỉnh và trọng số vào hàng đợi ưu tiên
       } 
  } 
} // DijkstrasAlgorithm

int main (void){

  int source = 0;
  vector<Pair> adjList[numVertices]; // Tạo vector
  createAndAddEdge(adjList, 0, 5, 1);
  createAndAddEdge(adjList, 0, 10, 3);
  createAndAddEdge(adjList, 1, 2, 2);
  createAndAddEdge(adjList, 1, 10, 5);
  createAndAddEdge(adjList, 1, 5, 4);
  createAndAddEdge(adjList, 2, 1, 3);
  createAndAddEdge(adjList, 2, 5, 4);
  createAndAddEdge(adjList, 2, 3, 0);
  createAndAddEdge(adjList, 4, 2, 5);
  DijkstrasAlgorithm(adjList, source);

  cout << "Shortest path from source vertex " << source << ": ";
  for (int i = 0; i < numVertices; i++)
    cout << ShortestPath[i] << " ";
  cout << endl;

}