# Write your MySQL query statement below

SELECT Products.product_name, sum(Orders.unit) as unit
FROM Products
INNER JOIN Orders
ON Products.product_id = Orders.product_id
where Orders.order_date between '2020_02_01' and '2020_02_29'
GROUP BY Products.product_name
having sum(Orders.unit)>=100;

