#include <stdio.h>
void readInput(int *n, int *t, int *c, int crime_levels[]) 
{
    printf("Enter the number of prisoners, severity threshold, and group size: ");
    scanf("%d %d %d", n, t, c);
    
    printf("Enter the crime severity levels for each prisoner: ");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &crime_levels[i]);
    }
}
int countValidGroups(int n, int t, int c, int crime_levels[]) {
	
    int valid_segments = 0;
    int window_start = 0;
    
    for (int window_end = 0; window_end < n; window_end++) 
	{
        if (crime_levels[window_end] > t) 
		{
            window_start = window_end + 1;
        }
        
        if (window_end - window_start + 1 == c) 
		{
            valid_segments++;
            window_start++;
        }
    }
    
    return valid_segments;
}

int main() 
{
    int n, t, c;
    int crime_levels[100]; 
    
    readInput(&n, &t, &c, crime_levels);
    
    int result = countValidGroups(n, t, c, crime_levels);
    
    printf("Number of valid groups that can be transferred: %d\n", result);
    
    return 0;
}
