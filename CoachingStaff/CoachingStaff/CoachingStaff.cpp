#include "CoachingStaff.h"



CoachingStaff::CoachingStaff() : Head(nullptr), Tail(nullptr), size(0) {};


CoachingStaff::~CoachingStaff()
{
	if (this->size == 0) {
	}
	else {
		Coach* temp = Head;
		while (Head != nullptr) {

			this->fireCoach(Head->firstname, Head->lastname);
		}
	}
}

CoachingStaff::CoachingStaff(const CoachingStaff & staff)
{
	
	Coach*temp = staff.Head;
	for(int i=0;i<staff.numberOfCoaches();i++) {
		std::string first, last;
		IType value;
		staff.whichCoach(i, first, last, value);
		this->hireCoach(first,last, value);
		temp = temp->next;
	}
}

void CoachingStaff::operator=(const CoachingStaff & staff)
{
	CoachingStaff clone=CoachingStaff(staff);
	this->changeStaff(clone);

}

bool CoachingStaff::noCoaches() const
{
	if (size == 0)
		return true;
	else 
		return false;
}

int CoachingStaff::numberOfCoaches() const
{
	return size;
}

bool CoachingStaff::hireCoach(const std::string & firstName, const std::string & lastName, const IType & value)
{

	if (this->coachOnStaff(firstName, lastName)) {
		

		return false;
	}



	else {
		Coach *Temp = Head;
		Coach* addition = new Coach(firstName,lastName,value);



	if (this->Head == nullptr) {
			this->Head = addition;
			this->Tail = addition;
			this->size=1;
			return true;
		}

	else{


		while (Temp != nullptr) {
		

			// ADDING TO THE END IF ELEMENT IS GREATER THAN OTHERS
		 if (this->compareCoach(*addition, *Temp) && Temp->next == nullptr) {
				Temp->next = addition;
				addition->previous = Temp;
				Tail = addition;
				this->size++;
				return true;
			}
		 
		 // IF IT IS GREATER THAN THE CURRENT ELEMENT BUT LESS THAN THE NEXT, INSERT INBETWEEN
		else if (this->compareCoach(*addition, *Temp) && this->compareCoach(*Temp->next, *addition)) {
				addition->previous = Temp;
				addition->next = Temp->next;

				Temp->next->previous = addition;
				Temp->next = addition;
				this->size++;
				return true;

			}

		// ADDING TO BEGINNING IF SMALLER THAN FIRST ELEMENT
		else if (this->compareCoach(*Temp, *addition) && Temp->previous == nullptr) {
			addition->next = Temp;
			Temp->previous = addition;
			Head = addition;
			Head->next = Temp;
			this->size++;
			return true;
		}



			Temp = Temp->next;

		}

		}
		return false;
	}
	
}

bool CoachingStaff::renameCoach(const std::string & firstName, const std::string & lastName, const IType & value)
{
	if(!this->coachOnStaff(firstName,lastName))
	return false;
	else {
		if (this->size == 1) {
			Head->val = value;
			return true;
		}
		else {
			Coach *Temp = Head;
			while (Temp != nullptr) {
				if (Temp->lastname == lastName && Temp->firstname == firstName) {
					Temp->val = value;
					return true;
				}

				Temp = Temp -> next;
			}
			return false;
		}
	}
}

bool CoachingStaff::hireOrRename(const std::string & firstName, const std::string & lastName, const IType & value)
{
	if (this->coachOnStaff(firstName, lastName)) {
		this->renameCoach(firstName, lastName, value);
		return true;
	}
	else {
		this->hireCoach(firstName, lastName, value);
		return true;
	}
}

bool CoachingStaff::fireCoach(const std::string & firstName, const std::string & lastName)
{
	if(!this->coachOnStaff(firstName,lastName))
return false;
	else {
		Coach *temp = Head;
		while (temp != nullptr) {
			if (temp->firstname==firstName&&temp->lastname==lastName) {
				if (temp == Head) {
					Head = temp->next;
					this->size--;
					delete temp;
					return true;
				}
				else if (temp == Tail) {
					Tail = temp->previous;
					this->size--;
					delete temp;
					return true;
				}
				else {
					temp->previous->next = temp->next;
					temp->next->previous = temp->previous;
					this->size--;
					delete temp;
					return true;
				}
				
			}

			temp = temp->next;
		}
		return false;


	}
}

bool CoachingStaff::coachOnStaff(const std::string & firstName, const std::string & lastName) const
{
	if (this->size == 0)
		return false;


	else {
		Coach *temp = Head;
		while (temp != nullptr) {
			if (temp->firstname == firstName && temp->lastname == lastName) {
				return true;
			}
			else {
				temp = temp->next;
				continue;
			}
		}
		// No coach found
			return false;
		
	}

}

bool CoachingStaff::findCoach(const std::string & firstName, const std::string & lastName, IType & value) const
{
	if(!this->coachOnStaff(firstName,lastName))
	return false;
	else {
		Coach *temp = Head;
		while (temp != nullptr) {
			if (temp->firstname == firstName && temp->lastname == lastName) {
				value = temp->val;
				return true;
			}
			else {
				temp = temp->next;
				continue;
			}
		}
		return false;
	}
}

bool CoachingStaff::whichCoach(int i, std::string & firstName, std::string & lastName, IType & value) const
{
	if (i < 0 || i >= this->size) {
		return false;
	}
	//if (i >= 0 && i < this->size) 
	else {
	
		int count = 0;
		Coach *temp = this->Head;
		for(int j=0;j<i;j++) {
			temp = temp->next;
		}
		firstName = temp->firstname;
		lastName = temp->lastname;
		value = temp->val;
		return true;
	}
}

void CoachingStaff::changeStaff(CoachingStaff & other)
{
	//Pointer swapping Heads
	Coach * temp = this->Head;
	this->Head = other.Head;
	other.Head = temp;

	// Swapping Tails
	temp = this->Tail;
	this->Tail = other.Tail;
	other.Tail = temp;

	// Swapping sizes
	int tempsize = this->size;
	this->size = other.size;
	other.size = tempsize;

}

bool mergeStaffs(const CoachingStaff & csOne, const CoachingStaff & csTwo, CoachingStaff & csMerged)
{
	CoachingStaff newone = CoachingStaff(csOne);
	int add = csTwo.numberOfCoaches();
	std::string first, last;
	IType value;
	bool check = true;
	for (int i = 0; i < add; i++) {
		csTwo.whichCoach(i, first, last, value);
		if (!newone.coachOnStaff(first, last))
			newone.hireCoach(first, last, value);
		else {
			newone.fireCoach(first, last);
			check = false;
		}
	}
	newone.changeStaff(csMerged);

	return check;

}

void searchStaff(const std::string & fsearch, const std::string & lsearch, const CoachingStaff & csOne, CoachingStaff & csResult)
{
	if (&csOne == &csResult) {
		return;
}


	CoachingStaff temp;
	std::string first, last;
	IType value;

	if (fsearch == "*"&&lsearch == "*") {
		for (int i = 0; i < csOne.numberOfCoaches(); i++) {
			csOne.whichCoach(i, first, last, value);
			temp.hireCoach(first, last, value);
		}
	}
	else if (fsearch == "*") {
		for (int i = 0; i < csOne.numberOfCoaches(); i++) {
			csOne.whichCoach(i, first, last, value);
			if (lsearch == last)
			temp.hireCoach(first, last, value);
		}
	}
	else if (lsearch == "*") {
		for (int i = 0; i < csOne.numberOfCoaches(); i++) {
			csOne.whichCoach(i, first, last, value);
			if (fsearch == first)
				temp.hireCoach(first, last, value);
		}
	}

	temp.changeStaff(csResult);
}
