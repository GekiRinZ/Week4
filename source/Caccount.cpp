#include "Maccount.h"
#include "Mchat.h"
#include<bits/stdc++.h>
#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;

Maccount::Maccount(){}
Maccount::~Maccount(){}
void Maccount::LogIn() {
	username = new (char);
	password = new (char);

	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	Mchat conn;
	conn.Open();
	if (conn.Select_login(conn.db,username,password)>0) {
		cout << "Login successfully!\n";
		id = conn.Select_login(conn.db, username, password);
		check = true;
		zuid = id;
	}
	else {
		cout << "Login fail!\n";
		check = false;
		_getch();
	}
}
void Maccount::Register() {
	username = new (char);
	password = new char;
	birth = new char;
	name = new char;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	cout << "Gender: ";
	cin >> sex;
	cout << "Birth: ";
	cin >> birth;
	cout << "Name: ";
	cin >> name;
	cout << "Address: (use province code from(1-63)): ";
	cin >> address;
	Mchat conn;
	conn.Open();
	if (conn.Select_all(conn.db,username)>0) {
		cout << "Username available! \n" << endl;
	}
	else
	{
		conn.Insert_Acc(conn.db, username, password, sex, birth, name, address);
		int id_mask = conn.Select_mask(conn.db);
		conn.Insert_maskuser(conn.db, id_mask, name, sex, address);
		cout << "Success!" << endl;
	}
}
void Maccount::LogOut() {
	check = false;
	cout << "Logout success!\n";
}

void Maccount::SendMess(int id) {
	if (check) {
		int fid;
		cout << "Choose user: ";
		char *frien;
		frien = new char;
		cin >> frien;
		Mchat conn;
		conn.Open();
		fid = conn.Seach_fr(frien);
		if (fid > 0) {
			char *mess, *dt;
			mess = new char;
			dt = new char;
			if (conn.CheckBlock(conn.db, id, fid)) {
				cout << "You are blocked!\n";
			}
			else {
				int tt = 1;
				conn.update_tt(conn.db, id, fid);
				cout << "Insert Mess: \n";
				cin.ignore();
				cin.getline(mess,100);
				time_t hientai = time(0);
				dt = ctime(&hientai);
				long int x;
				x = static_cast<int> (hientai);
				conn.WriteToMess(conn.db, id, fid, mess, dt,tt, x);
				conn.ShowMessDetail(conn.db, id, fid);
			}
		}
		else cout << "Username does not exist! \n";
	}
	else {
		cout << "Login first!\n";
	}
}
void Maccount::SendMess_ctr_l(int id) {

	if (check) {
		    char ch;
            cout << "Press Ctrl + L to continue.\n";
            cin.ignore();
            ch= getch();
			if (ch == 12)
			{
				Mchat conn;
				conn.Open();
				ShowFriend(id);
				cout << "Choose user: ";
				int n;
				cin >> n;
				int fid=conn.ShowaaFriend(conn.db,id,n);
				char *mess, *dt;
				mess = new char;
				dt = new char;
				int tt = 1;
				conn.update_tt(conn.db, id, fid);
				cout << "Insert Mess: \n";
				cin.ignore();
				cin.getline(mess, 100);
				time_t hientai = time(0);
				dt = ctime(&hientai);
				long int x;
				x = static_cast<int> (hientai);
				conn.WriteToMess(conn.db, id, fid, mess, dt, tt, x);
			}

		}
	else {
		cout << "Login first!\n";
	}
}
void Maccount::ShowMess_send(int ID) {
	if (check) {
		Mchat conn;
		conn.Open();
		conn.SelectMess_send(conn.db, zuid);
	}
	else {
		cout << "Login first!\n";
	}
}
void Maccount::ShowMess_rec(int ID) {
	if (check) {
		Mchat conn;
		conn.Open();
		conn.SelectMess_receive(conn.db, zuid);
	}
	else {
		cout << "Login first!\n";
	}
}
int Maccount::ShowMessDetail(int uid) {
	if (check) {
		int fid;
		cout << "Choose User: ";
		char *frien;
		frien = new char;
		cin >> frien;
		Mchat conn;
		conn.Open();
		fid = conn.Seach_fr(frien);
		if (fid > 0) {
			conn.ShowMessDetail(conn.db, uid, fid);
			zfid = fid;
			Detail = true;
		}
		else { cout << "Username does not exist! \n"; Detail = false; }
	}
	else {
		cout << "Login first!\n";
	}
	return zfid;
}
void Maccount::ShowFriend(int id) {
	if (check) {
		Mchat conn;
		conn.Open();
		conn.ShowFriend(conn.db, id);
	}
	else {
		cout << "Login first!\n";
	}
}
void Maccount::ShowFriend_ctr_C(int id) {
	if (check) {
		   char ch;
            cout << "Ctrl+C to Sort Friend\n";
            cin.ignore();
            ch = getch();
            if(ch == 3)

			{
				Mchat conn;
				conn.Open();
				conn.ShowFriend(conn.db, id);
			}

		}

	else {
		cout << "Login first!n\n";
	}
}
void Maccount::AddFriend(int id) {
	if (check) {
		cout << "Username you want to add: ";
		char *newfr;
		newfr = new char;
		cin >> newfr;
		Mchat conn;
		conn.Open();
		int fid = conn.Seach_fr(newfr);
		if (fid > 0) {
			if (!conn.CheckFriend(conn.db, id, fid)) {
				if (!conn.CheckBlock(conn.db, id, fid)) {
					conn.WriteToFriend(conn.db, id, fid);
					ShowFriend(id);
				}
				else cout << "You were blocked by him(her)\n";
			}
			else cout << "You was friend\n";
		}
		else cout << "Username does not exist! \n";
	}
	else cout << "Login first!\n";
}
void Maccount::BlockFriend(int id) {
	if (check) {
		cout << "You want to block: \n";
		char *name;
		name = new char;
		cin >> name;
		Mchat conn;
		conn.Open();
		int fid = conn.Seach_fr(name);
		if (fid > 0) {
			conn.BlockFriend(conn.db, id, fid);
			cout << "---------Block Successfuly---------\n";
			conn.ShowFriend(conn.db, id);
		}
		else cout << "Username does not exist! \n";
	}
	else {
		cout << "Login first!\n";
	}
}
void Maccount::Update_fr(int id) {
	if (check) {
		cout << "Username you want to change: ";
		char *newfr;
		newfr = new char;
		cin >> newfr;
		Mchat conn;
		conn.Open();
		int fid = conn.Seach_fr(newfr);
		if (fid > 0) {
			if (conn.CheckFriend(conn.db, id, fid)) {
				name = new char;
				cout << "Name: ";
				cin >> name;
				cout << "Gender: ";
				cin >> sex;
				cout << "Address: ";
				cin >> address;
				conn.Update_fr(conn.db,name,sex,address,fid);
			}
			else cout << "You was friend \n";
		}
		else cout << "Username does not exist! \n";
	}
	else cout << "Login first!\n";
}
int Maccount::Detail_fr(int id) {
	if (check) {
		cout << "Username you want to see detail: ";
		char *newfr;
		newfr = new char;
		cin >> newfr;
		Mchat conn;
		conn.Open();
		int fid = conn.Seach_fr(newfr);
		if (fid > 0) {
			if (conn.CheckFriend(conn.db, id, fid)) {
				conn.Detail_fr(conn.db, fid);
				Detail = true;
				zfid = fid;
			}
			else { cout << "You was friend \n"; Detail = false;}
		}
		else { cout << "Username does not exist! \n"; Detail = false;}
	}
	else cout << "Login first!\n";
	return zfid;
}
void Maccount::Reply(int id) {
	if(check){

            char ch;
	        cout << "Press Ctrl+R.\n";
            cin.ignore();
            ch = getch();
            if(ch == 18){
			char *mess, *dt;
			mess = new char;
			dt = new char;
			int tt = 1;
			Mchat conn;
			conn.Open();
			conn.update_tt(conn.db, id, zfid);
			cout << "Insert Mess: \n";
			cin.ignore();
			cin >> mess;
			time_t hientai = time(0);
			dt = ctime(&hientai);
			long int x;
			x = static_cast<int> (hientai);
			conn.WriteToMess(conn.db, id, zfid, mess, dt, tt, x);
			conn.ShowMessDetail(conn.db, id, zfid);
		}
}
}
void Maccount::Detail_Reply(int id) {
	char *mess, *dt;
	mess = new char;
	dt = new char;
	int tt = 1;
	Mchat conn;
	conn.Open();
	conn.update_tt(conn.db, id, zfid);
	cout << "Insert Mess: \n";
	cin.ignore();
	cin >> mess;
	time_t hientai = time(0);
	dt = ctime(&hientai);
	long int x;
	x = static_cast<int> (hientai);
	conn.WriteToMess(conn.db, id, zfid, mess, dt, tt, x);
	conn.ShowMessDetail(conn.db, id, zfid);
}
