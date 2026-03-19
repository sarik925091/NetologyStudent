create table if not exists genres (
    id serial primary key,
    name varchar(100) not null unique
);

create table if not exists artists (
    id serial primary key,
    name varchar(200) not null
);

create table if not exists genresArtists (
    genres_id integer not null references genres(id),
    artist_id integer not null references artists(id),
    primary key (genres_id, artist_id)
);

create table if not exists album (
    id serial primary key,
    title varchar(200) not null,
    release_year integer check (release_year > 1900)
);

create table if not exists artistsAlbums (
    artist_id integer not null references artists(id),
    album_id integer not null references album(id),
    primary key (artist_id, album_id)
);

create table if not exists track (
    id serial primary key,
    title varchar(200) not null,
    duration integer not null,
    album_id integer not null references album(id) on delete cascade
);

create table if not exists collection (
    id serial primary key,
    title varchar(200) not null,
    release_year integer check (release_year > 1900)
);

create table if not exists collectionTracks (
    collection_id integer not null references collection(id) on delete cascade,
    track_id integer not null references track(id) on delete cascade,
    primary key (collection_id, track_id)
);
