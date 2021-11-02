#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swapElements(int *a, int *b);
void sortArray(int *array, const int size);
void printArray(int *array, const int size);
double findMean(int *array, const int size);
double findMedian(int *array, const int size);
double findStandardDeviation( int *array, const int size, double average);

int main(){

	int *p1;
   double average;
   double sum = 0.0;
   int i = 0;
   int j;
   int data;
   p1 = malloc(sizeof(int));
   double mean = 0.0, median = 0.0, stdDev = 0.0;
   
	printf("Bonus version of the program. This program can read as many integers as the user types and keep on displaying the cumalive mean, median, and average of the numbers typed so far. Lastly, the allocated memory needs to be freed.\n");

        
	/*****************************************************************/

	//x is not automatically assigned a memory block when it is defined as a pointer variable, you need to allocate a block
	//of memory large enough to hold 'n' integers
   // Write the function that allocates memory to hold 'n' integers
   while(scanf("%d", &data) == 1)
   {
      p1[i] = data;
      
      sum += p1[i];
      i++;
      
      printArray(p1, i);
      average = sum/i;
      printf("The mean value is: %f\n", average);
      
      median = findMedian(p1, i);
      printf("Median of the numbers is: %f\n", median);
      
      stdDev = findStandardDeviation(p1, i, average);
      printf("Standard deviation of the numbers is: %f\n", stdDev);
      
      p1 = realloc(p1, sizeof(int)*(i+1));
   } 
        //Deallocate the memory ;
        free(p1);
        
        return 0;
}





void printArray( int *array, const int size){

    // Complete this function
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sortArray(int* array, const int size) {

    //Complete this function
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swapElements(&array[j], &array[j + 1]);
            }
        }
    }
}   

void swapElements( int *x, int *y){

     // Complete this function
    int temp = *x;
    *x = *y;
    *y = temp;
}


double findMedian(int *array, const int size){

   //Complete this function;
   sortArray(array, size);
   
   if(size % 2)
   {
     return array[size/2];
   }
   if(size % 2 == 0)
   {
      return array[size/2] + array[size/2 - 1]/2.0;
   }
}


double findStandardDeviation( int *array, const int size, double average){

       // Complete this function
       int i;
       double sum = 0.0;
       for(i = 0; i < size; i++)
       {
         sum += pow((array [i] - average), 2);
       }
       if (size > 1)
       {
         return sqrt(sum/(size-1));
       }
       else
         return 0;
}