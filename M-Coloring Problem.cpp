class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isValid(int index, int col, bool graph[101][101], int n, vector<int> &colour)
    {
        for(int i = 0;i<=n;i++)
        {
            if(graph[index][i]==1)
            {
                if(col == colour[i]) 
                    return 0;
            }
        }
        return 1;
    }
    
    bool solve(bool graph[101][101], int n, int m, int index, vector<int> &colour)
    {
        if(index>=n) return 1;
        
        for(int col = 1;col<=m;col++)
        {
            if(isValid(index, col, graph, n, colour))
            {
                colour[index]=col;
                if(solve(graph, n, m, index+1, colour)==1)
                    return 1;
                else colour[index]=0;
            }
        }
        return 0;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colour(n, 0);
        return solve(graph, n, m, 0, colour);
    }
};