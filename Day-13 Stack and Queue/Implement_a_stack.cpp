// Stack class.
class Stack {
    int arr[1000];
    int topp;
    int size;
    
public:
    
    Stack(int capacity)
    {
        size = capacity;
        topp = -1;
    }

    void push(int num) 
    {
        if(topp >= size)
            return;
        arr[++topp] = num;
    }

    int pop() 
    {
        if(topp != -1)
            return arr[topp--];
        return -1;
    }
    
    int top()
    {
        if(topp != -1 && topp < size)
            return arr[topp];
        return -1;
    }
    
    int isEmpty() 
    {
        if(topp == -1)
            return 1;
        return 0;
        
    }
    
    int isFull()
    {
        if(topp >= size)
            return 1;
        return 0;
        
    }
    
};