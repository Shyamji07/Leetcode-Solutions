function dfs(graph, node, colors, color) {
  colors[node] = color;
  for (const neighbor of graph[node]) {
    if (colors[neighbor] === color) {
      return false;
    }
    if (!colors[neighbor]) {
      if (!dfs(graph, neighbor, colors, -color)) {
        return false;
      }
    }
  }
  return true;
}

isBipartite = function(graph) {
  const n = graph.length;
  const colors = new Array(n).fill(0);  
  for (let i = 0; i < n; i++) {
    if (!colors[i]) {
      if (!dfs(graph, i, colors, 1)) {
        return false;
      }
    }
  }
  return true;
}