#include "fileTest.h"

void convertLower(char* str)
{
   int i, len;
   len = strlen(str);
   for(i = 0; i < len; i++)
   {
      str[i] = tolower(str[i]);
   }
}

int countString(const char* fileName, char *str){
    
    int word_count = 0;
    char buff[100];
    
    FILE* f = fopen(fileName, "r");
    if(f == NULL)
    {
      perror("Error in opening file:");
      exit(0);
    }
    
    convertLower(str);
    
    while(fscanf(f, "%s", buff) != -1)
    {
      convertLower(buff);
      if(strstr(buff, str) != NULL)
      {
         word_count++;
      }
    }
    return word_count;
}



int countEmptyLines(const char *fileName){
    
    int emptyLine = 0;
    char buff[BUFSIZ];
    int i, len;
    
    FILE* f = fopen(fileName, "r");
    
    if(f==NULL)
    {
      perror("Error in opening file:");
      exit(0);
    }
    
    while(fgets(buff, sizeof(buff), f) != NULL)
    {
       emptyLine++;
       len = strlen(buff);
       for(i = 0; i < len; i++)
       {
          if(buff[i] != '\n' && buff[i] != '\t' && buff[i] != ' ')
            emptyLine--;
            break;
       }
    }
    return emptyLine;
}