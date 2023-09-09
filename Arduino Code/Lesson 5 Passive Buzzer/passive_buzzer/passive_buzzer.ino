#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556
 
#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278
 
#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 1112
// List all D-tuned frequencies
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
// List all beats
int tune [] = // List each frequency according to the notation
{
  NTDH1, NTD6, NTD5, NTD0,
  NTDH1, NTD6, NTD5, NTDH1,NTD6,NTD0,NTD6,
  NTD6, NTD6, NTD5, NTD6,NTD0,NTD6,
  NTDH1,NTD6, NTD5,NTDH1,NTD6,NTD0,
  NTD1, NTD1, NTD3,
  NTDL1, NTD1, NTD3, NTD0,
  NTD6, NTD6, NTD6, NTD5,NTD6,
  NTD5, NTD1, NTD3, NTD0,
  NTDH1, NTD6, NTD6, NTD5,NTD6,
  NTD5, NTD1, NTD2, NTD0, 
  NTD7, NTD7, NTD5, NTD3,
  NTD5,
  NTDH1, NTD0, NTDL6, NTD6,NTD5, NTDL5, NTD6,NTD6,
  NTD0, NTD5, NTD1, NTD3,NTD0,
  NTDH1,NTD0, NTD6, NTD6, NTD5, NTD5,NTD6, NTD6, 
  NTD0,NTD5,NTD1,NTD2,NTD0, 
  NTD3,NTD3,NTD1,NTDL6,
  NTD1,
  NTD3,NTD5,NTD6,NTDL6,
  NTD3,NTD5,NTD6,NTDL6,
  NTDH1, NTD0, NTD7,NTD5,
  NTD6
};
float durt [] = // List the beats according to the notation
{
  1,1,0.5,0.5,1,
  0.5,0.5,0.5,0.5,1,0.5,0.5,
  0.5,1,0.5,1,0.5,0.5,
  0.5,0.5,0.5,0.5,1,1,
  1,1,1+1,
  0.5,1,1+0.5,1,
  1,1,0.5,0.5,1,
  0.5,1,1 + 0.5,1,
  0.5,0.5,0.5,0.5,1+1,
  0.5,1,1+0.5,1,
  1+1,0.5,0.5,1,
  1+1+1+1,
  0.5,0.5,0.5+0.25,0.5,0.5+0.25,0.5,0.5+0.25,0.5,
  0.5,1,0.5,1,1,
  0.5,0.5,0.5+0.25,0.5,0.5+0.25,0.5,0.5+0.25,0.5,
  0.5,1,0.5,1,1,
  1+1,0.5,0.5,1,
  1+1+1+1,
  0.5,1,0.5,1+1,
  0.5,1,0.5,1+1,
  1+1,0.5,0.5,1,
  1+1+1+1
};
int length;
int tonepin = 8; // Use interface 8
void setup ()
{
  pinMode (tonepin, OUTPUT);
  length = sizeof (tune) / sizeof (tune [0]); // Calculate length
}
void loop ()
{
  for (int x = 0; x <length; x ++)
  {
    tone (tonepin, tune [x]);
    delay (350* durt [x]); // This is used to adjust the delay according to the beat, 350 can be adjusted by yourself.
    noTone (tonepin);
  }
  delay (2000); // delay 2S
}

