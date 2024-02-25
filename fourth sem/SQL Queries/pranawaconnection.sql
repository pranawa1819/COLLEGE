// LAB 2

create table Department
(
d_no int primary key,
d_name VARCHAR2(20) not null,
block_no int
);
/
insert into Department values (101, 'CSIT',10);
/
insert into Department values (102, 'BCA',20);
/
insert into Department values (103, 'BIM',30);
/
insert into Department values (104, 'BHM',40);
/
insert into Department values (105, 'BBA',50);
/
select * from Department;
/

create table employee
(
e_id varchar2 (20) primary key,
e_name varchar2 (20) not null,
address varchar2 (20),
salary number check(salary between 30000 and 100000),
d_no number,
foreign key(d_no) references Department(d_no)
);
/
insert into employee values('e01','Kamala', 'Kathmandu',40000,101);
/
insert into employee values('e02','Kunti', 'Lalitpur',30000,101);
/
insert into employee values('e03','Sahil', 'Golfutar',35000,102);
insert into employee values('e04','Gopi', 'Balaju',50000,102);
insert into employee values('e05','Kamal', 'Hattigauda',45000,102);

/
select * from employee;
/



// LAB 3
//Create a table high paid employee from existing table using sub query.


create table High_Paid_Employee
as
select * from employee
where salary>30000;
/

select * from High_Paid_Employee
/

// LAB 4 
// Add new column to existing table employee.


alter table Employee
ADD e_phoneNumber number;
/
select * from employee;
/
update Employee set e_phoneNumber= 9867575644 where e_id = 'e03';

/
//lab 5

create table Employee2
(
Eid int primary key,
Ename varchar2(30),
Address varchar2(30),
salary int
);
/
insert into employee2 values(1,'Kamala', 'Kathmandu',40000);
insert into employee2 values(2,'Kunti', 'Pokhara',30000);
insert into employee2 values(3,'Sahil', 'Pokhara',85000);
insert into employee2 values(4,'Gopi', 'Kathmandu',50000);
insert into employee2 values(5,'Kamal', 'Pokhara',56000);
insert into employee2 values(9,'Samriddhi', 'Kritipur',70000);
insert into employee2 values(10,'Pratyusha', 'Dharan',100000);
/
select * from Employee2;
/

update Employee2 
set salary = salary*1.20 
where Address like 'K%';
/
update Employee2
set salary = 40000
where Address = 'Pokhara';
/
update Employee2 
set Address= 'Banepa'
where Eid = 10;
/
select max(salary) as maximum_salary, min(salary) as minimum_salary from Employee2;
/
select avg(salary) as average_salary from Employee2;
/
select address, avg(salary) from Employee2 group by Address having count(salary)>=2;
/
select address, avg(salary) from Employee2 group by Address;

select Ename, Eid,Address, salary from Employee2 order by salary ASC;  


// lab 7

create table department2
(
dep_id int primary key,
dname varchar2(30),
dept_block_no int
);
/
insert into Department2 values (11, 'CSIT',110);
insert into Department2 values (12, 'BCA',210);
insert into Department2 values (13, 'BIM',320);
insert into Department2 values (14, 'BBM',310);
insert into Department2 values (15, 'BHM',420);
/
select * from Department2;
/
delete from department2 
where dep_id = 13;
/
create table employe2
(
eid int primary key,
ename varchar2(20),
salary number,
address varchar2(20),
dept_no int,
foreign key (dept_no) References department2(dep_id)on delete cascade
);
/
insert into employe2 values(01,'Kamal', 65000,'Kathmandu',11);
insert into employe2 values(02,'Karuna',42000, 'Pokhara',11);
insert into employe2 values(03,'Sakthi',85000,'Bhaktapur',12);
insert into employe2 values(04,'Ganesh',50000, 'Kathmandu',14);
insert into employe2 values(05,'Sahil',105000,'Bhaktapur',13);
insert into employe2 values(06,'Radhaa',59000, 'Lalitpur',13);


/
select * from employe2;
/
delete from employe2
where ename = 'Karuna';

/
select * from Department2 d inner join employe2 e on (d.dep_id = e.dept_no);
/
select * from Department2 d right join employe2 e on (d.dep_id = e.dept_no);
/
select * from Department2 d left join employe2 e on (d.dep_id = e.dept_no);
/
select * from Department2 d full join employe2 e on (d.dep_id = e.dept_no);