/*
  wiring.h - Partial implementation of the Wiring API for the ATmega8.
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 387 2008-03-08 21:30:00Z mellis $
*/

#ifndef Wiring_h
#define Wiring_h

#include <avr/io.h>
#include "binary.h"

#ifdef __cplusplus
extern "C"{
#endif

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1

#define true 0x1
#define false 0x0

#define PI 3.14159265
#define HALF_PI 1.57079
#define TWO_PI 6.283185
#define DEG_TO_RAD 0.01745329
#define RAD_TO_DEG 57.2957786

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define INTERNAL 3
#define DEFAULT 1
#define EXTERNAL 0

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define int(x)     ((int)(x))
#define char(x)    ((char)(x))
#define long(x)    ((long)(x))
#define byte(x)    ((uint8_t)(x))
#define float(x)   ((float)(x))
#define boolean(x) ((uint8_t)((x)==0?0:1))

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() sei()
#define noInterrupts() cli()

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

typedef uint8_t boolean;
typedef uint8_t byte;

void init(void);

void beginSerial(long);
void serialWrite(unsigned char);
int serialAvailable(void);
int serialRead(void);
void serialFlush(void);
void printByte(unsigned char c);
void printString(const char *s);
void printInteger(long n);
void printHex(unsigned long n);
void printOctal(unsigned long n);
void printBinary(unsigned long n);
void printIntegerInBase(unsigned long n, unsigned long base);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, byte val);

void setup(void);
void loop(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
