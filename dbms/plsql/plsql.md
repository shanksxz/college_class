# PL/SQL Commands

## Table of Contents
- [Creating Tables](#creating-tables)
- [User Input](#user-input)
- [Conditional Statements](#conditional-statements)
- [LOOPS](#loops)
- [Cursors](#cursors)
- [Triggers](#triggers)
- [Procedures](#procedures)
- [Functions](#functions)
- [Exception Handling](#exception-handling)
- [Sequence](#sequence)
- [Packages](#packages)


### Creating Tables
```sql
CREATE TABLE EMP(
    EMP_ID INT,
    EMP_NAME VARCHAR(25),
    EMP_SALARY INT
);


desc emp;


INSERT INTO EMP (
    EMP_ID,
    EMP_NAME,
    EMP_SALARY
) VALUES (
    1,
    'Rahul',
    98000
);


SELECT * FROM EMP;
SELECT * FROM EMP WHERE EMP_SALARY > 50000;
```


### User Input
```sql
accept ename char prompt 'enter name';

SELECT * FROM EMP WHERE EMP_NAME = '&ename'


-- printing
DECLARE MESSAGE VARCHAR(50);
BEGIN
    MESSAGE := 'Hi there';
    DBMS_OUTPUT.PUT_LINE(MESSAGE);
END;

-- this includes cursors, ignore for now
DECLARE
    NAME   EMP.EMP_NAME%TYPE;
    SALARY EMP.EMP_SALARY%TYPE;
    MSG    NUMBER;
BEGIN
    SELECT EMP_NAME, EMP_SALARY INTO NAME,SALARY FROM EMP
    WHERE EMP_ID = &MSG;
    DBMS_OUTPUT.PUT_LINE(NAME);
    DBMS_OUTPUT.PUT_LINE(SALARY);
END;
```

### Conditional Statements
```sql
-- if statement
DECLARE
    E_SALE       NUMBER := 50000;
    E_COMMISSION NUMBER := 0;
BEGIN
    IF E_SALE > 40000 THEN
        E_COMMISSION := (E_SALE * 10)/100;
        DBMS_OUTPUT.PUT_LINE('commision is '|| E_COMMISSION);
    END IF;
END;

-- if-else statement
DECLARE
    E_SALE       NUMBER := 35000;
    E_COMMISSION NUMBER := 0;
BEGIN
    IF E_SALE > 40000 THEN
        E_COMMISSION := (E_SALE * 10)/100;
        DBMS_OUTPUT.PUT_LINE('commision is '|| E_COMMISSION);
    ELSE
        DBMS_OUTPUT.PUT_LINE('commision is '|| E_COMMISSION);
    END IF;
END;


-- if-elsif-else statement
DECLARE
    E_SALE       NUMBER := 35000;
    E_COMMISSION NUMBER := 0;
BEGIN
    IF E_SALE > 40000 THEN
        E_COMMISSION := (E_SALE * 10)/100;
        DBMS_OUTPUT.PUT_LINE('if case '|| E_COMMISSION);
    ELSIF E_SALE >30000 AND E_SALE<=30000 THEN
        DBMS_OUTPUT.PUT_LINE('else if case '|| E_COMMISSION);
    ELSE
        DBMS_OUTPUT.PUT_LINE('else case '|| E_COMMISSION);
    END IF;
END;
```
### LOOPS
```sql
-- Basic Loop
DECLARE
    I NUMBER := 0;
BEGIN
    LOOP
        I := I + 1;
        IF I > 10 THEN EXIT;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(I);
END;

DECLARE
    I NUMBER := 0;
BEGIN
    LOOP
        I := I + 1;
        EXIT WHEN I > 10;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(I);
END;

-- Basic Loop with Labels
DECLARE
    I NUMBER := 0;
    J NUMBER := 0;
BEGIN
    <<OUTER>>
    LOOP
        I := I + 1;
        EXIT OUTER WHEN I > 2;
        DBMS_OUTPUT.PUT_LINE('value of i '|| I);
        <<INNER>>
        LOOP
            J := J + 1;
            EXIT INNER WHEN J > 2;
            DBMS_OUTPUT.PUT_LINE('value of j '|| J);
        END LOOP;
    END LOOP;
END;


-- while loop
DECLARE
    I NUMBER := 0;
BEGIN
    WHILE I<=10 LOOP
        I := I + 1;
        DBMS_OUTPUT.PUT_LINE(I);
    END LOOP;
END;
DECLARE
    I NUMBER := 0;
BEGIN
    WHILE I<=10 LOOP
        I := I + 1;
        DBMS_OUTPUT.PUT_LINE(I);
        EXIT WHEN I = 3;
    END LOOP;
END;


-- for loop
DECLARE
    I NUMBER := 0;
    J NUMBER := 0;
BEGIN
    FOR I IN 1..5 LOOP
        FOR J IN 1..5 LOOP
        DBMS_OUTPUT.put_line('value of i is ' || I);
        DBMS_OUTPUT.put_line('value of j is ' || J);
        END LOOP;
    END LOOP;
    END;
```


### Cursors
- Cursors are database objects or constructs that are used to retrieve and manipulate data from a relational database management system (RDBMS), typically through SQL (Structured Query Language) queries. 
    - Implicit Cursors:
        Implicit cursors are automatically managed by the database system, and you don't need to explicitly declare them. They are typically used for simple SQL statements. Common attributes associated with implicit cursors include SQL%FOUND, SQL%NOTFOUND, and SQL%ROWCOUNT. Implicit cursors are suitable for single-row queries.

    - Explicit Cursors:
        Explicit cursors are explicitly declared by the programmer and provide more control over the retrieval and processing of result sets. These cursors are useful for more complex queries or when you need to process multiple rows of data. Explicit cursors are defined using the CURSOR statement, and you can open, fetch, and close them manually.

    #### Implicit Cursors
    ```sql
    DECLARE
        total_rows NUMBER;
    BEGIN
        UPDATE emp set EMP_SALARY = EMP_SALARY + 5000;
        if sql%notfound then
            dbms_output.put_line('Record not updated');
        elsif sql%found THEN
            total_rows := sql%rowcount;
            dbms_output.put_line('updated rows count ' || total_rows);
    end if;
    END;d
    select * from emp;
    ```
    #### Explicit Cursors
    ```sql
    DECLARE
        id NUMBER;
        name VARCHAR(25);

        CURSOR details IS
        SELECT emp_id,emp_name FROM emp;
    BEGIN
        OPEN details;
        LOOP
            FETCH details into id,name;
            exit when details%notfound;
            dbms_output.put_line('emp id ' || id || ' emp name ' || name);
        END LOOP;
    close details;
    END;
    ```
### Triggers
```sql
create table new_emp(
    id NUMBER,
    salary number,
    MESSAGE VARCHAR(50)
);

CREATE TRIGGER trigger_emp
AFTER UPDATE OF emp_salary ON EMP
for each row
BEGIN
    INSERT INTO new_emp(id,salary,message)
    VALUES(:old.emp_id,:NEW.emp_salary,'Record is updated');
END;


SELECT * from new_emp;

UPDATE emp SET EMP_SALARY = 90000 where emp_id = 1;


-- idk? maybe example
create table customers(
    customer_id number primary key,
    customer_name varchar2(255),
    salary number
);




insert into customers values(1,'Somya',90000);
insert into customers values(2,'Rahul',78800);
insert into customers values(3,'Raghav',76000);
insert into customers values(4,'Amit',45000);


select * from customers


create or replace trigger display_salary_changes after update on customers for each row
when (new.customer_id > 0)
DECLARE
sal_diff number;
begin
sal_diff := :new.salary - :old.salary;
dbms_output.put_line('Old ' || :old.salary);
dbms_output.put_line('New ' || :new.salary);
dbms_output.put_line('Diff ' || sal_diff);
end;

update customers set salary = 700600 where customer_id = 4;


begin
dbms_output.put_line('hergh');
end;
```


### Procedures
```sql
-- there might be error in the below code, will remove in future if find any errors
create PROCEDURE p_emp (
    num1 in NUMBER,
    num2 in NUMBER,
    sum out NUMBER
) as 
BEGIN
sum := num1 + num2;
END p_emp;


DECLARE
   result NUMBER;
BEGIN
   p_emp(10, 20, result);
   DBMS_OUTPUT.PUT_LINE('Sum: ' || result);
END;

-- taking input in procedures

Create the 'dept' table
CREATE TABLE dept (
    id NUMBER,
    name VARCHAR(50)
);

-- Create the procedure 'insert_dept'
CREATE OR REPLACE PROCEDURE insert_dept (
    emp_id IN NUMBER,
    emp_name IN VARCHAR
) AS 
BEGIN
    INSERT INTO dept(id, name)
    VALUES (emp_id, emp_name);
END;



DECLARE
    id NUMBER := &id;
    emp_name VARCHAR(50) := '&emp_name';
BEGIN
    insert_dept(id, emp_name);
END;


-- select * from dept


create table emp_table(
    emp_id integer,
    emp_name varchar2(255)
);

create or replace procedure insertintoemp(
    emp_id integer,
    emp_name varchar2
)
is
BEGIN
    insert into emp_table values(
        emp_id,emp_name
    );
end;

DECLARE
    employee_id integer:= &employee_id;
    employee_name varchar(50):= '&employee_name';
BEGIN
    insertintoemp(employee_id,employee_name);
end;
```

### Functions
```sql
create or replace function squareNumber(n1 in number)
RETURN number is sum_num number;
BEGIN
    sum_num := n1 * n1;
    return sum_num;
END;


    --calling
DECLARE
    sum_num number := 0;
BEGIN
    sum_num := squareNumber(5);
    dbms_output.put_line(sum_num);
END;
```

### Exception Handling
```sql
DECLARE
    i NUMBER := &i;
    less_than_zero exception;
    greater_than_ten exception;
    between_zero_and_ten exception;
BEGIN
    if i > 10 THEN
        RAISE greater_than_ten;
    elsif i >=0 and i <=10 THEN
        RAISE between_zero_and_ten;
    else RAISE less_than_zero;
    end if;
EXCEPTION
    WHEN greater_than_ten THEN 
        dbms_output.put_line('Number is greater then ten ' || i);
    WHEN less_than_zero THEN 
        dbms_output.put_line('Number is less then zero ' || i);
    WHEN between_zero_and_ten THEN 
        dbms_output.put_line('Number is between zero and ten ' || i);
END;


DECLARE
    i NUMBER := 5; -- Assign the desired value to i
    less_than_zero EXCEPTION;
    greater_than_ten EXCEPTION;
    between_zero_and_ten EXCEPTION;
BEGIN
    IF i > 10 THEN
        RAISE greater_than_ten;
    ELSIF i >= 0 AND i <= 10 THEN
        RAISE between_zero_and_ten;
    ELSE
        RAISE less_than_zero;
    END IF;
EXCEPTION
    WHEN greater_than_ten THEN 
        DBMS_OUTPUT.PUT_LINE('Number is greater than ten: ' || i);
    WHEN less_than_zero THEN 
        DBMS_OUTPUT.PUT_LINE('Number is less than zero: ' || i);
    WHEN between_zero_and_ten THEN 
        DBMS_OUTPUT.PUT_LINE('Number is between zero and ten: ' || i);
END;

```

### Sequence
```sql
create table customers(
    customer_id number primary key,
    customer_name varchar2(255),
    address varchar2(255)
);

create SEQUENCE customer_id_seq start with 1 increment by 1 nocache nocycle;

DECLARE
new_customer_id number;
begin
select customer_id_seq.nextval INTO new_customer_id from dual;
insert into customers (customer_id, customer_name, address)
values (new_customer_id, 'John Doe','123 Main Street');
end;

select * from customers

drop table customers;
```

### Packages
```sql
create or replace package my_package as
    procedure my_procedure (p_param1 NUMBER);
    function calculate_sum (a NUMBER, b NUMBER) return number;
end my_package;


CREATE OR REPLACE PACKAGE BODY my_package AS
    PROCEDURE my_procedure (p_param1 NUMBER) IS
    BEGIN
        -- Your implementation logic for my_procedure goes here
        -- For example, you can perform operations using p_param1
        DBMS_OUTPUT.PUT_LINE('my_procedure called with ' || p_param1);
    END my_procedure;

    FUNCTION calculate_sum (a NUMBER, b NUMBER) RETURN NUMBER IS
    BEGIN
        -- Your implementation logic for calculate_sum goes here
        RETURN a + b;
    END calculate_sum;
END my_package
```