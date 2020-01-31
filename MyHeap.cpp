#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

template <typename ValueType>
class MyHeap
{
    public:
        vector <ValueType> data;

        bool empty()
        {
            if(data.size() == 0)
                return true;
            return false;
        }

        void push(ValueType & v)
        {
            data.push_back(v);
            bool swapped = true;
            int cur = data.size()-1;
            int par = 0;
            while(swapped)
            {
                if(cur!=0)
                {
                    if(cur % 3 == 0)
                        par = cur/3 -1;
                    else
                        par = cur/3;
                    
                    if(data[par] < data[cur])
                    {
                        iter_swap(data.begin() + cur, data.begin()+par);
                        cur = par;
                    }
                    else
                    {
                        swapped = false;
                    }
                    
                }
                else
                    swapped = false;                
            }
        }

        void pop()
        {
            if(empty())
                return;
            ValueType result = data[0];
            iter_swap(data.begin(), data.end()-1);
            data.pop_back();
            bool swapped = true;
            int cur = 0;
            while(swapped)
            {
                if(3*cur+1 < data.size()-1)
                {
                    ValueType chil1 = data[3*cur+1];
                    if(3*cur+2<data.size()-1)
                    {
                        ValueType chil2 = data[3*cur+2];
                        if(3*cur+3<data.size()-1)
                        {
                            ValueType chil3 = data[3*cur+3];
                            ValueType max = chil1;
                            if(chil2>max)
                                max = chil2;
                            if(chil3>max)
                                max = chil3;

                            if(data[cur] < max)
                            {
                                if(max==chil1)
                                {
                                    iter_swap(data.begin() + cur, data.begin()+ 3*cur +1);
                                    cur = 3*cur + 1;
                                }
                                else if (max == chil2)
                                {
                                    iter_swap(data.begin() + cur, data.begin()+ 3*cur +2);
                                    cur = 3*cur + 2;
                                }
                                else
                                {
                                    iter_swap(data.begin() + cur, data.begin()+ 3*cur +3);
                                    cur = 3*cur + 3;
                                }
                            }
                            else
                            {
                                swapped = false;
                            }
                            
                        }
                        else
                        {
                            if(chil1>chil2)
                            {
                                if(data[cur] < chil1)
                                {
                                    iter_swap(data.begin() + cur, data.begin()+ 3*cur +1);
                                }
                            }
                            else
                            {
                                if(data[cur] < chil2)
                                {
                                    iter_swap(data.begin() + cur, data.begin()+ 3*cur +2);
                                }
                            }
                            swapped = false;
                        }
                        
                    }
                    else
                    {
                        if(data[cur] < chil1)
                            iter_swap(data.begin() + cur, data.begin()+ 3*cur +1);
                        swapped = false;
                    }
                }
                else
                    swapped = false;                
            }
        }
        void printHeap()
        {
            print_r(0, 0);
        }

        void print_r(int cur, int height)
        {
            for(int i=0; i < height; i++)
                cout<<"  ";
            cout<<data[cur]<<endl;
            if(3*cur+1 <=data.size()-1)
            {
                print_r(3*cur+1, height+1);

                if(3*cur+2 <= data.size()-1)
                {
                    print_r(3*cur+2, height+1);

                    if(3*cur+3<= data.size()-1)
                    {
                        print_r(3*cur+3, height+1);
                    }
                }
            }
        }
};

int main()
{
    MyHeap<int> h;
    int n = 14;
    srand(time(NULL));

    int v[n];
    for(int i = 0; i < n; ++i)
        v[i] = rand()%152;

    for(int i = 0; i < n; ++i)
        h.push(v[i]);

    h.printHeap();
    h.pop();
    cout << endl;
    h.printHeap();
}