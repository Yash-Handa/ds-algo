/*
? Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
? 1. The amount of petrol that every petrol pump has.
? 2. Distance from that petrol pump to the next petrol pump.
? Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
? Note : Assume for 1 litre petrol, the truck can go 1 unit of distance.
*/
#include <iostream>
#include <vector>

int tour(std::vector<int> &petrol, std::vector<int> &dist)
{
    int front = 0, back = 0, sz = petrol.size();
    bool possible = true;

    int i = 0, petrol_left = 0;
    while (back != front - 1 && possible)
    {
        // add point to queue
        back = (i + 1) % sz;

        petrol_left += petrol[i] - dist[i];
        // remove all points from the queue
        if (petrol_left < 0)
        {
            // we have already seen all the elements and still couldn't find a complete route
            if (front > back)
            {
                possible = false;
                break;
            }

            // remove all the elements form the queue
            while (back != front)
                front = (front + 1) % sz;

            petrol_left = 0;
        }

        i = (i + 1) % sz;
    }

    if (back == front - 1 && petrol_left + petrol[back] - dist[back] < 0)
        return -1;

    if (possible)
        return front;
    return -1;
}

int main()
{
    int p[] = {4, 6, 7, 4}, d[] = {6, 5, 3, 5};
    // int p[] = {4, 6, 7, 4}, d[] = {60, 5, 3, 5};
    // int p[] = {6, 3, 7}, d[] = {4, 6, 3};
    std::vector<int> petrol(p, p + sizeof(p) / sizeof(p[0])), dist(d, d + sizeof(d) / sizeof(d[0]));

    int start_index = tour(petrol, dist);
    if (start_index == -1)
        std::cout << "The journey is not possible.\n";
    else
        std::cout << "The journey can be competed if started from " << start_index << " indexed petrol pump\n";
    return 0;
}