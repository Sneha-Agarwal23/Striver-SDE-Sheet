vector<int> maxMinWindow(vector<int> a, int n)
{
    vector<int> result(n);
    for(int i = 0; i < n; i++)
    {
        result[i] = INT_MIN;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int x = INT_MAX;
            for(int k = i; k <= j; k++)
            {
                x = min(x, a[k]);
            }
            int y = j - i;
            result[y] = max(result[y], x);
        }
    }
    return result;
    
}