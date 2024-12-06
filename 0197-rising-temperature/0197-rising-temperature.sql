select today.Id 
from weather prev, weather today
where datediff(today.recordDate, prev.recordDate) = 1
and prev.temperature < today.temperature
