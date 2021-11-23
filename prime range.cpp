int main()

{

    // get number of test cases

    int numTest;

    cin>>numTest;

    // loop until all the test cases are covered

    while(numTest!=0)

    {

        // initialize L and R

        unsigned long long  L,R;

        // get L and R input

        cin>>L;

        cin>>R;

        // store prime rangers count

        unsigned long long counts=0;

        // loop from L to R

        for(unsigned long long i=L;i<=R;i++)

        {

            // get the number

            unsigned long long num=i;

            // count array containing counts of 2,3,5,7 digits in the

            // number in that order

            int count[4]={0};

            // get all the digits of the number

            while(num!=0)

            {

                int digit=num%10;

                // match the digit with one of the prime digit

                // and increment the respective count

                switch(digit)

                {

                    case 2:

                        count[0]++;

                        break;

                    case 3:

                        count[1]++;

                        break;

                    case 5:

                        count[2]++;

                        break;

                    case 7:

                        count[3]++;

                        break;

                }

                num=num/10;

            }

            // to store is prime ranger condition is satifisfied

            bool isPrimeRanger=true;

            // loop the count array

            for(int j=0;j<3;j++)

            {

                // check consecutive elements

                // if prime ranger condition fails

                // update the prime ranger flag

                if(count[j]<count[j+1])

                    isPrimeRanger=false;

            }

            // check prime ranger flag

            // and update

            if(isPrimeRanger)

                counts++;

        }

        // print the prime ranger count in modulo 10^9+7;

        cout<<counts%1000000007<<endl;

        numTest--;

    }

}

// for input output
#include <iostream>
using namespace std;
// main function
int main()
{
    // get number of test cases
    int numTest;
    cin>>numTest;
    // loop until all the test cases are covered
    while(numTest!=0)
    {
        // initialize L and R 
        unsigned long long  L,R;
        // get L and R input
        cin>>L;
        cin>>R;
        // store prime rangers count
        unsigned long long counts=0;
        // loop from L to R
        for(unsigned long long i=L;i<=R;i++)
        {
            // get the number
            unsigned long long num=i;
            // count array containing counts of 2,3,5,7 digits in the 
            // number in that order
            int count[4]={0};
            // get all the digits of the number
            while(num!=0)
            {
                int digit=num%10;
                // match the digit with one of the prime digit
                // and increment the respective count
                switch(digit)
                {
                    case 2:
                        count[0]++;
                        break;
                    case 3:
                        count[1]++;
                        break;
                    case 5:
                        count[2]++;
                        break;
                    case 7:
                        count[3]++;
                        break;
                }
                num=num/10;
            }
            // to store is prime ranger condition is satifisfied
            bool isPrimeRanger=true;
            // loop the count array
            for(int j=0;j<3;j++)

{
                // check consecutive elements
                // if prime ranger condition fails 
                // update the prime ranger flag
                if(count[j]<count[j+1])
                    isPrimeRanger=false;
            }
            // check prime ranger flag
            // and update
            if(isPrimeRanger)
                counts++;
        }
        // print the prime ranger count in modulo 10^9+7;
        cout<<counts%1000000007<<endl;
        numTest--;}}
