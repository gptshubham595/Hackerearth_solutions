"""
Hackerank Solution

Given a chess board of n rows (top to bottom) and n columns (left to right). In each move, a knight moves either

"""

#check if a move is valid or not.
def valid(x, y, N): 
    if (x >= 0 and x < N and y >= 0 and y < N):  
        return True
    return False


def minMoves(n, startRow, startCol, endRow, endCol):
    #Implement using queue for BFS(breadth for search)
    q=[]
    #consider all moves possible for a knight from given posiiton
    x = [2, 2, -2, -2, 1, 1, -1, -1] 
    y = [1, -1, 1, -1, 2, -2, 2, -2] 
    
    q.append([startRow,startCol,0])
    
    #maintain already visited cells in the board
    visited=[]
    for i in range(n+1):
        visited.append([False]*(n+1))
        
    #visit the startRow and startCol
    visited[startRow][startCol] = True
    
    #Implement BFS until there is no element in q.
    while(len(q)>0):
        
        temp = q[0]
        q.pop(0)
        
        if(temp[0]==endRow and temp[1]==endCol): #temp[0] stores startRow , temp[1] stores startCol
            return temp[2] #temp[2] stores distance covered
        
        # Travel through all states from a given position
        for i in range(8):
            xx = temp[0] + x[i]
            yy = temp[1] + y[i]
        
            if(valid(xx,yy,n) and not visited[xx][yy]):
                visited[xx][yy] = True
                q.append([xx, yy, temp[2]+1])

if __name__=='__main__': 
    n = int(input())
    start_row=int(input())
    start_col=int(input())
    end_row=int(input())
    end_col=int(input())
    print(minMoves(n,start_row,start_col,end_row,end_col))
