// C++ program to illustrate Banker's Algorithm
#include<iostream>
using namespace std;

// Number of processes
int P=3;

// Number of resources
int R=3;

// Function to find the need of each process
void calculateNeed(int need[100][100], int maxm[100][100],int allot[100][100])
{
	// Calculating Need of each P
	for (int i = 0 ; i < P ; i++)
		for (int j = 0 ; j < R ; j++)

			// Need of instance = maxm instance -
			//				 allocated instance
			need[i][j] = maxm[i][j] - allot[i][j];
}

// Function to find the system is in safe state or not
bool isSafe(int processes[], int avail[], int maxm[][100],
			int allot[][100])
{
	int need[100][100];

	// Function to calculate need matrix
	calculateNeed(need, maxm, allot);

	// Mark all processes as infinish
	bool finish[P] = {0};

	// To store safe sequence
	int safeSeq[P];

	// Make a copy of available resources
	int work[R];
	for (int i = 0; i < R ; i++)
		work[i] = avail[i];

	// While all processes are not finished
	// or system is not in safe state.
	int count = 0;
	while (count < P)
	{
		// Find a process which is not finish and
		// whose needs can be satisfied with current
		// work[] resources.
		bool found = false;
		for (int p = 0; p < P; p++)
		{
			// First check if a process is finished,
			// if no, go for next condition
			if (finish[p] == 0)
			{
				// Check if for all resources of
				// current P need is less
				// than work
				int j;
				for (j = 0; j < R; j++)
					if (need[p][j] > work[j])
						break;

				// If all needs of p were satisfied.
				if (j == R)
				{
					// Add the allocated resources of
					// current P to the available/work
					// resources i.e.free the resources
					for (int k = 0 ; k < R ; k++)
						work[k] += allot[p][k];

					// Add this process to safe sequence.
					safeSeq[count++] = p;

					// Mark this p as finished
					finish[p] = 1;

					found = true;
				}
			}
		}

		// If we could not find a next process in safe
		// sequence.
		if (found == false)
		{
			cout << "System is not in safe state";
			return false;
		}
	}

	// If system is in safe state then
	// safe sequence will be as below
	cout << "System is in safe state.\nSafe"
		" sequence is: ";
	for (int i = 0; i < P ; i++)
		cout << safeSeq[i] << " ";

	return true;
}

// Driver code
int main()
{
    int i,j;
    cout<<"enter the number of process: ";
    cin>>P;
    int processes[100];
    cout<<"\n enter the process no: ";
    for(i=0;i<P;i++){
        cin>>processes[i];
    }
    cout<<"\n enter the resource: ";
    cin>>R;
    cout<<"\n enter the avail: ";
    int avail[100];
    for(i=0;i<R;i++){
        cin>>avail[i];
    }
    cout<<"\n enter the maximum request:";
    int maxm[100][100],allot[100][100];
    for(i=0;i<P;i++){
        for(j=0;j<R;j++){
            cin>>maxm[i][j];
        }
    }
    cout<<"\n enter the allocation:";
    for(i=0;i<P;i++){
        for(j=0;j<R;j++){
            cin>>allot[i][j];
        }
    }
    isSafe(processes, avail, maxm, allot);


	/*int processes[n] = {0, 1, 2, 3, 4};

	// Available instances of resources
	int avail[] = {3, 3, 2};

	// Maximum R that can be allocated
	// to processes
	int maxm[][R] = {{7, 5, 3},
					{3, 2, 2},
					{9, 0, 2},
					{2, 2, 2},
					{4, 3, 3}};

	// Resources allocated to processes
	int allot[][R] = {{3, 3, 2},
					{2, 0, 0},
					{3, 0, 2},
					{2, 1, 1},
					{0, 0, 2}};*/

	// Check system is in safe state or not


	return 0;
}

