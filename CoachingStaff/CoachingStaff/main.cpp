#include"CoachingStaff.h"
#include<string>
#include<iostream>
#include<cassert>


using std::string;
using std::cout; using std::endl;

int main() {

	// General test
	
		CoachingStaff o;
		o.hireCoach("Chip", "Kelly", "54");
		o.hireCoach("Dana", "Bible", "64");
		o.hireCoach("Jimmie", "Dougherty", "39");
		o.hireCoach("DeShaun", "Foster", "38");
		o.hireCoach("Derek", "Sage", "40");
		o.hireCoach("Justin", "Frye", "34");

		CoachingStaff fortyTimes;

		fortyTimes.hireCoach("Jerry", "Azzinaro", "6.99");
		fortyTimes.hireCoach("Vince", "Oghobaase", "5.19");
		fortyTimes.hireCoach("", "", "4.00");
		fortyTimes.hireCoach("Roy", "Manning", "4.7");
	
		{
			//cout << "The " << n + 1 << " Coach:\n";

			string first;
			string last;
			IType val;
			fortyTimes.whichCoach(n, first, last, val);

			cout << first << " " << last << " " << val << endl;
		}
	{
		
		string first;
		string last;
		IType val;
		newone.whichCoach(n, first, last, val);

		cout << first << " " << last << " " << val << endl;
	}
	{

		string first;
		string last;
		IType val;
		newtwo.whichCoach(n, first, last, val);

		cout << first << " " << last << " " << val << endl;
	}