#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>

int main() {

    //Declare Arrays to store inputs
	char processors[10][100];
	float costs[10];
	float clockrates[10];
	float cpis[10];
	float executiontimes[10];

    //Prompt and Store number of processors
    printf("Please enter the number of processors [1 to 10]: \n");
    int numOfProcessors;
    scanf("%d", &numOfProcessors);    

    //Loop through Processors and store into array
    int i;
    for (i = 0; i < numOfProcessors; i++) {
        printf("Processor Name (no spaces): \n");
        scanf("%s", processors[i]);
        printf("Processor cost (US dollars): \n");
        scanf("%f", &costs[i]);
        printf("Processor clock rate (in GHz): \n");
        scanf("%f", &clockrates[i]);
        printf("Processor average CPI: \n");
        scanf("%f", &cpis[i]);  
    }
    //Calculate Execution Times
    int c;
    for(c = 0; c < numOfProcessors; c++) {
        executiontimes[c] = (float)(int)(10000*(cpis[c] / (clockrates[c] * 100)) + .5) / 10000;   
    }

    printf("Now ranking execution times...  from lowest to highest execution time, your results are: \n");
    int z, j; 
    
    float temp1;
    float tCosts;
    char *strTemp;

    //Bubble Sort
    for (z = 0; z < numOfProcessors-1; z++){
       for (j = 0; j < numOfProcessors-1-z; j++){
           if (executiontimes[j] > executiontimes[j+1]){
                //Swap Execution times
                temp1 = executiontimes[j];
                executiontimes[j] = executiontimes[j+1];
                executiontimes[j+1] = temp1;
                //Swap Names
                strcpy(strTemp, processors[j]); 
                strcpy(processors[j], processors[j+1]);
                strcpy(processors[j+1], strTemp);
                //Swap Costs
                tCosts = costs[j];
                costs[j] = costs[j+1];
                costs[j+1] = tCosts;
           }
       }
    }       
    //Print out processors after sorting
    for (i = 0; i < numOfProcessors; i++) {
        printf("%s: %.4f\n", processors[i], executiontimes[i]);
    }
    float targetTime;
    printf("What execution time (in seconds) are you targeting? \n");
    scanf("%f", &targetTime);
    
    i = 0;
    int minCostIndex = 0;
    
    for (i = 0; i < numOfProcessors - 1 ; i++) {
        if (executiontimes[i] < targetTime) {
            if (costs[i] < costs[minCostIndex]) {
                minCostIndex = i;
            }
        }
    }
    
    printf("The cheapest processor to meet your specification is: %s at a price of $%.2f.\n", processors[minCostIndex], costs[minCostIndex]);

    return 0;
}
