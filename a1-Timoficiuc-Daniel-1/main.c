// problem 11 Timoficiuc Daniel A1
#include <stdio.h>

int check_if_prime(int x)
{
    int i;
    if(x < 2)
        return 0;
    if(x == 2)
        return 1;
    if(x%2==0)
        return 0;
    for(i=3;i<=x/2;i++)
        if(x%i == 0)
            return 0;
    return 1;

}

int check_if_pairs(int n)
{
    if(check_if_prime(n)==1)
    {
        n =  n - 2;
        if(check_if_prime(n)==1)
        {
            return 1;
        }
    }
    return 0;

}

void menu()
{
    printf("Choose an option: \n");
    printf("1.Read numbers until the character -1 is read\n.");
    printf("2.Determine the first n pairs of twin numbers, where n is a given natural and non-null number."
           " Two prime numbers p and q are called twin if q - p = 2. \n");
    printf("3.Given a vector of numbers, find the longest decreasing contiguous subsequence.\n");
    printf("4.Read a sequence of natural numbers (sequence ended by 0) and determine the number of 0 digits\n"
           "of the product of the read numbers.\n");
    printf("5.Exit\n");
}

int read_option()
{
    int x;
    printf(" Which option? =\n");
    scanf("%d",&x);
    return x;
}

void read_array(int array[100])
{
    int pozitie = 0;
    int aux = 0;
    while (aux != -1)
    {
        {
            scanf("%d", &aux);
            array[pozitie++] = aux;
        }
    }
}

int optiune_1(int n)
{
    int v[1001] = {0};
    int i=3;
    int pozitie=0;
    while(n!=0)
    {
        if (check_if_pairs(i) == 1)
        {
            v[pozitie++] = i - 2;
            v[pozitie++] = i;
            n--;
        }
        i++;
    }

    for (i = 0; v[i] != 0; i = i + 2)
        printf("pair is %d and %d \n", v[i], v[i + 1]);
    return 0;
}

void print_longest_sequence(int array[100])
{
    int poz_max = 0;
    int lungime_max = 0;
    int pozitie = 0;
    int lungime = 0;
    int ok=0;
    int i;
    for(i=1;array[i]!= -1;i++)
    {
        if (array[i - 1] >= array[i] && ok == 1)
            lungime++;
        else if (array[i - 1] >= array[i] && ok == 0) {
            lungime = 1;
            pozitie = i - 1;
            ok = 1;
        } else if (array[i - 1] < array[i]) {
            if (lungime_max < lungime) {
                poz_max = pozitie;
                lungime_max = lungime;
            }
            ok = 0;
        }
    }
    for(i=poz_max;lungime_max+1!=0;i++,lungime_max--)
        printf("%d ",array[i]);

}
int determine_number_of_zero_digits(int length, int array[100])
{
    int product = 1;
    int i;
    int number_of_zero = 0;
    for(i=0;i<length;i++)
        product = array[i]* product;
    while(product!=0)
    {
        if(product % 10 == 0)
            number_of_zero++;
        product = product/10;
    }
    return number_of_zero;
}

int option_4()
{
    int aux;
    int length = 0;
    int array[100];
    int product;
    scanf("%d",&aux);
    array[0]= aux;
    while(aux !=0 )
    {
        scanf("%d",&aux);
        array[++length] = aux;
    }
    return determine_number_of_zero_digits(length,array);
}

int main()
{
    int x;
    int ok = 1;
    int if_read = 0;
    int array[100];
    menu();
    while(ok == 1)
    {
        x=read_option();

        if (x == 1)
        {
            printf("Input numbers for array, input '-1' to stop\n");
            read_array(array);
            if_read = 1;
        }
        else
            if (x == 2)
            {
                int n;
                printf("How many pairs?\n");
                scanf("%d", &n);

                if(n>500)
                {
                    printf("Too many pairs to generate.\n");
                    goto end;
                }

                optiune_1(n);
            }
            else
                if (x == 3 && if_read == 1)
                {
                    print_longest_sequence(array);
                }
                else
                    if(x == 3 && if_read == 0)
                    {
                        printf("No array of numbers read.\n");
                    }
                    else
                        if (x == 4)
                        {
                            printf("%d\n",option_4());
                        }
                        else
                            if(x == 5)
                            {
                                ok = 0;
                            }

        end: ;
    }
    return 0;
}