-- альбомы
INSERT INTO "homeWork".album
(album_id, album_name, album_date)
VALUES(1, 'Охота на лисицу', '2021-01-01');
INSERT INTO "homeWork".album
(album_id, album_name, album_date)
VALUES(2, 'Первое свидание', '2020-01-01');
INSERT INTO "homeWork".album
(album_id, album_name, album_date)
VALUES(3, 'Отпусти и забудь', '2021-01-01');
INSERT INTO "homeWork".album
(album_id, album_name, album_date)
VALUES(4, 'Актриса весна', '1992-01-01');
INSERT INTO "homeWork".album
(album_id, album_name, album_date)
VALUES(5, 'Brand New Day', '1999-09-24');
INSERT INTO "homeWork".album
(album_id, album_name, album_date)
VALUES(6, 'Реверсивная хроника событий', '2004-01-01');
INSERT INTO "homeWork".album
(album_id, album_name, album_date)
VALUES(7, 'Дорога сна', '2003-01-01');
INSERT INTO "homeWork".album
(album_id, album_name, album_date)
VALUES(8, 'Thriller', '1982-01-01');

-- музыкантов
INSERT INTO "homeWork".musician
(musician_id, first_name, last_name)
VALUES(1, 'Sting', NULL);
INSERT INTO "homeWork".musician
(musician_id, first_name, last_name)
VALUES(2, 'Юрий', 'Шевчук');
INSERT INTO "homeWork".musician
(musician_id, first_name, last_name)
VALUES(3, 'Наталья', 'О'' Шей');
INSERT INTO "homeWork".musician
(musician_id, first_name, last_name)
VALUES(4, 'Michael', 'Jackson');
INSERT INTO "homeWork".musician
(musician_id, first_name, last_name)
VALUES(5, 'Алёна', 'Швец');
INSERT INTO "homeWork".musician
(musician_id, first_name, last_name)
VALUES(6, 'Сплин', NULL);
INSERT INTO "homeWork".musician
(musician_id, first_name, last_name)
VALUES(7, 'Михаил', 'Егоров');
INSERT INTO "homeWork".musician
(musician_id, first_name, last_name)
VALUES(8, 'Green', 'Apelsin');

-- жанры
INSERT INTO "homeWork".genre_of_music
(genre_id, "name")
VALUES(1, 'Фанк');
INSERT INTO "homeWork".genre_of_music
(genre_id, "name")
VALUES(2, 'Инди-поп');
INSERT INTO "homeWork".genre_of_music
(genre_id, "name")
VALUES(3, 'Авторская песня');
INSERT INTO "homeWork".genre_of_music
(genre_id, "name")
VALUES(4, 'Фолк-рок');
INSERT INTO "homeWork".genre_of_music
(genre_id, "name")
VALUES(5, 'Поп');
INSERT INTO "homeWork".genre_of_music
(genre_id, "name")
VALUES(6, 'Рок');
INSERT INTO "homeWork".genre_of_music
(genre_id, "name")
VALUES(7, 'Соул');
INSERT INTO "homeWork".genre_of_music
(genre_id, "name")
VALUES(8, 'R&B');
INSERT INTO "homeWork".genre_of_music
(genre_id, "name")
VALUES(9, 'Русский рок');

-- Сборники
INSERT INTO "homeWork".collection
(collection_id, collection_name, collection_date)
VALUES(1, '25 Year', '2019-01-01');
INSERT INTO "homeWork".collection
(collection_id, collection_name, collection_date)
VALUES(2, 'The best', '2007-01-01');
INSERT INTO "homeWork".collection
(collection_id, collection_name, collection_date)
VALUES(3, '2.0', '2019-01-01');
INSERT INTO "homeWork".collection
(collection_id, collection_name, collection_date)
VALUES(4, 'Popular classics', '2021-01-01');

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

-- Треки в сборник
INSERT INTO "homeWork".collectiontracks
(track_id, collection_id)
VALUES(19, 4);
INSERT INTO "homeWork".collectiontracks
(track_id, collection_id)
VALUES(18, 2);
INSERT INTO "homeWork".collectiontracks
(track_id, collection_id)
VALUES(18, 3);
INSERT INTO "homeWork".collectiontracks
(track_id, collection_id)
VALUES(16, 1);