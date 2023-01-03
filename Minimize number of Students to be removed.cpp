/*
Link to the "Minimize number of Students to be removed" Problem ==>>  https://practice.geeksforgeeks.org/problems/7d0fa4007b8eabadc404fcc9fa917aa52982aa96/1

Link to the complete Explaination Video ==>> https://youtu.be/DDb41WsMw7I 

*/

class Solution {
  public:
    int removeStudents(int H[], int n) {
        
        vector<int>arr;
        for(int i=0;i<n;i++){
    
          int it=lower_bound(arr.begin(),arr.end(),H[i])-arr.begin();
          if(it==arr.size()){
              arr.push_back(H[i]);
          }
          else
            arr[it]=H[i];
        }
        return n-arr.size();
    }
};