// args.cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string *args_to_strArray(int argc, char **argv){

  string *s = new string[argc]();
  
  for (int i = 0; i < argc; i++){
      s[i] = argv[i];
  }

  return s;

}

void print_args(int argc, string *strs){

    for (int i = 0; i < argc; i++){
        cout << "array:: " << strs[i] << endl;
    }
}

vector<string> args_to_strVector(int argc, char **argv){
  vector<string> s;

    for (int i = 0; i< argc; i++){
        s.push_back(argv[i]);
    }

  return s;
}

void print_args(vector<string> strs){
 
  for(int i = 0; i < strs.size(); i++){
     cout << "vector:: " << strs[i] << endl;
  }
}

int main(const int argc, char** argv) {
    string *s;
    vector<string> v;

  cout << "You entered: "
       << argc << " arguments:" << endl;

  for (int i = 0; i < argc; ++i){
      cout << argv[i] << endl;
  }

    s= args_to_strArray(argc, argv);
   print_args(argc, s);

    v = args_to_strVector(argc, argv);
    print_args(v);

  return 0;

}