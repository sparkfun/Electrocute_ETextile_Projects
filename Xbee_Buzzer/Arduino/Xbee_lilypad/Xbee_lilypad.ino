#include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 6); // RX, TX
int vibePin = A5;
int buzzerPin = A4;
int buttonPin = A2;

const int songLength = 18;

// Notes is an array of text characters corresponding to the notes
// in your song. A space represents a rest (no tone)

char notes[] = "cdcdcdcdcdcdcdcdcd"; // a space represents a rest

// Beats is an array of values for each note and rest.
// A "1" represents a quarter-note, 2 a half-note, etc.
// Don't forget that the rests (spaces) need a length as well.

int beats[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int tempo = 150;

void setup() {
  pinMode(vibePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(vibePin, LOW);
  digitalWrite(buzzerPin, LOW);
  mySerial.begin(9600);
  
}

int frequency(char note) 
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.
  
  int i;
  const int numNotes = 8;  // number of notes we're storing
  
  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  
  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.
  
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}

void play() 
{
  int i, duration;
  
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
    
    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
 
}


void loop() {
   int buttonMode = digitalRead(buttonPin);
      if (buttonMode == LOW){
        mySerial.write("a");
        delay(1000);
        mySerial.write("b");
      }

    while (mySerial.available()) { //is there anything to read?
      
      char getData = mySerial.read();  //if yes, read it

      if(getData == 'a'){    
          digitalWrite(vibePin, HIGH); 
          play();
          digitalWrite(vibePin, LOW);
      }else if (getData != 'a') {
          digitalWrite(vibePin, LOW);
          digitalWrite(buzzerPin, LOW);       
      }
    }

}
