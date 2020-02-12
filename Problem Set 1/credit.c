#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int count = 0;
    long number = get_long("Number : ");
    int digit1 = 0;
    int digit2 = 0;
    int odd_sum = 0;
    int even_sum = 0;
    
    while (number != 0)
    {
        count++;
        digit2 = digit1;
        digit1 = number % 10;
        
        if (count % 2 == 1)
        {
            odd_sum += digit1; 
        }
        else
        {
            int multiple = digit1 * 2;
            even_sum += multiple / 10 + multiple % 10;
        }
        number /= 10;
    }
    
    int test_num = (odd_sum + even_sum) % 10;
    int initial_digit = digit1 * 10 + digit2;

    if (test_num == 0 &&(initial_digit == 34 || initial_digit == 37) && (count == 15))
    {
        printf("AMEX\n");
    }
    else if (test_num == 0 && initial_digit >= 51 && initial_digit <= 55 && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (test_num == 0 && digit1 == 4 && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }
            
}
