//LAB 1

create table Student 
(
s_id int,
s_name varchar2(20),
s_level varchar2(20),
s_age int ,
sex varchar2(20),
primary key (s_id)
);
/
insert into Student values (101,'Raju','Bachelor',19,'Male');
insert into Student values (102,'Sita','Bachelor',18,'Female');
insert into Student values (103,'Gita','Bachelor',19,'Female');
insert into Student values (104,'Shyam','Bachelor',20,'Male');
insert into Student values (105,'Hari','Bachelor',19,'Male');
/
select * from Student;

/
create table Instructor(
I_id number,
I_name varchar2(20),
Age int,
sex varchar2(20),
primary key(I_id)
);
/
insert into Instructor values (204, 'Yunika', 19, 'Female');
insert into Instructor values (202, 'Sahil', 21, 'Male');
insert into Instructor values (203, 'Pratima', 32, 'Female');
/
select * from Instructor;
/

create table Course
(
c_id varchar2(20),
cname varchar2(30),
credit_hours int,
primary key(c_id)
);

/
insert into Course values ('CSC259','Operating System',3);
insert into Course values ('CSC257','Theory of computation',3);
insert into Course values ('CSC258','Computer Network',3);
insert into Course values ('CSC260','DBMS',3);
insert into Course values ('CSC261','Artificial Intelligence',3);
/
select *from Course;
/

create table Enrolled_by (
    s_id int,
    c_id varchar2(20),
    PRIMARY KEY (s_id, c_id),
    FOREIGN KEY (s_id) REFERENCES Student(s_id),
    FOREIGN KEY (c_id) REFERENCES Course(c_id)
);
/
insert into Enrolled_by values (101,'CSC259');
insert into Enrolled_by values (101,'CSC258');
insert into Enrolled_by values (102,'CSC259');
insert into Enrolled_by values (103,'CSC260');
insert into Enrolled_by values (103,'CSC257');
insert into Enrolled_by values (102,'CSC260');
/
select *from Enrolled_by;

/

CREATE TABLE Taken_by (
    I_id INT,
    c_id varchar2(20),
    PRIMARY KEY (I_id, c_id),
    FOREIGN KEY (I_id) REFERENCES Instructor(I_id),
    FOREIGN KEY (c_id) REFERENCES Course(c_id)
);
/
insert into Taken_by values (202,'CSC259');
insert into Taken_by values (204,'CSC258');
insert into Taken_by values (202,'CSC261');
insert into Taken_by values (203,'CSC260');
insert into Taken_by values (203,'CSC257');

/
select *from Taken_by;

/