#include <Event.h>
#include <MyTimer.h>
//#include <Timer.h>

/* Marco Datola 140803729 Queen Mary University of London *
 * First C4DM assignment: produce sound using Teensey 2.0 */
#include <PS2Keyboard.h>
#include "pitches.h"


//create arrays that hold the information
int melody1 [] = {
  NOTE_A3, NOTE_A3, NOTE_B3, NOTE_A3, NOTE_D4, NOTE_C4};
int melody1NoteDuration[]={
  8.5,16,4,4,4,2};
int melody2 []={
  NOTE_A3, NOTE_A3, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_G4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_E4, NOTE_D4};
int melody2NoteDuration[]={
  8.5,16,4,4,4,4,4,8.5,16,4,4,4,2};

//create keyboard object

PS2Keyboard keys;

//create Timer object

Timer time;

//initialize pins


int demo = 2; //pullup button 2 play demo
int keyData = 3; //key
int IRQ = 7;    //key
int lowScale = 5; //button to play 1 scale down
int highScale = 6; //button to play one scale up
int audioOut = 8;

void setup()
{
  keys.begin(keyData,IRQ, PS2Keymap_US);
  pinMode(demo, INPUT_PULLUP);

  int timerEventID=time.every(1000/16,playUserNote); //runs playUserNote method every 1000/16 secs

}

void loop ()
{
  int playDemo = digitalRead(demo);
  if(!playDemo)
    playHappyBirthday();
  else
  {
    int cycleNum;
    while(keys.available())
      int timerEventID=time.every(1000/16,playUserNote,-1,&cycleNum); //runs playUserNote method every 1000/16 secs
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well
    delay (cycleNum*16*1.3);
  }
}

void playUserNote()
{
  int up=digitalRead(highScale);
  int down=digitalRead(lowScale);
  int scale;
  if(up&&!down)
  {
    scale=1;
  }
  else if((up&&down)||(!up&&!down))
  {
    scale=0;
  }
  else
  {
    scale=-1;
  }  
  playnote(keys.read(), scale);
}

void playnote (char note, int scale)
{
  switch (note){
    /*RIGHT HAND*/
  case 'n':
    {
      if(scale == 1)
        tone(audioOut,NOTE_C7);
      else if(scale ==0)
        tone(audioOut,NOTE_C5);
      else
        tone(audioOut,NOTE_C3);
      break;
    }
  case 'j':
    {
      if(scale == 1)
        tone(audioOut,NOTE_D7);
      else if(scale ==0)
        tone(audioOut,NOTE_D5);
      else
        tone(audioOut,NOTE_D3);
      break;
    }
  case 'k':
    {
      if(scale == 1)
        tone(audioOut,NOTE_E7);
      else if(scale ==0)
        tone(audioOut,NOTE_E5);
      else
        tone(audioOut,NOTE_E3);
      break;
    }
  case 'l':
    {
      if(scale == 1)
        tone(audioOut,NOTE_F7);
      else if(scale ==0)
        tone(audioOut,NOTE_F5);
      else
        tone(audioOut,NOTE_F3);
      break;
    }
  case ';':
    {                  //CHECK DIFFERENT KEYBOARD COMPATIBILITIES
      if(scale == 1)
        tone(audioOut,NOTE_G7);
      else if(scale ==0)
        tone(audioOut,NOTE_G5);
      else
        tone(audioOut,NOTE_G3);
      break;
    }
  case 'i':
    {
      if(scale == 1)
        //tone(audioOut,NOTE_A8);  /there is no NOTE_A8
        ;
      else if(scale ==0)
        tone(audioOut,NOTE_A6);
      else
        tone(audioOut,NOTE_A4);
      break;
    }
  case 'o':
    {
      if(scale == 1)
        //tone(audioOut,NOTE_B8);   /there is no NOTE:_B8    
        ;
      else if(scale ==0)
        tone(audioOut,NOTE_B6);
      else
        tone(audioOut,NOTE_B4);
      break;
    }
  case 'p':
    {
      if(scale == 1)
        tone(audioOut,NOTE_C8);
      else if(scale ==0)
        tone(audioOut,NOTE_C6);
      else
        tone(audioOut,NOTE_C3);
      break;
    }
    /*LEFT HAND*/
  case 'v':
    {
      if(scale == 1)
        tone(audioOut,NOTE_C6);
      else if(scale ==0)
        tone(audioOut,NOTE_C4);
      else
        tone(audioOut,NOTE_C2);
      break;
    }
  case 'f':
    {
      if(scale == 1)
        tone(audioOut,NOTE_D6);
      else if(scale ==0)
        tone(audioOut,NOTE_D4);
      else
        tone(audioOut,NOTE_D2);
      break;
    }
  case 'd':
    {
      if(scale == 1)
        tone(audioOut,NOTE_E6);
      else if(scale ==0)
        tone(audioOut,NOTE_E4);
      else
        tone(audioOut,NOTE_E2);
      break;
    }
  case 's':
    {
      if(scale == 1)
        tone(audioOut,NOTE_F6);
      else if(scale ==0)
        tone(audioOut,NOTE_F4);
      else
        tone(audioOut,NOTE_F2);
      break;
    }
  case 'a':
    {
      if(scale == 1)
        tone(audioOut,NOTE_G6);
      else if(scale ==0)
        tone(audioOut,NOTE_G4);
      else
        tone(audioOut,NOTE_G2);
      break;
    }
  case 'e':
    {
      if(scale == 1)
        tone(audioOut,NOTE_A7);
      else if(scale ==0)
        tone(audioOut,NOTE_A5);
      else
        tone(audioOut,NOTE_A3);
      break;
    }
  case 'w':
    {
      if(scale == 1)
        tone(audioOut,NOTE_B7);
      else if(scale ==0)
        tone(audioOut,NOTE_B5);
      else
        tone(audioOut,NOTE_B3);
      break;
    }
  case 'q':
    {
      if(scale == 1)
        tone(audioOut,NOTE_C7);
      else if(scale ==0)
        tone(audioOut,NOTE_C5);
      else
        tone(audioOut,NOTE_C3);
      break;
    }
  }
}
void playHappyBirthday()
{
  for(int a=0; a<=1;a++)
  {
    for(int nPlayed=0;nPlayed<6;nPlayed++)
    {
      int noteDuration=1000/melody1NoteDuration[nPlayed];
      tone(audioOut,melody1[nPlayed],noteDuration);
      int pauseBtwnNotes=noteDuration*1.30;
      delay(pauseBtwnNotes);
    }    
  }
  for(int nPlayed=0;nPlayed<12;nPlayed++)
  {
    int noteDuration=1000/melody2NoteDuration[nPlayed];
    tone(audioOut,melody2[nPlayed],noteDuration);
    int pauseBtwnNotes=noteDuration*1.30;
    delay(pauseBtwnNotes);
  }
  noTone(8);
  delay(500);
}

