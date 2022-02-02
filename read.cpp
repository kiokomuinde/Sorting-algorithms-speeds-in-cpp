// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include<stdio.h>
#define MAX_LINE_LENGTH 100000
using namespace std;


// A utility function to print an array of size n
void printArray(string record[], int n){

  int i;
  for(i=0; i<n; i++)
    {
        cout<<i<< ".  "<<record[i]<<"\n";
    }
}

int main () {
  char line[100000];
  ifstream myfile ("329416963_ChildCareCenters.csv");

  int i = 0;
  char *token;
  // char **name;
  int n = 0;

//   char **Answers = 
// for(i = 0 ; i < 11 ; i++)
// {
//    Answers[i] = calloc(1, sizeof(char)*MY_STRING_LENGTH); //Basically it is MY_STRING_LENGTH as sizeof(char) is almost always one, but it's there only for the readability of the code.
// }

  while ( myfile.getline(line, MAX_LINE_LENGTH) )
  {
    i++;
  }
  myfile.close();

  ifstream myfile2 ("329416963_ChildCareCenters.csv");
  cout<<i<<endl;
  n = i;
  i =0;
  
  // name = (char **)malloc (n * sizeof (char *));
  string name[n];

  i =0;

  char temp[255];
  if (myfile2.is_open())
  {
    while ( myfile2.getline(line, 100000) )
    {

      int k =0;
      token = strtok(line, ",");
      for (k = 0; k < 5; k++)
    {
      
      if (k == 4)
      {
        // strcpy(name[i], &token);
        name[i] = token;
        // strcpy(name, temp);

      }
      token = strtok(NULL,",");
      
    }

      if (i==0)
      {  
          //nothing for now
        
      }else{

        // cout<<i<<".  " << name[i] << '\n';
      }
      
      i++;
    }
    myfile2.close();

    
  }else cout << "Unable to open file"; 
  

  // printArray(name, n);

  cout<<name[2].compare(name[1]);

  return 0;
}