#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
 
int a[101][101];
queue<int> q;
stack<int> s;
int z = 0;
int n,m,Free[101], u,v,start;

// duyệt theo chiều rộng (sử dụng queue)
void BFS(int s) {
  q.push(s); 
  Free[s] = 0;
  while (!q.empty()) {
    int u = q.front(); 
    q.pop();
    cout << u << '\t';
    for (int v = 1; v <= n; v++) {
      if (Free[v] && a[u][v] == 1) {
          Free[v] = 0;
          q.push(v);
      }
    }
  }
}

// duyệt theo chiều sâu (sử dụng stack)
void DFS(int d) {  
  s.push(d);     			           
  Free[d] = 0;        			          
  cout << d << "\t ";  			          
  while (!s.empty()) {   
    int u = s.top();                          	    
    s.pop();                               		     
    for (int v = 1; v <= n; v++) {    	       	       
      if (a[u][v] == 1 && Free[v] == 1) {             
        cout << v << "\t ";            		                 
        Free[v] = 0;                  		             
        s.push(u);                		            
        s.push(v);             	       	                
        break;       
      }
    }
  }
}

int main() {
  cin >> n >> m >> start;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = 0;

  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    a[u][v] = 1;
    a[v][u] = 1;
  }

  for (int i = 1; i <= n; i++)
    Free[i] = 1;

  BFS(start);
  // DFS(start);
  cout << z;
  return 0;
}