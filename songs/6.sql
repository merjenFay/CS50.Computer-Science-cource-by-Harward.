SELECT name FROM songs
WHERE artist_id = (SELECT id FROM artists Where name = "Post Malone");