/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    int check(vector <vector <int>> &grid , int r1 , int c1 , int r2 , int c2) {
    
        int val = grid[r1][c1];
        for(int i = r1; i <= r2; i++) {
            for(int j = c1; j <= c2; j++) {
                if(grid[i][j] != val) return -1;
            }
        }
        
        return val;
    } 
    
    Node* solve(vector <vector <int>> &grid , int r1 , int c1 , int r2 , int c2) {
        int val = check(grid , r1 , c1 , r2 , c2);
        if(val != -1) {
            Node* root = new Node(val == 1 ? true : false , true);
            return root;
        }
        
        int size = r2 - r1 + 1;
        int block = size / 2;
        
        Node* root = new Node(true , false);
        
        root->topLeft = solve(grid , r1 , c1 , r2 - block , c2 - block);
        root->topRight = solve(grid , r1 , c1 + block , r2 - block , c2);
        root->bottomLeft = solve(grid , r1 + block , c1 , r2 , c2 - block);
        root->bottomRight = solve(grid , r1 + block , c1 + block , r2 , c2);
        
        return root;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        
        int n = grid.size();
        return solve(grid , 0 , 0 , n - 1 , n - 1);
        
    }
};