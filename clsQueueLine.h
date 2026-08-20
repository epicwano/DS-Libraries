#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include <stack>
#include "E:/Libraries/clsDate.h"

using namespace std;

class clsQueueLine
{

private:

	struct TicketInfo {

		string ID;
		string DateTime;
		int WitingClients;
		int WaitngTime;
	};

	queue<TicketInfo> _QueueLine;
	queue<TicketInfo> _TempQueue;

	int _TotalTickets = 0;
	int _WitingClients = 0;
	int _ServedClients = 0;

	string _Prefix;
	short _AvarageWitingTime;


	TicketInfo _PrepareTicket()
	{
		TicketInfo Ticket;

		Ticket.ID = _Prefix + to_string(_TotalTickets + 1);
		Ticket.DateTime = clsDate::GetSystemDateTime();
		Ticket.WitingClients = (_TotalTickets + 1) - 1;
		Ticket.WaitngTime = _WitingClients * _AvarageWitingTime;

		return Ticket;
	}

	void _PrintClientTicket(TicketInfo Ticket)
	{
		cout << setw(35) << left << "" << "_____________________\n\n";
		cout << setw(35) << left << "" << "\t   " << Ticket.ID << "\n\n";
		
		cout << setw(35) << left << "" << "  " << Ticket.DateTime << endl;
		cout << setw(35) << left << "" << "  Waitng CLinets : " << Ticket.WitingClients << endl;
		cout << setw(35) << left << "" << "  Serve Time in \n";
		cout << setw(35) << left << "" << "   " << Ticket.WaitngTime << "Minutes." << endl;
		cout << setw(35) << left << "" << "_____________________\n";
	}

public:

	struct TicketInfo;

	clsQueueLine(string Prefix,short AvarageWitingTime)
	{
		_Prefix = Prefix;
		_AvarageWitingTime = AvarageWitingTime;	
	}

	void PrintInfo()
	{

		cout << setw(35) << left << "" << "____________________________\n\n";
		cout << setw(35) << left << "" << "\t   Queue Info \n";
		cout << setw(35) << left << "" << "____________________________\n\n";
					  
		cout << setw(35) << left << "" << "   Prefix          = " << _Prefix << endl;
		cout << setw(35) << left << "" << "   Total Tickets   = " << _TotalTickets << endl;
		cout << setw(35) << left << "" << "   Served Clients  = " << _ServedClients << endl;
		cout << setw(35) << left << "" << "   Witing Clients  = " << _WitingClients << endl;
					  
		cout << setw(35) << left << "" << "____________________________\n\n";

	}

	void IssueTicket()
	{
		TicketInfo Ticket = _PrepareTicket();

		_QueueLine.push(Ticket);
		_TotalTickets++;
		_WitingClients++;

	}

	void PrintTicketsLineRTL(bool Reverse = false)
	{
		if (Reverse)
		{
			queue<TicketInfo> Copy = _QueueLine;
			stack<TicketInfo> StackForReverse;

			while (!Copy.empty())
			{
				StackForReverse.push(Copy.front());
				Copy.pop();
			}

			while (!StackForReverse.empty())
			{
				_TempQueue.push(StackForReverse.top());
				StackForReverse.pop();
			}

		}
		else
			_TempQueue = _QueueLine;
		

		cout << setw(25) << left << "" << "Tickets: ";

		while (!_TempQueue.empty())
		{
			cout << _TempQueue.front().ID << " <-- ";
			_TempQueue.pop();
		}

		cout << "\n";
	}

	void PrintTicketsLineLTR()
	{
		PrintTicketsLineRTL(true);
	}

	void PrintAllTickets()
	{
		_TempQueue = _QueueLine;

		while (!_TempQueue.empty())
		{
			_PrintClientTicket(_TempQueue.front());
			cout << "\n";
			_TempQueue.pop();
		}
	
	}

	void ServeNextClient()
	{
		_QueueLine.pop();

		_WitingClients--;
		_ServedClients++;
	}


};