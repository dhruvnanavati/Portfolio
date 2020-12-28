import lyricsgenius

explicit = ["fuck", "fucks", "fuckin", "fucking", "mothafuckin", "motherfuckin", "shit", "shits",
            "bitch", "bitches", "nigga", "niggas", "hoe", "hoes", "ass", "dick", "pussy"]
genius = lyricsgenius.Genius("Xec48ynEULGRZf9kI7CS3D9ZjPWHkPab6R0G4g0502eyKTdNUW9LRC35aDXdEPpT")


#Takes out all special characters
def filterLyrics(originalLyrics):
    filterSymbols = [ ".", ",", "(", ")", "!", "?", "'"]
    originalLyrics = originalLyrics.translate({ord(w): "" for w in filterSymbols})
    originalLyrics = originalLyrics.lower()
    filteredLyricsLines = [[x for x in ll.split(" ")] for ll in originalLyrics.splitlines()]
    #print(filteredLyricsLines)
    return filteredLyricsLines


#Checks whether there are bad words in the lyrics
#Makes the explicit words red
#Prints the lyrics
#Prints according to the amount of bad words
def checkExplicit(l):
    global lyricsLines
    
    explicitCount = 0
    for i, line in enumerate(l):
        for j, word in enumerate(l[i]):
            for explicitWord in explicit:
                if word == explicitWord:
                    lyricsLines[i][j] = "\033[31m" + lyricsLines[i][j] + "\033[30m"
                    explicitCount += 1
        lyricsLines[i] = " ".join(lyricsLines[i])

    lyricsLines = "\n".join(lyricsLines)
    print("\n" + lyricsLines + "\n")
            
    if explicitCount == 0:
        print("This song is not explicit")
    elif explicitCount == 1:
        print(songName + " by " + artistName + " has " + str(explicitCount) + " bad word so it is barely explicit")
    elif explicitCount < 10:
        print(songName + " by " + artistName + " has " + str(explicitCount) + " bad words so it is explicit.")
    elif explicitCount < 25:
        print(songName + " by " + artistName + " has " + str(explicitCount) + " bad words so it is pretty explicit.")
    elif explicitCount < 40:
        print(songName + " by " + artistName + " has " + str(explicitCount) + " bad words so it is super explicit.")
    else:
        print(songName + " by " + artistName + " is a bad influence on you. " + str(explicitCount) + " explicit words.")
        print("You can do better.")


#Main
print("Welcome to the Explicit Music Detector!")
print("[1] Check a song")
print("[QUIT] Ends the program")
endProgram = input("Which option would you like to choose? ")
while endProgram != "1" and endProgram != "QUIT":
    endProgram = input("That's not an option! Try again: ")

while endProgram != "QUIT":
    print("[1] Find a song using the song name and artist name")
    print("[2] Find a song using parts of the lyrics")
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
        lyricsLines = [[x for x in ll.split(" ")] for ll in lyrics.splitlines()]
        #lyricsWords = lyrics.split()
        #print("\n" + lyrics + "\n")
        
        checkExplicit(filterLyrics(str(lyrics)))
    except:
        print("")
    
    print("\n[1] Check another song")
    print("[QUIT] Ends the program")
    endProgram = input("Which option would you like to choose? ")
    while endProgram != "1" and endProgram != "QUIT":
        endProgram = input("That's not an option! Try again: ")

print("Have a nice day!")
