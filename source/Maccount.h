#pragma once
class Maccount
{
public:
	int  id;
	char *username;
	char *password;
	bool sex;
	char *birth;
	char *name;
	int address;
	int zuid;
	bool check;
	bool Detail;
	int zfid
public:
	Maccount();
	~Maccount();
	void LogIn();
	void Register();
	void LogOut();
	void ShowMess_send(int);
	void ShowMess_rec(int);
	int ShowMessDetail(int);
	void SendMess(int);
	void SendMess_ctr_l(int);
	void AddFriend(int);
	void ShowFriend(int);
	void BlockFriend(int);
	void Update_fr(int);
	int Detail_fr(int);
	void Reply(int);
	void Detail_Reply(int);
	void ShowFriend_ctr_C(int);
};

