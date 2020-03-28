#include<stdio.h>
#include<stdlib.h>



/*constants*/

#define GRID_CONSTANT  2

int
main ()
{

  long i = 0;
  long steps = 0;
  long test_case_num = 0;
  long num_test_cases = 0;
  long grid_size = 0;

  /*input from user/tester */
  scanf ("%ld", &num_test_cases);

  for (test_case_num = 0; test_case_num < num_test_cases; test_case_num++)
    {
      /*grid size input */
      scanf ("%ld", &grid_size);
      
	  /*total steps to be taken including south and east*/
	  steps = ((GRID_CONSTANT * grid_size) - GRID_CONSTANT);
	  
	  /*C string*/
      char *lyndia_path = (char *) malloc ((steps + 1));
      char *my_path = (char *) malloc ((steps + 1));
	  
	  
      /*lyndia's path */
      scanf ("%s", lyndia_path);
	  
      /*calculate my own path */
      for (i = 0; i < steps; i++)
      {
	     lyndia_path[i] == 'E' ? (my_path[i] = 'S') : (my_path[i] =
							    'E');
	  }
     
      my_path[steps] = '\0';
      lyndia_path[steps] = '\0';
      
      printf ("Case #%ld: %s\n", (test_case_num + 1), my_path);
      /*never leave any memory behind when managing yourself */
      free (lyndia_path);
      lyndia_path = NULL;

      free (my_path);
      my_path = NULL;
      
      grid_size = 0;
      steps = 0;
      
    }
  return 0;
}


