#include <stdio.h>
#include "Exceptions.h"


changecom(`#')

define(cew_Variables,
         `int cew_Test_Count=0;
          int cew_Error_Count=0;
          short exceptionThrown= 1;
          int EXnum__;'
)

define(cew_Summary,
         `printf("\n**********Summary**********\n");
          printf("Total number of test cases = %d\n", cew_Test_Count);
          printf("Total number of test cases in error = %d\n", cew_Error_Count);'
)


define(cew_Ncase,`
         
         exceptionThrown= 1;
         cew_Test_Count=cew_Test_Count+1;
         TRY {
         	$2;
         exceptionThrown = 0;
         
            if (($3) $5 ($4)) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", $1);
               printf("Actual Value is %d\n", $3);
               printf("Expected Value is %d\n", $4);
            } 
         }
         
         FINALLY {
            if (exceptionThrown == 1)
            {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ncase) in script at line number %d\n", $1);
               printf("Unexpected Exception Thrown\n");
    
            }
         }
         
         ETRY;
')

define(cew_Ecase, `
      cew_Test_Count=cew_Test_Count+1;      
      TRY {
        $2 ;
        printf("\nTest Case ERROR (Ecase) in script at line number %d\n", $1);
        printf("Exception not thrown\n");
        cew_Error_Count=cew_Error_Count+1;
      }
      
      CATCH {
            if (EXnum__ != $3) {
               cew_Error_Count=cew_Error_Count+1;
               printf("\nTest Case ERROR (Ecase) in script at line number %d\n", $1);
               printf("Actual Value is %d\n", $3);
               printf("Expected Value is %d\n", EXnum__);
            }
     }

      
     FINALLY {
     }

     ETRY;
')
