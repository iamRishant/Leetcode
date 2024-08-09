# Write your MySQL query statement below
select l.name, r.bonus from Employee as l 
left join Bonus as r on l.empId=r.empId where bonus<1000 or bonus is NULL;
