#include<iostream>
#include<string.h>
#include<stdio.h>
#include <fstream>
using namespace std;
#define MAX_NAME_LENGTH 255
#define MAX_LINE_LENGTH 100000

// void merge(char [][],int, int , int );


// Merge sort 
void merge(string str[], string record[], int low, int high, int mid)
{
    // Local variables to be used for here
    int i, j, k;
    string c[high + 1];
    string d[high + 1];

    // Getting our iterators to be used in merging
    i = low;
    k = low;
    j = mid + 1;

    // Merging process
    while (i <= mid && j <= high) {
        if (str[j].compare(str[i]) > 0) {
            c[k] = str[i];
            d[k] = record[i];
            k++;
            i++;
        }
        else  {
            c[k] = str[j];
            d[k] = record[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = str[i];
        d[k] =  record[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = str[j];
        d[k] = record[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        str[i] = c[i];
        record[i] = d[i];
    }
}

void merge_sort(string str[], string record[], int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(str, record,low,mid);
        merge_sort(str, record,mid+1,high);
        //merge or conquer sorted arrays
        merge(str, record,low,high,mid);
    }
}

// A utility function to print an array of size n
void printArray(string record[], int size, string topic) 
{ 

    // Creating and opening an output file 
    ofstream myfile2("mergesort.csv");

    //printing topic first
    myfile2<<topic;
    int i; 
    for (i=0; i < size; i++){  
        // printing our array into an output file
        myfile2<<record[i]<<endl;
    }
}
      


// read input array and call mergesort
int main(){ 
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

    //sort array
    merge_sort(str, record, 0, n-1);
    cout<<"Sorted array\n";
    
    //Print array
    printArray(record, n, topic);
}