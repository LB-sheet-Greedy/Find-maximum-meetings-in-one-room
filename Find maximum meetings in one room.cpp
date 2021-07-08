/*
Approach: Same as Activity Selection Problem.

>> Sort all pairs(Meetings) in increasing order of second number(Finish time) of each pair.

>> Select first meeting of sorted pair as the first Meeting in the room and push it into result 
   vector and set a variable time_limet(say) with the second value(Finishing time) of the first selected meeting.

>> Iterate from the second pair to last pair of the array and if the value of the first element(Starting time of meeting) 
   of the current pair is greater then previously selected pair finish time (time_limit) then select the current pair and 
   update the result vector (push selected meeting number into vector) and variable time_limit.

>> Print the Order of meeting from vector.

Time Complexity: O(Nlog(N)) for sorting

*/

#include<iostream>
#include<algorithm>  //to use sort()
#include<vector>    

using namespace std;

// Structure for storing starting time, finishing time and position of meeting.
struct meeting 
{
    int start;
    int end;
    int pos;
};

//our own comparator function
//Comparator function which can compare the second element of structure used to sort pairs in increasing order of second value.
bool comparator(struct meeting m1,struct meeting m2)
{
	//returns true if condition holds
    return (m1.end<m2.end);
}

//our greedy function
void maxMeeting(int s[],int f[],int n)
{
	//making a structure array
    struct meeting meet[n];
    
    //Feeding the structure array we just created above with input arrays by user
    for (int i=0;i<n;i++)
    {
        //Starting time of meeting i.
        meet[i].start=s[i];
         
        //Finishing time of meeting i
        meet[i].end=f[i];
         
        //Original position/index of meeting
        meet[i].pos=i+1;
    }
 
    //Sorting of meeting according to their finish time. We pass the structure.
	//3rd argument is what we created above in bool function
    sort(meet,meet+n,comparator);
 
    //_________________After sorting__________________
 
    //Using vector for storing selected Activity as we don't know size beforehand to store. Print this vector later
    vector<int> m;
 
    //Initially select first meet bcoz its the one thats going to finish soon so that we can do more meetings (greedy).
    m.push_back(meet[0].pos);
 
    //time_limit to check whether new meeting can be conducted or not.
    int time_limit=meet[0].end;
 
    //Tarverse the struct array from 1st index and check whether the current meeting can be selected or not.
    //The meeting can be selected only if its starting time is less than or equal to time_limit
    for (int i=1;i<n;i++) 
	{
        if (meet[i].start >= time_limit)
        {
            //Push selected meeting to vector
            m.push_back(meet[i].pos);
             
            //Update time limit so that we can select next meeting
            time_limit=meet[i].end;
        }
    }
 
    // Print final selected meetings.
    cout<<"\nSelected activities in  terms of index numbers are => \n";
    for (int i=0;i<m.size();i++) 
	{
        cout<<" "<<m[i];
    }
}

int main()
{
	//Keeping input static as its just for testing purpose
	
	//Starting time
    int s[] = { 1, 3, 0, 5, 8, 5 };
     
    //Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
     
    //Number of meetings.
    int n=6;
 
    //call our sunction
    maxMeeting(s, f, n);
	
	return 0;
}
