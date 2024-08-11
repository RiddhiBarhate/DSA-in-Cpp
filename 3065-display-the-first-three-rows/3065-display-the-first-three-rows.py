import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    rows = employees.head(3)

    return(rows)
    