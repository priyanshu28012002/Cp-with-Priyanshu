//                                1 Function binary_search_index

// Functions the return index if exists otherwise -1

int binary_search_index(vector<int>&v,int target){
   int n = v.size();
   int s=0;
    int e = n-1;
      while(s<=e){
         int mid = s + (e-s)/2;
         if(v[mid]==target){
            return mid;
         }
         else if (v[mid]>target){
            e = mid-1;
         }
         else{
            s = mid+1;
         }
      }
      return -1;
}

//                                2 Function binary_search 


// STL function return bool value if exists true otherwise false
bool found = binary_search(v.begin(), v.end(), target);


// Implementation of both functions
int main(){
    in(n);
    inputVec(v,n);
    sortav;
    
    int target = 3;
    bool found = binary_search(v.begin(), v.end(), target);

    if (found) {
        cout << "Element found in the array." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    cout<<binary_search_index(v,target);

}

