#include <bits/stdc++.h>
using namespace std;

bool coprime(int a, int b)
{
    return (__gcd(a, b) == 1);
}

/* Checks if any possible triplet (a, b, c) satisfying the condition
   that (a, b) is coprime, (b, c) is coprime but (a, c) isnt */
void possibleTripletInRange(int L, int R)
{

    bool flag = false;
    int possibleA, possibleB, possibleC;

    // Generate and check for all possible triplets between L and R
    for (int a = L; a <= R; a++)
    {
        for (int b = a + 1; b <= R; b++)
        {
            for (int c = b + 1; c <= R; c++)
            {
                // if we find any such triplets set flag to true
                if (coprime(a, b) && coprime(b, c) && !coprime(a, c))
                {
                    flag = true;
                    possibleA = a;
                    possibleB = b;
                    possibleC = c;
                    break;
                }
            }
        }
    }

    // flag = True indicates that a pair existsbetween L and R
    if (flag == true)
        cout<<"("<<possibleA<<", "<<possibleB<<", "<<possibleC<<")"<<" is one such possible triplet between "<<L<<" and "<<R<<endl;
    else
        cout<<"No Such Triplet exists between "<<L<<" and "<<R<<endl;
}

int main()
{
    int L, R;

    cin>>L>>R;
    possibleTripletInRange(L, R);
}
