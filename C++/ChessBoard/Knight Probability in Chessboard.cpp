//Picked from one of LeetCode Solution
#define KNIGHT_MOVES 8
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> prob1(N, vector<double>(N, 0));
        vector<vector<double>> prob2(N, vector<double>(N, 0));
        vector<vector<double>> *pprob1 = &prob1;
        vector<vector<double>> *pprob2 = &prob2;
        
        double prob = 1.0;
        prob1[r][c] = 1.0;
        
        for(int i = 0; i < K; i++)
        {
            prob = knightInBoardProb(N, *pprob1, *pprob2);
            cleanup(*pprob1);
            swap(pprob1, pprob2);
        }
        
        return prob;   
    }
    
   double knightInBoardProb(int N, vector<vector<double>> &prev, vector<vector<double>> &curr)
    {
        
        vector<pair<int,int>>dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1,-2}, {-1,-2},{-2, -1}};
        
        double prob = 0;
        
        for(int i = 0; i < prev.size(); i++)
        {
            for(int j = 0; j < prev[i].size(); j++)
            {
                if(prev[i][j] != 0)
                {
                    for(auto &traversal:dirs)
                    {
                        int x = i + traversal.first;
                        int y = j + traversal.second;
                        
                        if(isInBoard(N, x, y))
                        {
                            curr[x][y] += prev[i][j]/KNIGHT_MOVES;
                            prob += prev[i][j]/KNIGHT_MOVES;
                        }
                    }
                }
            }
        }
        
        return prob;
    }
    
    bool isInBoard(int N, int r, int c)
    {
        return (r >= 0 && c >= 0 && r < N && c < N);
    }
    
    void cleanup(vector<vector<double>> &m)
    {
        for(int i = 0; i < m.size(); i++)
        {
            for(int j = 0; j < m[i].size(); j++)
            {
                m[i][j] = 0;
            }
        }
    } 
    
    
};
