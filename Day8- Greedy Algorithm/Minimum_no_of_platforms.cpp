int calculateMinPatforms(int at[], int dt[], int n)
{
    /*int plat[2360] = {0};
    int minplat = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = at[i]; j <= dt[i]; j++)
        {
            plat[j]++;
            minplat = max(minplat, plat[j]);
        }
    }
    return minplat;*/
    
    sort(at, at+n);
    sort(dt, dt+n);
    int curplat = 0;
    int minplat = 0;
    int i = 0;
    int j = 0;
    while(i < n && j < n)
    {
        if(at[i] <= dt[j])
        {
            curplat++;
            i++;
        }
        else
        {
            curplat--;
            j++;
        }
        minplat = max(minplat, curplat);
    }
    return minplat;
    
}