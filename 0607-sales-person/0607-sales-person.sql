# Write your MySQL query statement below
select name 
from SalesPerson 
where sales_id not in(
    Select o.sales_id 
    From Orders o
    Join Company c On
    o.com_id=c.com_id
    where c.name='RED' )