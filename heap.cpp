#include<iostream>
#include<string.h>
#include<stdio.h>
#include <fstream>
using namespace std;
#define MAX_NAME_LENGTH 255
#define MAX_LINE_LENGTH 100000
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(string str[], string record[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && str[l].compare(str[largest]) > 0)
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && str[r].compare(str[largest]) > 0) 
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(str[i], str[largest]);
        swap(record[i], record[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(str, record, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(string str[], string record[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(str, record, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(str[0], str[i]);
        swap(record[0], record[i]);
 
        // call max heapify on the reduced heap
        heapify(str, record, i, 0);
    }
}
 
/* A utility function to print array of size n */
void printArray(string record[], int size, string topic) 
{ 

    // Creating and opening an output file 
    ofstream myfile2("heapsort.csv");

    //printing topic first
    myfile2<<topic;
    int i; 
    for (i=0; i < size; i++){  
        // printing our array into an output file
        myfile2<<record[i]<<endl;
    }
}
 
// Driver code
int main()
{
    char line[MAX_LINE_LENGTH];
    
    //Our input file
    ifstream myfile ("329416963_ChildCareCenters.csv");
    int i = 0;

    //Opening file to get its number of line for allocating our array length
    while ( myfile.getline(line, MAX_LINE_LENGTH) )
    {
      i++;
    }
    myfile.close();

    // Opening our file again to feed in our arrays
    ifstream myfile2 ("329416963_ChildCareCenters.csv");

    // ifstream myfile ("329416963_ChildCareCenters.csv");

    int n = i;


    // Global variables 
    // Name to contain characters of length max name length
    string str[n];

    //record to be max line length in size
    string record[n];

    //USed to store first line of the csv file.
    string topic;

    i = 0;
    
    //Variable to be used for tokenising text
    char *token;
    string name;
    int iterator = 0;
    if (myfile2.is_open())
    {
        while ( myfile2.getline(line, MAX_LINE_LENGTH))
        {

            if (i==0)
            { 

                topic = line;
            }else{

                //Feeding our record array to store the data in every record
                record[i] = line;

                int k =0;
                token = strtok(line, ",");
                    for (k = 0; k < 5; k++)
                    {
                          
                        if (k == 4)
                        {
                            //Feeding our str array with the names to be used for sorting
                            str[i] = token;

                        }
                        
                        token = strtok(NULL,",");
                          
                    }

                iterator++;

            }
          
            i++;
        }
        
        //Close file
        myfile2.close();

        
    }else cout << "Unable to open file";
 
    heapSort(str, record, n);
 
    cout << "Sorted array is \n";
    printArray(record, n, topic);
}