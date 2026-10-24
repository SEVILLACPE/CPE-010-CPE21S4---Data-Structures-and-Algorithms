#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

using namespace std;

const int maxSize = 100;

void selectionsort(int values[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int smallest = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (values[j] < values[smallest])
            {
                smallest = j;
            }
        }

        int temporary = values[i];
        values[i] = values[smallest];
        values[smallest] = temporary;
    }
}

string candinates[6] = {
    "",
    "Bo Dalton Capistrano",
    "Cornelius Raymon Agustín",
    "Deja Jayla Bañaga",
    "Lalla Brielle Yabut",
    "Franklin Relano Castro"};

int main()
{
    int votes[maxSize];
    int voteCount[6] = {0};

    srand(time(0));
    cout << " VOTES (Unsorted)\n";
    for (int i = 0; i < maxSize; i++)
    {
        votes[i] = rand() % 5 + 1;
        cout << votes[i] << " ";
    }
    cout << "\n\n";

    selectionsort(votes, maxSize);
    cout << " VOTES (Sorted)\n";
    for (int i = 0; i < maxSize; i++)
    {
        cout << votes[i] << " ";
    }
    cout << "\n\n";

    for (int i = 0; i < maxSize; i++)
    {
        voteCount[votes[i]]++;
    }

//votes count 
    cout << " VOTES COUNT\n";
    int highestVoteCount = 0;
    int winnerIndex = 0;

    for (int i = 1; i <= 5; i++) {
        cout << "Candidate " << i << ": " << candinates[i] << endl;
        cout << "   Votes: " << voteCount[i] << " / " << maxSize << endl;
        
        if (voteCount[i] > highestVoteCount) {
            highestVoteCount = voteCount[i];
            winnerIndex = i;
        }
        cout    << endl;
    }

    cout << "Winner: " << candinates[winnerIndex] << endl;
    cout << "Total Votes: " << highestVoteCount << endl;

    return 0;

}