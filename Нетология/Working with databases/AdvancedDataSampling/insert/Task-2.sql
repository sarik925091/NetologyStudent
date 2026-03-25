
INSERT INTO genres (id, name) VALUES
    (1, 'Rock'),
    (2, 'Jazz'),
    (3, 'Electronic');

INSERT INTO artists (id, name) VALUES
    (1, 'The Beatles'),
    (2, 'Nirvana'),
    (3, 'Miles Davis'),
    (4, 'Daft Punk');

INSERT INTO genresArtists (genres_id, artist_id) VALUES
    (1, 1),   -- The Beatles -> Rock
    (1, 2),   -- Nirvana -> Rock
    (2, 3),   -- Miles Davis -> Jazz
    (3, 4);   -- Daft Punk -> Electronic

INSERT INTO album (id, title, release_year) VALUES
    (1, 'Abbey Road', 1969),
    (2, 'Nevermind', 1991),
    (3, 'Kind of Blue', 1959),
    (4, 'Random Access Memories', 2013);

INSERT INTO artistsalbums (artist_id, album_id) VALUES 
	(1, 1), (2, 2), (3, 3), (4, 4);
	

INSERT INTO track (id, title, duration, album_id) VALUES
    -- Abbey Road
    (1, 'Come Together', 259, 1),
    (2, 'Something', 182, 1),
    -- Nevermind
    (3, 'Smells Like Teen Spirit', 301, 2),
    (4, 'Lithium', 257, 2),
    (5, 'In Bloom', 255, 2),
    -- Kind of Blue
    (6, 'So What', 543, 3),
    (7, 'Freddie Freeloader', 586, 3),
    -- Random Access Memories
    (8, 'Get Lucky', 368, 4),
    (9, 'Instant Crush', 337, 4);


INSERT INTO collection (id, title, release_year) VALUES
    (1, 'Classic Rock Anthems', 2020),
    (2, 'Jazz Legends', 2018),
    (3, 'Electronic Beats', 2021),
    (4, '90s Grunge', 2019);

INSERT INTO collectionTracks (collection_id, track_id) VALUES
    -- Classic Rock Anthems (collection 1)
    (1, 1), (1, 2), (1, 3), (1, 4),
    -- Jazz Legends (collection 2)
    (2, 6), (2, 7),
    -- Electronic Beats (collection 3)
    (3, 8), (3, 9),
    -- 90s Grunge (collection 4)
    (4, 3), (4, 4), (4, 5);
	
	
