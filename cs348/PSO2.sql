--order by
select distinct pname from parts order by pname;
select distinct pname from parts order by pname desc;

-- nested queries
-- Get cname values of customers who have placed orders with employee living in Fort Dodge.
select distinct cname from orders,customers where orders.cno = customers.cno and eno in (select eno from employees,zipcodes where employees.zip = zipcodes.zip and city = 'Fort Dodge');

--get cname values of customers living in Fort Dodger or Liberal
select cname from customers,zipcodes where customers.zip = zipcodes.zip and city in ('Fort Dodge','Liberal');

--get pname values of parts with the lowest price
select pname from parts where price <= all(select price from parts);

--exists and not exists
--get cname values of customers who have placed atleast one order through the employee with eno=1000
select cname from customers where exists (select * from orders where orders.cno = customers.cno and eno = 1000);


--get cname values of customers who have not placed any orders through the employee with eno=1000
select cname from customers where not exists (select * from orders where orders.cno = customers.cno and eno = 1000);

--get cities in which customers or employees are located
--union eliminates duplicates use union all if you dont want to eliminate duplicates 
select city from customers,zipcodes where customers.zip=zipcodes.zip union select city from employees,zipcodes where employees.zip=zipcodes.zip


--aggregate functions
select avg(price),min(price),max(price) from parts;

--get the total number of customers
select count(cno) as NUM_CUSTOMERS from customers;
select count(*) NUM_CUSTOMERS from customers;

--get the number of cities in which customers are based
select count(distinct city) as Cities from customers,zipcodes where customers.zip=zipcodes.zip;

--get the pname values of parts that cost more than the average cost of all parts
select pname as EXPENSIVE_PARTS from parts where price > (select avg(price) from parts);


--joins
--get cname values of customers living in Fort Dodger or Liberal
select cname from (customers join zipcodes on customers.zip = zipcodes.zip) where city in ('Fort Dodge','Liberal');

--natural join
select cname from (customers natural join zipcodes) where city in ('Fort Dodge','Liberal');

--get list of customers and cities
--left outer join
select cname,city from customers left outer join zipcodes on customers.zip=zipcodes.zip;

--select cname,city from zipcodes left outer join customers on customers.zip=zipcodes.zip;

--right outer join
select cname,city from customers right outer join zipcodes on customers.zip=zipcodes.zip;

--full outer join
select cname,city from customers full outer join zipcodes on customers.zip=zipcodes.zip;

--group by and having clauses
--for each part get pno and pname values along with total sales in dollars
select pno,pname,sum(qty*price) as TOTAL_SALES from odetails natural join parts group by pno,pname;

--for each part get pno and pname values along with total sales in dollars when the total sales exceed $1000
select pno,pname,sum(qty*price) as TOTAL_SALES from odetails natural join parts group by pno,pname having sum(qty*price) > 50;

--views
drop view employee_sales;
create view employee_sales as 
select eno,ename,sum(price*qty) SALES from employees natural join orders natural join odetails natural join parts group by eno,ename;

select * from employee_sales;


alter table employees add address varchar(30);
alter table employees drop column ename;










