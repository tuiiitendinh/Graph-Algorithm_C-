#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Topological Sort.
 * Topological Sort only works for a đồ thị hai chiều có hướng
 * Có dùng thêm BFS nên độ phức tạp ở mức O(|Đỉnh| + |Cạnh|)
 */

const int numVertices = 6; // 6 đỉnh (0,1,2,3,4,5)
int source;
vector <bool> visitedVertex(numVertices, false); // Kỹ thuật gắn cờ, tất cả = false, nếu đã duyệt qua thì gán thành True
vector <int> inDegree(numVertices, 0); // Đặt tất cả giá trị về 0
vector <int> T; // Lưu trữ tất cả các đỉnh nếu TopologicalSort duyệt qua theo thứ tự.

void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
}

void TopologicalSort(vector <int> adjList[]){
  queue <int> Q; //Queue dùng BFS
  int v;
  //duyệt qua tất cả các đỉnh trong đồ thị
  for (int i = 0; i < numVertices; i++) 
    for (vector <int>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++) //duyệt các đỉnh kế bên
      inDegree.at(*it)++; 

  for (int i = 0; i < numVertices; i++)
    if (inDegree.at(i) == 0){
      source = i;
      Q.push(source); // Push vào Queue để đánh dấu điểm bắt đầu cho BFS
      visitedVertex.at(source) = true; //Gắn cờ = true
      break;
    } 

  while (!Q.empty()){
    v = Q.front();
    Q.pop();
    T.push_back(v); // Thêm vào T-Vector

    /* Now to proceed with Topological Sort, we remove the vertex and all its corresponding edges.
     * Để tiếp tục, cần phải xoá các đỉnh và cạnh của nó
     * Suy ra, các cạnh của các đỉnh kế bên sẽ giảm đi 1
     */

    for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // //duyệt các đỉnh kế bên
      if (!visitedVertex.at(*it)){
        inDegree.at(*it)--; //Trừ đi 1
        if (inDegree.at(*it) == 0){
          Q.push(*it);
          visitedVertex.at(*it) = true; //Gắn cờ = true
        }
      }
  } 
} // TopologicalSort(vector <int> adjList[])

int main (void){
  vector<int> adjList[numVertices]; 
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 3);
  createAndAddEdge(adjList, 1, 2);
  createAndAddEdge(adjList, 1, 3);
  createAndAddEdge(adjList, 2, 3);
  createAndAddEdge(adjList, 2, 4);
  createAndAddEdge(adjList, 2, 5);
  createAndAddEdge(adjList, 3, 4);
  createAndAddEdge(adjList, 3, 5);
  createAndAddEdge(adjList, 4, 5);

  TopologicalSort(adjList); // Topological Sort 
  cout << "Topological Sort for the given DAG: ";
  for (int i = 0; i < T.size(); i++)
    cout << T.at(i) << " ";
  cout << endl;
  //Ket Qua: 0 1 2 3 4 5

}