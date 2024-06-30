int caminhos(grafo *g, int s){
  int *pai = malloc(g->n*sizeof(int));
  for(int i=0; i < g->n;i++) pai[i]=-1;
  dfs(g, pai, s, s);
  return pai;
}


void dfs(grafo *g, int *pai, int p, int v){
  pai[v] = p;
  for(int i = 0; i < g->n; i++){
    if(g->adj[v][i] && pai[i] == -1) dfs(g, pai, v, i);
  }
}