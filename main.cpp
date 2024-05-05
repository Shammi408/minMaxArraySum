#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// function to find the sum 

long sum(vector<int> ar, int num, int size) {
  long sum = 0;
  ar[num] = 0;
  for (int i = 0; i < size; i++) {
    sum = sum + ar[i];
  }
  return sum;
}

//function to find index of max, min or any value

int ondex(vector<int> ar, int num) {
  int a = 0;
  for (int i = 0; i < ar.size(); i++) {
    if (num == ar[i]) {
      a = i;
      break;
    }
  }
  return a;
}
/*function to print the sum
 we will not need to find the max or min value 
if we only want to add without a certain number.*/

void miniMaxSum(vector<int> arr) {
  int max = 0;
  int min = arr[0];
  int size = 0;

  for (int i = 0; i < arr.size(); i++) {

    if (max < arr[i]) {
      max = arr[i];
    } else if (min > arr[i]) {
      min = arr[i];
    }
    size++;
  }

  cout << min << "  " << max << endl;
  int maxIndex = ondex(arr, max);
  int minIndex = ondex(arr, min);

  long maxsum = sum(arr, minIndex, size);  //'size' input is not necessary we can use ar.size() 
  long minsum = sum(arr, maxIndex, size);

  cout << minsum << " " << maxsum;
}

int main() {

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp)); 

  vector<int> arr(5);

  for (int i = 0; i < 5; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  miniMaxSum(arr);

  return 0;
}
//still learning about how rtrim and ltrim works sorry rest code section is from hackerrank

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
