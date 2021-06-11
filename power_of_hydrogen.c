/*****************************************************************************************************************/
/*						    'pH' Calculator	                                         */
/*****************************************************************************************************************/

/* 
 * Author:	Aly Khan Nuruddin
 * Date:	May 25, 2021
 *
 * Purpose:	This program prompts the user to enter the molar concentration of a solution in Molarity (M),
 *		and then computes its power of Hydrogen (pH) value to four decimal places.
 */

/*****************************************************************************************************************/
 
 #define _CRT_SECURE_NO_WARNINGS		// Prohibit the compiler from suggesting secure versions of library functions.

 #include <stdio.h>				// Include the standard input and output library in C.
 #include <stdlib.h>				// Include the standard library in C.
 #include <math.h>				// Include the standard math library in C.
 
 #define ACIDITY_THRESHOLD 6.5			// Define the power of Hydrogen (pH) limit for which a solution is acidic.
 #define ALKALINITY_THRESHOLD 7.5		// Define the power of Hydrogen (pH) limit for which a solution is alkaline.
 
 #define MAX_COUNT 3				// Define the maximum number of loop iterations.
 
 int main( void )				// Define the function "main".
 {   
     int count = 1;										// Initialize the variable that keeps track of each loop iteration.
     
     double molarConcentration;									// Define the variable that stores the molar concentration of a solution in Molarity.
     double powerOfHydrogen;									// Define the variable that stores the power of Hydrogen of a solution.
     
     printf( "Enter the molar concentration of a solution in Molarity (M): " );			// Request the user to input the molar concentration of a solution in Molarity.
     scanf( "%lf", &molarConcentration );							// Read the value entered by the user and assign it to the variable.
     
     while( count < MAX_COUNT )									// Define the condition where 'count' is within the permissible number of iterations.
     {
         if( molarConcentration < 0 )								// Define the condition where the user inputs a negative molar concentration value.
         {
             printf( "\nError: Do not enter a negative value for molar concentration! " );	// Notify the user that they have entered an invalid input.
             printf( "The logarithm of a negative number cannot be computed. " );		// Inform the user that the logarithm of a negative number cannot be computed.
             
             printf( "\n\nEnter the molar concentration of a solution in Molarity (M): " );	// Request the user to input the molar concentration of a solution in Molarity.
             scanf( "%lf", &molarConcentration );						// Read the value entered by the user and assign it to the variable.
         }
         
         else											// Define the condition where the user inputs a positive molar concentration value.
         {
             powerOfHydrogen = -log10(molarConcentration);					// Compute the power of Hydrogen (pH) of the solution.
             
             printf( "\nThe power of Hydrogen (pH) value of the solution is %.4lf. ", powerOfHydrogen );  // Print the power of Hydrogen value upto four decimal places.
             
             if ( powerOfHydrogen > ALKALINITY_THRESHOLD )					// Define the condition where the power of Hydrogen is greater than 7.5.
             {
                 printf( "The solution is alkaline! " );					// Notify the user that the solution is alkaline.
             }
             
             else if ( powerOfHydrogen < ACIDITY_THRESHOLD )					// Define the condition where the power of Hydrogen is less than 6.5.
             {
                 printf( "The solution is acidic! " );						// Notify the user that the solution is acidic.
             }
             
             else										// Define the condition where the power of Hydrogen is between 6.5 and 7.5.
             {
                 printf( "The solution is neutral! " );						// Notify the user that the solution is neutral.
             }
             break;										// Terminate the execution of the loop.
         }
         count++;										// Increment the value of "count" by 1.
     }
     
     if ( count == MAX_COUNT)									// Define the condition where 'count' equals the permissible number of iterations.
     {   
         if( molarConcentration < 0 )								// Define the condition where the user inputs a negative molar concentration value.
         {	 
	     printf( "\nThe program has been terminated. " );                                	// Notify the user that the program has been terminated.
             return 0;										// Terminate the execution of the program.
         }
         
         else											// Define the condition where the user inputs a positive molar concentration value.
         {
	     powerOfHydrogen = -log10(molarConcentration);					// Compute the power of Hydrogen (pH) of the solution.

	     printf("\nThe power of Hydrogen (pH) value of the solution is %.4lf. ", powerOfHydrogen);	// Print the power of Hydrogen value upto four decimal places.

	     if (powerOfHydrogen > ALKALINITY_THRESHOLD)					// Define the condition where the power of Hydrogen is greater than 7.5.
	     {
		 printf("The solution is alkaline! ");						// Notify the user that the solution is alkaline.
	     }

	     else if (powerOfHydrogen < ACIDITY_THRESHOLD)					// Define the condition where the power of Hydrogen is less than 6.5.
	     {
		 printf("The solution is acidic! ");						// Notify the user that the solution is acidic.
	     }

	     else										// Define the condition where the power of Hydrogen is between 6.5 and 7.5.
	     {
		 printf("The solution is neutral! ");						// Notify the user that the solution is neutral.
	     }
         }
     }
     
     system( "PAUSE" );										// Suspend the execution of the program.
     return 0;											// Terminate the execution of the program.
}
