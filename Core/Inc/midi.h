#ifndef _MIDI_H
#define _MIDI_H

#include "main.h"

// midi states
#define MIDI_WAIT 1
#define MIDI_READING 2
#define MIDI_IGNORING 3

// midi events
#define MIDI_NOTE_OFF 	0x80
#define MIDI_NOTE_ON 	0x90
#define MIDI_POLY_TOUCH 	0xA0
#define MIDI_CONTROL_CHANGE	0xB0
#define MIDI_PROGRAM_CHANGE	0xC0
#define MIDI_CHANNEL_TOUCH	0xD0
#define MIDI_PITCH_BEND	        0xE0

// midi system events
#define MIDI_SYSEX_START        0xF0
#define MIDI_SYSEX_END          0xF7
#define MIDI_MTC                0xF1
#define MIDI_SPP                0xF2
#define MIDI_SONG_SEL           0xF3
#define MIDI_TUNE_REQ           0xF6
#define MIDI_CLOCK              0xF8
#define MIDI_SYNC               0xF9
#define MIDI_START              0xFA
#define MIDI_STOP               0xFC
#define MIDI_CONT               0xFB
#define MIDI_SENSE              0xFE
#define MIDI_RESET              0xFF


#define MIDI_DATA_MASK			0x7F
#define MIDI_STATUS_MASK		0xF0
#define MIDI_CHANNEL_MASK		0x0F

#define MIDI_BAUD_RATE			31250

/**
 * MIDI event definition structure
 *
 * Structure defining a MIDI event and its related data.
 * A pointer to this structure type is passed the the related callback function.
 */
typedef struct
{
  uint8_t track;    ///< the track this was on
  uint8_t channel;  ///< the midi channel
  uint8_t size;     ///< the number of data bytes
  uint8_t data[4];  ///< the data. Only 'size' bytes are valid
} midi_event;

/**
 * SYSEX event definition structure
 *
 * Structure defining a SYSEX event and its related data.
 * A pointer to this structure type is passed the the related callback function.
 */
typedef struct
{
  uint8_t track;    ///< the track this was on
  uint16_t size;    ///< the number of data bytes
  uint8_t data[50]; ///< the data. Only 'size' bytes are valid
} sysex_event;

/**
 * META event definition structure
 *
 * Structure defining a META event and its related data.
 * A pointer to this structure type is passed the the related callback function.
 */
typedef struct
{
  uint8_t track;    ///< the track this was on
  uint16_t size;    ///< the number of data bytes
  uint8_t type;     ///< meta event type
  union
  {
    uint8_t data[50]; ///< byte data. Only 'size' bytes are valid
    char chars[50];   ///< string data. Only 'size' bytes are valid
  };
} meta_event;

struct midi_time_event{
	midi_event event;
	unsigned long delta;
};
	
unsigned char * getMidiEvent();
struct midi_time_event * getMidiStruct(unsigned long dt);
BOOL readMidiMessage(unsigned char c,unsigned char *len);
void sendMidiMessage(unsigned char num);
void sendMidiBuffer(unsigned char *buf,unsigned char num);
void sendProgramChange(unsigned char bank,unsigned char program);
void midiFileVolume(unsigned char vol);
void midiPlayVolume(unsigned char vol);
void midiFun(midi_event *ev);
void metaFun(const meta_event *ev);
void sysexFun(sysex_event *ev);
void midiInit(void);
void midiPoll(unsigned char byte);
unsigned char commandLen(unsigned char cmd);




#endif
