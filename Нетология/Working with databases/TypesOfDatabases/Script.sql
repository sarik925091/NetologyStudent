create table if not exists genres (
	id SERIAL PRIMARY KEY,
	name VARCHAR(100) NOT NULL unique   
);

create table if not exists artists (
	id serial primary key,
	name varchar(200) not null,
	genres_id INTEGER not null references genres(id) on delete restrict
);

create table if not exists album (
	id serial primary key,
	title varchar(200) not null,
	release_year integer check (release_year > 1900),
	arists_id integer not null references artists(id) ON DELETE CASCADE
);

create table if not exists track (
	id serial primary key,
	title varchar(200) not null,
	duration  integer not null,
	album_id integer not null references album(id) ON DELETE CASCADE
);