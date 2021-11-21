#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define BAD_NUMBER_ARGS 1

/**
 * Parses the command line.
 *
 * argc: the number of items on the command line (and length of the
 *       argv array) including the executable
 * argv: the array of arguments as strings (char* array)
 * bits: the integer value is set to TRUE if bits output indicated
 *       outherwise FALSE for hex output
 *
 * returns the input file pointer (FILE*)
 **/
FILE *parseCommandLine(int argc, char **argv, int *bits)
{
  if (argc > 2)
  {
    printf("Usage: %s [-b|-bits]\n", argv[0]);
    exit(BAD_NUMBER_ARGS);
  }

  if (argc == 2 &&
      (strcmp(argv[1], "-b") == 0 || strcmp(argv[1], "-bits") == 0))
  {
    *bits = TRUE;
  }
  else
  {
    *bits = FALSE;
  }

  return stdin;
}

/**
 * Writes data to stdout in hexadecimal.
 *
 * See myxxd.md for details.
 *
 * data: an array of no more than 16 characters
 * size: the size of the array
 **/
void printDataAsHex(unsigned char *data, size_t size)
{
  // unsigned char bad = 0X0000;
  // unsigned char ender = 0X007F;
  printf(" ");
  for (unsigned int i = 0; i < 16; i++)
  {
    if (i < size)
    {
      printf("%02x", data[i]);
    }
    else
    {
      printf("  ");
    }
    if (i % 2 == 1 && i > 0)
    {
      printf(" ");
    }
  }
  // printf("TODO 1: printDataAsHex (2)");
}

/**
 * Writes data to stdout as characters.
 *
 * See myxxd.md for details.
 *
 * data: an array of no more than 16 characters
 * size: the size of the array
 **/
void printDataAsChars(unsigned char *data, size_t size)
{
  // unsigned char bad = 0X0020;
  // unsigned char ender = 0X007E;
  // unsigned char nuller = 0X0000;
  // unsigned char endofText = 0X007F;
  // unsigned char newLine = 0X000A;
  for (unsigned int v = 0; v < 16; v++)
  {
    if (v < size)
    {
      if (data[v] >= 0x20 && data[v] <= 0x7e)
      {
        printf("%c", data[v]);
      }
      else
      {
        printf(".");
      }
      // else
      // {
      //   printf(" ");
      // }
    }
  }

  // printf("TODO 2: printDataAsChars (3)");
}

void readAndPrintInputAsHex(FILE *input)
{
  unsigned char data[16];
  int numBytesRead = fread(data, 1, 16, input);
  unsigned int offset = 0;
  while (numBytesRead != 0)
  {
    printf("%08x:", offset);
    offset += numBytesRead;
    printDataAsHex(data, numBytesRead);
    printf(" ");
    printDataAsChars(data, numBytesRead);
    printf("\n");
    for (unsigned int i = 0; i < 16; i++)
    {
      data[i] = 0X0000;
    }
    numBytesRead = fread(data, 1, 16, input);
  }
}

void printDataAsBinary(unsigned char *data, size_t size)
{
  unsigned char bitString[9];
  for (unsigned int i = 0; i < 6; i++)
  {
    int value = data[i];
    for (unsigned int x = 0; x < 8; x++)
    {
      bitString[x] = 0X0000;
    }
    for (unsigned int j = 0; j < 8; j++)
    {
      if (value % 2 == 1)
      {
        bitString[j + 1] = 1;
      }
      else
      {
        bitString[j + 1] = 0;
      }
      value = value / 2;
    }
    // int truth = 0;
    // for (unsigned int t = 0; t < 8; t++)
    // {
    //   if (bitString[t] != 0)
    //   {
    //     truth = 1;
    //     break;
    //   }
    // }
    // if (truth)
    // {
    //   for (unsigned int k = 8; k > 0; k--)
    //   {
    //     printf("%d", bitString[k]);
    //   }
    // }
    // else
    // {
    //   printf("        ");
    // }
    if (i < size)
    {

      for (unsigned int k = 8; k > 0; k--)
      {
        printf("%d", bitString[k]);
      }
    }
    else 
    {
      printf("        ");

    }
    printf(" ");
  }
}

/**
 * Bits output for xxd.
 *
 * See myxxd.md for details.
 *
 * input: input stream
 **/
void readAndPrintInputAsBits(FILE *input)
{
  unsigned char data[6];
  int numBytesRead = fread(data, 1, 6, input);
  unsigned int offset = 0;
  while (numBytesRead != 0)
  {
    printf("%08x:", offset);
    printf(" ");
    offset += numBytesRead;
    printDataAsBinary(data, numBytesRead);
    printf(" ");
    printDataAsChars(data, numBytesRead);
    printf("\n");
    for (unsigned int i = 0; i < 6; i++)
    {
      data[i] = 0X0000;
    }
    numBytesRead = fread(data, 1, 6, input);
  }
}

int main(int argc, char **argv)
{
  int bits = FALSE;
  FILE *input = parseCommandLine(argc, argv, &bits);

  // printf("string %c" ,input);

  if (bits == FALSE)
  {
    readAndPrintInputAsHex(input);
  }
  else
  {
    readAndPrintInputAsBits(input);
  }
  return 0;
}
