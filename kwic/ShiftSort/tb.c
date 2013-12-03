/*
==========================
Documentation Type: Test Implemention
Last Updated: Dec 2, 2013
Author: Justin Waterhouse
==========================
*/

#include <stdio.h>
#include "kwic.h"
#include "LineStorage.h"
#include "ShiftSort.h"

#include <stdio.h>
#include "Exceptions.h"














//LOCAL
#define MAXWORDS 6

int i,j;

static struct {
	int numWords;
	int shiftNum;
	char* wordList[MAXWORDS];
}

lineList[] = {
	{1,0,"A"},
	{1,0,"A"},
	{2,0,"A","B"},
	{2,0,"A","C"},
	{2,1,"B","A"},
	{2,1,"C","A"},
	{4,1,"C","Programming","Language","The"},
	{5,1,"Cat","in","the","Hat","The"},
	{5,4,"Hat","The","Cat","in","the"},
	{4,3,"Language","The","C","Programming"},
	{4,2,"Programming","Language","The","C"},
	{0} /* terminator */
};


int main()
{
	int cew_Test_Count=0;
          int cew_Error_Count=0;
          short exceptionThrown= 1;
          int EXnum__;

	
	SSInit();
	// CEW N CASES
	
         
         exceptionThrown= 1;
         cew_Test_Count=cew_Test_Count+1;
         TRY {
         	;
         exceptionThrown = 0;
         
            if ((SSShiftSort()) != (KWSUCCESS)) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 49);
               printf("Actual Value is %d\n", SSShiftSort());
               printf("Expected Value is %d\n", KWSUCCESS);
            } 
         }
         
         FINALLY {
            if (exceptionThrown == 1)
            {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 49);
               printf("Unexpected Exception Thrown\n");
    
            }
         }
         
         ETRY;

	
         
         exceptionThrown= 1;
         cew_Test_Count=cew_Test_Count+1;
         TRY {
         	;
         exceptionThrown = 0;
         
            if ((SSNumLines()) != (11)) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 50);
               printf("Actual Value is %d\n", SSNumLines());
               printf("Expected Value is %d\n", 11);
            } 
         }
         
         FINALLY {
            if (exceptionThrown == 1)
            {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 50);
               printf("Unexpected Exception Thrown\n");
    
            }
         }
         
         ETRY;


	for(i = 0; i < 11; i++)
	{
		
         
         exceptionThrown= 1;
         cew_Test_Count=cew_Test_Count+1;
         TRY {
         	;
         exceptionThrown = 0;
         
            if ((SSNumWords(i)) != (lineList[i].numWords)) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 54);
               printf("Actual Value is %d\n", SSNumWords(i));
               printf("Expected Value is %d\n", lineList[i].numWords);
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

		
         
         exceptionThrown= 1;
         cew_Test_Count=cew_Test_Count+1;
         TRY {
         	;
         exceptionThrown = 0;
         
            if ((SSGetShiftNum(i)) != (lineList[i].shiftNum)) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 55);
               printf("Actual Value is %d\n", SSGetShiftNum(i));
               printf("Expected Value is %d\n", lineList[i].shiftNum);
            } 
         }
         
         FINALLY {
            if (exceptionThrown == 1)
            {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 55);
               printf("Unexpected Exception Thrown\n");
    
            }
         }
         
         ETRY;

		
		for(j = 0; j < lineList[i].numWords; j++)
		{
			
         
         exceptionThrown= 1;
         cew_Test_Count=cew_Test_Count+1;
         TRY {
         	;
         exceptionThrown = 0;
         
            if ((strcmp(SSGetWord(i,j),lineList[i].wordList[j])) != (0)) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 59);
               printf("Actual Value is %d\n", strcmp(SSGetWord(i,j),lineList[i].wordList[j]));
               printf("Expected Value is %d\n", 0);
            } 
         }
         
         FINALLY {
            if (exceptionThrown == 1)
            {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 59);
               printf("Unexpected Exception Thrown\n");
    
            }
         }
         
         ETRY;

		}
	}
	
	
         
         exceptionThrown= 1;
         cew_Test_Count=cew_Test_Count+1;
         TRY {
         	SSReset();
         exceptionThrown = 0;
         
            if ((SSShiftSort()) != (KWSUCCESS)) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 63);
               printf("Actual Value is %d\n", SSShiftSort());
               printf("Expected Value is %d\n", KWSUCCESS);
            } 
         }
         
         FINALLY {
            if (exceptionThrown == 1)
            {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", 63);
               printf("Unexpected Exception Thrown\n");
    
            }
         }
         
         ETRY;


   //Test Print method
   SSPrintState();
   
   // CEW E CASES
   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetWord(-1000,0) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 69);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 69);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetWord(-1,0) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 70);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 70);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetWord(12,0) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 71);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 71);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;
   
   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetWord(1012,0) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 72);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 72);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSNumWords(-1000) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 74);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 74);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSNumWords(-1) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 75);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 75);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSNumWords(12) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 76);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 76);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSNumWords(1012) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 77);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 77);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetShiftNum(-1000) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 79);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 79);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetShiftNum(-1) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 80);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 80);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetShiftNum(12) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 81);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 81);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetShiftNum(1012) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 82);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 82);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetWord(0,-1000) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 84);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 84);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetWord(0,-1) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 85);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 85);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;

   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetWord(0, lineList[0].numWords+1) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 86);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 86);
               printf("Actual Value is %d\n", KWRANGEERROR);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;
   
   
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        SSGetWord(0,lineList[0].numWords+1000) ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 87);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != KWRANGEERROR) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", 87);
               printf("Actual Value is %d\n", KWRANGEERROR);
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
