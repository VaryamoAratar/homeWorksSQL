select "name" Название_жанра, count(mg.genre_id) as Число_исполнителей
from "homeWork".musician_genre mg
join "homeWork".genre_of_music gom on mg.genre_id = gom.genre_id 
group by "name"
order by count(mg.genre_id) desc
;

select count(album) Tracks_in_2019_2020
from "homeWork".track t 
join "homeWork".album a on t.album = a.album_id 
where a.album_date between '2019-01-01' and '2020-01-01'
;

select avg(t.lenght_track) Средняя_длина_трека, a.album_name Название_альбома
from "homeWork".track t
join "homeWork".album a on t.album = a.album_id
group by a.album_name 
;

select m.first_name, m.last_name 
from "homeWork".musician_album ma 
join "homeWork".album a on ma.album_id  = a.album_id 
join "homeWork".musician m on ma.musician_id = m.musician_id 
where a.album_date != '2020-01-01' 
;

select c.collection_name Название_сборника
from "homeWork".collection c 
join "homeWork".collectiontracks c2 on c.collection_id = c2.collection_id 
join "homeWork".track t on c2.track_id = t.track_id 
join "homeWork".musician_album ma on t.album = ma.album_id 
where ma.musician_id = 4
;