# Write your MySQL query statement below
select r.product_name,l.year,l.price from Sales as l inner join Product as r on l.product_id=r.product_id;