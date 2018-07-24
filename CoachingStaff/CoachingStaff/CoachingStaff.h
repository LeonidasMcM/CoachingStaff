

#ifndef COACHINGSTAFF_H
#define COACHINGSTAFF_H

#include<string>
#include<iostream>



typedef std::string IType;
class CoachingStaff
{
private:

	struct Coach {

		Coach(std::string first, std::string last, IType value) :firstname(first), lastname(last), val(value) {
			previous = nullptr;
			next = nullptr;
		}

		Coach*previous, *next;
		std::string firstname, lastname;
		IType val;
		
	};
	bool compareCoach(Coach& coach1, Coach& coach2) {
		//std::cout << "Last names: "<<coach1.lastname << " " << coach2.lastname << "\n";
		//std::cout << "First names: " << coach1.firstname << " " << coach2.firstname << "\n";
		if (coach1.lastname > coach2.lastname) {
			return true;
		}
		else if (coach1.lastname == coach2.lastname) {
			if (coach1.firstname > coach2.firstname) {
				return true;
			}
			else
				return false;
		}
		else {
			return false;
		}
	}

	Coach *Head, *Tail;
	int size;


public:
	CoachingStaff(); // Create an empty CoachingStaff list

	~CoachingStaff();// If nessecary to destroy the list post deletion

	CoachingStaff(const CoachingStaff& staff);

	void operator=(const CoachingStaff&staff);

	bool noCoaches() const; // Return true if the CoachingStaff list
							// is empty, otherwise false.

	int numberOfCoaches() const; // Return the number of elements in
								 // the CoachingStaff list.


	 /*
	 hireCoach
	 If the full name (both the first and last name) is not equal
	to any full name currently in the list then add it and return
	true. Elements should be added according to their last name.
	 Elements with the same last name should be added according to
	their first names. Otherwise, make no change to the list and
	 return false (indicating that the name is already in the
	 list).*/
	bool hireCoach(const std::string& firstName, const std::string&
		lastName, const IType& value);
	
	// If the full name is equal to a full name currently in the
	// list, then make that full name no longer map to the value it
	// currently maps to, but instead map to the value of the third 
	// parameter; return true in this case. Otherwise, make no
	// change to the list and return false.
	bool renameCoach(const std::string& firstName, const std::string&
		lastName, const IType& value);
	
	// If full name is equal to a name currently in the list, then
	// make that full name no longer map to the value it currently
	// maps to, but instead map to the value of the third parameter;
	// return true in this case. If the full name is not equal to
	// any full name currently in the list then add it and return
	// true. In fact, this function always returns true.
		bool hireOrRename(const std::string& firstName, const std::string&
			lastName, const IType& value);
	
		// If the full name is equal to a full name currently in the
		// list, remove the full name and value from the list and return
		// true. Otherwise, make no change to the list and return
		// false.
	bool fireCoach(const std::string& firstName, const std::string&
		lastName);
	
	// Return true if the full name is equal to a full name
	// currently in the list, otherwise false.
	bool coachOnStaff(const std::string& firstName, const std::string&
		lastName) const;
	
	// If the full name is equal to a full name currently in the
	// list, set value to the value in the list that that full name
	// maps to, and return true. Otherwise, make no change to the
	// value parameter of this function and return false.
	bool findCoach(const std::string& firstName, const std::string&
		lastName, IType& value) const;
	
	// If 0 <= i < size(), copy into firstName, lastName and value
	// parameters the corresponding information of the element at
	// position i in the list and return true. Otherwise, leave the
	// parameters unchanged and return false. (See below for details
	// about this function.)
	bool whichCoach(int i, std::string& firstName, std::string&
		lastName, IType& value) const;
	

	void changeStaff(CoachingStaff& other);
	// Exchange the contents of this list with the other one.
};

bool mergeStaffs(const CoachingStaff & csOne,
	const CoachingStaff & csTwo,
	CoachingStaff & csMerged);

void searchStaff(const std::string& fsearch,
	const std::string& lsearch,
	const CoachingStaff& csOne,
	CoachingStaff& csResult);

#endif // !COACHINGSTAFF.H
