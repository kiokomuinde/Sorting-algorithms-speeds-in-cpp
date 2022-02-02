#include<iostream>
#include<string.h>
#include<stdio.h>
#include <fstream>
#define MAX_LINE_LENGTH 100000
using namespace std;
#define MAX_NAME_LENGTH 255

// partition the array using last element as pivot
int partition (string str[], string record[], int low, int high) 
{ 
    string pivot; 
    string bigPivot;

    // strcpy(pivot, str[high]); 
    pivot =  str[high]; // pivot 

    // strcpy(bigPivot, record[high]); 
    bigPivot = record[high];
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (pivot.compare(str[j]) > 0) 
        { 
            i++;    // increment index of smaller element 
            swap(str[i], str[j]); 
            swap(record[i], record[j]);
        } 
    } 
    swap(str[i + 1], str[high]);
    swap(record[i + 1], record[high]);
    return (i + 1); 
} 
   
//quicksort algorithm
void quickSort(string str[], string record[], int low, int high) 
{ 
    if (low < high) 
    { 
        //partition the array 
        int pivot = partition(str, record, low, high); 
   
        //sort the sub arrays independently 
        quickSort(str, record, low, pivot - 1); 
        quickSort(str, record, pivot + 1, high); 
    } 
} 
   
void displayArray(string record[], int size, string topic) 
{ 

    // Creating and opening an output file 
    ofstream myfile2("quicksort.csv");

    //printing topic first
    myfile2<<topic;
    int i; 
    for (i=0; i < size; i++){  
        // printing our array into an output file
        myfile2<<record[i]<<endl;
    }
}
   
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
        while ( myfile2.getline(line, MAX_LINE_LENGTH) )
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

    quickSort(str, record, 0, n-1); 
    cout<<"Array sorted with quick sort"<<endl; 
    displayArray(record,n, topic); 
    return 0; 
}