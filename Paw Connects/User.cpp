#include <iostream>
#include "User.h"
#include "Dynamic_array.h"
#include <string>
using namespace std;


User::User() : name("null"), email("null"), UserID("null") {

}
User::User(string nme, string em, string id) : name(nme), email(em), UserID(id) {

}
void User::setname(string nme) {
	name = nme;
}
void User::setemail(string em) {
	email = em;
}
void User::setUserID(string id) {
	UserID = id;
}
string User::getname() {
	return name;
}
string User::getemail() {
	return email;
}
string User::getUserID(){
	return UserID;
}