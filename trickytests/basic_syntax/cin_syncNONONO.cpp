#include <iostream>
using namespace std;

int main(){
  int choice;
  int temp;

  /*
  cin >> choice;
  cin.ignore(1024, '\n');
  cout << "fail?" << cin.fail() << endl;
  cout << "bad?" << cin.bad() << endl;

  cout << "after clear" << endl;
  cin.clear();
  cin.ignore(1024, '\n');
  cout << "fail?" << cin.fail() << endl;
  cout << "bad?" << cin.bad() << endl;

  cin >> choice;
  cin.ignore(1024, '\n');
  cout << "after input" << endl;
  cout << "fail?" << cin.fail() << endl;
  cout << "bad?" << cin.bad() << endl;
  */
  while(1){
		cin>>temp;
		try{
			if(cin.fail())
				throw 1;
		}
		catch(int){
			cin.clear();
            cin.ignore(1024, '\n');
            cin.sync() //不能清理缓存区
			cout<<"非数字"<<endl;
			continue;
		}
		cout<<temp<<endl;
	}
  return 0;
}
