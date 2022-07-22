string writeAsYouSpeak(int n) 
{
	string ans = "1";
    for(int i = 1; i < n; i++)
    {
        string temp = "";
        int count = 1;
        for(int j = 0; j < ans.size()-1; j++)
        {
            if(ans[j] == ans[j+1])
                count++;
            else
            {
                temp += (to_string(count) + ans[j]);
                count = 1;
            }
        }
        temp += to_string(count) + ans[ans.length()-1];
        ans = temp;
    }
    return ans;
    
}