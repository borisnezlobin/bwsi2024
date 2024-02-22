// Copyright 2024 The MITRE Corporation. ALL RIGHTS RESERVED

// Approved for public release. Distribution unlimited 23-02181-18.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is you HEADER file. All of your utility functions are described here as
 * function signatures. The return type and parameters must match your function
 * definitions in the "utils.c" file.
 *
 * You will not have to modify any part of this file, but we do recommend you
 * look through it as an example for common header file objects.
 */

// Consider using a macro to define your "magic numbers", like the size of your
// input buffer
#define BUF_SIZE 256

// This is a c struct, which allows us to define custom datatypes. Each member
// of the struct (hdrLen, checksum, dataLen, data) can be accessed with the dot
// operator (pkt.hdrLen) or the arrow operator if pkt is a pointer (pkt->hdrLen)
//
// The struct definition below acts as a template for the memory structure of
// any packets we wish to declare.
typedef struct pkt_t {
  // pkt header
  uint8_t hdrLen;
  uint8_t checksum;
  uint8_t dataLen;
  // pkt data
  char *data;
} pkt_t;

void getUserInput(char *buffer);
void parseInput(char *buffer, pkt_t *packet);
void printPacket(uint8_t *buffer, uint16_t bufSize);
