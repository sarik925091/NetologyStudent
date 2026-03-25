SELECT title, duration
FROM track
WHERE duration >= (SELECT MAX(duration) FROM track);

SELECT title, duration
FROM track
WHERE duration > 210; -- 3.5 min!

SELECT title, release_year 
FROM collection
WHERE release_year BETWEEN 2018 AND 2020;

SELECT name 
FROM artists
WHERE name NOT LIKE '% %';

--SELECT title 
--FROM track
--WHERE title LIKE '%my%' OR title LIKE '%мой%';
 
--tracks with the title'мой' or 'my' are not listed
--tracks with the name 'get' exist
SELECT title 
FROM track
WHERE title LIKE '%get%' OR title LIKE '%Get%'; 
