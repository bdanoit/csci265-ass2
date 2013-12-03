/*
==========================
Documentation Type: Test Implemention
Last Updated: Dec 2, 2013
Author: Justin Waterhouse
==========================
*/


#include "kwic.h"
#include "WordTable.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>
#include "Exceptions.h"













// LOCAL VARIABLES
char* inWordList[] = {
	"a", "an", "and", "and/or", 
	"as", "at", "for", "from", "in",
	"of", "on", "or", "the", "to", "with",

	/* upper case variations: */
	"And", "aNd", "anD",
	/*trailing crap*/

	0 /* terminator */
};

char* notInWordList[] = {
	/* words containing words in inWordList */
	"thereupon", "into", "stool",

	/* special strings */
        "", " ", ",",

	0 /* terminator */
};



int main()
{
 int cew_Test_Count=0;
          int cew_Error_Count=0;
          short exceptionThrown= 1;
          int EXnum__;

   int i;
   
   // Only used during testing
   WTPrintState();
   
	WTInit("testNoiseWords");
	
	// CEW N CASES
	for (i = 0; inWordList[i]; i++) {
	   // Check if words are in list
	   
         
         exceptionThrown= 1;
         cew_Test_Count=cew_Test_Count+1;
         TRY {
         	;
         exceptionThrown = 0;
         
            if ((WTIsMember(inWordList[i])) != (1)) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 54);
               printf("Actual Value is %d\n", WTIsMember(inWordList[i]));
               printf("Expected Value is %d\n", 1);
            } 
         }
         
         FINALLY {
            if (exceptionThrown == 1)
            {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 54);
               printf("Unexpected Exception Thrown\n");
    
            }
         }
         
         ETRY;

   }
   
   for (i = 0; notInWordList[i]; i++ )
   {
      // Look for words not in the list
	   
         
         exceptionThrown= 1;
         cew_Test_Count=cew_Test_Count+1;
         TRY {
         	;
         exceptionThrown = 0;
         
            if ((WTIsMember(notInWordList[i])) != (0)) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 60);
               printf("Actual Value is %d\n", WTIsMember(notInWordList[i]));
               printf("Expected Value is %d\n", 0);
            } 
         }
         
         FINALLY {
            if (exceptionThrown == 1)
            {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 60);
               printf("Unexpected Exception Thrown\n");
    
            }
         }
         
         ETRY;

   }


   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        WTInit("NotAFile") ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 64);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWFILEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 64);
               printf("Actual Value is %d\n", KWFILEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;


   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        WTInit("NotAFile") ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 66);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWFILEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 66);
               printf("Actual Value is %d\n", KWFILEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;


   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        WTInit("NotAFile") ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 68);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWFILEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 68);
               printf("Actual Value is %d\n", KWFILEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;
   

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        WTInit("NotAFile") ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 70);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWFILEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 70);
               printf("Actual Value is %d\n", KWFILEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;



	printf("\n**********Summary**********\n");
          printf("Total number of test cases = %d\n", cew_Test_Count);
          printf("Total number of test cases in error = %d\n", cew_Error_Count);

	return 0;
}
