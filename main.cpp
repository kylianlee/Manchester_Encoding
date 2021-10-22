//
// Created by Kylian Lee on 2021/10/22.
//

#include <iostream>

using namespace std;

void ManchesterEncoding(const string &code){
  cout << "Manchester Encoding" << '\n';
  unsigned long len = code.length();
  if(code[0] == '0')
    cout << "⎺|⎽";
  else
    cout << "⎽|⎺";
  for (int i = 1; i < len; ++i) {
    if(code[i] == '0'){
      if(code[i - 1] == '0')
        cout << "|⎺|⎽";
      else
        cout << "⎺|⎽";
    }
    else{
      if(code[i - 1] == '1')
        cout << "|⎽|⎺";
      else
        cout << "⎽|⎺";
    }
  }
  cout << '\n';
}

void DiffManchesterEncoding(const string &code) {
  cout << "Differential Manchester Encoding" << '\n';
  unsigned long len = code.length();
  bool highVoltage = false;
  if(code[0] == '0')
    cout << "|⎺|⎽";
  else
    cout << "⎺|⎽";
  for (int i = 1; i < len; ++i) {
    if(code[i] == '0'){
      if(highVoltage)
        cout << "|⎽|⎺";
      else
        cout << "|⎺|⎽";
    }
    else{
      if(highVoltage)
        cout << "⎺|⎽";
      else
        cout << "⎽|⎺";
      highVoltage = !highVoltage;
    }
  }
  cout << '\n';
}

void ManchesterDecoding(const string &code){
  unsigned long len = code.length();
//  for (int i = 0; i < len; ++i) {
//
//  }
  cout << len << '\n';
}

void DiffManchesterDecoding(const string &code){

}

int main(){
  string code;
  cin >> code;
  //code = 01100010110101100111
  ManchesterEncoding(code);
  DiffManchesterEncoding(code);

  string code1 = "⎺|⎽⎽|⎺|⎽|⎺⎺|⎽|⎺|⎽|⎺|⎽⎽|⎺⎺|⎽⎽|⎺|⎽|⎺⎺|⎽⎽|⎺⎺|⎽⎽|⎺|⎽|⎺⎺|⎽|⎺|⎽⎽|⎺|⎽|⎺|⎽|⎺";
//  string code1 = "⎺";
  string code2 = "|⎺|⎽⎽|⎺⎺|⎽|⎺|⎽|⎺|⎽|⎺|⎽⎽|⎺|⎽|⎺⎺|⎽⎽|⎺|⎽|⎺⎺|⎽|⎺|⎽⎽|⎺⎺|⎽|⎺|⎽|⎺|⎽⎽|⎺⎺|⎽⎽|⎺";
  ManchesterDecoding(code1);
  DiffManchesterDecoding(code2);
  return 0;
}