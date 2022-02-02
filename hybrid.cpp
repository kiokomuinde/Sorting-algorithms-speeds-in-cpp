#include<iostream>
#include<string.h>
#include<stdio.h>
#include <fstream>
#define MAX_NAME_LENGTH 255
#define MAX_LINE_LENGTH 100000
using namespace std;

// Quick sort start 

// partition the array using last element as pivot
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
// Quick sort end


// Insertion sort start
//Function for insertion sort of our char array
void insertionSort(string str[], string record[], int n){
    string t;
    string bigTemp;
    int i, j;

    for(i=1; i<n; i++)
    {
        // strcpy(t, str[i]);
        t = str[i];
        // strcpy(bigTemp, record[i]);
        bigTemp = record[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && str[j].compare(t) > 0) {

            // strcpy(str[j + 1], str[j]);
            str[j + 1] = str[j];
            // strcpy(record[j + 1], record[j]);
            record[j + 1] = record[j];
            j = j - 1;
        }
        // strcpy(str[j + 1], t);
        str[j + 1] = t;
        // strcpy(record[j + 1], bigTemp);
        record[j + 1] = bigTemp;


    }

}

// A utility function to print an array of size n
void printArray(string record[], int size, string topic) 
{ 

    // Creating and opening an output file 
    ofstream myfile2("hybrid.csv");

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
    

    if (n<=20)
    {
    	insertionSort(str, record, n);
    }else{

    	quickSort(str, record, 0, n-1);
    	
    }
    

    cout<<"\n Names Sorted in Alphabetical Order : \n\n";

    printArray(record, n, topic);
    return 0;
}