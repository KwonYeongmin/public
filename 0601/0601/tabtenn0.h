#pragma once
#ifndef TABTENN_H_
#define TABTENN_H_
#include <string>
using std::string;
class tableTennisPlayer
{
private:
	string firstName;
	string lastName;
	bool hasTable;
public:
	~tableTennisPlayer();
	
	tableTennisPlayer(const string &fn = "none", 
						const string &ln = "none",bool ht=false);
	void Name() const;
	bool HasTable() const { return hasTable; };
	
	//인터페이스
	void ResetTable(bool v) { hasTable = v; }
	
};


class RatedPlayer : public tableTennisPlayer
{
private:unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string &fn = "none",
		const string &ln = "none", bool ht = false);
	RatedPlayer(unsigned int, const tableTennisPlayer&tp);
	unsigned int Rating() { return rating; }
	
};

#endif // !TABTENN_H_



