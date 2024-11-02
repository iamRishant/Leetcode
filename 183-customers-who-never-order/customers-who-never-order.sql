# Write your MySQL query statement below
select c.name as Customers  from Customers as c where c.id  not in(
    select c.id from Customers as c 
    join Orders as o 
    on c.id=o.CustomerId
);