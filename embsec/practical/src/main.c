// Copyright 2024 The MITRE Corporation. ALL RIGHTS RESERVED

// Approved for public release. Distribution unlimited 23-02181-18.

#include "utils.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is the main function, it will get called first when you run your program
int main() {

  /*
   * We are going to be designing a procedure that reads, modifies, then writes
   * data. We can think of each of these steps are discrete operations, or
   * functions. We will define a function to perform each of these tasks, then
   * here in main(), link them together with our data.
   *
   * We will need to define functions that do the following
   * 1. Read input from the user into a string that we can do operations are
   * 2. Parse that input and generate metadata
   * 3. Encode the data and metadata into our packet format
   * 4. Output the packet in a human readable form
   *
   * The output of each function will be specified, but it's up to you on how to
   * define them! Each function's signature is stated in the utils.h file, with
   * the definitions started in utils.c. You don't have to change the function's
   * signature/definition if you don't want to, but if you'd like to solve the
   * problem in a different way, you may.
   *
   * We are using a seperate C module called utils in order to demonstrate how a
   * C program can be built from multiple files, but it is not required. All
   * your code could be written in a single C file, but it is often helpful to
   * organize code into header and module files as we have done.
   *
   * Start implementing below! Each step begins here in main(), and might jump
   * over to utils if you need to define a function housed there. Wherever you
   * see "<code here>" there should be something to implement.
   *
   * However, if you come up with a clever solution to solve a problem or
   * implement a solution, we'd love to see it.
   *
   * If you get stuck with a C concept or are looking for a pointer, head over
   * to Piazza and feel free to post your code. Instructors will be happy to
   * point you in the right direction and students are encouraged to also
   * provide support.
   *
   * Now: 3, 2, 1... Begin!
   */

  /* STEP 1: GET INPUT FROM THE USER */

  // First, define a character array of size 256 to hold our input.
  // <code here>
  char buffer[256];

  // Next, go to utils.c and define your "getUserInput" function.
  // Call your "getUserInput" function here, it will use the input buffer you
  // just declared <code here>

  getUserInput(buffer);

  /* END STEP 1: Now our input string should be stored inside our input buffer!
   */

  /* STEP 2: PARSE THE INPUT STRING */

  // First, create a packet using our pkt_t struct
  // <code here>

  pkt_t* pkt = malloc(sizeof(pkt_t));

  // Next, define and call your parseInput function passing the string
  // input and pkt as arguments <code here>

  parseInput(buffer, pkt);

  /* END STEP 2: the packet structure should now contain metadata (length &
   * checksum) */

  /* STEP 3: TRANSFER DATA FROM THE PACKET STRUCTURE TO A MEMORY BUFFER */
  // We need to create a new buffer in memory (separate from the input buffer)
  // to hold our packet. Since we only know the size of our packet since parsing
  // it, we will have to create this memory at runtime. You'll have to use
  // malloc (https://man7.org/linux/man-pages/man3/malloc.3.html) to create a
  // pointer to a new buffer of the correct size (hdrLen + dataLen) <code here>

  uint16_t size = pkt->hdrLen + pkt->dataLen;
  uint8_t* pkt_buffer = malloc(size);

  // Transfer data from the pkt struct we built into this new buffer
  // Remember the structure of the packet
  /*
  +-------------------------------------------- Buffer ------------------------------------------+
  | hdrLen (1) | checksum (1) | dataLen (1) |                   data (n...)                      |
  +----------------------------------------------------------------------------------------------+
  */
  // (hint: try using memcpy
  // [https://man7.org/linux/man-pages/man3/memcpy.3.html], you may have to copy
  // struct fields over individually, think about why?) <code here>

  memcpy(pkt_buffer, &pkt->hdrLen, 1);
  memcpy(pkt_buffer + 1, &pkt->checksum, pkt->hdrLen);
  memcpy(pkt_buffer + 2, &pkt->dataLen, 1);
  memcpy(pkt_buffer + pkt->hdrLen, pkt->data, pkt->dataLen);

  /* END STEP 3: Your packet should now be loaded into a buffer of continuous
   * memory */

  /* STEP 4: SEND OUT YOUR PACKET */
  // Well, just to the commandline. We'll have to translate our byte array into
  // a human-readable format, then use printf to print the buffer to the
  // commandline. Implement the printPacket function in utils.c below and call
  // it here <code here>

  /* END STEP 4: compile and run your executable, your input will be encoded
   * then printed to the console as a sequence of bytes */

  printPacket(pkt_buffer, size);

  free(pkt);
  free(pkt_buffer);

  return 0;
}
