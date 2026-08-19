# Write your MySQL query statement below
select p.product_name as product_name,
e.year as year,
e.price as price
from sales e
join product p
on e.product_id=p.product_id
