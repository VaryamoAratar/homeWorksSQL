select a.album_name Название_альбома
from musician_album ma 
join album a on ma.album_id = a.album_id 
join musician_genre mg  on ma.musician_id = mg.musician_id 
group by a.album_name, mg.musician_id 
having count(mg.musician_id) > 1
;

select t.track_name Название_трека
from track t 
full outer join collectiontracks c on t.track_id = c.track_id 
where c.collection_id is null 
order by t.track_id 
;

select first_name, last_name 
from musician m 
join musician_album ma on m.musician_id = ma.musician_id 
join track t on ma.album_id = t.album 
where t.lenght_track = (select min(lenght_track) from track)
;

select album_name
from album a 
join track t on a.album_id = t.album 
group by album_name
having count(t.album) <= (select count(album)
						  from track
						  group by album
						  order by (count(album))
						  limit 1)
;
