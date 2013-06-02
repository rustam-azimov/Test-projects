#include "play.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void startTheGame()
{
    cout << "__GAME IS STARTING!__" << endl << endl;
    cout << "__The First Tour__" << endl;
    cout << "__Guess number of 4 digits ranging from 1 to 6__" << endl
         << "__It is recommended to write it down on paper__" << endl;
    int computerResult = 0;
    int userResult = 0;
    computerResult = startFirstTour();
    cout <<"__Computer's result is : " << computerResult
           << "__" << endl << endl;

    cout << "__The Second Tour__" << endl;
    cout << "__Now you guess!__" << endl;
    userResult = startSecondTour();
    cout <<"__Yours result is : " << userResult
           << "__" << endl << endl;
    if (computerResult < userResult)
    {
        cout << "Computer WIN!" << endl;
    }
    else
        if (computerResult > userResult)
        {
            cout << "You WIN!" << endl;
        }
        else
        {
            cout << "Draw." << endl;
        }
}

int startFirstTour()
{
        Node* head = new Node;
        head->next = NULL;
        for (int i = 0; i < 4; i++)
        {
            head->array[i] = 0;
        }
        createStartNode(head);
        int currentExactMatch = 0;
        int currentMatchByValue = 0;
        int NumberOfMyTry = 0;
        Node *currentProbe = getFirstTry(head);
        while (currentExactMatch < 4)
        {
            if (NumberOfMyTry > 0)
                currentProbe = head->next;
            NumberOfMyTry++;
            print_node(currentProbe, NumberOfMyTry);
            cout << "Number of exact hits: ";
            cin >> currentExactMatch;
            cout << "Number of matches by value: ";
            cin >> currentMatchByValue;
            cout << endl;
            removeInvalidValues(head, currentProbe,
                                currentExactMatch, currentMatchByValue);
        }
        cout << "Answer is : " << head->next->array[0]
                << head->next->array[1]
                   << head->next->array[2]
                      << head->next->array[3] << endl;
        return NumberOfMyTry;
}

int startSecondTour()
{
    int numberOfUserTry = 0;

    Node *secret = new Node;
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        secret->array[i] = (rand() % 6) + 1;
    }
    Node *userProbeNode = new Node;
    for (int i = 0; i < 4; i++)
    {
        userProbeNode->array[i] = 0;
    }
    int userProbe = 0;
    int userExactMatches = 0;
    int userMatchByValue = 0;
    bool isGuess = false; // угадано ли?
    while (!isGuess)
    {
        numberOfUserTry++;
        cout << "Your Probe" << numberOfUserTry << " : ";
        cin >> userProbe;
        userProbeNode->array[0] = userProbe / 1000;
        userProbeNode->array[1] = (userProbe / 100 ) % 10;
        userProbeNode->array[2] = (userProbe / 10 ) % 10;
        userProbeNode->array[3] = userProbe % 10;
        userExactMatches = getNumbOfExactMatches(userProbeNode, secret);
        userMatchByValue = getNumbOfMatchByValue(userProbeNode, secret);
        if (userExactMatches < 4)
        {
            cout << "Number of exact hits: " << userExactMatches << endl
                 << "Number of matches by value: " << userMatchByValue
                    << endl;
        }
        else
        {
            isGuess = true;
        }
    }
    cout << " You guessed it! Answer is : " << userProbe << endl;
    delete userProbeNode;
    delete secret;
    return numberOfUserTry;
}

Node *getFirstTry(Node *head)
{
    Node *temp = head->next;
    int digit12 = (rand() % 6) + 1;
    int digit3 = ((digit12 + 1) % 6) + 1;
    int digit4 = ((digit12 - 3) % 6) + 1;
    while (temp)
    {
        if (temp->array[0] == temp->array[1] && temp->array[1] == digit12
                && temp->array[2] == digit3 && temp->array[3] == digit4)
        {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

void removeInvalidValues(Node *head, Node *myProbe, int numberOfExactMatches,
                         int numberOfMatchByValue)
{
    Node* temp = head->next;
    Node* probe = new Node;
    for (int i = 0; i < 4; i++)
    {
        probe->array[i] = myProbe->array[i];
    }
    int digit1 = 0;
    int digit2 = 0;
    int digit3 = 0;
    int digit4 = 0;
    while (temp)
    {
        if (numberOfExactMatches != getNumbOfExactMatches(probe, temp)
                || numberOfMatchByValue != getNumbOfMatchByValue(myProbe, temp))
        {
            digit1 = temp->array[0];
            digit2 = temp->array[1];
            digit3 = temp->array[2];
            digit4 = temp->array[3];
            temp = temp->next;
            removeValue(head, digit1, digit2, digit3, digit4);
        }
        else
        {
            temp = temp->next;
        }
    }
    delete probe;
}

int getNumbOfExactMatches(Node *myProbe, Node *test)
{
    int result = 0;
    for (int i = 0; i < 4; i++)
    {
        if (myProbe->array[i] == test->array[i])
        {
            result++;
        }
    }
    return result;
}

int getNumbOfMatchByValue(Node *myProbe, Node *test)
{
    int result = 0;
    int probeArray[4];
    for (int i = 0; i < 4; i++)
        probeArray[i] = myProbe->array[i];
    int testArray[4];
    for (int i = 0; i < 4; i++)
        testArray[i] = test->array[i];
    for (int i = 0; i < 4; i++)
    {
        if (probeArray[i] == testArray[i])
        {
            probeArray[i] = -1;
            testArray[i] = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (testArray[i] == probeArray[j])
            {
                result++;
                testArray[i] = 0;
                probeArray[j] = -1;
            }
        }
    }
    return result;
}
