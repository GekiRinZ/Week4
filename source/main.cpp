#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "Maccount.h"

using namespace std;
Maccount u = Maccount();

void Detail_send_fr() {
	int chon;
    cout << "1.Detail send friend. \n " << endl;
    cout << "2.Exit. \n " << endl;
    cout << "Chose 1-2: \n ";
	while (1)
	{
		cout << "ban chon so: ";
		cin >> chon;
		switch (chon) {
		case 1:
			u.Detail_Reply(u.id);
			break;
		case 2:
			return;
		}
	}
}
void  Ctrl_R() {
	int chon;
	while (1)
	{
        cout << "1.Reply Friend. \n " << endl;
        cout << "2.Exit. \n " << endl;
		cout << "Chose 1-2: \n ";
		cin >> chon;
		switch (chon) {
		case 1:
			u.Reply(u.id);
			break;
		case 2:
			return;
		}
	}
}
void send() {
	int chon;
	while (1)
	{
		cout << "1.Send Mess. \n " << endl;
		cout << "1.Ctrl+L Function. \n " << endl;
        cout << "3.Exit. \n " << endl;
		cout << "Chose 1-3: \n ";
		cin >> chon;
		switch (chon) {
		case 1:
			u.SendMess(u.id);
			break;
		case 2:
			u.SendMess_ctr_l(u.id);
			break;
		case 3:
			return;
		}
	}
}
void showmess() {
	int chon;
	while (1)
	{
		cout << "1.Send Mess. \n " << endl;
		cout << "2.Receive Mess. \n " << endl;
		cout << "3.Exit. \n " << endl;
		cout << "Choose 1-3: ";
		cin >> chon;
		switch (chon) {
		case 1:
			u.ShowMess_send(u.id);
			break;
		case 2:
			u.ShowMess_rec(u.id);
			break;
		case 3:
			return;
		}
	}
}
void login() {
	int chon;
	while (1)
	{
		cout << "User menu: \n" << endl;
		cout << "1.ShowMess. \n " << endl;
		cout << "2.MessDetail. \n " << endl;
		cout << "3.SendMess. \n " << endl;
		cout << "4.AddFriend. \n " << endl;
		cout << "5.FriendList. \n " << endl;
		cout << "6.BlockFriend. \n " << endl;
		cout << "7.UpdateFriend. \n " << endl;
		cout << "8.FriendDetail. \n " << endl;
		cout << "9.Exit. \n " << endl;
		cout << "Choose 1-9: ";
		cin >> chon;
		switch (chon) {
			case 1:
				showmess();
				break;
			case 2:
				u.ShowMessDetail(u.id);
				if (u.Detail) {
					Ctrl_R();
				}
				break;
			case 3:
				send();
				break;
			case 4:
				u.AddFriend(u.id);
				break;
			case 5:
				u.ShowFriend_ctr_C(u.id);
				break;
			case 6:
				u.BlockFriend(u.id);
				break;
			case 7:
				u.Update_fr(u.id);
				break;
			case 8:
				u.Detail_fr(u.id);
				if (u.Detail) {
					Detail_send_fr();
				}
				break;
			case 9:
				break;
			default:
				printf(" ");
				_getch();
		}
		if (chon == 9)
		{
			break;
		}
	}
}


void print_menu() {
	cout << "Menu:\n";
	cout << "1.Login\n";
	cout << "2.Register\n";
	cout << "3.Logout\n";
	cout << "4.Exit\n";
	cout << "Choose 1-4: ";
}
int main()
{
	int choice = 0;
	do {
		system("cls");
		print_menu();
		fflush(stdin);
		cin >> choice;
		switch (choice) {
		case 1:
			u.LogIn();
			if (u.check) {
				login();
			}
			break;
		case 2:
			u.Register();
			break;
		case 3:
			u.LogOut();
			break;
		case 4:
			break;
		default:
			printf("\r\n>> Choose another!");
			_getch();
		}
		if (choice == 4)
		{
			break;
		}
	} while (1);
	printf("\r\n>> End!");
	return 0;
}

