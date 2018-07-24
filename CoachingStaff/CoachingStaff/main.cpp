#include"CoachingStaff.h"
#include<string>
#include<iostream>
#include<cassert>


using std::string;
using std::cout; using std::endl;
#include <type_traits>

#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }
static_assert(std::is_default_constructible<CoachingStaff>::value,
	"Map must be default-constructible.");

static_assert(std::is_copy_constructible<CoachingStaff>::value,
	"Map must be copy-constructible.");
void ThisFunctionWillNeverBeCalled()
{
	CHECKTYPE(&CoachingStaff::operator=, CoachingStaff&
		(CoachingStaff::*)(const CoachingStaff&));
	CHECKTYPE(&CoachingStaff::noCoaches, bool
	(CoachingStaff::*)() const);
	CHECKTYPE(&CoachingStaff::numberOfCoaches, int
	(CoachingStaff::*)() const);
	CHECKTYPE(&CoachingStaff::hireCoach, bool (CoachingStaff::*)
		(const std::string&, const std::string&, const IType&));
	CHECKTYPE(&CoachingStaff::renameCoach, bool
	(CoachingStaff::*)(const std::string&, const std::string&,
		const IType&));
	CHECKTYPE(&CoachingStaff::hireOrRename, bool
	(CoachingStaff::*)(const std::string&, const std::string&,
		const IType&));
	CHECKTYPE(&CoachingStaff::fireCoach, bool (CoachingStaff::*)
		(const std::string&, const std::string&));
	CHECKTYPE(&CoachingStaff::coachOnStaff, bool
	(CoachingStaff::*)(const std::string&, const std::string&)
		const);
	CHECKTYPE(&CoachingStaff::findCoach, bool (CoachingStaff::*)
		(const std::string&, const std::string&, IType&) const);
	CHECKTYPE(&CoachingStaff::whichCoach, bool (CoachingStaff::*)
		(int, std::string&, std::string&, IType&)
		const);
	CHECKTYPE(&CoachingStaff::changeStaff, void
	(CoachingStaff::*)(CoachingStaff&));

	CHECKTYPE(mergeStaffs, bool(*)(const CoachingStaff&, const
		CoachingStaff&, CoachingStaff&));
	CHECKTYPE(searchStaff, void(*)(const std::string&,
		const std::string&, const CoachingStaff&, CoachingStaff&));
}




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


	// numberOfCoaches and whichCoach and coachOnStaff
	for (int n = 0; n < fortyTimes.numberOfCoaches(); n++)
	{


		string first;
		string last;
		IType val;
		fortyTimes.whichCoach(n, first, last, val);

		cout << first << " " << last << " " << val << endl;
	}

	//copy Constructor
	
	CoachingStaff newone(fortyTimes);


	// mergestaff and changeStaff
	mergeStaffs(fortyTimes, o, newone);

	cout << "Should be 10 coaches:\n";
	for (int n = 0; n < newone.numberOfCoaches(); n++)
	{

		string first;
		string last;
		IType val;
		newone.whichCoach(n, first, last, val);

		cout << first << " " << last << " " << val << endl;
	}

	CoachingStaff newtwo;



	// SeachStaff
	searchStaff("*", "Kelly", newone, newtwo);

	cout << "Should be 1 coaches:\n";
	for (int n = 0; n < newtwo.numberOfCoaches(); n++)
	{

		string first;
		string last;
		IType val;
		newtwo.whichCoach(n, first, last, val);

		cout << first << " " << last << " " << val << endl;
	}

	// Hire or Rename
	newtwo.hireOrRename("CHIP", "Kelly", "4.2");
	cout << "Should be 2 coaches:\n";
	for (int n = 0; n < newtwo.numberOfCoaches(); n++)
	{

		string first;
		string last;
		IType val;
		newtwo.whichCoach(n, first, last, val);

		cout << first << " " << last << " " << val << endl;
	}

	// Hire and rename
	newtwo.hireOrRename("CHIP", "Kelly", "4.3");
	cout << "Should be 2 coaches:\n";
	for (int n = 0; n < newtwo.numberOfCoaches(); n++)
	{

		string first;
		string last;
		IType val;
		newtwo.whichCoach(n, first, last, val);

		cout << first << " " << last << " " << val << endl;
	}


	// Assignment operator fire coach
	newtwo = newone;

	newtwo.fireCoach("Dana", "Bible");
	cout << "Should be 9 coaches:\n";
	for (int n = 0; n < newtwo.numberOfCoaches(); n++)
	{

		string first;
		string last;
		IType val;
		newtwo.whichCoach(n, first, last, val);

		cout << first << " " << last << " " << val << endl;
	}

	CoachingStaff Thisone;
	if (Thisone.noCoaches()) {
		cout << "This staff is empty\n";
	}

}