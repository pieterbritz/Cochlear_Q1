#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger.h"

void logger(const char* tag, const char* message) 
{
   FILE *fptr = fopen("rewards.log", "a");
   if (fptr == NULL)
   {
      fptr = fopen("rewards.log", "w");
      if (fptr == NULL)
      {
         return;
      }
   }
   time_t now;
   time(&now);
   fprintf(fptr,"%s [%s]: %s\n", ctime(&now), tag, message);
   fclose(fptr);
}