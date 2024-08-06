# Write your MySQL query statement below
select r.unique_id,l.name from Employees as l left join EmployeeUNI as r on l.id=r.id;