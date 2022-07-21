string reverseString(string str)
{
    string result = "";
    for(int i = str.size()-1; i >= 0; i--)
    {
        if(str[i] == ' ')
            continue;
        int j = i;
        while(j >= 0 && str[j] != ' ')
            j--;
        result += str.substr(j+1, i-j);
        result += ' ';
        i = j;
    }
    return result;
}