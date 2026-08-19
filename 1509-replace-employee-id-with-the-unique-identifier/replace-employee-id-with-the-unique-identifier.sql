# Write your MySQL query statement below
SELECT m.unique_id, e.name
FROM Employees e
LEFT JOIN EmployeeUNI m
  ON e.id = m.id;

