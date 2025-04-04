# Write your MySQL query statement below

select a1.name as Employee from
Employee a1
join Employee a2
on a2.id = a1.managerId
where a1.salary>a2.salary