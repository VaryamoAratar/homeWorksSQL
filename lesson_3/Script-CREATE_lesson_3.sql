create table if not exists genre_of_music(
genre_id SERIAL primary key,
name VARCHAR(60) not null
);

create table if not exists musician(
musician_id SERIAL primary key,
first_name VARCHAR(60) not null,
last_name VARCHAR(60) null
);

create table if not exists musician_genre(
musician_id integer not null references musician(musician_id),
genre_id integer not null references genre_of_music(genre_id),
constraint mg primary key (musician_id, genre_id)
);

create table if not exists album(
album_id SERIAL primary key,
album_name VARCHAR(60) not null,
album_date DATE not null
);

create table if not exists musician_album(
musician_id integer not null references musician(musician_id),
album_id integer not null references album(album_id),
constraint ma primary key (musician_id, album_id)
);

create table if not exists track(
track_id SERIAL primary key,
track_name VARCHAR(60) not null,
track_genre integer not null references genre_of_music (genre_id),
album integer not null references album (album_id),
lenght_track TIME not null
);

create table if not exists Collection(
collection_id SERIAL primary key,
collection_name VARCHAR(60) not null,
collection_date DATE not null
);

create table if not exists CollectionTracks(
track_id integer not null references track(track_id),
collection_id integer not null references Collection(collection_id),
constraint colTr primary key (track_id, collection_id)
);

