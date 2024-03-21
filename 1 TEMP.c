#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    float temperature;
} DayTemperature;

float calculateAverage(DayTemperature arr[], int n)
{
    float sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i].temperature;
    }
    return sum / n;
}

void sortArray(DayTemperature arr[], int n)
{
    int i, j;
    DayTemperature temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i].temperature < arr[j].temperature)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int user_input = 0;
    DayTemperature tem[7];

    while (1)
    {
        printf("Weekly Weather Analyzer\nLets see what the weather looks like this week!\nTo input the daily temperature during the week, write 1 \nTo view an organized temperature list, highest to lowest, write 2 \nTo see the weekly temperature average, write 3 \nTo exit program, write 4\n");

        scanf("%d", &user_input);

        if (user_input == 1)
        {
            for (int i = 0; i < 7; i++)
            {
                printf("Day %d: ", i + 1);
                scanf("%f", &tem[i].temperature);
                tem[i].day = i + 1;
            }
        }
        else if (user_input == 2)
        {
            sortArray(tem, 7);

            printf(" \n Sorted temperatures from highest to lowest:\n ");
            for (int i = 0; i < 7; i++)
            {
                printf("Day %d: Temperature %.2f\n", tem[i].day, tem[i].temperature);
            }
        }
        else if (user_input == 4)
        {
            printf(" \n Thank you, very much for using this program!\n ");

            exit(0);
        }
        else if (user_input == 3)
        {
            float average = calculateAverage(tem, 7);
            printf(" \n The weekly temperature average is %.2f\n ", average);
        }
        else
        {
            printf(" \n Invalid input. Please retry and enter 1, 2, or 3.\n ");
            scanf("%d", &user_input);
        }
    }

    return 0;
}
