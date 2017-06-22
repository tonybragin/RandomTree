#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int grc(int max)
{
    return (int)rand() % max;
}

int g_added(int a[], int n)
{
    return a[grc(n)];
}

int g_noadded(int a[], int max)
{
    for (int i = 0; i < max; i++) {
        int r = grc(max);
        if (a[r] == 0) return r;
    }
    
    return 0;
}

int main()
{
    FILE *file;
    int k = 1, max = 10, count = max - 1;
    int tops[max][max], tops_added[max], tops_noadded[max];
    srand(time(NULL));
    
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            tops[i][j] = 0;
        }
        tops_noadded[i] = 0;
    }

    tops_added[0] = 0;
    tops_noadded[0] = 1;
    for (int i = 0; i < count; i++) {
        int r = g_added(tops_added, k);
        int a = g_noadded(tops_noadded, max);
        if (a == 0) {
            printf("\nError\n");
            //return 0;
        }
        tops[r][a] = 1;
        tops[a][r] = 1;
        tops_added[k] = a;
        tops_noadded[a] = 1;
        k++;
    }
    
    
    file = fopen("data", "w");

    fprintf(file, "   ");
    for (int i = 0; i < max; i++) fprintf(file, "%d ", i);
    fprintf(file, "\n\n");
    
    for (int i = 0; i < max; i++) {
        fprintf(file, "%d  ", i);
        for (int j = 0; j < max; j++) {
            fprintf(file, "%d ", tops[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
    return 0;
}
