#include<bits/stdc++.h>
class LFUCache
{
    int cap, minfreq;
    unordered_map<int, pair<int, int>> keyValFreq;
    unordered_map<int, list<int>> freqKey;
    unordered_map<int, list<int>::iterator> keyItr;
public:
    LFUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if(keyValFreq.find(key) == keyValFreq.end())
            return -1;
        int f = keyValFreq[key].second;
        freqKey[f].erase(keyItr[key]);
        f++;
        freqKey[f].emplace_front(key);
        keyItr[key] = freqKey[f].begin();
        keyValFreq[key].second = f;
        if(freqKey[minfreq].empty())
            minfreq = f;
        return keyValFreq[key].first;
    }

    void put(int key, int value)
    {
        if(cap <= 0)
            return;
        if(get(key) != -1)
        {
            keyValFreq[key].first = value;
            return;
        }
        if(keyValFreq.size() == cap)
        {
            int del = freqKey[minfreq].back();
            freqKey[minfreq].pop_back();
            keyValFreq.erase(del);
            keyItr.erase(del);
        }
        minfreq = 1;
        keyValFreq[key] = {value, minfreq};
        freqKey[minfreq].emplace_front(key);
        keyItr[key] = freqKey[minfreq].begin(); 
    }
};
