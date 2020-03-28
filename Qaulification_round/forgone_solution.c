#include<stdio.h>
#include<math.h>

/*constants*/
#define DIGIT_TO_REMOVE 4
#define MOD_BASE        10

/*function used to count the number of digits*/
int count_digits(int n);
/*function that will make disappear for. your keyboard needs reaparing soon .  don't expect us to do for othr keys*/
void disappear_four(int n , int num_digits, int * part_1, int * part_2);
int main()
{
    int num_digits = 0;
    int num_tests =  0;
    int num =0;
    int part1, part2 = 0;
    int loop = 0;
    scanf("%d", &num_tests);
    for(loop = 1; loop <=num_tests; loop++)
    {        
        scanf("%d", &num);       
        num_digits = count_digits(num);
        disappear_four(num, num_digits, &part1 , &part2);
        printf("Case #%d: %d  %d\n",(loop), part1, part2);
		
		/*intialize the values again*/
        num =0;
        part1, part2 =0;
    }   
    return 0;
}

void disappear_four(int n , int num_digits, int *part1, int *part2)
{
    int loop = 0;
    
    int * num_arr = malloc(sizeof(int)*(num_digits));
    *(part1) = 0;
    *(part2) = 0;
	
    while(loop < num_digits)
    {
        num_arr[loop] = n%MOD_BASE;       
        n = n/MOD_BASE;        
        if(DIGIT_TO_REMOVE == num_arr[loop] )
        {
            int temp = (num_arr[loop]*((pow(MOD_BASE, loop))))/2;
            *part1 += temp;
            *part2 += temp;
        }
        else
        {
            *part2 += num_arr[loop] *((pow(MOD_BASE, loop)));
        }
        
        loop++;
    }
}
int count_digits(int n)
{
    int num_digits = 0;
    while(n != 0)
    {
        n = n/10;
        num_digits++;
        if(MOD_BASE == n)
        {
            num_digits+=2;
            break;
        }
        
    }
    return num_digits;
    
    
    
}