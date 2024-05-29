-- альбомы
INSERT INTO "homeWork".album
(album_name, album_date)
VALUES('Охота на лисицу', '2021-01-01');
INSERT INTO "homeWork".album
(album_name, album_date)
VALUES('Первое свидание', '2020-01-01');
INSERT INTO "homeWork".album
(album_name, album_date)
VALUES('Отпусти и забудь', '2021-01-01');
INSERT INTO "homeWork".album
(album_name, album_date)
VALUES('Актриса весна', '1992-01-01');
INSERT INTO "homeWork".album
(album_name, album_date)
VALUES('Brand New Day', '1999-09-24');
INSERT INTO "homeWork".album
(album_name, album_date)
VALUES('Реверсивная хроника событий', '2004-01-01');
INSERT INTO "homeWork".album
(album_name, album_date)
VALUES('Дорога сна', '2003-01-01');
INSERT INTO "homeWork".album
(album_name, album_date)
VALUES('Thriller', '1982-01-01');

-- музыкантов
INSERT INTO "homeWork".musician
(first_name)
VALUES('Sting');
INSERT INTO "homeWork".musician
(first_name, last_name)
VALUES('Юрий', 'Шевчук');
INSERT INTO "homeWork".musician
(first_name, last_name)
VALUES('Наталья', 'О'' Шей');
INSERT INTO "homeWork".musician
(first_name, last_name)
VALUES('Michael', 'Jackson');
INSERT INTO "homeWork".musician
(first_name, last_name)
VALUES('Алёна', 'Швец');
INSERT INTO "homeWork".musician
(first_name)
VALUES('Сплин');
INSERT INTO "homeWork".musician
(first_name, last_name)
VALUES('Михаил', 'Егоров');
INSERT INTO "homeWork".musician
(first_name, last_name)
VALUES('Green', 'Apelsin');

-- жанры
INSERT INTO "homeWork".genre_of_music
("name")
VALUES('Фанк');
INSERT INTO "homeWork".genre_of_music
("name")
VALUES('Инди-поп');
INSERT INTO "homeWork".genre_of_music
("name")
VALUES('Авторская песня');
INSERT INTO "homeWork".genre_of_music
("name")
VALUES('Фолк-рок');
INSERT INTO "homeWork".genre_of_music
("name")
VALUES('Поп');
INSERT INTO "homeWork".genre_of_music
("name")
VALUES('Рок');
INSERT INTO "homeWork".genre_of_music
("name")
VALUES('Соул');
INSERT INTO "homeWork".genre_of_music
("name")
VALUES('R&B');
INSERT INTO "homeWork".genre_of_music
("name")
VALUES('Русский рок');

-- Сборники
INSERT INTO "homeWork".collection
(collection_name, collection_date)
VALUES('25 Year', '2019-01-01');
INSERT INTO "homeWork".collection
(collection_name, collection_date)
VALUES('The best', '2007-01-01');
INSERT INTO "homeWork".collection
(collection_name, collection_date)
VALUES('2.0', '2019-01-01');
INSERT INTO "homeWork".collection
(collection_name, collection_date)
VALUES('Popular classics', '2021-01-01');

-- Жанры музыкантов
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(1, 5);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(3, 4);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(2, 9);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(4, 5);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(4, 1);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(4, 7);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(4, 8);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(5, 3);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(5, 2);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(6, 9);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(7, 3);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(8, 3);
INSERT INTO "homeWork".musician_genre
(musician_id, genre_id)
VALUES(8, 4);

-- Альбомы музыкантов
INSERT INTO "homeWork".musician_album
(musician_id, album_id)
VALUES(1, 5);
INSERT INTO "homeWork".musician_album
(musician_id, album_id)
VALUES(2, 4);
INSERT INTO "homeWork".musician_album
(musician_id, album_id)
VALUES(3, 7);
INSERT INTO "homeWork".musician_album
(musician_id, album_id)
VALUES(4, 8);
INSERT INTO "homeWork".musician_album
(musician_id, album_id)
VALUES(5, 2);
INSERT INTO "homeWork".musician_album
(musician_id, album_id)
VALUES(6, 6);
INSERT INTO "homeWork".musician_album
(musician_id, album_id)
VALUES(7, 3);
INSERT INTO "homeWork".musician_album
(musician_id, album_id)
VALUES(8, 1);

-- треки
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('Охота на лисицу', 2, 1, '03:12:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('Охота на лисицу (акустика)', 2, 1, '03:19:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('Первое свидание', 2, 2, '02:32:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('Отпусти и забудь', 9, 3, '05:04:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('Дождь', 9, 4, '05:04:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('Родина', 9, 4, '04:37:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('Desert rose', 5, 5, '04:47:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('Романс', 9, 6, '03:25:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('На север', 4, 7, '03:32:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('Billie Jean', 5, 8, '04:53:00');
INSERT INTO "homeWork".track
(track_name, track_genre, album, lenght_track)
VALUES('The Lady in My Life', 5, 8, '05:00:00');

-- Треки в сборник
INSERT INTO "homeWork".collectiontracks
(track_id, collection_id)
VALUES(10, 4);
INSERT INTO "homeWork".collectiontracks
(track_id, collection_id)
VALUES(9, 2);
INSERT INTO "homeWork".collectiontracks
(track_id, collection_id)
VALUES(9, 3);
INSERT INTO "homeWork".collectiontracks
(track_id, collection_id)
VALUES(7, 1);