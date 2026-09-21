# Write your MySQL query statement below
select person.firstName,person.lastName,Address.city,Address.state 
from Person LEFT JOIN Address
ON Person.personId = Address.personId;