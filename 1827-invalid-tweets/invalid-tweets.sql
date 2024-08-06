# Write your MySQL query statement below
select tweet_id from Tweets where CHAR_LENGTH(content)>15;

-- length return size in bytes length('E') is 3 bytes while char_length return number of character char_length('e') is 1 