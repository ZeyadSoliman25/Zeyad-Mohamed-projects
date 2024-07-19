from bs4 import BeautifulSoup
import requests
import spotipy
from spotipy.oauth2 import *


destination_time = input("Which year you want to travel to? Enter time in the form YYYY-MM-DD ")

response = requests.get(f"https://www.billboard.com/charts/hot-100/{destination_time}/")
webpage_data = response.text

billboard_songs = BeautifulSoup(webpage_data, "html.parser")
top_songs = [song.get_text().strip() for song in billboard_songs.select(selector="li ul li h3")]

spotipy_client = SpotifyOAuth(client_id="",
                              client_secret="", redirect_uri="",
                              scope="",
                              show_dialog=True, cache_path="token.txt")
spotipy_user = spotipy.Spotify(auth_manager=spotipy_client)
client_id = spotipy_user.current_user()["id"]

year = destination_time.split("-")[0]
songs_uri=[]

for song in top_songs:
    result = spotipy_user.search(q=f"track:{song} year:{year}", type="track")
    try:
        uri = result["tracks"]["items"][0]["uri"]
        songs_uri.append(uri)
    except IndexError:
        print(f"{song} not found, so I skipped it")

spotify_list = spotipy_user.user_playlist_create(user=client_id, name=f"{destination_time} billboard songs", public=False)
spotipy_user.playlist_add_items(playlist_id=spotify_list["id"], items=songs_uri)
