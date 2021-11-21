#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define BAD_NUMBER_ARGS 1
#define FSEEK_ERROR 2
#define FREAD_ERROR 3
#define MALLOC_ERROR 4
#define FWRITE_ERROR 5

/**
 * Parses the command line.
 *
 * argc:      the number of items on the command line (and length of the
 *            argv array) including the executable
 * argv:      the array of arguments as strings (char* array)
 * grayscale: the integer value is set to TRUE if grayscale output indicated
 *            outherwise FALSE for threshold output
 *
 * returns the input file pointer (FILE*)
 **/
FILE *parseCommandLine(int argc, char **argv, int *isGrayscale)
{
  if (argc > 2)
  {
    printf("Usage: %s [-g]\n", argv[0]);
    exit(BAD_NUMBER_ARGS);
  }

  if (argc == 2 && strcmp(argv[1], "-g") == 0)
  {
    *isGrayscale = TRUE;
  }
  else
  {
    *isGrayscale = FALSE;
  }

  return stdin;
}

unsigned getFileSizeInBytes(FILE *stream)
{
  unsigned fileSizeInBytes = 0;

  rewind(stream);
  if (fseek(stream, 0L, SEEK_END) != 0)
  {
    exit(FSEEK_ERROR);
  }
  fileSizeInBytes = ftell(stream);

  return fileSizeInBytes;
}

void getBmpFileAsBytes(unsigned char *ptr, unsigned fileSizeInBytes, FILE *stream)
{
  rewind(stream);
  if (fread(ptr, fileSizeInBytes, 1, stream) != 1)
  {
#ifdef DEBUG
    printf("feof() = %x\n", feof(stream));
    printf("ferror() = %x\n", ferror(stream));
#endif
    exit(FREAD_ERROR);
  }
}

unsigned char getAverageIntensity(unsigned char blue, unsigned char green, unsigned char red)
{
  int temp = 0;
  char charple = 0;
  temp = temp + (int)blue;
  temp = temp + (int)green;
  temp = temp + (int)red;

  temp = temp / 3;
  charple = (char)temp;
  // printf("TODO: unsigned char getAverageIntensity(unsigned char blue, unsigned char green, unsigned char red)\n");
  return charple;
}

void applyGrayscaleToPixel(unsigned char *pixel)
{
#ifndef DEBUG
  int temp = 0;
  temp = temp + (int)*pixel;
  // printf(" average %d", temp);
  temp = temp + (int)*(pixel + 1);
  // printf(" average %d", temp);
  temp = temp + (int)*(pixel + 2);
  // printf(" average %d", temp);

  temp = temp / 3;
  // printf("   final average %d", temp);

  *pixel = (char)temp;
  pixel[1] = (char)temp;
  pixel[2] = (char)temp;
#endif

#ifdef DEBUG
  int temp = 0;
  temp = temp + (int)*pixel;
  printf(" average %d", temp);
  temp = temp + (int)*(pixel + 1);
  printf(" average %d", temp);
  temp = temp + (int)*(pixel + 2);
  printf(" average %d", temp);

  temp = temp / 3;
  printf("   final average %d", temp);

  *pixel = (char)temp;
  *(pixel + 1) = (char)temp;
  *(pixel + 2) = (char)temp;
#endif
  // printf("TODO: void applyGrayscaleToPixel(unsigned char* pixel)\n");
}

void applyThresholdToPixel(unsigned char *pixel)
{
  unsigned char temp = getAverageIntensity(*pixel, pixel[1], pixel[2]);
  int value = 0;
  
  value = (int) temp;

  // printf("Average value: %d", value);
  if (value >= 128)
  {
    value = 0xff;
  }
  else
  {
    value = 0x00;
  }

  temp = (char) value;

  *pixel = (char) temp;
  pixel[1] = (char) temp;
  pixel[2] = (char) temp;
  // printf("TODO: void applyThresholdToPixel(unsigned char* pixel)\n");
}

void applyFilterToPixel(unsigned char *pixel, int isGrayscale)
{

  if (isGrayscale)
  {
    applyGrayscaleToPixel(pixel);
  }
  else
  {
    applyThresholdToPixel(pixel);
  }
  // printf("TODO: void applyFilterToPixel(unsigned char* pixel, int isGrayscale)\n");
}

void applyFilterToRow(unsigned char *row, int width, int isGrayscale)
{
  for (int i = 0; i < (width * 3); i = i + 3)
  {
    applyFilterToPixel(row + i, isGrayscale);
#ifdef DEBUG
    printf("\n");
#endif
  }
  // printf("TODO: void applyFilterToRow(unsigned char* row, int width, int isGrayscale)\n");
}

void applyFilterToPixelArray(unsigned char *pixelArray, int width, int height, int isGrayscale)
{

  int widthInBytes = 0;
  if ((width * 3) % 4 == 0)
  {
    widthInBytes = width * 3;
  }
  else
  {
    widthInBytes = width * 3 + (4 - ((width * 3) % 4));
  }
  for (unsigned int i = 0; i < height; i++)
  {
    applyFilterToRow(pixelArray + (i * widthInBytes), width, isGrayscale);
  }

  // printf("TODO: void applyFilterToPixelArray(unsigned char* pixelArray, int width, int height, int isGrayscale)\n");
}

void parseHeaderAndApplyFilter(unsigned char *bmpFileAsBytes, int isGrayscale)
{
  int offsetFirstBytePixelArray = 0;
  int width = 0;
  int height = 0;
  unsigned char *pixelArray = NULL;
  int *offsetData = (int *)(bmpFileAsBytes + 10);
  int *widthData = (int *)(bmpFileAsBytes + 18);
  int *heightData = (int *)(bmpFileAsBytes + 22);

  offsetFirstBytePixelArray = *offsetData;
  width = *widthData;
  height = *heightData;
  pixelArray = bmpFileAsBytes + offsetFirstBytePixelArray;

  // printf("This is the offsetfor the pixels?: %d", *offsetData);
  // printf("TODO: set offsetFirstBytePixelArray\n");
  // printf("TODO: set width\n");
  // printf("TODO: set height\n");
  // printf("TODO: set the pixelArray to the start of the pixel array\n");

#ifdef DEBUG
  printf("offsetFirstBytePixelArray = %u\n", offsetFirstBytePixelArray);
  printf("width = %u\n", width);
  printf("height = %u\n", height);
  printf("pixelArray = %p\n", pixelArray);
#endif

  applyFilterToPixelArray(pixelArray, width, height, isGrayscale);
}

int main(int argc, char **argv)
{
  int grayscale = FALSE;
  unsigned fileSizeInBytes = 0;
  unsigned char *bmpFileAsBytes = NULL;
  FILE *stream = NULL;

  stream = parseCommandLine(argc, argv, &grayscale);
  fileSizeInBytes = getFileSizeInBytes(stream);

#ifdef DEBUG
  printf("fileSizeInBytes = %u\n", fileSizeInBytes);
#endif

  bmpFileAsBytes = (unsigned char *)malloc(fileSizeInBytes);
  if (bmpFileAsBytes == NULL)
  {
    exit(MALLOC_ERROR);
  }
  getBmpFileAsBytes(bmpFileAsBytes, fileSizeInBytes, stream);

  parseHeaderAndApplyFilter(bmpFileAsBytes, grayscale);

#ifndef DEBUG
  if (fwrite(bmpFileAsBytes, fileSizeInBytes, 1, stdout) != 1)
  {
    exit(FWRITE_ERROR);
  }
#endif

  free(bmpFileAsBytes);
  return 0;
}
