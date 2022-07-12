class Queue {
public:
    vector<int> v;
    int f;
    int rear;
    Queue() 
    {
        f = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() 
    {
        if(v.size() == 0)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        v.push_back(data);
        rear = v.size()-1;
    }

    int dequeue()
    {
        if(v.size() == 0)
            return -1;
        int x = v[f];
        v.erase(v.begin() + 0);
        return x;
        
    }

    int front() 
    {
        if(v.size() == 0)
            return -1;
        else
            return v[f];
    }
};