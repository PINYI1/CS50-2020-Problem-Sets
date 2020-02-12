#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int count = 0;
    long number = get_long("Number : ");
    long num = number;
    int odd_digit = 0;
    int odd_sum = 0;
    int even_digit = 0;
    int even_sum = 0;
    int initial_digit;
    while (num != 0)
    {
        /* Increment digit count */
        count++;

        /* Remove last digit of 'num' */
        num /= 10;
    }
    if (count < 13)
    {
        printf("INVALID\n");
    }
    else
    {
        for (int i = 1; i <= count; i++)
        {
            if (i % 2 == 1)
            {
                odd_digit = number % 10;
                odd_sum += odd_digit; 
                number /= 10;
            }
            else
            {
                even_digit = (number % 10) * 2;
                if (even_digit > 9)
                {
                    int loop_digit = even_digit;
                    int sub_digit = 0;
                    while (loop_digit)
                    {
                        sub_digit += loop_digit % 10;
                        loop_digit /= 10;
                    }
                    even_sum += sub_digit; 
                    number /= 10;
                }
                else
                {
                    even_sum += even_digit; 
                    number /= 10;
                } 
            }
        }
        int test_num = (odd_sum + even_sum) % 10;
        if (test_num == 0)
        {
            if (count % 2 == 0)
            {
                initial_digit = even_digit / 2 * 10 + odd_digit;
                if (initial_digit == 34 || initial_digit == 37)
                {
                    printf("AMEX\n");
                }
                else if (initial_digit == 51 || initial_digit == 52 || initial_digit == 53 || initial_digit == 54 || initial_digit == 55)
                {
                    printf("MASTERCARD\n");
                }
                else if (even_digit == 8)
                {
                    printf("VISA\n");
                }
                else 
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                initial_digit = odd_digit * 10 + even_digit / 2;
                if (initial_digit == 34 || initial_digit == 37)
                {
                    printf("AMEX\n");
                }
                else if (initial_digit == 52 || initial_digit == 53 || initial_digit == 54 || initial_digit == 55)
                {
                    printf("MASTERCARD\n");
                }
                else if (odd_digit == 4)
                {
                    printf("VISA\n");
                }
                else 
                {
                    printf("INVALID\n");
                }
            }
        }
        else 
        {
            printf("INVALID\n");
        }
    }
}
