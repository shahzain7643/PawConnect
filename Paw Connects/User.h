#ifndef User_H
#define User_H
#include <string>
using namespace std;
class User
{

private:
	string name;
	string email;
	string UserID;

public:
	User();
	User(string nme, string em, string id);
	virtual void display_menu() = 0;
	void setname(string nme);
	void setemail(string em);
	void setUserID(string id);
	string getname();
	string getemail();
	string getUserID();


};



#endif
