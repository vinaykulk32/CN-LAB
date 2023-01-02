#include <stdio.h>
#include <stdlib.h>
int transmit(int);
void main()
{
    int bucketSize, ch, incomingData, content = 0, i = 0;
    printf("Enter the bucket size:\t");
    scanf("%d", &bucketSize);
    while (i < 10)
    {
        printf("1-->Enter the incoming data packet size:\n2-->Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the packet size\n");
            scanf("%d", &incomingData);
            if ((content + incomingData) < bucketSize)
            {
                content += incomingData;
                content = transmit(content);
            }
            else
            {
                printf("BucketSize exceeded can not take this data input\n");
                content = transmit(content);
            }
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("Invalid Input");
            break;
        }
        i += 1;
    }
}

int transmit(int content)
{
    if (content == 0)
    {
        printf("The Bucket has nothing to transmit\n");
    }
    else if (content <= 3)
    {
        printf("Data Transmitted:\t%d \nData remaining in the bucket:\t0\n", content);
        content = 0;
    }
    else
    {
        content -= 3;
        printf("Data Transmitted:\t3 \nData remaining in the bucket:\t%d\n", content);
    }
    return content;
}