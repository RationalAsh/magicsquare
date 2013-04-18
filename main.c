/*
_________________________________________________________________________________________________________________
|    This is a program that makes magic squares that contain an odd number of rows or columns. It follows        |
|    a special algorithm to generate the magic square. I will explain the algorithm here using a 3x3 square      |
|    as an example.                                                                                              |
|                                                                                                                |
|    1. First draw a 3x3 grid on a piece of paper.                                                               |
|                                                                                                                |
|    2. Go to the right edge column and find the cell that is in the middle of the column. In the case of        |
|       the 3x3 grid the position of this cell is Row 2, Column 3. For a 5x5 it would be Row 3, column 5.        |
|                                                                                                                |
|    3. Write down 1 on that square.                                                                             |
|                                                                                                                |
|    4. To find the cell in which 2 must be filled, increase the index of the row and the column by 1. If the    |
|       row or column index exceeds the maximum round back to the first index. For example in the 3x3 grid, if   |
|       you're at position 2,3 the next position is 3,4. Since 4 exceeds the maximum value of the index, 4       |
|       becomes 3 so next position after 2,3 is 3,1.                                                             |
|                                                                                                                |
|    5. If the next cell you need to fill already contains a number, stay on the same row but move one column    |
|       to the right to get to the next cell. For example, in the case of the 3x3 grid, after filling position   |
|       1,2 with the number three, the next position is 2,3 which already contains the number 1. So following    |
|       the rule above, the next position to fill is 1,1.                                                        |
|                                                                                                                |
|    6. If you reach the bottom right corner of the grid (position 3,3 for the 3x3 grid), the next position is   |
|       1,1. But this is already filled. So the next position would be shited to the left.So after 3,3 comes 3,2.|
|-----------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,rows,**magic,i,j,r_index=0,c_index=0;
    printf("This program generates an NxN magic square. N has to be an odd number and cannot be less than 3.");
    start:
    printf("\n\nEnter the value of N: ");
    scanf("%d",&N);

    if(((N%2)==0)||N<3)
    {
        printf("\n\nYou entered an invalid value of N. Try again!");
        goto start;
    }

    rows=N;

    r_index=((N+1)/2)-1;
    c_index=N-1;

    magic=malloc(rows*sizeof(int*));
    for(i=0;i<rows;i++) magic[i]=malloc(rows*sizeof(int));

    for(i=0;i<rows;i++){ for(j=0;j<rows;j++) magic[i][j]=0;}
    i=1;
    while(i<=N*N)
    {
        magic[r_index][c_index]=i;
        r_index++; c_index++; i++;

        if((r_index>N-1)&&(c_index>N-1))
        {
            r_index--; c_index--; c_index--;
        }
        if(r_index>N-1) r_index=0;
        if(c_index>N-1) c_index=0;
        if((magic[r_index][c_index]) != 0)
        {
            r_index--; c_index--; c_index--;
        }

    }

    printf("\n\nThe magic square is: \n\n");

    for(i=0;i<rows;i++)
    {
        for(j=0;j<rows;j++) printf("%7d",magic[i][j]);
        printf("\n\n");
    }

    printf("\n\nALL ROWS AND COLUMNS IN THE MAGIC SQUARE ADD UP TO %d.\n\n\n\n", (rows*magic[((rows+1)/2)-1][((rows+1)/2)-1]));
    return 0;
}
