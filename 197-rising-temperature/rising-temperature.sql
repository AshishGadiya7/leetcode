# Write your MySQL query statement below
select w.id from Weather w join Weather x on datediff(w.recordDate,x.recordDate)=1 where w.temperature>x.temperature