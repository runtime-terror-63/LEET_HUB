# Write your MySQL query statement below

select w2.id from 
Weather as w1
join Weather w2
on DATEDIFF(w2.recordDate, w1.recordDate) = 1
where w1.temperature<w2.temperature;
