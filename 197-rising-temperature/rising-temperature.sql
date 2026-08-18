# Write your MySQL query statement below
Select w1.id as id
from Weather w1
join weather w2
on datediff(w1.recordDate,w2.recordDate)= 1
where w1.temperature> w2.temperature;
