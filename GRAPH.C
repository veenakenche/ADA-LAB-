bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    if (source == destination) return true;
    
    bool visited_map[n], stk_map[n];
    for (int i = 0; i < n; i++){
        stk_map[i] = false;     
        visited_map[i] = false; 
    } 
    int stk[n];
    unsigned int pt = -1;
    stk[++pt] = source;     
    stk_map[source] = true; 

    while (pt != -1){
        while (visited_map[stk[pt]] == true) pt--; 
        visited_map[stk[pt]] = true;
        int top = stk[pt--];    
        stk_map[top] = false;   

        /* We start to traverse through the "edges" 2D array, 
        finding adjacent vertex(es) of the "top" vertex.*/
        for(int i = 0; i < edgesSize; i++){
            for(int j = 0; j < *edgesColSize; j++){
                if (edges[i][j] == top){    
                    int vertex = edges[i][*edgesColSize-1-j];
                    if (vertex == destination) return true;
                    if (visited_map[vertex] == false && stk_map[vertex] == false){
                        /* if the adjacent vertex is not visited and not in stack, 
                        push the adjacent vertex to stack.*/
                        stk[++pt] = vertex; 
                        stk_map[vertex] = true;
                    } 
                    edges[i][j] = n;                
                    edges[i][*edgesColSize-1-j] = n;
                    break;
                }
            }
        } 
    }
    return visited_map[destination];
}
