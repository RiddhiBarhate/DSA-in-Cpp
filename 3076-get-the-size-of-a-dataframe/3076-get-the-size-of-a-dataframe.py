import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    #rows = len(players.axes[0])
    #cols = len(players.axes[1])

    #return[rows, cols]
    
    row,col = players.shape
    return[row, col]