import lyricsgenius
from py_imessage import imessage

"""This program annoyingly texts a person whatever song you would like line by
    line to a person of your choosing. You are able to choose a song using a
    line from the song or the name + artist"""


genius = lyricsgenius.Genius("Xec48ynEULGRZf9kI7CS3D9ZjPWHkPab6R0G4g0502eyKTdNUW9LRC35aDXdEPpT")



#Texts line by line through imessage to a number
def textLines(l, p_n):
    for i in l.splitlines():
        imessage.send(p_n, i)

#Main
print("Welcome to the LyricSpam")
print("[1] Text a song")
print("[QUIT] Ends the program")
endProgram = input("Which option would you like to choose? ")
while endProgram != "1" and endProgram != "QUIT":
    endProgram = input("That's not an option! Try again: ")

while endProgram != "QUIT":
    print("[1] Text a song using the song name and artist name")
    print("[2] Text a song using parts of the lyrics")
    findChoice = input("How would you like to find your song? ")
    while findChoice != "1" and findChoice != "2":
        findChoice = input("That's not an option! Try again: ")
    if findChoice == "1":
        songName = input("Please enter the song name: ")
        artistName = input("Please enter the artist name: ")
        song = genius.search_song(songName, artistName)
    elif findChoice == "2":
        partLyric = input("Please enter a part of the lyrics: ")
        song = genius.search_song(partLyric)

    try:
        songName = song.title
        artistName = song.artist
        lyrics = song.lyrics

        textLines(str(lyrics), "3152540569")

    except:
        print("")

    print("\n[1] Check another song")
    print("[QUIT] Ends the program")
    endProgram = input("Which option would you like to choose? ")
    while endProgram != "1" and endProgram != "QUIT":
        endProgram = input("That's not an option! Try again: ")

print("Have a nice day!")
