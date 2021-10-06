#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int main()
{
string str;
cout << "Enter the location: ";
cin >> str;
ifstream addresses("personnel_addresses.txt");
multimap<string, string>name_address;
ifstream salaries("personnel_salaries.txt");
multimap<string, string>name_salary;
string tmpstr1, tmpstr2;
while(getline(addresses, tmpstr1))
{
	int pos = tmpstr1.find("|");
	string name2address = tmpstr1.substr(0, pos);
	string address = tmpstr1.substr(pos+1);
	name_address.insert({address, name2address});
}	
while(getline(salaries, tmpstr2))
{
	int pos = tmpstr2.find("|");
	string name2employee = tmpstr2.substr(0, pos);
	string salary = tmpstr2.substr(pos+1);
	name_salary.insert({name2employee, salary});
}
	set<string>employees;
	int k=0;
	for (auto it = name_address.begin(); it != name_address.end(); ++it)
	{
		for(int i = 0; i < it->first.length(); ++i)
		{
			string tmpstr3 = it->first.substr(0+i, str.length());
			if(str == tmpstr3)
			{
				employees.insert(it->second);
				break;
			}
		}
	}	
		for (auto i = employees.begin(); i != employees.end(); i++)
		{
			for(auto it = name_salary.find(*i); it != name_salary.end(); it++)
			{
				
				if(*i == it->first)
				{
				cout << *i << ":" << it->second << "\n";
				//k++;
				break;
				}  
			}
		}
		//cout<<k<<"\n";
addresses.close();
salaries.close();
return 0; 
}
