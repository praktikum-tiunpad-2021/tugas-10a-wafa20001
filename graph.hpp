#pragma once

#include <functional>
#include <unordered_map>
#include <unordered_set>

namespace strukdat {

template <typename VertexType>
class graph {
  /**
   * @brief Tipe data dari adjacency list. (BOLEH DIUBAH)
   *
   * @note
   * Misal:
   *
   * adj_list_type adj_list =
   *
   * | map key  |             list_type
   * | - - - -  | - - - - - - - - - - - - - - - - -
   * | vertex_1 | vertex_2, vertex_5, vertex_4, ...
   * | vertex_2 | vertex_1, vertex_3
   * |   ...    |           ...
   *
   * maka,
   *
   * adj_list[vertex_2]; // { vertex_1, vertex_3 }
   */
  using list_type = std::unordered_set<VertexType>;
  using adj_list_type = std::unordered_map<VertexType, list_type>;

 public:
  /**
   * @brief Default constructor.
   *
   * @constructor
   */
  graph() {}

  /**
   * @brief Menambahkan vertex baru pada graph
   *
   * @param val nilai dari vertex yang akan ditambahkan
   */
  void add_vertex(const VertexType &val) {
    if(!_adj_list(val))
    _adj_list.insert(std::make_pair(val, list_type()));
  }

  void remove_vertex(const VertexType &val) {
    while(!_adj_list[val].empty()){
      remove_edge(val, _adj_list.back());
    }
    _adj_list.erase(val);
    VertexType::iterator va_list = find(_adj_list.begin(), _adj_list.end(), val);
    if(va_list != _adj_list.end()){
      _adj_list.erase(va_list);
    }
  }

  /**
   * @brief Menambahkan edge baru dari 2 vertex
   *
   * @param val1 nilai vertex 1
   * @param val2 nilai vertex 2
   */
  void add_edge(const VertexType &val1, const VertexType val2) {
    if ( val1 == val2) {
        return; 
	  }

	  if ( ! is_edge(val1, val2) ) 
	  {
		_adj_list.push_back(edge(val1, val2));
		add_vertex(val1);
		add_vertex(val2);
		
		vertices::iterator it = find( _adj_list[val1].begin(), _adj_list[val1].end(), val2 );
		if ( it == _adj_list[val1].end() ) 
		{
			_adj_list[val1].push_back(val2);
		}
		
		it = find( _adj_list[val2].begin(), _adj_list[val2].end(), val1 );
		if ( it == _adj_list[val2].end() ) 
		  {
			  _adj_list[val2].push_back(val1);
		  }
	  }
  }

  /**
   * @brief Menghapus vertex baru pada graph
   *
   * @param val nilai dari vertex yang akan dihapus
   */
  void remove_edge(const VertexType &val1, const VertexType &val2) {
    errno_t = find(_adj_list.begin(),_adj_list.end(), edges(val1, val2));
    if(errno_t != _adj_list.end()){
      _adj_list.erase(errno_t);
    }
    va_list = find( _adj_list[d].begin(), _adj_list[val2].end(), val1 );
	  if ( va_list != _adj_list[d].end() ) 
	  {
		_adj_list[val2].erase(va_list);
	  }
  }

  /**
   * @brief Mengembalikan ordo dari graph.
   *
   * @note
   * Ordo graph adalah jumlah node pada graph
   *
   * @return jumlah node pada graph
   */
  size_t order() const {
    
  }

  /**
   * @brief Cek apakah 2 vertex bertetangga satu sama lain.
   *
   * @param val1 nilai vertex 1
   * @param val2 nilai vertex 2
   *
   * @return vertex-vertex saling bertetangga
   */
  bool is_edge(const VertexType &val1, const VertexType &val2) const {
    
  }

  /**
   * @brief Melakukan BFS traversal pada graph
   *
   * @param root vertex awal
   * @param func fungsi yang akan dieksekusi pada setiap vertex
   */
  void bfs(const VertexType &root,
           std::function<void(const VertexType &)> func) const {
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
 
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;
 
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
  }

  /**
   * @brief Melakukan BFS traversal pada graph
   *
   * @param root vertex awal
   * @param func fungsi yang akan dieksekusi pada setiap vertex
   */
  void dfs(const VertexType &root,
           std::function<void(const VertexType &)> func) const {
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end();i++)
        {
            if (!visited[*i])
            DFS_visit(*i, visited);
        }
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end();i++)
        {
            if (!visited[*i])
            DFS_visit(*i, visited);
        }
  }

 private:
  /**
   * @brief Adjacency list dari graph
   *
   * @private
   */
  adj_list_type _adj_list;
};

}  // namespace strukdat