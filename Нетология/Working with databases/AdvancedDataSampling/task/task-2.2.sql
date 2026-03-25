SELECT count(name) FROM artists;

SELECT COUNT(*) FROM track
WHERE album_id IN (
    SELECT id FROM album WHERE release_year BETWEEN 2010 AND 2013
);

SELECT a.title, avg(duration) FROM album a
JOIN track t ON a.id = t.album_id
GROUP BY a.title;

SELECT a.name, al.release_year FROM artists a
JOIN artistsAlbums a2 ON a.id = a2.artist_id 
JOIN album al ON a2.album_id = al.id 
GROUP BY a.name, al.release_year 
HAVING al.release_year != 2020;

SELECT c.title FROM collection c
JOIN collectionTracks ct ON c.id = ct.collection_id 
JOIN track t ON ct.track_id = t.id 
JOIN album a ON t.album_id = a.id 
JOIN artistsAlbums ab ON a.id = ab.album_id 
JOIN artists a2 ON ab.artist_id = a2.id 
WHERE a2.name = 'The Beatles';




